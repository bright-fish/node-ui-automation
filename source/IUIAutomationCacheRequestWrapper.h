#pragma once

#include "Shared.h"

class IUIAutomationCacheRequestWrapper : public Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  IUIAutomationCacheRequest *m_pCacheRequest;

  IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info);
  IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info, IUIAutomationCacheRequest *pCacheRequest);
};
