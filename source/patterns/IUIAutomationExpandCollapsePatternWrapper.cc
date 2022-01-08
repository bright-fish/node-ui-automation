#include "IUIAutomationExpandCollapsePatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationExpandCollapsePatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationExpandCollapsePatternWrapper::GetCachedExpandCollapseState>("cachedExpandCollapseState"),
        InstanceAccessor<&IUIAutomationExpandCollapsePatternWrapper::GetCurrentExpandCollapseState>("currentExpandCollapseState"),

        InstanceMethod<&IUIAutomationExpandCollapsePatternWrapper::Collapse>("collapse"),
        InstanceMethod<&IUIAutomationExpandCollapsePatternWrapper::Expand>("expand"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationExpandCollapsePattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationExpandCollapsePatternWrapper::New(Napi::Env env, IUIAutomationExpandCollapsePattern *pExpandCollapsePattern)
{
    if (pExpandCollapsePattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationExpandCollapsePatternWrapperConstructor->New({Napi::External<IUIAutomationExpandCollapsePattern>::New(env, pExpandCollapsePattern)});
}

IUIAutomationExpandCollapsePatternWrapper::IUIAutomationExpandCollapsePatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationExpandCollapsePatternWrapper>(info)
{
    m_expandCollapsePattern = info[0].As<Napi::External<IUIAutomationExpandCollapsePattern>>().Data();
}

IUIAutomationExpandCollapsePatternWrapper::~IUIAutomationExpandCollapsePatternWrapper()
{
    m_expandCollapsePattern.Release();
}

Napi::Value IUIAutomationExpandCollapsePatternWrapper::GetCachedExpandCollapseState(const Napi::CallbackInfo &info)
{
    ExpandCollapseState expandCollapseState;
    auto hResult = m_expandCollapsePattern->get_CachedExpandCollapseState(&expandCollapseState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), expandCollapseState);
}

Napi::Value IUIAutomationExpandCollapsePatternWrapper::GetCurrentExpandCollapseState(const Napi::CallbackInfo &info)
{
    ExpandCollapseState expandCollapseState;
    auto hResult = m_expandCollapsePattern->get_CurrentExpandCollapseState(&expandCollapseState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), expandCollapseState);
}

void IUIAutomationExpandCollapsePatternWrapper::Collapse(const Napi::CallbackInfo &info)
{
    auto hResult = m_expandCollapsePattern->Collapse();

    HandleResult(info, hResult);
}

void IUIAutomationExpandCollapsePatternWrapper::Expand(const Napi::CallbackInfo &info)
{
    auto hResult = m_expandCollapsePattern->Expand();

    HandleResult(info, hResult);
}
