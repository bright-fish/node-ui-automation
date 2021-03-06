#pragma once

#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationTextChildPatternWrapper : public Napi::ObjectWrap<IUIAutomationTextChildPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTextChildPattern *pTextChildPattern);

    IUIAutomationTextChildPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTextChildPatternWrapper();

    Napi::Value GetTextContainer(const Napi::CallbackInfo &info);
    Napi::Value GetTextRange(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationTextChildPattern> m_textChildPattern = NULL;
};
