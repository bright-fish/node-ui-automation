#include "IUIAutomationElementWrapper.h"

#include "Library.h"
#include <comutil.h>
#include <stdio.h>

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationElementWrapper::constructor;

IUIAutomationElementWrapper::IUIAutomationElementWrapper(IUIAutomationElement *pAutomationElement)
{
    m_pAutomationElement = pAutomationElement;
}

IUIAutomationElementWrapper::~IUIAutomationElementWrapper()
{
}

void IUIAutomationElementWrapper::GetName(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    BSTR pName = NULL;

    auto pAutomationElementWrapperRaw = info.Holder()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElementWrapper = static_cast<IUIAutomationElementWrapper *>(pAutomationElementWrapperRaw);

    pAutomationElementWrapper->m_pAutomationElement->get_CurrentName(&pName);

    info.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(pName)).ToLocalChecked());
}

void IUIAutomationElementWrapper::GetProcessId(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    int32_t processId;

    auto pAutomationElementWrapperRaw = info.Holder()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElementWrapper = static_cast<IUIAutomationElementWrapper *>(pAutomationElementWrapperRaw);

    pAutomationElementWrapper->m_pAutomationElement->get_CurrentProcessId(&processId);

    info.GetReturnValue().Set(v8::Int32::New(isolate, processId));
}

NAN_MODULE_INIT(IUIAutomationElementWrapper::Init)
{
    auto isolate = target->GetIsolate();

    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("IUIAutomationElement").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();

    instanceTemplate->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(functionTemplate, "findFirst", FindFirst);

    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "name").ToLocalChecked(), GetName);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "processId").ToLocalChecked(), GetProcessId);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

Local<v8::Object> IUIAutomationElementWrapper::NewInstance(const Nan::FunctionCallbackInfo<v8::Value> &info, IUIAutomationElement *pElement)
{
    auto isolate = info.GetIsolate();
    auto context = isolate->GetCurrentContext();

    Local<v8::Function> constructorFunction = Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    auto pElementWrapper = new IUIAutomationElementWrapper(pElement);

    instance->SetInternalField(0, v8::External::New(isolate, pElementWrapper));

    // todo: accessor or define property.

    return instance;
}

void IUIAutomationElementWrapper::FindFirst(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pAutomationElementWrapperRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElementWrapper = static_cast<IUIAutomationElementWrapper *>(pAutomationElementWrapperRaw);

    auto treeScopeRaw = info[0].As<v8::Int32>()->Value();
    auto treeScope = static_cast<TreeScope>(treeScopeRaw);

    auto pConditionWrapperRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pConditionWrapper = static_cast<IUIAutomationCondition *>(pConditionWrapperRaw);

    IUIAutomationElement *pFoundElement = NULL;
    HRESULT hr = pAutomationElementWrapper->m_pAutomationElement->FindFirst(treeScope, pConditionWrapper, &pFoundElement);

    auto foundElement = IUIAutomationElementWrapper::NewInstance(info, pFoundElement);

    info.GetReturnValue().Set(foundElement);
}
