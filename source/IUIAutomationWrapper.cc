#include "Library.h"

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationWrapper::constructor;

IUIAutomationWrapper::IUIAutomationWrapper()
{
    HRESULT hr = CoInitialize(NULL);

    if (FAILED(hr))
    {
    }

    hr = CoCreateInstance(__uuidof(CUIAutomation8), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pAutomation));

    if (FAILED(hr))
    {
        // todo: Make it an error.
        wprintf(L"Failed to create a CUIAutomation8, HR: 0x%08x\n", hr);
        return;
    }
}

IUIAutomationWrapper::~IUIAutomationWrapper()
{
    CoUninitialize();
}

NAN_MODULE_INIT(IUIAutomationWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
    tpl->SetClassName(Nan::New("IUIAutomation").ToLocalChecked());
    tpl->InstanceTemplate()->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(tpl, "getRootElement", GetRootElement);
    Nan::SetPrototypeMethod(tpl, "createPropertyCondition", CreatePropertyCondition);

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
    auto isolate = info.GetIsolate();

    IUIAutomationWrapper *pAutomationWrapper = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    IUIAutomationElement *pRootElement = NULL;
    HRESULT hr = pAutomationWrapper->m_pAutomation->GetRootElement(&pRootElement);

    if (FAILED(hr))
    {
    }

    auto elementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pRootElement);

    info.GetReturnValue().Set(elementWrapper);
}

NAN_METHOD(IUIAutomationWrapper::CreatePropertyCondition)
{
    auto isolate = info.GetIsolate();

    auto propertyIdIndex = info[0].As<v8::Int32>()->Value();
    auto propertyId = static_cast<PROPERTYID>(propertyIdIndex);

    IUIAutomationWrapper *pAutomationWrapper = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    auto variant = ToVariant(isolate, info[1]);

    IUIAutomationCondition *pCondition = NULL;

    HRESULT hr = pAutomationWrapper->m_pAutomation->CreatePropertyCondition(propertyId, variant, &pCondition);
    if (FAILED(hr))
    {
    }

    auto condition = IUIAutomationConditionWrapper::NewInstance(info, pCondition);

    info.GetReturnValue().Set(condition);
}

VARIANT IUIAutomationWrapper::ToVariant(v8::Isolate *isolate, v8::Local<v8::Value> local)
{
    auto context = isolate->GetCurrentContext();

    VARIANT variant;

    if (local->IsInt32())
    {
        variant.intVal = local->Int32Value(context).ToChecked();
        variant.vt = VT_INT;
    }
    else if (local->IsString())
    {
        auto value = *v8::String::Utf8Value(isolate, local);

        variant.bstrVal = _com_util::ConvertStringToBSTR(value);
        variant.vt = VT_BSTR;
    }
    else if (local->IsBoolean())
    {
        variant.boolVal = local->ToBoolean(isolate)->Value();
        variant.vt = VT_BOOL;
    }

    return variant;
}
