#pragma once
#include "../Shared.h"

class ITransformProviderWrapper : public Napi::ObjectWrap<ITransformProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, ITransformProvider *pITransformProvider);

    ITransformProviderWrapper(const Napi::CallbackInfo &info);
    ~ITransformProviderWrapper();

    Napi::Value GetCanMove(const Napi::CallbackInfo &info);
    Napi::Value GetCanResize(const Napi::CallbackInfo &info);
    Napi::Value GetCanRotate(const Napi::CallbackInfo &info);

    void Move(const Napi::CallbackInfo &info);
    void Resize(const Napi::CallbackInfo &info);
    void Rotate(const Napi::CallbackInfo &info);
    
private:
    ITransformProvider *m_pITransformProvider;
};
