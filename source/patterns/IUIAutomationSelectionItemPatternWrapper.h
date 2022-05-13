#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationSelectionItemPatternWrapper : public Napi::ObjectWrap<IUIAutomationSelectionItemPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationSelectionItemPattern *pSelectionItemPattern);

    IUIAutomationSelectionItemPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationSelectionItemPatternWrapper();

    Napi::Value GetCachedIsSelected(const Napi::CallbackInfo &info);
    Napi::Value GetCachedSelectionContainer(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentIsSelected(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentSelectionContainer(const Napi::CallbackInfo &info);

    void AddToSelection(const Napi::CallbackInfo &info);
    void RemoveFromSelection(const Napi::CallbackInfo &info);
    void Select(const Napi::CallbackInfo &info);

private:
    ComAutoPointer<IUIAutomationSelectionItemPattern> m_selectionItemPattern = NULL;
};
