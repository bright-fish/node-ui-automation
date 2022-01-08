#pragma once
#include "../Shared.h"

class IUIAutomationGridPatternWrapper : public Napi::ObjectWrap<IUIAutomationGridPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationGridPattern *pGridPattern);

    Napi::Value GetCachedColumnCount(const Napi::CallbackInfo &info);
    Napi::Value GetCachedRowCount(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentColumnCount(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentRowCount(const Napi::CallbackInfo &info);

    IUIAutomationGridPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationGridPatternWrapper();

    Napi::Value GetItem(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationGridPattern> m_gridPattern;
};
