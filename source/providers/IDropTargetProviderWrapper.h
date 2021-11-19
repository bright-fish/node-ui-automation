#pragma once
#include "../Shared.h"

class IDropTargetProviderWrapper : public Napi::ObjectWrap<IDropTargetProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IDropTargetProvider *pDropTargetProvider);

    IDropTargetProviderWrapper(const Napi::CallbackInfo &info);
    ~IDropTargetProviderWrapper();

    Napi::Value GetDropTargetEffects(const Napi::CallbackInfo &info);
    Napi::Value GetDropTargetEffect(const Napi::CallbackInfo &info);
private:
    IDropTargetProvider *m_pIDropTargetProvider;
};
