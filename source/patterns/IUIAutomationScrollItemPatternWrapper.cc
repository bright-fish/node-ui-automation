#include "IUIAutomationScrollItemPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationScrollItemPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationScrollItemPatternWrapper::ScrollIntoView>("scrollIntoView"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationScrollItemPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationScrollItemPatternWrapper::New(Napi::Env env, IUIAutomationScrollItemPattern *pScrollItemPattern)
{
    if (pScrollItemPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationScrollItemPatternWrapperConstructor->New({Napi::External<IUIAutomationScrollItemPattern>::New(env, pScrollItemPattern)});
}

IUIAutomationScrollItemPatternWrapper::IUIAutomationScrollItemPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationScrollItemPatternWrapper>(info)
{
    m_pIScrollItemProvider = info[0].As<Napi::External<IScrollItemProvider>>().Data();
}

IUIAutomationScrollItemPatternWrapper::~IUIAutomationScrollItemPatternWrapper()
{
    m_pIScrollItemProvider.Release();
}

void IUIAutomationScrollItemPatternWrapper::ScrollIntoView(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIScrollItemProvider->ScrollIntoView();

    HandleResult(info, hResult);
}