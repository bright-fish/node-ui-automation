#pragma once
#include "../Shared.h"

class IUIAutomationSpreadsheetItemPatternWrapper : public Napi::ObjectWrap<IUIAutomationSpreadsheetItemPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationSpreadsheetItemPattern *pSpreadsheetItemPattern);

    IUIAutomationSpreadsheetItemPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationSpreadsheetItemPatternWrapper();

    Napi::Value GetCachedFormula(const Napi::CallbackInfo &info);
    Napi::Value GetCachedAnnotationObjects(const Napi::CallbackInfo &info);
    Napi::Value GetCachedAnnotationTypes(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentFormula(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentAnnotationObjects(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentAnnotationTypes(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationSpreadsheetItemPattern> m_spreadsheetItemPattern = NULL;
};
