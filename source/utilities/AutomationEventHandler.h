#pragma once

#include "../Shared.h"

class AutomationEventHandler : public IUIAutomationEventHandler
{
private:
    LONG _refCount;
    Napi::ThreadSafeFunction m_threadSafeFunction;

public:
    AutomationEventHandler(Napi::ThreadSafeFunction threadSafeFunction);
    ~AutomationEventHandler();

    ULONG STDMETHODCALLTYPE AddRef();
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
    ULONG STDMETHODCALLTYPE Release();
    HRESULT STDMETHODCALLTYPE HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID);
};
