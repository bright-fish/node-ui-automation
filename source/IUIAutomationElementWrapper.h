#pragma once

#include "Shared.h"

class IUIAutomationElementWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Object> NewInstance(const Nan::FunctionCallbackInfo<v8::Value> &info, IUIAutomationElement *pElement);
  explicit IUIAutomationElementWrapper(IUIAutomationElement *element);

  static void GetName(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value>& info);
  static void GetProcessId(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value>& info);

private:
  IUIAutomationElement *m_pAutomationElement;

  ~IUIAutomationElementWrapper();

  static NAN_METHOD(FindFirst);

  static Nan::Persistent<v8::Function> constructor;
};

// PropertyIds
// EventIds
// AttributeIds
// ControlTypeIds
// AnnotationTypes
// StyleIds
// LandmarkTypeIds
