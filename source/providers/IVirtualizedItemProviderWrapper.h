#pragma once
#include "../Shared.h"

class IVirtualizedItemProviderWrapper : public Napi::ObjectWrap<IVirtualizedItemProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IVirtualizedItemProvider *pIVirtualizedItemProvider);

    IVirtualizedItemProviderWrapper(const Napi::CallbackInfo &info);
    ~IVirtualizedItemProviderWrapper();

    void Realize(const Napi::CallbackInfo &info);
private:
    IVirtualizedItemProvider *m_pIVirtualizedItemProvider;
};
