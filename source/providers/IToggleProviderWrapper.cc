#include "IToggleProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IToggleProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IToggleProviderWrapper::GetToggleState>("toggleState"),

        InstanceMethod<&IToggleProviderWrapper::Toggle>("toggle"),
    };

    Napi::Function function = DefineClass(env, "IToggleProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IToggleProviderWrapper::New(Napi::Env env, IToggleProvider *pIToggleProvider)
{
    if (pIToggleProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IToggleProviderWrapperConstructor->New({Napi::External<IToggleProvider>::New(env, pIToggleProvider)});
}

IToggleProviderWrapper::IToggleProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IToggleProviderWrapper>(info)
{
    m_pIToggleProvider = info[0].As<Napi::External<IToggleProvider>>().Data();
}

IToggleProviderWrapper::~IToggleProviderWrapper()
{
    m_pIToggleProvider->Release();
}

Napi::Value IToggleProviderWrapper::GetToggleState(const Napi::CallbackInfo &info)
{
    ToggleState toggleState;
    auto hResult = m_pIToggleProvider->get_ToggleState(&toggleState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), toggleState);
}

void IToggleProviderWrapper::Toggle(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIToggleProvider->Toggle();

    HandleResult(info, hResult);
}
