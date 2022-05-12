#pragma once
#include "../Shared.h"

class IUIAutomationGridItemPatternWrapper : public Napi::ObjectWrap<IUIAutomationGridItemPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationGridItemPattern *pGridItemPattern);

    Napi::Value GetCachedColumn(const Napi::CallbackInfo &info);
    Napi::Value GetCachedColumnSpan(const Napi::CallbackInfo &info);
    Napi::Value GetCachedContainingGrid(const Napi::CallbackInfo &info);
    Napi::Value GetCachedRow(const Napi::CallbackInfo &info);
    Napi::Value GetCachedRowSpan(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentColumn(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentColumnSpan(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentContainingGrid(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentRow(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentRowSpan(const Napi::CallbackInfo &info);

    IUIAutomationGridItemPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationGridItemPatternWrapper();

private:
    ATL::CComPtr<IUIAutomationGridItemPattern> m_gridItemPattern = NULL;
};
