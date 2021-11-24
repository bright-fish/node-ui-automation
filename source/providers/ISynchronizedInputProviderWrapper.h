#pragma once
#include "../Shared.h"

class ISynchronizedInputProviderWrapper : public Napi::ObjectWrap<ISynchronizedInputProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, ISynchronizedInputProvider *pISynchronizedInputProvider);

    ISynchronizedInputProviderWrapper(const Napi::CallbackInfo &info);
    ~ISynchronizedInputProviderWrapper();

    void Cancel(const Napi::CallbackInfo &info);
    void StartListening(const Napi::CallbackInfo &info);
    
private:
    ISynchronizedInputProvider *m_pISynchronizedInputProvider;
};
