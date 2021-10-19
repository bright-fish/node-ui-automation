#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../Shared.h"
#include "../utilities/StructureChangedEventHandler.h"

Napi::FunctionReference *IUIAutomationStructureChangedEventHandlerWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationStructureChangedEventHandlerWrapper", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    return constructor;
}

IUIAutomationStructureChangedEventHandlerWrapper::IUIAutomationStructureChangedEventHandlerWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationStructureChangedEventHandlerWrapper>(info)
{
    // todo: needs some guards to validate input is a function.

    m_automationCallback = Napi::ThreadSafeFunction::New(info.Env(), info[0].As<Napi::Function>(), "IUIAutomationStructureChangedEventHandlerWrapper", 0, 1);

    m_pStructureChangedEventHandler = new StructureChangedEventHandler(m_automationCallback);
}

IUIAutomationStructureChangedEventHandlerWrapper::~IUIAutomationStructureChangedEventHandlerWrapper()
{
}


