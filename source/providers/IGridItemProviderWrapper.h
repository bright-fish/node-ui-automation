#pragma once
#include "../Shared.h"

class IGridItemProviderWrapper : public Napi::ObjectWrap<IGridItemProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IGridItemProvider *pIGridItemProvider);

    Napi::Value GetColumn(const Napi::CallbackInfo &info);
    Napi::Value GetColumnSpan(const Napi::CallbackInfo &info);
    Napi::Value GetContainingGrid(const Napi::CallbackInfo &info);
    Napi::Value GetRow(const Napi::CallbackInfo &info);
    Napi::Value GetRowSpan(const Napi::CallbackInfo &info);

    IGridItemProviderWrapper(const Napi::CallbackInfo &info);
    ~IGridItemProviderWrapper();

private:
    IGridItemProvider *m_pIGridItemProvider;
};
