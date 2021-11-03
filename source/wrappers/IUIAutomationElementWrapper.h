#pragma once

#include "../Shared.h"

class IUIAutomationElementWrapper : public Napi::ObjectWrap<IUIAutomationElementWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Object New(Napi::Env env, IUIAutomationElement *pElement);

  ATL::CComPtr<IUIAutomationElement> m_pElement;

  IUIAutomationElementWrapper(const Napi::CallbackInfo &info);
  ~IUIAutomationElementWrapper();

  Napi::Value BuildUpdatedCache(const Napi::CallbackInfo &info);
  Napi::Value FindAll(const Napi::CallbackInfo &info);
  Napi::Value FindAllBuildCache(const Napi::CallbackInfo &info);
  Napi::Value FindFirst(const Napi::CallbackInfo &info);
  Napi::Value FindFirstBuildCache(const Napi::CallbackInfo &info);
  Napi::Value GetCachedChildren(const Napi::CallbackInfo &info);
  Napi::Value GetCachedParent(const Napi::CallbackInfo &info);
  Napi::Value GetCachedPropertyValue(const Napi::CallbackInfo &info);
  Napi::Value GetCachedPropertyValueEx(const Napi::CallbackInfo &info);
  Napi::Value GetClickablePoint(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentPropertyValue(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentPropertyValueEx(const Napi::CallbackInfo &info);
  void SetFocus(const Napi::CallbackInfo &info);

  Napi::Value GetCurrentName(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentAcceleratorKey(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentAccessKey(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentAriaProperties(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentAriaRole(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentAutomationId(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentBoundingRectangle(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentClassName(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentControllerFor(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentControlType(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentCulture(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentDescribedBy(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentFlowsTo(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentFrameworkId(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentHasKeyboardFocus(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentHelpText(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsContentElement(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsControlElement(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsDataValidForForm(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsEnabled(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsKeyboardFocusable(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsOffscreen(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsPassword(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentIsRequiredForForm(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentItemStatus(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentItemType(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentLabeledBy(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentLocalizedControlType(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentNativeWindowHandle(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentOrientation(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentProcessId(const Napi::CallbackInfo &info);
  Napi::Value GetCurrentProviderDescription(const Napi::CallbackInfo &info);

  Napi::Value GetCachedName(const Napi::CallbackInfo &info);
  Napi::Value GetCachedAcceleratorKey(const Napi::CallbackInfo &info);
  Napi::Value GetCachedAccessKey(const Napi::CallbackInfo &info);
  Napi::Value GetCachedAriaProperties(const Napi::CallbackInfo &info);
  Napi::Value GetCachedAriaRole(const Napi::CallbackInfo &info);
  Napi::Value GetCachedAutomationId(const Napi::CallbackInfo &info);
  Napi::Value GetCachedBoundingRectangle(const Napi::CallbackInfo &info);
  Napi::Value GetCachedClassName(const Napi::CallbackInfo &info);
  Napi::Value GetCachedControllerFor(const Napi::CallbackInfo &info);
  Napi::Value GetCachedControlType(const Napi::CallbackInfo &info);
  Napi::Value GetCachedCulture(const Napi::CallbackInfo &info);
  Napi::Value GetCachedDescribedBy(const Napi::CallbackInfo &info);
  Napi::Value GetCachedFlowsTo(const Napi::CallbackInfo &info);
  Napi::Value GetCachedFrameworkId(const Napi::CallbackInfo &info);
  Napi::Value GetCachedHasKeyboardFocus(const Napi::CallbackInfo &info);
  Napi::Value GetCachedHelpText(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsContentElement(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsControlElement(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsDataValidForForm(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsEnabled(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsKeyboardFocusable(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsOffscreen(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsPassword(const Napi::CallbackInfo &info);
  Napi::Value GetCachedIsRequiredForForm(const Napi::CallbackInfo &info);
  Napi::Value GetCachedItemStatus(const Napi::CallbackInfo &info);
  Napi::Value GetCachedItemType(const Napi::CallbackInfo &info);
  Napi::Value GetCachedLabeledBy(const Napi::CallbackInfo &info);
  Napi::Value GetCachedLocalizedControlType(const Napi::CallbackInfo &info);
  Napi::Value GetCachedNativeWindowHandle(const Napi::CallbackInfo &info);
  Napi::Value GetCachedOrientation(const Napi::CallbackInfo &info);
  Napi::Value GetCachedProcessId(const Napi::CallbackInfo &info);
  Napi::Value GetCachedProviderDescription(const Napi::CallbackInfo &info);
};
