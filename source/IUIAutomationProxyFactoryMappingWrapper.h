#pragma once

#include "Shared.h"

class IUIAutomationProxyFactoryMappingWrapper
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Object> NewInstance(v8::Isolate *isolate, IUIAutomationProxyFactoryMapping *pProxyFactoryMapping);

private:
  static Nan::Persistent<v8::Function> constructor;
};
