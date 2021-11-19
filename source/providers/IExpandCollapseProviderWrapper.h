#pragma once
#include "../Shared.h"

class IExpandCollapseProviderWrapper : public Napi::ObjectWrap<IExpandCollapseProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IExpandCollapseProvider *pIExpandCollapseProvider);

    IExpandCollapseProviderWrapper(const Napi::CallbackInfo &info);
    ~IExpandCollapseProviderWrapper();

    Napi::Value GetExpandCollapseState(const Napi::CallbackInfo &info);
    void Collapse(const Napi::CallbackInfo &info);
    void Expand(const Napi::CallbackInfo &info);

private:
    IExpandCollapseProvider *m_pIExpandCollapseProvider;
};
