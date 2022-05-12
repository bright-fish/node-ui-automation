#include "StructureChangedEventHandler.h"
#include "../Shared.h"
#include "PropertyChangedEvent.h"
#include "../wrappers/IUIAutomationElementWrapper.h"

StructureChangedEventHandler::StructureChangedEventHandler(Napi::ThreadSafeFunction threadSafeFunction)
{
    m_threadSafeFunction = threadSafeFunction;
}

StructureChangedEventHandler::~StructureChangedEventHandler()
{
    m_threadSafeFunction.Release();
}

ULONG STDMETHODCALLTYPE StructureChangedEventHandler::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG STDMETHODCALLTYPE StructureChangedEventHandler::Release()
{
    ULONG output = InterlockedDecrement(&_refCount);

    if (output == 0)
    {
        delete this;
        return 0;
    }

    return output;
}

HRESULT STDMETHODCALLTYPE StructureChangedEventHandler::QueryInterface(REFIID riid, void **ppInterface)
{
    if (riid == __uuidof(IUnknown))
    {
        *ppInterface = static_cast<IUIAutomationStructureChangedEventHandler *>(this);
    }
    else if (riid == __uuidof(IUIAutomationStructureChangedEventHandler))
    {
        *ppInterface = static_cast<IUIAutomationStructureChangedEventHandler *>(this);
    }
    else
    {
        *ppInterface = NULL;
        return E_NOINTERFACE;
    }

    this->AddRef();

    return S_OK;
}

struct StructureChangedEvent
{
    ATL::CComPtr<IUIAutomationElement> m_pSender = NULL;
    StructureChangeType m_eChangeType;
    SAFEARRAY *m_pRuntimeId;
};

HRESULT STDMETHODCALLTYPE StructureChangedEventHandler::HandleStructureChangedEvent(IUIAutomationElement *pSender, StructureChangeType eChangeType, SAFEARRAY *pRuntimeId)
{
    auto *automationEvent = new StructureChangedEvent();
    automationEvent->m_pSender = pSender;
    automationEvent->m_eChangeType = eChangeType;
    automationEvent->m_pRuntimeId = pRuntimeId;

    auto internalCallback = [](Napi::Env env, Napi::Function function, StructureChangedEvent *event)
    {
        function.Call({
            IUIAutomationElementWrapper::New(env, event->m_pSender),
            Napi::Number::New(env, event->m_eChangeType),
            // todo: event->m_pRuntimeId
        });

        delete event;
    };

    auto status = m_threadSafeFunction.BlockingCall(automationEvent, internalCallback);

    return S_OK;
}
