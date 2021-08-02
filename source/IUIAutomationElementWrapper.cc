#include "IUIAutomationElementWrapper.h"

#include "Library.h"

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

NAN_MODULE_INIT(IUIAutomationElementWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>();
    tpl->SetClassName(Nan::New("IUIAutomationElement").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "findFirst", FindFirst);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
}

Local<v8::Object> IUIAutomationElementWrapper::NewInstance(const Nan::FunctionCallbackInfo<v8::Value> &info, IUIAutomationElement *pElement)
{
    auto isolate = info.GetIsolate();
    auto context = isolate->GetCurrentContext();

    Local<v8::Function> constructorFunction = Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    auto pElementWrapper = new IUIAutomationElementWrapper(pElement);

    instance->SetInternalField(0, v8::External::New(isolate, pElementWrapper));

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
