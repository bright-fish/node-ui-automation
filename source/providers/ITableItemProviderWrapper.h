#pragma once
#include "../Shared.h"

class ITableItemProviderWrapper : public Napi::ObjectWrap<ITableItemProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, ITableItemProvider *pITableItemProvider);

    ITableItemProviderWrapper(const Napi::CallbackInfo &info);
    ~ITableItemProviderWrapper();

    Napi::Value GetColumnHeaderItems(const Napi::CallbackInfo &info);
    Napi::Value GetRowHeaderItems(const Napi::CallbackInfo &info);
    
private:
    ITableItemProvider *m_pITableItemProvider;
};
