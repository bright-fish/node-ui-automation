#pragma once

#include "Shared.h"

class IUIAutomationCacheRequestWrapper
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(v8::Isolate *isolate, IUIAutomationCacheRequest *pCacheRequest);

private:
  static Nan::Persistent<v8::Function> constructor;
};
