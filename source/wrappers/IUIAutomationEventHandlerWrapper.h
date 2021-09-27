#pragma once

#include "../Shared.h"

class IUIAutomationEventHandlerWrapper : public Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);

    IUIAutomationEventHandlerWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationEventHandlerWrapper();
};
