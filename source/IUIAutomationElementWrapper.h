#pragma once

#include "Shared.h"

class IUIAutomationElementWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(v8::Isolate *isolate, IUIAutomationElement *pElement);

  static void GetCurrentProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info);
  static void GetCachedProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info);

private:
  static Nan::Persistent<v8::Function> constructor;

  static NAN_METHOD(FindFirst);
};
