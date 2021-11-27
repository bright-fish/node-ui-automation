#include "ISpreadsheetItemProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *ISpreadsheetItemProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ISpreadsheetItemProviderWrapper::GetFormula>("formula"),

        InstanceMethod<&ISpreadsheetItemProviderWrapper::GetAnnotationObjects>("getAnnotationObjects"),
        InstanceMethod<&ISpreadsheetItemProviderWrapper::GetAnnotationTypes>("getAnnotationTypes"),
    };

    Napi::Function function = DefineClass(env, "ISpreadsheetItemProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ISpreadsheetItemProviderWrapper::New(Napi::Env env, ISpreadsheetItemProvider *pISpreadsheetItemProvider)
{
    if (pISpreadsheetItemProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ISpreadsheetItemProviderWrapperConstructor->New({Napi::External<ISpreadsheetItemProvider>::New(env, pISpreadsheetItemProvider)});
}

ISpreadsheetItemProviderWrapper::ISpreadsheetItemProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ISpreadsheetItemProviderWrapper>(info)
{
    m_pISpreadsheetItemProvider = info[0].As<Napi::External<ISpreadsheetItemProvider>>().Data();
}

ISpreadsheetItemProviderWrapper::~ISpreadsheetItemProviderWrapper()
{
    m_pISpreadsheetItemProvider->Release();
}

Napi::Value ISpreadsheetItemProviderWrapper::GetFormula(const Napi::CallbackInfo &info)
{
    CComBSTR formula;

    auto hResult = m_pISpreadsheetItemProvider->get_Formula(&formula);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(formula));
}

Napi::Value ISpreadsheetItemProviderWrapper::GetAnnotationObjects(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> annotationObjects;

    auto hResult = m_pISpreadsheetItemProvider->GetAnnotationObjects(&annotationObjects.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < annotationObjects.GetCount(); i++)
    {
        auto variant = annotationObjects.GetAt(i);

        auto annotationObject = static_cast<IRawElementProviderSimple *>(variant.punkVal);

        auto annotationObjectWrapper = IRawElementProviderSimpleWrapper::New(info.Env(), annotationObject);

        output.Set(i, annotationObjectWrapper);
    }

    return output;
}

Napi::Value ISpreadsheetItemProviderWrapper::GetAnnotationTypes(const Napi::CallbackInfo &info)
{
    CComSafeArray<int> annotationTypes;

    auto hResult = m_pISpreadsheetItemProvider->GetAnnotationTypes(&annotationTypes.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < annotationTypes.GetCount(); i++)
    {
        auto annotationType = annotationTypes.GetAt(i);

        output.Set(i, annotationType);
    }

    return output;
}
