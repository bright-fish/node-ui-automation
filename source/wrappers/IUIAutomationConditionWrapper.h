#pragma once

#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationConditionWrapper : public Napi::ObjectWrap<IUIAutomationConditionWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Value New(Napi::Env env, IUIAutomationCondition *pCondition);

  ComAutoPointer<IUIAutomationCondition> m_pCondition = NULL;

  IUIAutomationConditionWrapper(const Napi::CallbackInfo &info);
  ~IUIAutomationConditionWrapper();
};
