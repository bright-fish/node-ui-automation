#pragma once

#include "Shared.h"

class IUIAutomationWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);

  static NAN_METHOD(New);
  static NAN_METHOD(GetRootElement);
  static NAN_METHOD(CreatePropertyCondition);
  static NAN_METHOD(CreateCacheRequest);
  static NAN_METHOD(AddAutomationEventHandler);

  static void GetProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info);

private:
  IUIAutomation *m_pAutomation;

  static Nan::Persistent<v8::Function> constructor;

  explicit IUIAutomationWrapper();
  ~IUIAutomationWrapper();

  static VARIANT ToVariant(v8::Isolate* isolate, v8::Local<v8::Value> local);
};
