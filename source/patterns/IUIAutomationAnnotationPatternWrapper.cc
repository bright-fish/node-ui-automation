#include "IUIAutomationAnnotationPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationAnnotationPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCachedAnnotationTypeId>("cachedAnnotationTypeId"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCachedAnnotationTypeName>("cachedAnnotationTypeName"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCachedAuthor>("cachedAuthor"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCachedDateTime>("cachedDateTime"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCachedTarget>("cachedTarget"),

        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCurrentAnnotationTypeId>("currentAnnotationTypeId"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCurrentAnnotationTypeName>("currentAnnotationTypeName"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCurrentAuthor>("currentAuthor"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCurrentDateTime>("currentDateTime"),
        InstanceAccessor<&IUIAutomationAnnotationPatternWrapper::GetCurrentTarget>("currentTarget"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationAnnotationPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationAnnotationPatternWrapper::New(Napi::Env env, IUIAutomationAnnotationPattern *pAnnotationPattern)
{
    if (pAnnotationPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationAnnotationPatternWrapperConstructor->New({Napi::External<IUIAutomationAnnotationPattern>::New(env, pAnnotationPattern)});
}

IUIAutomationAnnotationPatternWrapper::IUIAutomationAnnotationPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationAnnotationPatternWrapper>(info)
{
    m_annotationProvider = info[0].As<Napi::External<IUIAutomationAnnotationPattern>>().Data();
}

IUIAutomationAnnotationPatternWrapper::~IUIAutomationAnnotationPatternWrapper()
{
    m_annotationProvider.Release();
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCachedAnnotationTypeId(const Napi::CallbackInfo &info)
{
    int annotationTypeId;
    auto hResult = m_annotationProvider->get_CachedAnnotationTypeId(&annotationTypeId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), annotationTypeId);
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCachedAnnotationTypeName(const Napi::CallbackInfo &info)
{
    BSTR annotationTypeName;
    auto hResult = m_annotationProvider->get_CachedAnnotationTypeName(&annotationTypeName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(annotationTypeName));
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCachedAuthor(const Napi::CallbackInfo &info)
{
    BSTR author;
    auto hResult = m_annotationProvider->get_CachedAuthor(&author);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(author));
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCachedDateTime(const Napi::CallbackInfo &info)
{
    BSTR dateTime;
    auto hResult = m_annotationProvider->get_CachedDateTime(&dateTime);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dateTime));
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCachedTarget(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pTarget = NULL;
    auto hResult = m_annotationProvider->get_CachedTarget(&pTarget);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pTarget);
}


Napi::Value IUIAutomationAnnotationPatternWrapper::GetCurrentAnnotationTypeId(const Napi::CallbackInfo &info)
{
    int annotationTypeId;
    auto hResult = m_annotationProvider->get_CurrentAnnotationTypeId(&annotationTypeId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), annotationTypeId);
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCurrentAnnotationTypeName(const Napi::CallbackInfo &info)
{
    BSTR annotationTypeName;
    auto hResult = m_annotationProvider->get_CurrentAnnotationTypeName(&annotationTypeName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(annotationTypeName));
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCurrentAuthor(const Napi::CallbackInfo &info)
{
    BSTR author;
    auto hResult = m_annotationProvider->get_CurrentAuthor(&author);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(author));
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCurrentDateTime(const Napi::CallbackInfo &info)
{
    BSTR dateTime;
    auto hResult = m_annotationProvider->get_CurrentDateTime(&dateTime);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dateTime));
}

Napi::Value IUIAutomationAnnotationPatternWrapper::GetCurrentTarget(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pTarget = NULL;
    auto hResult = m_annotationProvider->get_CurrentTarget(&pTarget);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pTarget);
}