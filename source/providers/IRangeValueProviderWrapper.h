#pragma once
#include "../Shared.h"

class IRangeValueProviderWrapper : public Napi::ObjectWrap<IRangeValueProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IRangeValueProvider *pIRangeValueProvider);

    IRangeValueProviderWrapper(const Napi::CallbackInfo &info);
    ~IRangeValueProviderWrapper();

    Napi::Value GetIsReadOnly(const Napi::CallbackInfo &info);
    Napi::Value GetLargeChange(const Napi::CallbackInfo &info);
    Napi::Value GetMaximum(const Napi::CallbackInfo &info);
    Napi::Value GetMinimum(const Napi::CallbackInfo &info);
    Napi::Value GetSmallChange(const Napi::CallbackInfo &info);
    Napi::Value GetValue(const Napi::CallbackInfo &info);
    
    void SetValue(const Napi::CallbackInfo &info);

private:
    IRangeValueProvider *m_pIRangeValueProvider;
};
