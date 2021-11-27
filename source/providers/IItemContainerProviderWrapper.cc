#include "IItemContainerProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IItemContainerProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IItemContainerProviderWrapper::FindItemByProperty>("findItemByProperty"),
    };

    Napi::Function function = DefineClass(env, "IItemContainerProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IItemContainerProviderWrapper::New(Napi::Env env, IItemContainerProvider *pItemContainerProvider)
{
    if (pItemContainerProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IItemContainerProviderWrapperConstructor->New({Napi::External<IItemContainerProvider>::New(env, pItemContainerProvider)});
}

IItemContainerProviderWrapper::IItemContainerProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IItemContainerProviderWrapper>(info)
{
    m_pIItemContainerProvider = info[0].As<Napi::External<IItemContainerProvider>>().Data();
}

IItemContainerProviderWrapper::~IItemContainerProviderWrapper()
{
    m_pIItemContainerProvider->Release();
}

Napi::Value IItemContainerProviderWrapper::FindItemByProperty(const Napi::CallbackInfo &info)
{
    auto pStartAfterWrapper = Napi::ObjectWrap<IRawElementProviderSimpleWrapper>::Unwrap(info[0].ToObject());

    auto propertyId = static_cast<PROPERTYID>(info[1].ToNumber().Int32Value());

    auto variant = ToVariant(info.Env(), info[2]);

    IRawElementProviderSimple *pFound;
    auto hResult = m_pIItemContainerProvider->FindItemByProperty(pStartAfterWrapper->m_pRawElementProviderSimple, propertyId, variant, &pFound);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pFound);
}