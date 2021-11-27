#pragma once
#include "../Shared.h"

class IItemContainerProviderWrapper : public Napi::ObjectWrap<IItemContainerProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IItemContainerProvider *pIItemContainerProvider);

    IItemContainerProviderWrapper(const Napi::CallbackInfo &info);
    ~IItemContainerProviderWrapper();

    Napi::Value FindItemByProperty(const Napi::CallbackInfo &info);
private:
    IItemContainerProvider *m_pIItemContainerProvider;
};
