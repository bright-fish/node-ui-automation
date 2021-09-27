#include "Wrappers.h"
#include "../AutomationAddon.h"

Napi::FunctionReference *IUIAutomationProxyFactoryMappingWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationProxyFactoryMapping", {});

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IUIAutomationProxyFactoryMappingWrapper::New(Napi::Env env, IUIAutomationProxyFactoryMapping *pProxyFactoryMapping)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationProxyFactoryMappingWrapperConstructor->New({Napi::External<IUIAutomationProxyFactoryMapping>::New(env, pProxyFactoryMapping)});
}

IUIAutomationProxyFactoryMappingWrapper::IUIAutomationProxyFactoryMappingWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationProxyFactoryMappingWrapper>(info)
{
    if (info.Length() != 1)
    {
        throw Napi::TypeError::New(info.Env(), "IUIAutomationProxyFactoryMapping constructor is missing parameters.");
    }

    m_pProxyFactoryMapping = info[0].As<Napi::External<IUIAutomationProxyFactoryMapping>>().Data();
}