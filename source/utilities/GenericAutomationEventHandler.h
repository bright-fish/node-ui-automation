#pragma once

#include "../Shared.h"

class GenericAutomationEventHandler : public IUIAutomationEventHandler
{
private:
    LONG _refCount;
    std::function<void(IUIAutomationElement *, EVENTID)> m_fCallback;

public:
    GenericAutomationEventHandler();
    ~GenericAutomationEventHandler();

    ULONG STDMETHODCALLTYPE AddRef();
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
    ULONG STDMETHODCALLTYPE Release();
    HRESULT STDMETHODCALLTYPE HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID);

    void SetCallback(std::function<void(IUIAutomationElement *, EVENTID)> fCallback);
};
