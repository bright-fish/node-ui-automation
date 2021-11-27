#pragma once
#include "../Shared.h"

class IScrollItemProviderWrapper : public Napi::ObjectWrap<IScrollItemProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IScrollItemProvider *pIInvokeProvider);

    IScrollItemProviderWrapper(const Napi::CallbackInfo &info);
    ~IScrollItemProviderWrapper();

    void ScrollIntoView(const Napi::CallbackInfo &info);
private:
    IScrollItemProvider *m_pIScrollItemProvider;
};
