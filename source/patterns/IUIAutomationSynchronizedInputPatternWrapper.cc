#include "IUIAutomationSynchronizedInputPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationSynchronizedInputPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationSynchronizedInputPatternWrapper::Cancel>("cancel"),
        InstanceMethod<&IUIAutomationSynchronizedInputPatternWrapper::StartListening>("startListening"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationSynchronizedInputPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationSynchronizedInputPatternWrapper::New(Napi::Env env, IUIAutomationSynchronizedInputPattern *pISynchronizedInputProvider)
{
    if (pISynchronizedInputProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationSynchronizedInputPatternWrapperConstructor->New({Napi::External<IUIAutomationSynchronizedInputPattern>::New(env, pISynchronizedInputProvider)});
}

IUIAutomationSynchronizedInputPatternWrapper::IUIAutomationSynchronizedInputPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationSynchronizedInputPatternWrapper>(info)
{
    m_synchronizedInputPattern = info[0].As<Napi::External<IUIAutomationSynchronizedInputPattern>>().Data();
}

IUIAutomationSynchronizedInputPatternWrapper::~IUIAutomationSynchronizedInputPatternWrapper()
{
    m_synchronizedInputPattern.Release();
}

void IUIAutomationSynchronizedInputPatternWrapper::Cancel(const Napi::CallbackInfo &info)
{
    auto hResult = m_synchronizedInputPattern->Cancel();

    HandleResult(info, hResult);
}

void IUIAutomationSynchronizedInputPatternWrapper::StartListening(const Napi::CallbackInfo &info)
{
    SynchronizedInputType synchronizedInputType = static_cast<SynchronizedInputType>(info[0].ToNumber().Int32Value());

    auto hResult = m_synchronizedInputPattern->StartListening(synchronizedInputType);

    HandleResult(info, hResult);
}