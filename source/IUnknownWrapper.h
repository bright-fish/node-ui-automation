#pragma once

#include "Shared.h"

class IUnknownWrapper
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Object> NewInstance(v8::Isolate *pIsolate, IUnknown *pIUnknown);

private:
  static Nan::Persistent<v8::Function> constructor;
};
