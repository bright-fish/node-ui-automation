#pragma once
#include "../Shared.h"

class IToggleProviderWrapper : public Napi::ObjectWrap<IToggleProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IToggleProvider *pIToggleProvider);

    IToggleProviderWrapper(const Napi::CallbackInfo &info);
    ~IToggleProviderWrapper();

    Napi::Value GetToggleState(const Napi::CallbackInfo &info);
    void Toggle(const Napi::CallbackInfo &info);
    
private:
    IToggleProvider *m_pIToggleProvider;
};
