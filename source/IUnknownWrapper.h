#pragma once

#include "Shared.h"

class IUnknownWrapper : public Napi::ObjectWrap<IUnknownWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
  
  IUnknown* m_pIUnknown;
  IUnknownWrapper(const Napi::CallbackInfo &info);
  IUnknownWrapper(const Napi::CallbackInfo &info, IUnknown * pIUnknown);

private:
};
