#include "IMultipleViewProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IMultipleViewProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IMultipleViewProviderWrapper::GetCurrentView>("currentView"),

        InstanceMethod<&IMultipleViewProviderWrapper::GetSupportedViews>("getSupportedViews"),
        InstanceMethod<&IMultipleViewProviderWrapper::GetViewName>("getViewName"),
        InstanceMethod<&IMultipleViewProviderWrapper::SetCurrentView>("setCurrentView"),
    };

    Napi::Function function = DefineClass(env, "IMultipleViewProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IMultipleViewProviderWrapper::New(Napi::Env env, IMultipleViewProvider *pIMultipleViewProvider)
{
    if (pIMultipleViewProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IMultipleViewProviderWrapperConstructor->New({Napi::External<IMultipleViewProvider>::New(env, pIMultipleViewProvider)});
}

IMultipleViewProviderWrapper::IMultipleViewProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IMultipleViewProviderWrapper>(info)
{
    m_pIMultipleViewProvider = info[0].As<Napi::External<IMultipleViewProvider>>().Data();
}

IMultipleViewProviderWrapper::~IMultipleViewProviderWrapper()
{
    m_pIMultipleViewProvider->Release();
}

Napi::Value IMultipleViewProviderWrapper::GetCurrentView(const Napi::CallbackInfo &info)
{
    int currentView;
    auto hResult = m_pIMultipleViewProvider->get_CurrentView(&currentView);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), currentView);
}

Napi::Value IMultipleViewProviderWrapper::GetSupportedViews(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> supportedViews;
    auto hResult = m_pIMultipleViewProvider->GetSupportedViews(&supportedViews.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < supportedViews.GetCount(); i++)
    {
        auto variant = supportedViews.GetAt(i);
        auto supportedView = variant.intVal;

        output.Set(i, supportedView);
    }

    return output;
}

Napi::Value IMultipleViewProviderWrapper::GetViewName(const Napi::CallbackInfo &info)
{
    auto viewId = info[0].ToNumber().Int32Value();

    CComBSTR viewName;

    auto hResult = m_pIMultipleViewProvider->GetViewName(viewId, &viewName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(viewName));
}

void IMultipleViewProviderWrapper::SetCurrentView(const Napi::CallbackInfo &info)
{
    auto viewId = info[0].ToNumber().Int32Value();

    auto hResult = m_pIMultipleViewProvider->SetCurrentView(viewId);

    HandleResult(info, hResult);
}
