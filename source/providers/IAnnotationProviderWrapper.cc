#include "IAnnotationProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IAnnotationProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IAnnotationProviderWrapper::GetAnnotationTypeId>("annotationTypeId"),
        InstanceAccessor<&IAnnotationProviderWrapper::GetAnnotationTypeName>("annotationTypeName"),
        InstanceAccessor<&IAnnotationProviderWrapper::GetAuthor>("author"),
        InstanceAccessor<&IAnnotationProviderWrapper::GetDateTime>("dateTime"),
        InstanceAccessor<&IAnnotationProviderWrapper::GetTarget>("target"),
    };

    Napi::Function function = DefineClass(env, "IAnnotationProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IAnnotationProviderWrapper::New(Napi::Env env, IAnnotationProvider *pAnnotationProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IInvokeProviderWrapperConstructor->New({Napi::External<IAnnotationProvider>::New(env, pAnnotationProvider)});
}

IAnnotationProviderWrapper::IAnnotationProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IAnnotationProviderWrapper>(info)
{
    m_pIAnnotationProvider = info[0].As<Napi::External<IAnnotationProvider>>().Data();
}

IAnnotationProviderWrapper::~IAnnotationProviderWrapper()
{
    m_pIAnnotationProvider->Release();
}

Napi::Value IAnnotationProviderWrapper::GetAnnotationTypeId(const Napi::CallbackInfo &info)
{
    int annotationTypeId;
    auto hResult = m_pIAnnotationProvider->get_AnnotationTypeId(&annotationTypeId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), annotationTypeId);
}

Napi::Value IAnnotationProviderWrapper::GetAnnotationTypeName(const Napi::CallbackInfo &info)
{
    BSTR annotationTypeName;
    auto hResult = m_pIAnnotationProvider->get_AnnotationTypeName(&annotationTypeName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(annotationTypeName));
}

Napi::Value IAnnotationProviderWrapper::GetAuthor(const Napi::CallbackInfo &info)
{
    BSTR author;
    auto hResult = m_pIAnnotationProvider->get_Author(&author);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(author));
}

Napi::Value IAnnotationProviderWrapper::GetDateTime(const Napi::CallbackInfo &info)
{
    BSTR dateTime;
    auto hResult = m_pIAnnotationProvider->get_DateTime(&dateTime);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dateTime));
}

Napi::Value IAnnotationProviderWrapper::GetTarget(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *pTarget;
    auto hResult = m_pIAnnotationProvider->get_Target(&pTarget);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pTarget);
}