#include "IWindowProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
#include "ITextRangeProviderWrapper.h"

Napi::FunctionReference *IWindowProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IWindowProviderWrapper::GetCanMaximize>("canMaximize"),
        InstanceAccessor<&IWindowProviderWrapper::GetCanMinimize>("canMinimize"),
        InstanceAccessor<&IWindowProviderWrapper::GetIsModal>("isModal"),
        InstanceAccessor<&IWindowProviderWrapper::GetIsTopmost>("isTopmost"),
        InstanceAccessor<&IWindowProviderWrapper::GetWindowInteractionState>("windowInteractionState"),
        InstanceAccessor<&IWindowProviderWrapper::GetWindowVisualState>("windowVisualState"),

        InstanceMethod<&IWindowProviderWrapper::Close>("close"),
        InstanceMethod<&IWindowProviderWrapper::SetVisualState>("setVisualState"),
        InstanceMethod<&IWindowProviderWrapper::WaitForInputIdle>("waitForInputIdle"),
    };

    Napi::Function function = DefineClass(env, "IWindowProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IWindowProviderWrapper::New(Napi::Env env, IWindowProvider *pIWindowProvider)
{
    if (pIWindowProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IWindowProviderWrapperConstructor->New({Napi::External<IWindowProvider>::New(env, pIWindowProvider)});
}

IWindowProviderWrapper::IWindowProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IWindowProviderWrapper>(info)
{
    m_pIWindowProvider = info[0].As<Napi::External<IWindowProvider>>().Data();
}

IWindowProviderWrapper::~IWindowProviderWrapper()
{
    m_pIWindowProvider->Release();
}

Napi::Value IWindowProviderWrapper::GetCanMaximize(const Napi::CallbackInfo &info)
{
    BOOL canMaximize;
    auto hResult = m_pIWindowProvider->get_CanMaximize(&canMaximize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMaximize);
}

Napi::Value IWindowProviderWrapper::GetCanMinimize(const Napi::CallbackInfo &info)
{
    BOOL canMinimize;

    auto hResult = m_pIWindowProvider->get_CanMinimize(&canMinimize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMinimize);
}

Napi::Value IWindowProviderWrapper::GetIsModal(const Napi::CallbackInfo &info)
{
    BOOL isModal;

    auto hResult = m_pIWindowProvider->get_IsModal(&isModal);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isModal);
}

Napi::Value IWindowProviderWrapper::GetIsTopmost(const Napi::CallbackInfo &info)
{
    BOOL isTopmost;

    auto hResult = m_pIWindowProvider->get_IsTopmost(&isTopmost);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isTopmost);
}

Napi::Value IWindowProviderWrapper::GetWindowInteractionState(const Napi::CallbackInfo &info)
{
    WindowInteractionState windowInteractionState;

    auto hResult = m_pIWindowProvider->get_WindowInteractionState(&windowInteractionState);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), windowInteractionState);
}

Napi::Value IWindowProviderWrapper::GetWindowVisualState(const Napi::CallbackInfo &info)
{
    WindowVisualState windowVisualState;

    auto hResult = m_pIWindowProvider->get_WindowVisualState(&windowVisualState);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), windowVisualState);
}

void IWindowProviderWrapper::Close(const Napi::CallbackInfo &info)
{
    auto hResult = m_pIWindowProvider->Close();

    HandleResult(info, hResult);
}

void IWindowProviderWrapper::SetVisualState(const Napi::CallbackInfo &info)
{
    auto windowVisualState = static_cast<WindowVisualState>(info[0].ToNumber().Int32Value());

    auto hResult = m_pIWindowProvider->SetVisualState(windowVisualState);

    HandleResult(info, hResult);
}

Napi::Value IWindowProviderWrapper::WaitForInputIdle(const Napi::CallbackInfo &info)
{
    auto milliseconds = info[0].ToNumber();

    BOOL output;
    auto hResult = m_pIWindowProvider->WaitForInputIdle(milliseconds, &output);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), output);
}
