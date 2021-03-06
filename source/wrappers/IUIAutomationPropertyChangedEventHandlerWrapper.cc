
#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../Shared.h"

Napi::FunctionReference *IUIAutomationPropertyChangedEventHandlerWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationPropertyChangedEventHandler", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    return constructor;
}

IUIAutomationPropertyChangedEventHandlerWrapper::IUIAutomationPropertyChangedEventHandlerWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationPropertyChangedEventHandlerWrapper>(info)
{
    if(!info[0].IsFunction())
    {
        throw Napi::Error::New(info.Env(), "First parameter must be a callback function.");
    }

    m_pThreadSafeFunction = Napi::ThreadSafeFunction::New(info.Env(), info[0].As<Napi::Function>(), "IUIAutomationPropertyChangedEventHandlerWrapper", 0, 1);
    
    m_pPropertyChangedEventHandler = new PropertyChangedEventHandler(m_pThreadSafeFunction);
}

IUIAutomationPropertyChangedEventHandlerWrapper::~IUIAutomationPropertyChangedEventHandlerWrapper()
{
}
