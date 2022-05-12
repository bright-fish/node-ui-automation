#pragma once
#include "../Shared.h"

class IUIAutomationLegacyIAccessiblePatternWrapper : public Napi::ObjectWrap<IUIAutomationLegacyIAccessiblePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationLegacyIAccessiblePattern *pLegacyIAccessiblePattern);

    Napi::Value GetCachedChildId(const Napi::CallbackInfo &info);
    Napi::Value GetCachedDefaultAction(const Napi::CallbackInfo &info);
    Napi::Value GetCachedDescription(const Napi::CallbackInfo &info);
    Napi::Value GetCachedHelp(const Napi::CallbackInfo &info);
    Napi::Value GetCachedKeyboardShortcut(const Napi::CallbackInfo &info);
    Napi::Value GetCachedName(const Napi::CallbackInfo &info);
    Napi::Value GetCachedRole(const Napi::CallbackInfo &info);
    Napi::Value GetCachedState(const Napi::CallbackInfo &info);
    Napi::Value GetCachedValue(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentChildId(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentDefaultAction(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentDescription(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentHelp(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentKeyboardShortcut(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentName(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentRole(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentState(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentValue(const Napi::CallbackInfo &info);

    IUIAutomationLegacyIAccessiblePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationLegacyIAccessiblePatternWrapper();

    void DoDefaultAction(const Napi::CallbackInfo &info);
    // skipping: value too low for effort
    // Napi::Value GetIAccessible(const Napi::CallbackInfo &info);
    Napi::Value GetCachedSelection(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentSelection(const Napi::CallbackInfo &info);

    void Select(const Napi::CallbackInfo &info);
    void SetValue(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationLegacyIAccessiblePattern> m_legacyIAccessiblePattern = NULL;
};
