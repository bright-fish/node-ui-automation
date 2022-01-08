#include "IUIAutomationTogglePatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationTogglePatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTogglePatternWrapper::GetCachedToggleState>("cachedToggleState"),
        InstanceAccessor<&IUIAutomationTogglePatternWrapper::GetCurrentToggleState>("currentToggleState"),

        InstanceMethod<&IUIAutomationTogglePatternWrapper::Toggle>("toggle"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTogglePattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTogglePatternWrapper::New(Napi::Env env, IUIAutomationTogglePattern *pTogglePattern)
{
    if (pTogglePattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTogglePatternWrapperConstructor->New({Napi::External<IUIAutomationTogglePattern>::New(env, pTogglePattern)});
}

IUIAutomationTogglePatternWrapper::IUIAutomationTogglePatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTogglePatternWrapper>(info)
{
    m_togglePattern = info[0].As<Napi::External<IUIAutomationTogglePattern>>().Data();
}

IUIAutomationTogglePatternWrapper::~IUIAutomationTogglePatternWrapper()
{
    m_togglePattern.Release();
}

Napi::Value IUIAutomationTogglePatternWrapper::GetCachedToggleState(const Napi::CallbackInfo &info)
{
    ToggleState toggleState;
    auto hResult = m_togglePattern->get_CachedToggleState(&toggleState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), toggleState);
}

Napi::Value IUIAutomationTogglePatternWrapper::GetCurrentToggleState(const Napi::CallbackInfo &info)
{
    ToggleState toggleState;
    auto hResult = m_togglePattern->get_CurrentToggleState(&toggleState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), toggleState);
}

void IUIAutomationTogglePatternWrapper::Toggle(const Napi::CallbackInfo &info)
{
    auto hResult = m_togglePattern->Toggle();

    HandleResult(info, hResult);
}
