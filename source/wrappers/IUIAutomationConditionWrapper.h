#pragma once

#include "../Shared.h"

class IUIAutomationConditionWrapper : public Napi::ObjectWrap<IUIAutomationConditionWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Object New(Napi::Env env, IUIAutomationCondition *pCondition);

  ATL::CComPtr<IUIAutomationCondition> m_pCondition;

  IUIAutomationConditionWrapper(const Napi::CallbackInfo &info);
  // ~IUIAutomationConditionWrapper();
};
