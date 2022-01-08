#include "IUIAutomationVirtualizedItemPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationVirtualizedItemPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationVirtualizedItemPatternWrapper::Realize>("realize"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationVirtualizedItemPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationVirtualizedItemPatternWrapper::New(Napi::Env env, IUIAutomationVirtualizedItemPattern *pVirtualizedItemPattern)
{
    if (pVirtualizedItemPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationVirtualizedItemPatternWrapperConstructor->New({Napi::External<IUIAutomationVirtualizedItemPattern>::New(env, pVirtualizedItemPattern)});
}

IUIAutomationVirtualizedItemPatternWrapper::IUIAutomationVirtualizedItemPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationVirtualizedItemPatternWrapper>(info)
{
    m_virtualizedItemPattern = info[0].As<Napi::External<IUIAutomationVirtualizedItemPattern>>().Data();
}

IUIAutomationVirtualizedItemPatternWrapper::~IUIAutomationVirtualizedItemPatternWrapper()
{
    m_virtualizedItemPattern.Release();
}

void IUIAutomationVirtualizedItemPatternWrapper::Realize(const Napi::CallbackInfo &info)
{
    auto hResult = m_virtualizedItemPattern->Realize();

    HandleResult(info, hResult);
}