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
    Nan::Set(target, Nan::New("IUIAutomationElement").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

void IUIAutomationElementWrapper::NewInstance(const Nan::FunctionCallbackInfo<v8::Value> &info, IUIAutomationElement *pElement)
{
    v8::Isolate *isolate = info.GetIsolate();

    const unsigned argc = 1;
    Local<v8::Value> argv[argc] = {info[0]};
    Local<v8::Function> constructorFunction = Local<v8::Function>::New(isolate, constructor);
    Local<v8::Context> context = isolate->GetCurrentContext();

    auto instance = constructorFunction->NewInstance(context, argc, argv).ToLocalChecked();

    info.GetReturnValue().Set(instance);
}

void IUIAutomationElementWrapper::FindFirst(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    IUIAutomationElementWrapper *obj = Nan::ObjectWrap::Unwrap<IUIAutomationElementWrapper>(info.This());

    auto treeScopeRaw = info[0].As<v8::Int32>()->Value();
    auto treeScope = static_cast<TreeScope>(treeScopeRaw);

    auto pConditionRaw = info[1].As<v8::External>()->Value();
    auto pCondition = reinterpret_cast<IUIAutomationCondition *>(pConditionRaw);

    IUIAutomationElement *pFoundElement = NULL;
    HRESULT hr = obj->m_pAutomationElement->FindFirst(treeScope, pCondition, &pFoundElement);

    IUIAutomationElementWrapper::NewInstance(info, pFoundElement);
}
