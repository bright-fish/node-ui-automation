#pragma once
#include "../Shared.h"

class IAnnotationProviderWrapper : public Napi::ObjectWrap<IAnnotationProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IAnnotationProvider *pIAnnotationProvider);

    Napi::Value GetAnnotationTypeId(const Napi::CallbackInfo &info);
    Napi::Value GetAnnotationTypeName(const Napi::CallbackInfo &info);
    Napi::Value GetAuthor(const Napi::CallbackInfo &info);
    Napi::Value GetDateTime(const Napi::CallbackInfo &info);
    Napi::Value GetTarget(const Napi::CallbackInfo &info);

    IAnnotationProviderWrapper(const Napi::CallbackInfo &info);
    ~IAnnotationProviderWrapper();

private:
    IAnnotationProvider *m_pIAnnotationProvider;
};
