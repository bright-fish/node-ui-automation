#pragma once
#include "../Shared.h"

class IGridProviderWrapper : public Napi::ObjectWrap<IGridProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IGridProvider *pIGridProvider);

    IGridProviderWrapper(const Napi::CallbackInfo &info);
    ~IGridProviderWrapper();

    Napi::Value GetColumnCount(const Napi::CallbackInfo &info);
    Napi::Value GetRowCount(const Napi::CallbackInfo &info);
    Napi::Value GetItem(const Napi::CallbackInfo &info);
private:
    IGridProvider *m_pGridProvider;
};
