#pragma once

#include "Shared.h"

class IUIAutomationTreeWalkerWrapper : public Napi::ObjectWrap<IUIAutomationTreeWalkerWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  IUIAutomationTreeWalker *m_pTreeWalker;

  IUIAutomationTreeWalkerWrapper(const Napi::CallbackInfo &info);
  IUIAutomationTreeWalkerWrapper(const Napi::CallbackInfo &info, IUIAutomationTreeWalker *pTreeWalker);

  void GetProperty(Napi::String property, const Napi::CallbackInfo &info);

  Napi::Value GetFirstChildElement(const Napi::CallbackInfo &info);
  Napi::Value GetFirstChildElementBuildCache(const Napi::CallbackInfo &info);
  Napi::Value GetLastChildElement(const Napi::CallbackInfo &info);
  Napi::Value GetLastChildElementBuildCache(const Napi::CallbackInfo &info);
  Napi::Value GetNextSiblingElement(const Napi::CallbackInfo &info);
  Napi::Value GetNextSiblingElementBuildCache(const Napi::CallbackInfo &info);
  Napi::Value GetParentElement(const Napi::CallbackInfo &info);
  Napi::Value GetParentElementBuildCache(const Napi::CallbackInfo &info);
  Napi::Value GetPreviousSiblingElement(const Napi::CallbackInfo &info);
  Napi::Value GetPreviousSiblingElementBuildCache(const Napi::CallbackInfo &info);
  Napi::Value NormalizeElement(const Napi::CallbackInfo &info);
  Napi::Value NormalizeElementBuildCache(const Napi::CallbackInfo &info);

private:
  static Napi::FunctionReference constructor;
};
