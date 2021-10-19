#pragma once

#include "../Shared.h"
#include "../utilities/AutomationEventHandler.h"

class IUIAutomationEventHandlerWrapper : public Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);

    AutomationEventHandler* m_pEventHandler;
    Napi::ThreadSafeFunction m_automationCallback;
    
    IUIAutomationEventHandlerWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationEventHandlerWrapper();
};
