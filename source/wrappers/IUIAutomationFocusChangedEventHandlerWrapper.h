#pragma once

#include "../Shared.h"
#include "../utilities/FocusChangedEventHandler.h"

class IUIAutomationFocusChangedEventHandlerWrapper : public Napi::ObjectWrap<IUIAutomationFocusChangedEventHandlerWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);

    FocusChangedEventHandler *m_pFocusChangedEventHandler;
    Napi::ThreadSafeFunction m_pThreadSafeFunction;

    IUIAutomationFocusChangedEventHandlerWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationFocusChangedEventHandlerWrapper();
};
