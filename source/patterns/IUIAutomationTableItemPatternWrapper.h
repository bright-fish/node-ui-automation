#pragma once
#include "../Shared.h"

class IUIAutomationTableItemPatternWrapper : public Napi::ObjectWrap<IUIAutomationTableItemPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTableItemPattern *pTableItemPattern);

    IUIAutomationTableItemPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTableItemPatternWrapper();

    Napi::Value GetCachedColumnHeaderItems(const Napi::CallbackInfo &info);
    Napi::Value GetCachedRowHeaderItems(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentColumnHeaderItems(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentRowHeaderItems(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationTableItemPattern> m_tableItemPattern = NULL;
};
