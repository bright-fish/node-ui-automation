#pragma once

#include "Shared.h"

class IUIAutomationProxyFactoryMappingWrapper : public Napi::ObjectWrap<IUIAutomationProxyFactoryMappingWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  IUIAutomationProxyFactoryMapping *m_pProxyFactoryMapping;

  IUIAutomationProxyFactoryMappingWrapper(const Napi::CallbackInfo &info);
  IUIAutomationProxyFactoryMappingWrapper(const Napi::CallbackInfo &info, IUIAutomationProxyFactoryMapping *pProxyFactoryMapping);
};
