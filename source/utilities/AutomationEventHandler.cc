#include "AutomationEventHandler.h"
#include "AutomationEvent.h"
#include "../Library.h"

AutomationEventHandler::AutomationEventHandler(Napi::ThreadSafeFunction threadSafeFunction) : _refCount(1)
{
    m_threadSafeFunction = threadSafeFunction;
}

AutomationEventHandler::~AutomationEventHandler()
{
}

ULONG STDMETHODCALLTYPE AutomationEventHandler::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG STDMETHODCALLTYPE AutomationEventHandler::Release()
{
    ULONG output = InterlockedDecrement(&_refCount);

    if (output == 0)
    {
        delete this;
        return 0;
    }

    return output;
}

HRESULT STDMETHODCALLTYPE AutomationEventHandler::QueryInterface(REFIID riid, void **ppInterface)
{
    if (riid == __uuidof(IUnknown))
    {
        *ppInterface = static_cast<IUIAutomationEventHandler *>(this);
    }
    else if (riid == __uuidof(IUIAutomationEventHandler))
    {
        *ppInterface = static_cast<IUIAutomationEventHandler *>(this);
    }
    else
    {
        *ppInterface = NULL;
        return E_NOINTERFACE;
    }

    this->AddRef();

    return S_OK;
}

HRESULT STDMETHODCALLTYPE AutomationEventHandler::HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID)
{
    pSender->AddRef();

    AutomationEvent *automationEvent = new AutomationEvent();
    automationEvent->pSender = pSender;
    automationEvent->eventID = eventID;

    auto internalCallback = [](Napi::Env env, Napi::Function function, AutomationEvent *event)
    {
        function.Call({
            IUIAutomationElementWrapper::New(env, event->pSender),
            Napi::Number::New(env, event->eventID),
        });

        delete event;
    };

    auto status = m_threadSafeFunction.BlockingCall(automationEvent, internalCallback);

    return S_OK;
}

