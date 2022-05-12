#pragma once
#include "../Shared.h"

class IUIAutomationTransformPattern2Wrapper : public Napi::ObjectWrap<IUIAutomationTransformPattern2Wrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTransformPattern2 *pITransformProvider2);

    IUIAutomationTransformPattern2Wrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTransformPattern2Wrapper();

    Napi::Value GetCachedCanMove(const Napi::CallbackInfo &info);
    Napi::Value GetCachedCanResize(const Napi::CallbackInfo &info);
    Napi::Value GetCachedCanRotate(const Napi::CallbackInfo &info);
    Napi::Value GetCachedCanZoom(const Napi::CallbackInfo &info);
    Napi::Value GetCachedZoomLevel(const Napi::CallbackInfo &info);
    Napi::Value GetCachedZoomMaximum(const Napi::CallbackInfo &info);
    Napi::Value GetCachedZoomMinimum(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentCanMove(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCanResize(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCanRotate(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCanZoom(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentZoomLevel(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentZoomMaximum(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentZoomMinimum(const Napi::CallbackInfo &info);

    void Move(const Napi::CallbackInfo &info);
    void Resize(const Napi::CallbackInfo &info);
    void Rotate(const Napi::CallbackInfo &info);
    void Zoom(const Napi::CallbackInfo &info);
    void ZoomByUnit(const Napi::CallbackInfo &info);
    
private:
    ATL::CComPtr<IUIAutomationTransformPattern2> m_tranformPattern2 = NULL;
};
