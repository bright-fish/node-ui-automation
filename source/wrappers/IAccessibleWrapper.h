#pragma once

#include "../Shared.h"

class IAccessibleWrapper : public Napi::ObjectWrap<IAccessibleWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Value New(Napi::Env env, IAccessible *pIAccessible);

  IAccessible *m_pIAccessible;

  IAccessibleWrapper(const Napi::CallbackInfo &info);
  ~IAccessibleWrapper();
};
