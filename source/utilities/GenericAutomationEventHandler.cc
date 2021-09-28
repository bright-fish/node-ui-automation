#include "GenericAutomationEventHandler.h"

GenericAutomationEventHandler::GenericAutomationEventHandler() : _refCount(1)
{
}

GenericAutomationEventHandler::~GenericAutomationEventHandler()
{
}

ULONG STDMETHODCALLTYPE GenericAutomationEventHandler::AddRef()
{
    return InterlockedIncrement(&_refCount);
}

ULONG STDMETHODCALLTYPE GenericAutomationEventHandler::Release()
{
    ULONG output = InterlockedDecrement(&_refCount);

    if (output == 0)
    {
        delete this;
        return 0;
    }

    return output;
}

HRESULT STDMETHODCALLTYPE GenericAutomationEventHandler::QueryInterface(REFIID riid, void **ppInterface)
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

HRESULT STDMETHODCALLTYPE GenericAutomationEventHandler::HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID)
{
    m_fCallback(pSender, eventID);

    return S_OK;
}

void GenericAutomationEventHandler::SetCallback(std::function<void(IUIAutomationElement *, EVENTID)> fCallback)
{
    m_fCallback = fCallback;
}
