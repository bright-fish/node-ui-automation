#include "IInvokeProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IInvokeProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod("invoke", &IInvokeProviderWrapper::Invoke),
    };

    Napi::Function function = DefineClass(env, "IInvokeProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IInvokeProviderWrapper::New(Napi::Env env, IInvokeProvider *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IInvokeProviderWrapperConstructor->New({Napi::External<IInvokeProvider>::New(env, pInvokeProvider)});
}

IInvokeProviderWrapper::IInvokeProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IInvokeProviderWrapper>(info)
{
    m_pIInvokeProvider = info[0].As<Napi::External<IInvokeProvider>>().Data();
}

IInvokeProviderWrapper::~IInvokeProviderWrapper()
{
    m_pIInvokeProvider->Release();
}

void IInvokeProviderWrapper::Invoke(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIInvokeProvider->Invoke();

    HandleResult(info, hResult);
}