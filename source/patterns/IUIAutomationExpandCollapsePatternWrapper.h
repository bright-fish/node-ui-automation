#pragma once
#include "../Shared.h"

class IUIAutomationExpandCollapsePatternWrapper : public Napi::ObjectWrap<IUIAutomationExpandCollapsePatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationExpandCollapsePattern *pExpandCollapsePattern);

    IUIAutomationExpandCollapsePatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationExpandCollapsePatternWrapper();

    Napi::Value GetCachedExpandCollapseState(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentExpandCollapseState(const Napi::CallbackInfo &info);

    void Collapse(const Napi::CallbackInfo &info);
    void Expand(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationExpandCollapsePattern> m_expandCollapsePattern;
};
