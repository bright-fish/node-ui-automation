#pragma once
#include "../Shared.h"

class ISelectionItemProviderWrapper : public Napi::ObjectWrap<ISelectionItemProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ISelectionItemProvider *pISelectionItemProvider);

    ISelectionItemProviderWrapper(const Napi::CallbackInfo &info);
    ~ISelectionItemProviderWrapper();

    Napi::Value GetIsSelected(const Napi::CallbackInfo &info);
    Napi::Value GetSelectionContainer(const Napi::CallbackInfo &info);

    void AddToSelection(const Napi::CallbackInfo &info);
    void RemoveFromSelection(const Napi::CallbackInfo &info);
    void Select(const Napi::CallbackInfo &info);

private:
    ISelectionItemProvider *m_pISelectionItemProvider;
};
