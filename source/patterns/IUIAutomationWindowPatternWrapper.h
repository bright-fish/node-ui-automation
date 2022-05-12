#pragma once
#include "../Shared.h"

class IUIAutomationWindowPatternWrapper : public Napi::ObjectWrap<IUIAutomationWindowPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationWindowPattern *pIWindowProvider);

    IUIAutomationWindowPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationWindowPatternWrapper();

    Napi::Value GetCachedCanMaximize(const Napi::CallbackInfo &info);
    Napi::Value GetCachedCanMinimize(const Napi::CallbackInfo &info);
    Napi::Value GetCachedIsModal(const Napi::CallbackInfo &info);
    Napi::Value GetCachedIsTopmost(const Napi::CallbackInfo &info);
    Napi::Value GetCachedWindowInteractionState(const Napi::CallbackInfo &info);
    Napi::Value GetCachedWindowVisualState(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentCanMaximize(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCanMinimize(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentIsModal(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentIsTopmost(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentWindowInteractionState(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentWindowVisualState(const Napi::CallbackInfo &info);

    void Close(const Napi::CallbackInfo &info);
    void SetWindowVisualState(const Napi::CallbackInfo &info);
    Napi::Value WaitForInputIdle(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationWindowPattern> m_windowPattern = NULL;
};
