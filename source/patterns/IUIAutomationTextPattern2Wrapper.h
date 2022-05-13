#pragma once

#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationTextPattern2Wrapper : public Napi::ObjectWrap<IUIAutomationTextPattern2Wrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTextPattern2 *pITextProvider2);

    IUIAutomationTextPattern2Wrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTextPattern2Wrapper();

    Napi::Value GetDocumentRange(const Napi::CallbackInfo &info);
    Napi::Value GetSupportedTextSelection(const Napi::CallbackInfo &info);

    Napi::Value GetSelection(const Napi::CallbackInfo &info);
    Napi::Value GetVisibleRanges(const Napi::CallbackInfo &info);
    Napi::Value RangeFromChild(const Napi::CallbackInfo &info);
    Napi::Value RangeFromPoint(const Napi::CallbackInfo &info);
    Napi::Value GetCaretRange(const Napi::CallbackInfo &info);
    Napi::Value RangeFromAnnotation(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationTextPattern2> m_pITextProvider2 = NULL;
};
