#pragma once

#include "Shared.h"

class IUIAutomationEventHandlerWrapper : public IUIAutomationEventHandler
{

private:
  LONG _refCount;
  static Nan::Persistent<v8::Function> constructor;
  Nan::Persistent<v8::Function> callback;


public:
  static NAN_MODULE_INIT(Init);
  static NAN_METHOD(New);

  IUIAutomationEventHandlerWrapper();
  ~IUIAutomationEventHandlerWrapper();
  ULONG STDMETHODCALLTYPE AddRef();
  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
  ULONG STDMETHODCALLTYPE Release();
  HRESULT STDMETHODCALLTYPE HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID);
};
