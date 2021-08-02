#pragma once

#include "Shared.h"

class IUIAutomationConditionWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Object> NewInstance(const Nan::FunctionCallbackInfo<v8::Value>& info, IUIAutomationCondition* pCondition);

private:
  IUIAutomationCondition *m_pAutomationCondition;

  explicit IUIAutomationConditionWrapper();
  ~IUIAutomationConditionWrapper();

  static Nan::Persistent<v8::Function> constructor;
};
