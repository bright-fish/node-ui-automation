#pragma once

#include "../Shared.h"
#include "../utilities/PropertyChangedEventHandler.h"

class IUIAutomationPropertyChangedEventHandlerWrapper : public Napi::ObjectWrap<IUIAutomationPropertyChangedEventHandlerWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);

    PropertyChangedEventHandler *m_pPropertyChangedEventHandler;
    Napi::ThreadSafeFunction m_pThreadSafeFunction;

    IUIAutomationPropertyChangedEventHandlerWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationPropertyChangedEventHandlerWrapper();
};
