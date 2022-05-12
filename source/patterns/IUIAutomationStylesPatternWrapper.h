#pragma once

#include "../Shared.h"

class IUIAutomationStylesPatternWrapper : public Napi::ObjectWrap<IUIAutomationStylesPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationStylesPattern *pStylesPattern);

    Napi::Value GetCachedExtendedProperties(const Napi::CallbackInfo &info);
    Napi::Value GetCachedFillColor(const Napi::CallbackInfo &info);
    Napi::Value GetCachedFillPatternColor(const Napi::CallbackInfo &info);
    Napi::Value GetCachedFillPatternStyle(const Napi::CallbackInfo &info);
    Napi::Value GetCachedShape(const Napi::CallbackInfo &info);
    Napi::Value GetCachedStyleId(const Napi::CallbackInfo &info);
    Napi::Value GetCachedStyleName(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentExtendedProperties(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentFillColor(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentFillPatternColor(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentFillPatternStyle(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentShape(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentStyleId(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentStyleName(const Napi::CallbackInfo &info);

    Napi::Value GetCachedExtendedPropertiesAsArray(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentExtendedPropertiesAsArray(const Napi::CallbackInfo &info);

    IUIAutomationStylesPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationStylesPatternWrapper();

private:
    ATL::CComPtr<IUIAutomationStylesPattern> m_stylesPattern = NULL;
};
