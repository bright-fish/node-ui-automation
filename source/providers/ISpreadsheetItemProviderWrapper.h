#pragma once
#include "../Shared.h"

class ISpreadsheetItemProviderWrapper : public Napi::ObjectWrap<ISpreadsheetItemProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, ISpreadsheetItemProvider *pISpreadsheetItemProvider);

    ISpreadsheetItemProviderWrapper(const Napi::CallbackInfo &info);
    ~ISpreadsheetItemProviderWrapper();

    Napi::Value GetFormula(const Napi::CallbackInfo &info);
    Napi::Value GetAnnotationObjects(const Napi::CallbackInfo &info);
    Napi::Value GetAnnotationTypes(const Napi::CallbackInfo &info);

private:
    ISpreadsheetItemProvider *m_pISpreadsheetItemProvider;
};
