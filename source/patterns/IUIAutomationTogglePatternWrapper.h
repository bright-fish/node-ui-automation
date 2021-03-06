#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationTogglePatternWrapper : public Napi::ObjectWrap<IUIAutomationTogglePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTogglePattern *pTogglePattern);

    IUIAutomationTogglePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTogglePatternWrapper();

    Napi::Value GetCachedToggleState(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentToggleState(const Napi::CallbackInfo &info);

    void Toggle(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationTogglePattern> m_togglePattern = NULL;
};
