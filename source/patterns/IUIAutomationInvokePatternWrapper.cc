#include "IUIAutomationInvokePatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationInvokePatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationInvokePatternWrapper::Invoke>("invoke"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationInvokePattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationInvokePatternWrapper::New(Napi::Env env, IUIAutomationInvokePattern *pInvokePattern)
{
    if (pInvokePattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationInvokePatternWrapperConstructor->New({Napi::External<IUIAutomationInvokePattern>::New(env, pInvokePattern)});
}

IUIAutomationInvokePatternWrapper::IUIAutomationInvokePatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationInvokePatternWrapper>(info)
{
    m_invokePattern = info[0].As<Napi::External<IUIAutomationInvokePattern>>().Data();
}

IUIAutomationInvokePatternWrapper::~IUIAutomationInvokePatternWrapper()
{
    m_invokePattern.Release();
}

void IUIAutomationInvokePatternWrapper::Invoke(const Napi::CallbackInfo &info)
{
    auto hResult = m_invokePattern->Invoke();

    HandleResult(info, hResult);
}