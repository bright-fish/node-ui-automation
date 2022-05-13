#include "IUIAutomationSpreadsheetItemPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "../utilities/ComAutoPointer.h"
#include "../utilities/AutoSafeArray.h"

Napi::FunctionReference *IUIAutomationSpreadsheetItemPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationSpreadsheetItemPatternWrapper::GetCachedFormula>("cachedFormula"),
        InstanceAccessor<&IUIAutomationSpreadsheetItemPatternWrapper::GetCurrentFormula>("currentFormula"),

        InstanceMethod<&IUIAutomationSpreadsheetItemPatternWrapper::GetCachedAnnotationObjects>("getCachedAnnotationObjects"),
        InstanceMethod<&IUIAutomationSpreadsheetItemPatternWrapper::GetCachedAnnotationTypes>("getCachedAnnotationTypes"),
        InstanceMethod<&IUIAutomationSpreadsheetItemPatternWrapper::GetCurrentAnnotationObjects>("getCurrentAnnotationObjects"),
        InstanceMethod<&IUIAutomationSpreadsheetItemPatternWrapper::GetCurrentAnnotationTypes>("getCurrentAnnotationTypes"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomatioinSpreadsheetItemPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationSpreadsheetItemPatternWrapper::New(Napi::Env env, IUIAutomationSpreadsheetItemPattern *pSpreadsheetItemPattern)
{
    if (pSpreadsheetItemPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationSpreadsheetItemPatternWrapperConstructor->New({Napi::External<IUIAutomationSpreadsheetItemPattern>::New(env, pSpreadsheetItemPattern)});
}

IUIAutomationSpreadsheetItemPatternWrapper::IUIAutomationSpreadsheetItemPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationSpreadsheetItemPatternWrapper>(info)
{
    m_spreadsheetItemPattern = info[0].As<Napi::External<IUIAutomationSpreadsheetItemPattern>>().Data();
}

IUIAutomationSpreadsheetItemPatternWrapper::~IUIAutomationSpreadsheetItemPatternWrapper()
{
    m_spreadsheetItemPattern.Release();
}

Napi::Value IUIAutomationSpreadsheetItemPatternWrapper::GetCachedFormula(const Napi::CallbackInfo &info)
{
    BSTR formula;

    auto hResult = m_spreadsheetItemPattern->get_CachedFormula(&formula);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(formula));
}

Napi::Value IUIAutomationSpreadsheetItemPatternWrapper::GetCurrentFormula(const Napi::CallbackInfo &info)
{
    BSTR formula;

    auto hResult = m_spreadsheetItemPattern->get_CurrentFormula(&formula);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(formula));
}


Napi::Value IUIAutomationSpreadsheetItemPatternWrapper::GetCachedAnnotationObjects(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElementArray> annotationObjects = NULL;

    auto hResult = m_spreadsheetItemPattern->GetCachedAnnotationObjects(&annotationObjects);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = annotationObjects->get_Length(&length);

    for (long i = 0; i < length; i++)
    {
        ComAutoPointer<IUIAutomationElement> element = NULL;

        hResult = annotationObjects->GetElement(i, &element);

        HandleResult(info, hResult);

        auto annotationObjectWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, annotationObjectWrapper);
    }

    return output;
}

Napi::Value IUIAutomationSpreadsheetItemPatternWrapper::GetCachedAnnotationTypes(const Napi::CallbackInfo &info)
{
    AutoSafeArray<int> annotationTypes;

    auto hResult = m_spreadsheetItemPattern->GetCachedAnnotationTypes(&annotationTypes.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < annotationTypes.GetCount(); i++)
    {
        auto annotationType = annotationTypes.GetAt(i);

        output.Set(i, annotationType);
    }

    return output;
}

Napi::Value IUIAutomationSpreadsheetItemPatternWrapper::GetCurrentAnnotationObjects(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElementArray> annotationObjects = NULL;

    auto hResult = m_spreadsheetItemPattern->GetCurrentAnnotationObjects(&annotationObjects);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = annotationObjects->get_Length(&length);

    for (long i = 0; i < length; i++)
    {
        ComAutoPointer<IUIAutomationElement> element = NULL;

        hResult = annotationObjects->GetElement(i, &element);

        HandleResult(info, hResult);

        auto annotationObjectWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, annotationObjectWrapper);
    }

    return output;
}

Napi::Value IUIAutomationSpreadsheetItemPatternWrapper::GetCurrentAnnotationTypes(const Napi::CallbackInfo &info)
{
    AutoSafeArray<int> annotationTypes;

    auto hResult = m_spreadsheetItemPattern->GetCurrentAnnotationTypes(&annotationTypes.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < annotationTypes.GetCount(); i++)
    {
        auto annotationType = annotationTypes.GetAt(i);

        output.Set(i, annotationType);
    }

    return output;
}
