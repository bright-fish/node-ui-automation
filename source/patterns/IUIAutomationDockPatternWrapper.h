#pragma once
#include "../Shared.h"

class IUIAutomationDockPatternWrapper : public Napi::ObjectWrap<IUIAutomationDockPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationDockPattern *pIDockProvider);

    IUIAutomationDockPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationDockPatternWrapper();

    Napi::Value GetCachedDockPosition(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentDockPosition(const Napi::CallbackInfo &info);

    void SetDockPosition(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationDockPattern> m_dockPattern = NULL;
};
