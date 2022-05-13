#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationRangeValuePatternWrapper : public Napi::ObjectWrap<IUIAutomationRangeValuePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationRangeValuePattern *pRangeValuePattern);

    IUIAutomationRangeValuePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationRangeValuePatternWrapper();

    Napi::Value GetCachedIsReadOnly(const Napi::CallbackInfo &info);
    Napi::Value GetCachedLargeChange(const Napi::CallbackInfo &info);
    Napi::Value GetCachedMaximum(const Napi::CallbackInfo &info);
    Napi::Value GetCachedMinimum(const Napi::CallbackInfo &info);
    Napi::Value GetCachedSmallChange(const Napi::CallbackInfo &info);
    Napi::Value GetCachedValue(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentIsReadOnly(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentLargeChange(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentMaximum(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentMinimum(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentSmallChange(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentValue(const Napi::CallbackInfo &info);

    void SetValue(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationRangeValuePattern> m_rangeValuePattern = NULL;
};
