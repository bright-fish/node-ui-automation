#pragma once
#include "../Shared.h"

class ITextProviderWrapper : public Napi::ObjectWrap<ITextProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ITextProvider *pITextProvider);

    ITextProviderWrapper(const Napi::CallbackInfo &info);
    ~ITextProviderWrapper();

    Napi::Value GetDocumentRange(const Napi::CallbackInfo &info);
    Napi::Value GetSupportedTextSelection(const Napi::CallbackInfo &info);

    Napi::Value GetSelection(const Napi::CallbackInfo &info);
    Napi::Value GetVisibleRanges(const Napi::CallbackInfo &info);
    Napi::Value RangeFromChild(const Napi::CallbackInfo &info);
    Napi::Value RangeFromPoint(const Napi::CallbackInfo &info);
    
private:
    ITextProvider *m_pITextProvider;
};
