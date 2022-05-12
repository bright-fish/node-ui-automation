#pragma once
#include "../Shared.h"

class IUIAutomationTextPatternWrapper : public Napi::ObjectWrap<IUIAutomationTextPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTextPattern *pTextPattern);

    IUIAutomationTextPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTextPatternWrapper();

    Napi::Value GetDocumentRange(const Napi::CallbackInfo &info);
    Napi::Value GetSupportedTextSelection(const Napi::CallbackInfo &info);

    Napi::Value GetSelection(const Napi::CallbackInfo &info);
    Napi::Value GetVisibleRanges(const Napi::CallbackInfo &info);
    Napi::Value RangeFromChild(const Napi::CallbackInfo &info);
    Napi::Value RangeFromPoint(const Napi::CallbackInfo &info);
    
private:
    ATL::CComPtr<IUIAutomationTextPattern> m_textPattern = NULL;
};
