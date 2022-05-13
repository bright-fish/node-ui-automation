#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationScrollPatternWrapper : public Napi::ObjectWrap<IUIAutomationScrollPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationScrollPattern *pScrollPattern);

    IUIAutomationScrollPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationScrollPatternWrapper();

    Napi::Value GetCachedHorizontallyScrollable(const Napi::CallbackInfo &info);
    Napi::Value GetCachedHorizontalScrollPercent(const Napi::CallbackInfo &info);
    Napi::Value GetCachedHorizontalViewSize(const Napi::CallbackInfo &info);
    Napi::Value GetCachedVerticallyScrollable(const Napi::CallbackInfo &info);
    Napi::Value GetCachedVerticalScrollPercent(const Napi::CallbackInfo &info);
    Napi::Value GetCachedVerticalViewSize(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentHorizontallyScrollable(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentHorizontalScrollPercent(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentHorizontalViewSize(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentVerticallyScrollable(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentVerticalScrollPercent(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentVerticalViewSize(const Napi::CallbackInfo &info);

    void Scroll(const Napi::CallbackInfo &info);
    void SetScrollPercent(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationScrollPattern> m_scrollPattern = NULL;
};
