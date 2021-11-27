#pragma once
#include "../Shared.h"

class IScrollProviderWrapper : public Napi::ObjectWrap<IScrollProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IScrollProvider *pIScrollProvider);

    IScrollProviderWrapper(const Napi::CallbackInfo &info);
    ~IScrollProviderWrapper();


    Napi::Value GetHorizontallyScrollable(const Napi::CallbackInfo &info);
    Napi::Value GetHorizontalScrollPercent(const Napi::CallbackInfo &info);
    Napi::Value GetHorizontalViewSize(const Napi::CallbackInfo &info);
    Napi::Value GetVerticallyScrollable(const Napi::CallbackInfo &info);
    Napi::Value GetVerticalScrollPercent(const Napi::CallbackInfo &info);
    Napi::Value GetVerticalViewSize(const Napi::CallbackInfo &info);

    void Scroll(const Napi::CallbackInfo &info);
    void SetScrollPercent(const Napi::CallbackInfo &info);

private:
    IScrollProvider *m_pIScrollProvider;
};
