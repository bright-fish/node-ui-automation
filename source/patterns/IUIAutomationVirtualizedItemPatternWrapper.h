#pragma once
#include "../Shared.h"

class IUIAutomationVirtualizedItemPatternWrapper : public Napi::ObjectWrap<IUIAutomationVirtualizedItemPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationVirtualizedItemPattern *pVirtualizedItemPattern);

    IUIAutomationVirtualizedItemPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationVirtualizedItemPatternWrapper();

    void Realize(const Napi::CallbackInfo &info);
private:
    ATL::CComPtr<IUIAutomationVirtualizedItemPattern> m_virtualizedItemPattern;
};
