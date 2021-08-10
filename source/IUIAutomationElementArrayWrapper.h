#pragma once

#include "Shared.h"

class IUIAutomationElementArrayWrapper
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(v8::Isolate *isolate, IUIAutomationElementArray *elementArray);
  static NAN_METHOD(GetElement);

private:
  static Nan::Persistent<v8::Function> constructor;
  static IUIAutomationElementArray* m_pElementArray;
};
