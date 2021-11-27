#pragma once
#include "../Shared.h"

class ISpreadsheetProviderWrapper : public Napi::ObjectWrap<ISpreadsheetProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ISpreadsheetProvider *pISpreadsheetProvider);

    ISpreadsheetProviderWrapper(const Napi::CallbackInfo &info);
    ~ISpreadsheetProviderWrapper();

    Napi::Value GetItemByName(const Napi::CallbackInfo &info);
private:
    ISpreadsheetProvider *m_pISpreadsheetProvider;
};
