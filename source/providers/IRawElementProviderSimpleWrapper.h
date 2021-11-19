#pragma once
#include "../Shared.h"

class IRawElementProviderSimpleWrapper : public Napi::ObjectWrap<IRawElementProviderSimpleWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Object New(Napi::Env env, IRawElementProviderSimple *pRawElementProviderSimple);

    IRawElementProviderSimpleWrapper(const Napi::CallbackInfo &info);
    ~IRawElementProviderSimpleWrapper();
    
    Napi::Value GetHostRawElementProvider(const Napi::CallbackInfo &info);
    Napi::Value GetProviderOptions(const Napi::CallbackInfo &info);
    Napi::Value GetPatternProvider(const Napi::CallbackInfo &info);
    Napi::Value GetPropertyValue(const Napi::CallbackInfo &info);

    IRawElementProviderSimple *m_pRawElementProviderSimple;
};
