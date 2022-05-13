#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationDropTargetPatternWrapper : public Napi::ObjectWrap<IUIAutomationDropTargetPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationDropTargetPattern *pDropTargetPattern);

    IUIAutomationDropTargetPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationDropTargetPatternWrapper();

    Napi::Value GetCachedDropTargetEffects(const Napi::CallbackInfo &info);
    Napi::Value GetCachedDropTargetEffect(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentDropTargetEffects(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentDropTargetEffect(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationDropTargetPattern> m_dropTargetPattern = NULL;
};
