#include "IExpandCollapseProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IExpandCollapseProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IExpandCollapseProviderWrapper::GetExpandCollapseState>("expandCollapseState"),
        InstanceMethod<&IExpandCollapseProviderWrapper::Collapse>("collapse"),
        InstanceMethod<&IExpandCollapseProviderWrapper::Expand>("expand"),
    };

    Napi::Function function = DefineClass(env, "IExpandCollapseProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IExpandCollapseProviderWrapper::New(Napi::Env env, IExpandCollapseProvider *pIExpandCollapseProvider)
{
    if (pIExpandCollapseProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IExpandCollapseProviderWrapperConstructor->New({Napi::External<IExpandCollapseProvider>::New(env, pIExpandCollapseProvider)});
}

IExpandCollapseProviderWrapper::IExpandCollapseProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IExpandCollapseProviderWrapper>(info)
{
    m_pIExpandCollapseProvider = info[0].As<Napi::External<IExpandCollapseProvider>>().Data();
}

IExpandCollapseProviderWrapper::~IExpandCollapseProviderWrapper()
{
    m_pIExpandCollapseProvider->Release();
}

Napi::Value IExpandCollapseProviderWrapper::GetExpandCollapseState(const Napi::CallbackInfo &info)
{
    ExpandCollapseState expandCollapseState;
    auto hResult = m_pIExpandCollapseProvider->get_ExpandCollapseState(&expandCollapseState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), expandCollapseState);
}

void IExpandCollapseProviderWrapper::Collapse(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIExpandCollapseProvider->Collapse();

    HandleResult(info, hResult);
}

void IExpandCollapseProviderWrapper::Expand(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIExpandCollapseProvider->Expand();

    HandleResult(info, hResult);
}
