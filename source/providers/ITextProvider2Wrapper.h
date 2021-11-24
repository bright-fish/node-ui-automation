#pragma once
#include "../Shared.h"

class ITextProvider2Wrapper : public Napi::ObjectWrap<ITextProvider2Wrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, ITextProvider2 *pITextProvider2);

    ITextProvider2Wrapper(const Napi::CallbackInfo &info);
    ~ITextProvider2Wrapper();

    Napi::Value GetDocumentRange(const Napi::CallbackInfo &info);
    Napi::Value GetSupportedTextSelection(const Napi::CallbackInfo &info);

    Napi::Value GetSelection(const Napi::CallbackInfo &info);
    Napi::Value GetVisibleRanges(const Napi::CallbackInfo &info);
    Napi::Value RangeFromChild(const Napi::CallbackInfo &info);
    Napi::Value RangeFromPoint(const Napi::CallbackInfo &info);
    Napi::Value GetCaretRange(const Napi::CallbackInfo &info);
    Napi::Value RangeFromAnnotation(const Napi::CallbackInfo &info);

private:
    ITextProvider2 *m_pITextProvider2;
};
