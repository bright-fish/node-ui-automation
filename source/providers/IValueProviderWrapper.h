#pragma once
#include "../Shared.h"

class IValueProviderWrapper : public Napi::ObjectWrap<IValueProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IValueProvider *pIValueProvider);

    IValueProviderWrapper(const Napi::CallbackInfo &info);
    ~IValueProviderWrapper();

    Napi::Value GetIsReadOnly(const Napi::CallbackInfo &info);
    Napi::Value GetValue(const Napi::CallbackInfo &info);

    void SetValue(const Napi::CallbackInfo &info);

private:
    IValueProvider *m_pIValueProvider;
};
