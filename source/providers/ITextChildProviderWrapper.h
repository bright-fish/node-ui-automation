#pragma once

#include "../Shared.h"

class ITextChildProviderWrapper : public Napi::ObjectWrap<ITextChildProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ITextChildProvider *pITextChildProvider);

    ITextChildProviderWrapper(const Napi::CallbackInfo &info);
    ~ITextChildProviderWrapper();

    Napi::Value GetTextContainer(const Napi::CallbackInfo &info);
    Napi::Value GetTextRange(const Napi::CallbackInfo &info);

private:
    ITextChildProvider *m_pITextChildProvider;
};
