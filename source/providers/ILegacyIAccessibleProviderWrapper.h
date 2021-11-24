#pragma once
#include "../Shared.h"

class ILegacyIAccessibleProviderWrapper : public Napi::ObjectWrap<ILegacyIAccessibleProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, ILegacyIAccessibleProvider *pILegacyIAccessibleProvider);

    Napi::Value GetChildId(const Napi::CallbackInfo &info);
    Napi::Value GetDefaultAction(const Napi::CallbackInfo &info);
    Napi::Value GetDescription(const Napi::CallbackInfo &info);
    Napi::Value GetHelp(const Napi::CallbackInfo &info);
    Napi::Value GetKeyboardShortcut(const Napi::CallbackInfo &info);
    Napi::Value GetName(const Napi::CallbackInfo &info);
    Napi::Value GetRole(const Napi::CallbackInfo &info);
    Napi::Value GetState(const Napi::CallbackInfo &info);
    Napi::Value GetValue(const Napi::CallbackInfo &info);

    void DoDefaultAction(const Napi::CallbackInfo &info);
    // skipping: value too low for effort
    // Napi::Value GetIAccessible(const Napi::CallbackInfo &info);
    Napi::Value GetSelection(const Napi::CallbackInfo &info);
    void Select(const Napi::CallbackInfo &info);
    void SetValue(const Napi::CallbackInfo &info);

    ILegacyIAccessibleProviderWrapper(const Napi::CallbackInfo &info);
    ~ILegacyIAccessibleProviderWrapper();

private:
    ILegacyIAccessibleProvider *m_pILegacyIAccessibleProvider;
};
