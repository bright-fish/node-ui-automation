#pragma once

#include "../Shared.h"

class IUIAutomationCacheRequestWrapper : public Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Value New(Napi::Env env, IUIAutomationCacheRequest *pCacheRequest);

  ATL::CComPtr<IUIAutomationCacheRequest> m_pCacheRequest = NULL;

  IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info);
  ~IUIAutomationCacheRequestWrapper();

  void AddPattern(const Napi::CallbackInfo &info);
  void AddProperty(const Napi::CallbackInfo &info);
  Napi::Value Clone(const Napi::CallbackInfo &info);

  Napi::Value GetAutomationElementMode(const Napi::CallbackInfo &info);
  void PutAutomationElementMode(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value GetTreeFilter(const Napi::CallbackInfo &info);
  void PutTreeFilter(const Napi::CallbackInfo &info, const Napi::Value &value);

  Napi::Value GetTreeScope(const Napi::CallbackInfo &info);
  void PutTreeScope(const Napi::CallbackInfo &info, const Napi::Value &value);
};
