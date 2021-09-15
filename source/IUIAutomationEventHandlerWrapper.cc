#include "IUIAutomationEventHandlerWrapper.h"

using v8::Local;
using v8::Object;
using v8::Value;

Nan::Persistent<v8::Function> IUIAutomationEventHandlerWrapper::constructor;

NAN_MODULE_INIT(IUIAutomationEventHandlerWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("IUIAutomationEventHandler").ToLocalChecked());
    functionTemplate->InstanceTemplate()->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

NAN_METHOD(IUIAutomationEventHandlerWrapper::New)
{
    if (info.IsConstructCall())
    {
        IUIAutomationEventHandlerWrapper *eventHandlerWrapper = new IUIAutomationEventHandlerWrapper();

        info.GetReturnValue().Set(info.This());
    }
    else
    {
        v8::Local<v8::Function> cons = Nan::New(constructor);
        info.GetReturnValue().Set(Nan::NewInstance(cons).ToLocalChecked());
    }
}

IUIAutomationEventHandlerWrapper::IUIAutomationEventHandlerWrapper() : _refCount(1)
{
}

ULONG STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::Release()
{
    ULONG output = InterlockedDecrement(&_refCount);
    if (output == 0)
    {
        delete this;
        return 0;
    }
    return output;
}

HRESULT STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::QueryInterface(REFIID riid, void **ppInterface)
{
    if (riid == __uuidof(IUnknown))
        *ppInterface = static_cast<IUIAutomationEventHandler *>(this);
    else if (riid == __uuidof(IUIAutomationEventHandler))
        *ppInterface = static_cast<IUIAutomationEventHandler *>(this);
    else
    {
        *ppInterface = NULL;
        return E_NOINTERFACE;
    }

    this->AddRef();

    return S_OK;
}

HRESULT STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID)
{
    // todo: get the callback from javascript.  
    // then call the callback.  
    // what about the case where you dont want to return S_OK?  
    

    return S_OK;
}
