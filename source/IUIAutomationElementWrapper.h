#pragma once

#include "Shared.h"

class IUIAutomationElementWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
  static void NewInstance(const Nan::FunctionCallbackInfo<v8::Value>& info, IUIAutomationElement* pElement);
  explicit IUIAutomationElementWrapper(IUIAutomationElement *element);

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
