#pragma once
#include "../Shared.h"

class IUIAutomationDragPatternWrapper : public Napi::ObjectWrap<IUIAutomationDragPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationDragPattern *pDragPattern);

    IUIAutomationDragPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationDragPatternWrapper();

    Napi::Value GetCachedDropEffects(const Napi::CallbackInfo &info);
    Napi::Value GetCachedDropEffect(const Napi::CallbackInfo &info);
    Napi::Value GetCachedIsGrabbed(const Napi::CallbackInfo &info);
    Napi::Value GetCachedGrabbedItems(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentDropEffects(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentDropEffect(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentIsGrabbed(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentGrabbedItems(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationDragPattern> m_dragPattern;
};
