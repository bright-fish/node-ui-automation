#pragma once
#include "../Shared.h"

class IUIAutomationSelectionPatternWrapper : public Napi::ObjectWrap<IUIAutomationSelectionPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationSelectionPattern *pSelectionPattern);

    IUIAutomationSelectionPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationSelectionPatternWrapper();

    Napi::Value GetCachedCanSelectMultiple(const Napi::CallbackInfo &info);
    Napi::Value GetCachedIsSelectionRequired(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCanSelectMultiple(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentIsSelectionRequired(const Napi::CallbackInfo &info);

    Napi::Value GetCachedSelection(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentSelection(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationSelectionPattern> m_selectionPattern;
};
