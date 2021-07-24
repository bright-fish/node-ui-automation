#include "Library.h"

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationWrapper::constructor;

IUIAutomationWrapper::IUIAutomationWrapper()
{
}

IUIAutomationWrapper::~IUIAutomationWrapper()
{
}

NAN_MODULE_INIT(IUIAutomationWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("IUIAutomation").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(0);

    Nan::SetPrototypeMethod(tpl, "getRootElement", GetRootElement);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
    Nan::Set(target, Nan::New("IUIAutomation").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(IUIAutomationWrapper::New)
{
    if (info.IsConstructCall())
    {
        IUIAutomationWrapper *obj = new IUIAutomationWrapper();
        obj->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    }
    else
    {
        const int argc = 1;
        v8::Local<v8::Value> argv[argc] = {};
        v8::Local<v8::Function> cons = Nan::New(constructor);
        info.GetReturnValue().Set(Nan::NewInstance(cons, argc, argv).ToLocalChecked());
    }
}

NAN_METHOD(IUIAutomationWrapper::GetRootElement)
{
    IUIAutomationWrapper *obj = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    IUIAutomationElement *pRoot = NULL;

    HRESULT hr = obj->m_pAutomation->GetRootElement(&pRoot);

    // v8::Local<v8::Object> element = Local<Object>::New()
    auto element = new IUIAutomationElementWrapper(pRoot);

    // todo: needs to return the IUIAutomationElementWrapper to node so it can be used.
    // info.GetReturnValue().Set(element);
}
