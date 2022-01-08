#pragma once

#include "../Shared.h"

class IUIAutomationTextEditPatternWrapper : public Napi::ObjectWrap<IUIAutomationTextEditPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTextEditPattern *pTextEditPattern);

    IUIAutomationTextEditPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTextEditPatternWrapper();

    Napi::Value GetDocumentRange(const Napi::CallbackInfo &info);
    Napi::Value GetSupportedTextSelection(const Napi::CallbackInfo &info);
    Napi::Value GetSelection(const Napi::CallbackInfo &info);
    Napi::Value GetVisibleRanges(const Napi::CallbackInfo &info);
    Napi::Value RangeFromChild(const Napi::CallbackInfo &info);
    Napi::Value RangeFromPoint(const Napi::CallbackInfo &info);

    Napi::Value GetActiveComposition(const Napi::CallbackInfo &info);
    Napi::Value GetConversionTarget(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationTextEditPattern> m_textEditPattern;
};
