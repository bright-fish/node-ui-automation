#pragma once
#include "../Shared.h"

class IUIAutomationInvokePatternWrapper : public Napi::ObjectWrap<IUIAutomationInvokePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationInvokePattern *pIInvokeProvider);

    IUIAutomationInvokePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationInvokePatternWrapper();

    void Invoke(const Napi::CallbackInfo &info);
private:
    ATL::CComPtr<IUIAutomationInvokePattern> m_invokePattern = NULL;
};
