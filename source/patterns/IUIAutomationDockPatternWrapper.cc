#include "IUIAutomationDockPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationDockPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationDockPatternWrapper::GetCachedDockPosition>("cachedDockPosition"),
        InstanceAccessor<&IUIAutomationDockPatternWrapper::GetCurrentDockPosition>("currentDockPosition"),

        InstanceMethod<&IUIAutomationDockPatternWrapper::SetDockPosition>("setDockPosition"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationDockPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationDockPatternWrapper::New(Napi::Env env, IUIAutomationDockPattern *pDockPattern)
{
    if (pDockPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationDockPatternWrapperConstructor->New({Napi::External<IUIAutomationDockPattern>::New(env, pDockPattern)});
}

IUIAutomationDockPatternWrapper::IUIAutomationDockPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationDockPatternWrapper>(info)
{
    m_dockPattern = info[0].As<Napi::External<IUIAutomationDockPattern>>().Data();
}

IUIAutomationDockPatternWrapper::~IUIAutomationDockPatternWrapper()
{
    m_dockPattern.Release();
}

Napi::Value IUIAutomationDockPatternWrapper::GetCachedDockPosition(const Napi::CallbackInfo &info)
{
    DockPosition dockPosition;
    auto hResult = m_dockPattern->get_CachedDockPosition(&dockPosition);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), dockPosition);
}

Napi::Value IUIAutomationDockPatternWrapper::GetCurrentDockPosition(const Napi::CallbackInfo &info)
{
    DockPosition dockPosition;
    auto hResult = m_dockPattern->get_CurrentDockPosition(&dockPosition);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), dockPosition);
}

void IUIAutomationDockPatternWrapper::SetDockPosition(const Napi::CallbackInfo &info)
{
    auto dockPosition = static_cast<DockPosition>(info[0].ToNumber().Int32Value());

    auto hResult = m_dockPattern->SetDockPosition(dockPosition);

    HandleResult(info, hResult);
}