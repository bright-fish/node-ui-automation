#pragma once
#include "../Shared.h"

class IDragProviderWrapper : public Napi::ObjectWrap<IDragProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IDragProvider *pIDragProvider);

    IDragProviderWrapper(const Napi::CallbackInfo &info);
    ~IDragProviderWrapper();

    Napi::Value GetDropEffects(const Napi::CallbackInfo &info);
    Napi::Value GetDropEffect(const Napi::CallbackInfo &info);
    Napi::Value GetIsGrabbed(const Napi::CallbackInfo &info);
    Napi::Value GetGrabbedItems(const Napi::CallbackInfo &info);
private:
    IDragProvider *m_pIDragProvider;
};
