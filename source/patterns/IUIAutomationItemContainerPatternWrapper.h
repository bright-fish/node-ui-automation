#pragma once
#include "../Shared.h"

class IUIAutomationItemContainerPatternWrapper : public Napi::ObjectWrap<IUIAutomationItemContainerPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationItemContainerPattern *pIItemContainerProvider);

    IUIAutomationItemContainerPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationItemContainerPatternWrapper();

    Napi::Value FindItemByProperty(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationItemContainerPattern> m_itemContainerPattern = NULL;
};
