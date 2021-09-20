#pragma once

#include "Shared.h"

class RectWrapper : public Napi::ObjectWrap<RectWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  RECT m_pRECT;

  RectWrapper(const Napi::CallbackInfo &info);
  RectWrapper(const Napi::CallbackInfo &info, RECT *pRECT);

  Napi::Value RectWrapper::GetBottom(const Napi::CallbackInfo &info);
  Napi::Value RectWrapper::GetLeft(const Napi::CallbackInfo &info);
  Napi::Value RectWrapper::GetRight(const Napi::CallbackInfo &info);
  Napi::Value RectWrapper::GetTop(const Napi::CallbackInfo &info);
};
