#pragma once
#include "../Shared.h"

class IUIAutomationAnnotationPatternWrapper : public Napi::ObjectWrap<IUIAutomationAnnotationPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationAnnotationPattern *pIAnnotationProvider);

    IUIAutomationAnnotationPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationAnnotationPatternWrapper();

    Napi::Value GetCachedAnnotationTypeId(const Napi::CallbackInfo &info);
    Napi::Value GetCachedAnnotationTypeName(const Napi::CallbackInfo &info);
    Napi::Value GetCachedAuthor(const Napi::CallbackInfo &info);
    Napi::Value GetCachedDateTime(const Napi::CallbackInfo &info);
    Napi::Value GetCachedTarget(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentAnnotationTypeId(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentAnnotationTypeName(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentAuthor(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentDateTime(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentTarget(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationAnnotationPattern> m_annotationProvider;
};
