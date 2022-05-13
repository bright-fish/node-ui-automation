#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationValuePatternWrapper : public Napi::ObjectWrap<IUIAutomationValuePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationValuePattern *pValuePattern);

    IUIAutomationValuePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationValuePatternWrapper();

    Napi::Value GetCachedIsReadOnly(const Napi::CallbackInfo &info);
    Napi::Value GetCachedValue(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentIsReadOnly(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentValue(const Napi::CallbackInfo &info);

    void SetValue(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationValuePattern> m_pIValueProvider = NULL;
};
