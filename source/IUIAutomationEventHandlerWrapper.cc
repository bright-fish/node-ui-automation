#include "IUIAutomationEventHandlerWrapper.h"

using Napi::Object;
using Napi::Value;

Napi::Object IUIAutomationEventHandlerWrapper::Init(Napi::Env env, Napi::Object exports)
{
    // todo: Make this class instantiate and require a function as input.
    // store the function.
    // call the function from HandleAutomationEvent below.

    // Napi::Function function = DefineClass(env, "IUIAutomationEventHandler", {});

    // Napi::FunctionReference *constructor = new Napi::FunctionReference();

    // *constructor = Napi::Persistent(function);

    // env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

IUIAutomationEventHandlerWrapper::IUIAutomationEventHandlerWrapper() : _refCount(1)
{
}

IUIAutomationEventHandlerWrapper::~IUIAutomationEventHandlerWrapper()
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
