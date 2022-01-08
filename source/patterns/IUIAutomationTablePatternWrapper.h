#pragma once
#include "../Shared.h"

class IUIAutomationTablePatternWrapper : public Napi::ObjectWrap<IUIAutomationTablePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTablePattern *pTablePattern);

    IUIAutomationTablePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTablePatternWrapper();

    Napi::Value GetCachedRowOrColumnMajor(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentRowOrColumnMajor(const Napi::CallbackInfo &info);

    Napi::Value GetCachedColumnHeaders(const Napi::CallbackInfo &info);
    Napi::Value GetCachedRowHeaders(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentColumnHeaders(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentRowHeaders(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationTablePattern> m_tablePattern;
};
