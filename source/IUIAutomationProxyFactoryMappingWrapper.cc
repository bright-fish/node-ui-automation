#include "IUIAutomationProxyFactoryMappingWrapper.h"

using Napi::Object;
using Napi::Value;

Napi::Object IUIAutomationProxyFactoryMappingWrapper::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Function function = DefineClass(env, "IUIAutomationProxyFactoryMapping", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

IUIAutomationProxyFactoryMappingWrapper::IUIAutomationProxyFactoryMappingWrapper(const Napi::CallbackInfo &info, IUIAutomationProxyFactoryMapping *pProxyFactoryMapping) : IUIAutomationProxyFactoryMappingWrapper(info)
{
    m_pProxyFactoryMapping = pProxyFactoryMapping;
}

IUIAutomationProxyFactoryMappingWrapper::IUIAutomationProxyFactoryMappingWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationProxyFactoryMappingWrapper>(info)
{
}