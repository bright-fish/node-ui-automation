#pragma once

#include "../Shared.h"

class IUIAutomationWrapper : public Napi::ObjectWrap<IUIAutomationWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Object New(Napi::Env env);

  IUIAutomationWrapper(const Napi::CallbackInfo &info);
  ~IUIAutomationWrapper();

  Napi::Value CreateCacheRequest(const Napi::CallbackInfo &info);
  void AddAutomationEventHandler(const Napi::CallbackInfo &info);
  void AddFocusChangedEventHandler(const Napi::CallbackInfo &info);
  void AddPropertyChangedEventHandler(const Napi::CallbackInfo &info);
  void AddStructureChangedEventHandler(const Napi::CallbackInfo &info);
  Napi::Value CheckNotSupported(const Napi::CallbackInfo &info);
  Napi::Value CompareElements(const Napi::CallbackInfo &info);
  Napi::Value CreateAndCondition(const Napi::CallbackInfo &info);
  Napi::Value CreateFalseCondition(const Napi::CallbackInfo &info);
  Napi::Value CreateNotCondition(const Napi::CallbackInfo &info);
  Napi::Value CreateOrCondition(const Napi::CallbackInfo &info);
  Napi::Value CreatePropertyCondition(const Napi::CallbackInfo &info);
  Napi::Value CreateTreeWalker(const Napi::CallbackInfo &info);
  Napi::Value CreateTrueCondition(const Napi::CallbackInfo &info);
  Napi::Value ElementFromPoint(const Napi::CallbackInfo &info);
  Napi::Value ElementFromPointBuildCache(const Napi::CallbackInfo &info);
  Napi::Value GetFocusedElement(const Napi::CallbackInfo &info);
  Napi::Value GetFocusedElementBuildCache(const Napi::CallbackInfo &info);
  Napi::Value GetPatternProgrammaticName(const Napi::CallbackInfo &info);
  Napi::Value GetPropertyProgrammaticName(const Napi::CallbackInfo &info);
  Napi::Value GetRootElement(const Napi::CallbackInfo &info);
  Napi::Value GetRootElementBuildCache(const Napi::CallbackInfo &info);
  void RemoveAllEventHandlers(const Napi::CallbackInfo &info);
  void RemoveAutomationEventHandler(const Napi::CallbackInfo &info);
  void RemoveFocusChangedEventHandler(const Napi::CallbackInfo &info);
  void RemovePropertyChangedEventHandler(const Napi::CallbackInfo &info);
  void RemoveStructureChangedEventHandler(const Napi::CallbackInfo &info);

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
};