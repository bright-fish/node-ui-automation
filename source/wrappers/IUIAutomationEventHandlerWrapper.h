#pragma once

#include "../Shared.h"
#include "../utilities/GenericAutomationEventHandler.h"

class IUIAutomationEventHandlerWrapper : public Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);

    GenericAutomationEventHandler* m_pEventHandler;
    Napi::ThreadSafeFunction m_automationCallback;
    
    void HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID);

    IUIAutomationEventHandlerWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationEventHandlerWrapper();
};
