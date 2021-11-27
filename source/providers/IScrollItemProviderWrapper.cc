#include "IScrollItemProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IScrollItemProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IScrollItemProviderWrapper::ScrollIntoView>("scrollIntoView"),
    };

    Napi::Function function = DefineClass(env, "IScrollItemProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IScrollItemProviderWrapper::New(Napi::Env env, IScrollItemProvider *pIScrollItemProvider)
{
    if (pIScrollItemProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IScrollItemProviderWrapperConstructor->New({Napi::External<IScrollItemProvider>::New(env, pIScrollItemProvider)});
}

IScrollItemProviderWrapper::IScrollItemProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IScrollItemProviderWrapper>(info)
{
    m_pIScrollItemProvider = info[0].As<Napi::External<IScrollItemProvider>>().Data();
}

IScrollItemProviderWrapper::~IScrollItemProviderWrapper()
{
    m_pIScrollItemProvider->Release();
}

void IScrollItemProviderWrapper::ScrollIntoView(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIScrollItemProvider->ScrollIntoView();

    HandleResult(info, hResult);
}