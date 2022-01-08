#include "IUIAutomationWindowPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "IUIAutomationTextRangeWrapper.h"

Napi::FunctionReference *IUIAutomationWindowPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCachedCanMaximize>("cachedCanMaximize"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCachedCanMinimize>("cachedCanMinimize"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCachedIsModal>("cachedIsModal"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCachedIsTopmost>("cachedIsTopmost"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCachedWindowInteractionState>("cachedWindowInteractionState"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCachedWindowVisualState>("cachedWindowVisualState"),

        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCurrentCanMaximize>("currentCanMaximize"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCurrentCanMinimize>("currentCanMinimize"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCurrentIsModal>("currentIsModal"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCurrentIsTopmost>("currentIsTopmost"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCurrentWindowInteractionState>("currentWindowInteractionState"),
        InstanceAccessor<&IUIAutomationWindowPatternWrapper::GetCurrentWindowVisualState>("currentWindowVisualState"),

        InstanceMethod<&IUIAutomationWindowPatternWrapper::Close>("close"),
        InstanceMethod<&IUIAutomationWindowPatternWrapper::SetWindowVisualState>("setWindowVisualState"),
        InstanceMethod<&IUIAutomationWindowPatternWrapper::WaitForInputIdle>("waitForInputIdle"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationWindowPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationWindowPatternWrapper::New(Napi::Env env, IUIAutomationWindowPattern *pWindowPattern)
{
    if (pWindowPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationWindowPatternWrapperConstructor->New({Napi::External<IUIAutomationWindowPattern>::New(env, pWindowPattern)});
}

IUIAutomationWindowPatternWrapper::IUIAutomationWindowPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationWindowPatternWrapper>(info)
{
    m_windowPattern = info[0].As<Napi::External<IUIAutomationWindowPattern>>().Data();
}

IUIAutomationWindowPatternWrapper::~IUIAutomationWindowPatternWrapper()
{
    m_windowPattern.Release();
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCachedCanMaximize(const Napi::CallbackInfo &info)
{
    BOOL canMaximize;
    auto hResult = m_windowPattern->get_CachedCanMaximize(&canMaximize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMaximize);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCachedCanMinimize(const Napi::CallbackInfo &info)
{
    BOOL canMinimize;

    auto hResult = m_windowPattern->get_CachedCanMinimize(&canMinimize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMinimize);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCachedIsModal(const Napi::CallbackInfo &info)
{
    BOOL isModal;

    auto hResult = m_windowPattern->get_CachedIsModal(&isModal);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isModal);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCachedIsTopmost(const Napi::CallbackInfo &info)
{
    BOOL isTopmost;

    auto hResult = m_windowPattern->get_CachedIsTopmost(&isTopmost);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isTopmost);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCachedWindowInteractionState(const Napi::CallbackInfo &info)
{
    WindowInteractionState windowInteractionState;

    auto hResult = m_windowPattern->get_CachedWindowInteractionState(&windowInteractionState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), windowInteractionState);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCachedWindowVisualState(const Napi::CallbackInfo &info)
{
    WindowVisualState windowVisualState;

    auto hResult = m_windowPattern->get_CachedWindowVisualState(&windowVisualState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), windowVisualState);
}


Napi::Value IUIAutomationWindowPatternWrapper::GetCurrentCanMaximize(const Napi::CallbackInfo &info)
{
    BOOL canMaximize;
    auto hResult = m_windowPattern->get_CurrentCanMaximize(&canMaximize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMaximize);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCurrentCanMinimize(const Napi::CallbackInfo &info)
{
    BOOL canMinimize;

    auto hResult = m_windowPattern->get_CurrentCanMinimize(&canMinimize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMinimize);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCurrentIsModal(const Napi::CallbackInfo &info)
{
    BOOL isModal;

    auto hResult = m_windowPattern->get_CurrentIsModal(&isModal);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isModal);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCurrentIsTopmost(const Napi::CallbackInfo &info)
{
    BOOL isTopmost;

    auto hResult = m_windowPattern->get_CurrentIsTopmost(&isTopmost);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isTopmost);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCurrentWindowInteractionState(const Napi::CallbackInfo &info)
{
    WindowInteractionState windowInteractionState;

    auto hResult = m_windowPattern->get_CurrentWindowInteractionState(&windowInteractionState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), windowInteractionState);
}

Napi::Value IUIAutomationWindowPatternWrapper::GetCurrentWindowVisualState(const Napi::CallbackInfo &info)
{
    WindowVisualState windowVisualState;

    auto hResult = m_windowPattern->get_CurrentWindowVisualState(&windowVisualState);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), windowVisualState);
}



void IUIAutomationWindowPatternWrapper::Close(const Napi::CallbackInfo &info)
{
    auto hResult = m_windowPattern->Close();

    HandleResult(info, hResult);
}

void IUIAutomationWindowPatternWrapper::SetWindowVisualState(const Napi::CallbackInfo &info)
{
    auto windowVisualState = static_cast<WindowVisualState>(info[0].ToNumber().Int32Value());

    auto hResult = m_windowPattern->SetWindowVisualState(windowVisualState);

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationWindowPatternWrapper::WaitForInputIdle(const Napi::CallbackInfo &info)
{
    auto milliseconds = info[0].ToNumber();

    BOOL output;
    auto hResult = m_windowPattern->WaitForInputIdle(milliseconds, &output);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), output);
}
