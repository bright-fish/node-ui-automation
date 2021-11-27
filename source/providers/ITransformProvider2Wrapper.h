#pragma once
#include "../Shared.h"

class ITransformProvider2Wrapper : public Napi::ObjectWrap<ITransformProvider2Wrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ITransformProvider2 *pITransformProvider2);

    ITransformProvider2Wrapper(const Napi::CallbackInfo &info);
    ~ITransformProvider2Wrapper();

    Napi::Value GetCanMove(const Napi::CallbackInfo &info);
    Napi::Value GetCanResize(const Napi::CallbackInfo &info);
    Napi::Value GetCanRotate(const Napi::CallbackInfo &info);
    Napi::Value GetCanZoom(const Napi::CallbackInfo &info);
    Napi::Value GetZoomLevel(const Napi::CallbackInfo &info);
    Napi::Value GetZoomMaximum(const Napi::CallbackInfo &info);
    Napi::Value GetZoomMinimum(const Napi::CallbackInfo &info);

    void Move(const Napi::CallbackInfo &info);
    void Resize(const Napi::CallbackInfo &info);
    void Rotate(const Napi::CallbackInfo &info);
    void Zoom(const Napi::CallbackInfo &info);
    void ZoomByUnit(const Napi::CallbackInfo &info);
    
private:
    ITransformProvider2 *m_pITransformProvider2;
};
