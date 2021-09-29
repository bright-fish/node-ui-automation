#pragma once

#include "Shared.h"

class RectWrapper : public Napi::ObjectWrap<RectWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Object New(Napi::Env env, RECT *rect);

  RECT m_pRECT;

  RectWrapper(const Napi::CallbackInfo &info);

  Napi::Value RectWrapper::GetBottom(const Napi::CallbackInfo &info);
  Napi::Value RectWrapper::GetLeft(const Napi::CallbackInfo &info);
  Napi::Value RectWrapper::GetRight(const Napi::CallbackInfo &info);
  Napi::Value RectWrapper::GetTop(const Napi::CallbackInfo &info);
};
