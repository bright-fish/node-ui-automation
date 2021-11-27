#pragma once

#include "../Shared.h"

class IUIAutomationProxyFactoryMappingWrapper : public Napi::ObjectWrap<IUIAutomationProxyFactoryMappingWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Value New(Napi::Env env, IUIAutomationProxyFactoryMapping *pProxyFactoryMapping);

  IUIAutomationProxyFactoryMapping *m_pProxyFactoryMapping;

  IUIAutomationProxyFactoryMappingWrapper(const Napi::CallbackInfo &info);
  ~IUIAutomationProxyFactoryMappingWrapper();
};
