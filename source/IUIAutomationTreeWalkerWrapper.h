#pragma once

#include "Shared.h"

class IUIAutomationTreeWalkerWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(v8::Isolate *isolate, IUIAutomationTreeWalker *pTreeWalker);

private:
  static Nan::Persistent<v8::Function> constructor;
};
