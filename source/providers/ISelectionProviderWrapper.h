#pragma once
#include "../Shared.h"

class ISelectionProviderWrapper : public Napi::ObjectWrap<ISelectionProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ISelectionProvider *pISelectionProvider);

    ISelectionProviderWrapper(const Napi::CallbackInfo &info);
    ~ISelectionProviderWrapper();

    Napi::Value GetCanSelectMultiple(const Napi::CallbackInfo &info);
    Napi::Value GetIsSelectionRequired(const Napi::CallbackInfo &info);

    Napi::Value GetSelection(const Napi::CallbackInfo &info);

private:
    ISelectionProvider *m_pISelectionProvider;
};
