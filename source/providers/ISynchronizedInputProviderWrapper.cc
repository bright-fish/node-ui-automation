#include "ISynchronizedInputProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *ISynchronizedInputProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&ISynchronizedInputProviderWrapper::Cancel>("cancel"),
        InstanceMethod<&ISynchronizedInputProviderWrapper::StartListening>("startListening"),

    };

    Napi::Function function = DefineClass(env, "ISynchronizedInputProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ISynchronizedInputProviderWrapper::New(Napi::Env env, ISynchronizedInputProvider *pISynchronizedInputProvider)
{
    if (pISynchronizedInputProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ISynchronizedInputProviderWrapperConstructor->New({Napi::External<ISynchronizedInputProvider>::New(env, pISynchronizedInputProvider)});
}

ISynchronizedInputProviderWrapper::ISynchronizedInputProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ISynchronizedInputProviderWrapper>(info)
{
    m_pISynchronizedInputProvider = info[0].As<Napi::External<ISynchronizedInputProvider>>().Data();
}

ISynchronizedInputProviderWrapper::~ISynchronizedInputProviderWrapper()
{
    m_pISynchronizedInputProvider->Release();
}

void ISynchronizedInputProviderWrapper::Cancel(const Napi::CallbackInfo &info)
{
    auto hResult = m_pISynchronizedInputProvider->Cancel();

    HandleResult(info, hResult);
}

void ISynchronizedInputProviderWrapper::StartListening(const Napi::CallbackInfo &info)
{
    SynchronizedInputType synchronizedInputType = static_cast<SynchronizedInputType>(info[0].ToNumber().Int32Value());

    auto hResult = m_pISynchronizedInputProvider->StartListening(synchronizedInputType);

    HandleResult(info, hResult);
}