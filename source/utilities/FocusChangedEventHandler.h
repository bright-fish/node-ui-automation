#pragma once

#include "../Shared.h"

class FocusChangedEventHandler : public IUIAutomationFocusChangedEventHandler
{
private:
    LONG _refCount;
    Napi::ThreadSafeFunction m_threadSafeFunction;

public:
    FocusChangedEventHandler(Napi::ThreadSafeFunction threadSafeFunction);
    ~FocusChangedEventHandler();

    ULONG STDMETHODCALLTYPE AddRef();
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
    ULONG STDMETHODCALLTYPE Release();

    HRESULT STDMETHODCALLTYPE HandleFocusChangedEvent(IUIAutomationElement *pSender);
};
