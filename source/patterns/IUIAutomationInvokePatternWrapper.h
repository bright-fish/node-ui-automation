#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationInvokePatternWrapper : public Napi::ObjectWrap<IUIAutomationInvokePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationInvokePattern *pIInvokeProvider);

    IUIAutomationInvokePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationInvokePatternWrapper();

    void Invoke(const Napi::CallbackInfo &info);
private:
    ComAutoPointer<IUIAutomationInvokePattern> m_invokePattern = NULL;
};
