#include "IUIAutomationEventHandlerWrapper.h"
#include "../AutomationAddon.h"

Napi::FunctionReference *IUIAutomationEventHandlerWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationEventHandler", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    return constructor;
}

IUIAutomationEventHandlerWrapper::IUIAutomationEventHandlerWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>(info)
{
}

IUIAutomationEventHandlerWrapper::~IUIAutomationEventHandlerWrapper()
{
}