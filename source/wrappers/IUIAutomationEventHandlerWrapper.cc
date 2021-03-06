#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../Shared.h"
#include "../utilities/AutomationEventHandler.h"

Napi::FunctionReference *IUIAutomationEventHandlerWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationEventHandler", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    return constructor;
}

IUIAutomationEventHandlerWrapper::IUIAutomationEventHandlerWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>(info)
{
    if(!info[0].IsFunction())
    {
        throw Napi::Error::New(info.Env(), "First parameter must be a callback function.");
    }

    m_automationCallback = Napi::ThreadSafeFunction::New(info.Env(), info[0].As<Napi::Function>(), "IUIAutomationEventHandlerWrapper", 0, 1);

    m_pEventHandler = new AutomationEventHandler(m_automationCallback);
}

IUIAutomationEventHandlerWrapper::~IUIAutomationEventHandlerWrapper()
{
}


