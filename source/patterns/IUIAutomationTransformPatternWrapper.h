#pragma once
#include "../Shared.h"

class IUIAutomationTransformPatternWrapper : public Napi::ObjectWrap<IUIAutomationTransformPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTransformPattern *pITransformProvider);

    IUIAutomationTransformPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTransformPatternWrapper();

    Napi::Value GetCachedCanMove(const Napi::CallbackInfo &info);
    Napi::Value GetCachedCanResize(const Napi::CallbackInfo &info);
    Napi::Value GetCachedCanRotate(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentCanMove(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCanResize(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCanRotate(const Napi::CallbackInfo &info);

    void Move(const Napi::CallbackInfo &info);
    void Resize(const Napi::CallbackInfo &info);
    void Rotate(const Napi::CallbackInfo &info);
    
private:
    ATL::CComPtr<IUIAutomationTransformPattern> m_tranformPattern = NULL;
};
