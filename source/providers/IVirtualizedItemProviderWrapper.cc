#include "IVirtualizedItemProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IVirtualizedItemProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IVirtualizedItemProviderWrapper::Realize>("realize"),
    };

    Napi::Function function = DefineClass(env, "IVirtualizedItemProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IVirtualizedItemProviderWrapper::New(Napi::Env env, IVirtualizedItemProvider *pIVirtualizedItemProvider)
{
    if (pIVirtualizedItemProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IVirtualizedItemProviderWrapperConstructor->New({Napi::External<IVirtualizedItemProvider>::New(env, pIVirtualizedItemProvider)});
}

IVirtualizedItemProviderWrapper::IVirtualizedItemProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IVirtualizedItemProviderWrapper>(info)
{
    m_pIVirtualizedItemProvider = info[0].As<Napi::External<IVirtualizedItemProvider>>().Data();
}

IVirtualizedItemProviderWrapper::~IVirtualizedItemProviderWrapper()
{
    m_pIVirtualizedItemProvider->Release();
}

void IVirtualizedItemProviderWrapper::Realize(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIVirtualizedItemProvider->Realize();

    HandleResult(info, hResult);
}