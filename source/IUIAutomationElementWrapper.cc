#include "IUIAutomationElementWrapper.h"

#include "Library.h"

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationElementWrapper::constructor;

IUIAutomationElementWrapper::IUIAutomationElementWrapper(IUIAutomationElement* pAutomationElement)
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
    tpl->InstanceTemplate()->SetInternalFieldCount(0);

    Nan::SetPrototypeMethod(tpl, "findFirst", FindFirst);

    constructor.Reset(Nan::GetFunction(tpl).ToLocalChecked());
    // Nan::Set(target, Nan::New("IUIAutomationElement").ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked());
}

NAN_METHOD(IUIAutomationElementWrapper::FindFirst)
{
    IUIAutomationElementWrapper *obj = Nan::ObjectWrap::Unwrap<IUIAutomationElementWrapper>(info.This());

    // IUIAutomationElement *pRoot = NULL;

    // HRESULT hr = obj->m_pAutomationElement->FindFirst();

    // v8::Local<v8::Object> element = Local<Object>::New()

    // info.GetReturnValue().Set(element);
}
