#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationSynchronizedInputPatternWrapper : public Napi::ObjectWrap<IUIAutomationSynchronizedInputPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationSynchronizedInputPattern *pSynchronizedInputPattern);

    IUIAutomationSynchronizedInputPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationSynchronizedInputPatternWrapper();

    void Cancel(const Napi::CallbackInfo &info);
    void StartListening(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationSynchronizedInputPattern> m_synchronizedInputPattern = NULL;
};
