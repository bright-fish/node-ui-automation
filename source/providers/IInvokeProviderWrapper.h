#pragma once
#include "../Shared.h"

class IInvokeProviderWrapper : public Napi::ObjectWrap<IInvokeProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IInvokeProvider *pInvokeProvider);

    void Invoke(const Napi::CallbackInfo &info);

    IInvokeProviderWrapper(const Napi::CallbackInfo &info);
    ~IInvokeProviderWrapper();
private:
    IInvokeProvider *m_pIInvokeProvider;
};
