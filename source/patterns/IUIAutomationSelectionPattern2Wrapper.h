#pragma once
#include "../Shared.h"

class IUIAutomationSelectionPattern2Wrapper : public Napi::ObjectWrap<IUIAutomationSelectionPattern2Wrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationSelectionPattern2 *pSelectionPattern2);

    IUIAutomationSelectionPattern2Wrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationSelectionPattern2Wrapper();

    Napi::Value GetCachedCanSelectMultiple(const Napi::CallbackInfo &info);
    Napi::Value GetCachedIsSelectionRequired(const Napi::CallbackInfo &info);
    Napi::Value GetCachedCurrentSelectedItem(const Napi::CallbackInfo &info);
    Napi::Value GetCachedFirstSelectedItem(const Napi::CallbackInfo &info);
    Napi::Value GetCachedItemCount(const Napi::CallbackInfo &info);
    Napi::Value GetCachedLastSelectedItem(const Napi::CallbackInfo &info);

    Napi::Value GetCurrentCanSelectMultiple(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentIsSelectionRequired(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentCurrentSelectedItem(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentFirstSelectedItem(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentItemCount(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentLastSelectedItem(const Napi::CallbackInfo &info);

    Napi::Value GetCachedSelection(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentSelection(const Napi::CallbackInfo &info);

private:
    ATL::CComPtr<IUIAutomationSelectionPattern2> m_selectionPattern2;
};
