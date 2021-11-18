#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../Shared.h"

Napi::FunctionReference *IUIAutomationFocusChangedEventHandlerWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationFocusChangedEventHandler", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    return constructor;
}

IUIAutomationFocusChangedEventHandlerWrapper::IUIAutomationFocusChangedEventHandlerWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationFocusChangedEventHandlerWrapper>(info)
{
    if(!info[0].IsFunction())
    {
        throw Napi::Error::New(info.Env(), "First parameter must be a callback function.");
    }

    m_pThreadSafeFunction = Napi::ThreadSafeFunction::New(info.Env(), info[0].As<Napi::Function>(), "IUIAutomationFocusChangedEventHandlerWrapper", 0, 1);
    m_pFocusChangedEventHandler = new FocusChangedEventHandler(m_pThreadSafeFunction);
}

IUIAutomationFocusChangedEventHandlerWrapper::~IUIAutomationFocusChangedEventHandlerWrapper()
{

}
