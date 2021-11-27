#pragma once

#include "../Shared.h"

class IUnknownWrapper : public Napi::ObjectWrap<IUnknownWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Value New(Napi::Env env, IUnknown *pUnknown);

  IUnknown *m_pIUnknown;

  IUnknownWrapper(const Napi::CallbackInfo &info);
  // ~IUnknownWrapper();
};
