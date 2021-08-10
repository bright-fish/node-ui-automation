#pragma once

#include "Shared.h"

class IUIAutomationElementWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(v8::Isolate *isolate, IUIAutomationElement *pElement);
  explicit IUIAutomationElementWrapper(IUIAutomationElement *element);

  static void GetProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info);

private:
  IUIAutomationElement *m_pAutomationElement;

  ~IUIAutomationElementWrapper();

  static NAN_METHOD(FindFirst);

  static Nan::Persistent<v8::Function> constructor;
};
