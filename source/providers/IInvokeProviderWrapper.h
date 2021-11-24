#pragma once
#include "../Shared.h"

class IInvokeProviderWrapper : public Napi::ObjectWrap<IInvokeProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IInvokeProvider *pIInvokeProvider);

    IInvokeProviderWrapper(const Napi::CallbackInfo &info);
    ~IInvokeProviderWrapper();

    void Invoke(const Napi::CallbackInfo &info);
private:
    IInvokeProvider *m_pIInvokeProvider;
};
