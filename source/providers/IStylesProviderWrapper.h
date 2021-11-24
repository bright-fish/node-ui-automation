#pragma once

#include "../Shared.h"

class IStylesProviderWrapper : public Napi::ObjectWrap<IStylesProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IStylesProvider *pIStylesProvider);

    Napi::Value GetExtendedProperties(const Napi::CallbackInfo &info);
    Napi::Value GetFillColor(const Napi::CallbackInfo &info);
    Napi::Value GetFillPatternColor(const Napi::CallbackInfo &info);
    Napi::Value GetFillPatternStyle(const Napi::CallbackInfo &info);
    Napi::Value GetShape(const Napi::CallbackInfo &info);
    Napi::Value GetStyleId(const Napi::CallbackInfo &info);
    Napi::Value GetStyleName(const Napi::CallbackInfo &info);

    IStylesProviderWrapper(const Napi::CallbackInfo &info);
    ~IStylesProviderWrapper();

private:
    IStylesProvider *m_pIStylesProvider;
};
