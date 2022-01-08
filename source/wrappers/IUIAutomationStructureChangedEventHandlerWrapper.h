#pragma once

#include "../Shared.h"
#include "../utilities/AutomationEventHandler.h"

class IUIAutomationStructureChangedEventHandlerWrapper : public Napi::ObjectWrap<IUIAutomationStructureChangedEventHandlerWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);

    IUIAutomationStructureChangedEventHandler *m_pStructureChangedEventHandler;
    Napi::ThreadSafeFunction m_automationCallback;

    void HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID);

    IUIAutomationStructureChangedEventHandlerWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationStructureChangedEventHandlerWrapper();
};
