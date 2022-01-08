#pragma once
#include "../Shared.h"

class IUIAutomationScrollItemPatternWrapper : public Napi::ObjectWrap<IUIAutomationScrollItemPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationScrollItemPattern *pScrollItemPattern);

    IUIAutomationScrollItemPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationScrollItemPatternWrapper();

    void ScrollIntoView(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IScrollItemProvider> m_pIScrollItemProvider;
};
