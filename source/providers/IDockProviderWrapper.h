#pragma once
#include "../Shared.h"

class IDockProviderWrapper : public Napi::ObjectWrap<IDockProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IDockProvider *pIDockProvider);

    IDockProviderWrapper(const Napi::CallbackInfo &info);
    ~IDockProviderWrapper();

    Napi::Value GetDockPosition(const Napi::CallbackInfo &info);
    void SetDockPosition(const Napi::CallbackInfo &info);

private:
    IDockProvider *m_pIDockProvider;
};
