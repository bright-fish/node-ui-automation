#include "FocusChangedEventHandler.h"
#include "../wrappers/IUIAutomationElementWrapper.h"

FocusChangedEventHandler::FocusChangedEventHandler(Napi::ThreadSafeFunction threadSafeFunction) : _refCount(1)
{
    m_threadSafeFunction = threadSafeFunction;
}

FocusChangedEventHandler::~FocusChangedEventHandler()
{
}

ULONG STDMETHODCALLTYPE FocusChangedEventHandler::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG STDMETHODCALLTYPE FocusChangedEventHandler::Release()
{
    ULONG output = InterlockedDecrement(&_refCount);

    if (output == 0)
    {
        delete this;
        return 0;
    }

    return output;
}

HRESULT STDMETHODCALLTYPE FocusChangedEventHandler::QueryInterface(REFIID riid, void **ppInterface)
{
    if (riid == __uuidof(IUnknown))
    {
        *ppInterface = static_cast<IUIAutomationFocusChangedEventHandler *>(this);
    }
    else if (riid == __uuidof(IUIAutomationFocusChangedEventHandler))
    {
        *ppInterface = static_cast<IUIAutomationFocusChangedEventHandler *>(this);
    }
    else
    {
        *ppInterface = NULL;
        return E_NOINTERFACE;
    }

    this->AddRef();

    return S_OK;
}

HRESULT STDMETHODCALLTYPE FocusChangedEventHandler::HandleFocusChangedEvent(IUIAutomationElement *pSender)
{
    pSender->AddRef();
    
    auto internalCallback = [](Napi::Env env, Napi::Function function, IUIAutomationElement *pElement)
    {
        function.Call({
            IUIAutomationElementWrapper::New(env, pElement),
        });
    };

    auto status = m_threadSafeFunction.BlockingCall(pSender, internalCallback);

    return S_OK;
}