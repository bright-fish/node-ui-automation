#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

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
    ComAutoPointer<IUIAutomationExpandCollapsePattern> m_expandCollapsePattern = NULL;
};
