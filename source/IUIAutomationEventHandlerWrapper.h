#pragma once

#include "Shared.h"

class IUIAutomationEventHandlerWrapper : public IUIAutomationEventHandler
{

private:
  LONG _refCount;
  Napi::FunctionReference callback;

public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  IUIAutomationEventHandlerWrapper();
  ~IUIAutomationEventHandlerWrapper();
  ULONG STDMETHODCALLTYPE AddRef();
  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
  ULONG STDMETHODCALLTYPE Release();
  HRESULT STDMETHODCALLTYPE HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID);
};
