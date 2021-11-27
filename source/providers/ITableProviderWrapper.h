#pragma once
#include "../Shared.h"

class ITableProviderWrapper : public Napi::ObjectWrap<ITableProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ITableProvider *pITableProvider);

    ITableProviderWrapper(const Napi::CallbackInfo &info);
    ~ITableProviderWrapper();

    Napi::Value GetRowOrColumnMajor(const Napi::CallbackInfo &info);
    Napi::Value GetColumnHeaders(const Napi::CallbackInfo &info);
    Napi::Value GetRowHeaders(const Napi::CallbackInfo &info);
    
private:
    ITableProvider *m_pITableProvider;
};
