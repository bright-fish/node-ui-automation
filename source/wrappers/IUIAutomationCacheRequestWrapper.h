#pragma once

#include "../Shared.h"

class IUIAutomationCacheRequestWrapper : public Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Object New(Napi::Env env, IUIAutomationCacheRequest *pCacheRequest);

  IUIAutomationCacheRequest *m_pCacheRequest;

  IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info);
  // ~IUIAutomationCacheRequestWrapper();
};
