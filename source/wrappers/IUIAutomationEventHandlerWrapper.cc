#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../Shared.h"

Napi::FunctionReference *IUIAutomationEventHandlerWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationEventHandler", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    return constructor;
}

IUIAutomationEventHandlerWrapper::IUIAutomationEventHandlerWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>(info)
{
    // todo: needs some guards to validate input is a function.

    m_automationCallback = Napi::ThreadSafeFunction::New(info.Env(), info[0].As<Napi::Function>(), "IUIAutomationEventHandlerWrapper", 0, 1);

    m_pEventHandler = new GenericAutomationEventHandler();
    auto lambda = [&](IUIAutomationElement *pSender, EVENTID eventID)
    {
        this->HandleAutomationEvent(pSender, eventID);
    };

    m_pEventHandler->SetCallback(lambda);
}

IUIAutomationEventHandlerWrapper::~IUIAutomationEventHandlerWrapper()
{
}

struct AutomationEvent
{
    IUIAutomationElement *pSender;
    EVENTID eventID;
};

void IUIAutomationEventHandlerWrapper::HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID)
{
    AutomationEvent automationEvent;
    automationEvent.pSender = pSender;
    automationEvent.eventID = eventID;

    auto internalCallback = [&](Napi::Env env, Napi::Function function, AutomationEvent *event)
    {
        function.Call({
            IUIAutomationElementWrapper::New(env, event->pSender),
            Napi::Number::New(env, event->eventID),
        });
    };

    auto status = m_automationCallback.BlockingCall(&automationEvent, internalCallback);

    // todo: Error handle here.
}