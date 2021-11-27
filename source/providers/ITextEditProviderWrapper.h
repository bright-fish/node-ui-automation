#pragma once

#include "../Shared.h"

class ITextEditProviderWrapper : public Napi::ObjectWrap<ITextEditProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ITextEditProvider *pITextEditProvider);

    ITextEditProviderWrapper(const Napi::CallbackInfo &info);
    ~ITextEditProviderWrapper();

    Napi::Value GetActiveComposition(const Napi::CallbackInfo &info);
    Napi::Value GetConversionTarget(const Napi::CallbackInfo &info);

private:
    ITextEditProvider *m_pITextEditProvider;
};
