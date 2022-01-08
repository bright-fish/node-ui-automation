#include "IUIAutomationMultipleViewPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationMultipleViewPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationMultipleViewPatternWrapper::GetCachedCurrentView>("cachedCurrentView"),
        InstanceAccessor<&IUIAutomationMultipleViewPatternWrapper::GetCurrentCurrentView>("currentCurrentView"),

        InstanceMethod<&IUIAutomationMultipleViewPatternWrapper::GetCachedSupportedViews>("getCachedSupportedViews"),
        InstanceMethod<&IUIAutomationMultipleViewPatternWrapper::GetCurrentSupportedViews>("getCurrentSupportedViews"),

        InstanceMethod<&IUIAutomationMultipleViewPatternWrapper::GetViewName>("getViewName"),
        InstanceMethod<&IUIAutomationMultipleViewPatternWrapper::SetCurrentView>("setCurrentView"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationMultipleViewPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationMultipleViewPatternWrapper::New(Napi::Env env, IUIAutomationMultipleViewPattern *pMultipleViewPattern)
{
    if (pMultipleViewPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationMultipleViewPatternWrapperConstructor->New({Napi::External<IUIAutomationMultipleViewPattern>::New(env, pMultipleViewPattern)});
}

IUIAutomationMultipleViewPatternWrapper::IUIAutomationMultipleViewPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationMultipleViewPatternWrapper>(info)
{
    m_multipleViewPattern = info[0].As<Napi::External<IUIAutomationMultipleViewPattern>>().Data();
}

IUIAutomationMultipleViewPatternWrapper::~IUIAutomationMultipleViewPatternWrapper()
{
    m_multipleViewPattern.Release();
}

Napi::Value IUIAutomationMultipleViewPatternWrapper::GetCachedCurrentView(const Napi::CallbackInfo &info)
{
    int currentView;
    auto hResult = m_multipleViewPattern->get_CachedCurrentView(&currentView);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), currentView);
}

Napi::Value IUIAutomationMultipleViewPatternWrapper::GetCachedSupportedViews(const Napi::CallbackInfo &info)
{
    SAFEARRAY *pSafeArray;

    auto hResult = m_multipleViewPattern->GetCachedSupportedViews(&pSafeArray);

    HandleResult(info, hResult);

    ATL::CComSafeArray<long> supportedViews = pSafeArray;

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < supportedViews.GetCount(); i++)
    {
        auto value = supportedViews.GetAt(i);

        output.Set(i, value);
    }

    return output;
}

Napi::Value IUIAutomationMultipleViewPatternWrapper::GetCurrentCurrentView(const Napi::CallbackInfo &info)
{
    int currentView;
    auto hResult = m_multipleViewPattern->get_CurrentCurrentView(&currentView);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), currentView);
}

Napi::Value IUIAutomationMultipleViewPatternWrapper::GetCurrentSupportedViews(const Napi::CallbackInfo &info)
{
    SAFEARRAY *pSafeArray;

    auto hResult = m_multipleViewPattern->GetCurrentSupportedViews(&pSafeArray);

    HandleResult(info, hResult);

    ATL::CComSafeArray<long> supportedViews = pSafeArray;

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < supportedViews.GetCount(); i++)
    {
        auto value = supportedViews.GetAt(i);

        output.Set(i, value);
    }

    return output;
}

Napi::Value IUIAutomationMultipleViewPatternWrapper::GetViewName(const Napi::CallbackInfo &info)
{
    auto viewId = info[0].ToNumber().Int32Value();

    CComBSTR viewName;

    auto hResult = m_multipleViewPattern->GetViewName(viewId, &viewName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(viewName));
}

void IUIAutomationMultipleViewPatternWrapper::SetCurrentView(const Napi::CallbackInfo &info)
{
    auto viewId = info[0].ToNumber().Int32Value();

    auto hResult = m_multipleViewPattern->SetCurrentView(viewId);

    HandleResult(info, hResult);
}
