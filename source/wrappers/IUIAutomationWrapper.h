#pragma once

#include "../Shared.h"

class IUIAutomationWrapper : public Napi::ObjectWrap<IUIAutomationWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Object New(Napi::Env env);

  IUIAutomationWrapper(const Napi::CallbackInfo &info);
  ~IUIAutomationWrapper();

  Napi::Value GetRootElement(const Napi::CallbackInfo &info);
  Napi::Value CreatePropertyCondition(const Napi::CallbackInfo &info);
  Napi::Value CreateCacheRequest(const Napi::CallbackInfo &info);
  void AddAutomationEventHandler(const Napi::CallbackInfo &info);
  void AddFocusChangedEventHandler(const Napi::CallbackInfo &info);
  void AddPropertyChangedEventHandler(const Napi::CallbackInfo &info);
  void AddStructureChangedEventHandler(const Napi::CallbackInfo &info);

  Napi::Value GetRawViewWalker(const Napi::CallbackInfo &info);
  Napi::Value GetRawViewCondition(const Napi::CallbackInfo &info);
  Napi::Value GetContentViewWalker(const Napi::CallbackInfo &info);
  Napi::Value GetContentViewCondition(const Napi::CallbackInfo &info);
  Napi::Value GetControlViewWalker(const Napi::CallbackInfo &info);
  Napi::Value GetControlViewCondition(const Napi::CallbackInfo &info);
  Napi::Value GetProxyFactoryMapping(const Napi::CallbackInfo &info);
  Napi::Value GetReservedMixedAttributeValue(const Napi::CallbackInfo &info);
  Napi::Value GetReservedNotSupportedValue(const Napi::CallbackInfo &info);

private:
  ATL::CComPtr<IUIAutomation> m_pAutomation;

  VARIANT ToVariant(Napi::Value local);
};
