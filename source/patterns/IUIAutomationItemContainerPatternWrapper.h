#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationItemContainerPatternWrapper : public Napi::ObjectWrap<IUIAutomationItemContainerPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationItemContainerPattern *pIItemContainerProvider);

    IUIAutomationItemContainerPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationItemContainerPatternWrapper();

    Napi::Value FindItemByProperty(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationItemContainerPattern> m_itemContainerPattern = NULL;
};
