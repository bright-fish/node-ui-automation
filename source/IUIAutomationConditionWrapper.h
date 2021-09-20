#pragma once

#include "Shared.h"

class IUIAutomationConditionWrapper : public Napi::ObjectWrap<IUIAutomationConditionWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  IUIAutomationCondition *m_pCondition;

  IUIAutomationConditionWrapper(const Napi::CallbackInfo &info);
  IUIAutomationConditionWrapper(const Napi::CallbackInfo &info, IUIAutomationCondition *pCondition);
};
