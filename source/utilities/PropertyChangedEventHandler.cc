#include "PropertyChangedEventHandler.h"
#include "../Shared.h"
#include "PropertyChangedEvent.h"
#include "../wrappers/IUIAutomationElementWrapper.h"
#include "../utilities/Functions.h"

PropertyChangedEventHandler::PropertyChangedEventHandler(Napi::ThreadSafeFunction threadSafeFunction)
{
    m_threadSafeFunction = threadSafeFunction;
}

PropertyChangedEventHandler::~PropertyChangedEventHandler()
{
    m_threadSafeFunction.Release();
}

ULONG STDMETHODCALLTYPE PropertyChangedEventHandler::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG STDMETHODCALLTYPE PropertyChangedEventHandler::Release()
{
    ULONG output = InterlockedDecrement(&_refCount);

    if (output == 0)
    {
        delete this;
        return 0;
    }

    return output;
}

HRESULT STDMETHODCALLTYPE PropertyChangedEventHandler::QueryInterface(REFIID riid, void **ppInterface)
{
    if (riid == __uuidof(IUnknown))
    {
        *ppInterface = static_cast<IUIAutomationPropertyChangedEventHandler *>(this);
    }
    else if (riid == __uuidof(IUIAutomationPropertyChangedEventHandler))
    {
        *ppInterface = static_cast<IUIAutomationPropertyChangedEventHandler *>(this);
    }
    else
    {
        *ppInterface = NULL;
        return E_NOINTERFACE;
    }

    this->AddRef();

    return S_OK;
}

HRESULT PropertyChangedEventHandler::HandlePropertyChangedEvent(IUIAutomationElement *sender, PROPERTYID propertyId, VARIANT newValue)
{
    sender->AddRef();

    auto *automationEvent = new PropertyChangedEvent();
    automationEvent->pSender = sender;
    automationEvent->propertyId = propertyId;
    automationEvent->newValue = newValue;

    auto internalCallback = [](Napi::Env env, Napi::Function function, PropertyChangedEvent *event)
    {
        function.Call({
            IUIAutomationElementWrapper::New(env, event->pSender),
            Napi::Number::New(env, event->propertyId),
            FromVariant(env, event->newValue)
        });

        delete event;
    };

    auto status = m_threadSafeFunction.BlockingCall(automationEvent, internalCallback);

    return S_OK;
}
