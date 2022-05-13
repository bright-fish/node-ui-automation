#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationVirtualizedItemPatternWrapper : public Napi::ObjectWrap<IUIAutomationVirtualizedItemPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationVirtualizedItemPattern *pVirtualizedItemPattern);

    IUIAutomationVirtualizedItemPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationVirtualizedItemPatternWrapper();

    void Realize(const Napi::CallbackInfo &info);
private:
    ComAutoPointer<IUIAutomationVirtualizedItemPattern> m_virtualizedItemPattern = NULL;
};
