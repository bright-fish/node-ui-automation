#pragma once
#include "../Shared.h"

class IUIAutomationMultipleViewPatternWrapper : public Napi::ObjectWrap<IUIAutomationMultipleViewPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationMultipleViewPattern *pMutlipleViewPattern);

    IUIAutomationMultipleViewPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationMultipleViewPatternWrapper();

    Napi::Value GetCachedCurrentView(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCurrentView(const Napi::CallbackInfo &info);

    Napi::Value GetCachedSupportedViews(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentSupportedViews(const Napi::CallbackInfo &info);

    Napi::Value GetViewName(const Napi::CallbackInfo &info);
    void SetCurrentView(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationMultipleViewPattern> m_multipleViewPattern = NULL;
};
