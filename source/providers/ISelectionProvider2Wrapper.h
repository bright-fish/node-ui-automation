#pragma once
#include "../Shared.h"

class ISelectionProvider2Wrapper : public Napi::ObjectWrap<ISelectionProvider2Wrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, ISelectionProvider2 *pISelectionProvider2);

    ISelectionProvider2Wrapper(const Napi::CallbackInfo &info);
    ~ISelectionProvider2Wrapper();

    Napi::Value GetCanSelectMultiple(const Napi::CallbackInfo &info);
    Napi::Value GetIsSelectionRequired(const Napi::CallbackInfo &info);
    Napi::Value GetCurrentSelectedItem(const Napi::CallbackInfo &info);
    Napi::Value GetFirstSelectedItem(const Napi::CallbackInfo &info);
    Napi::Value GetItemCount(const Napi::CallbackInfo &info);
    Napi::Value GetLastSelectedItem(const Napi::CallbackInfo &info);

    Napi::Value GetSelection(const Napi::CallbackInfo &info);

private:
    ISelectionProvider2 *m_pISelectionProvider2;
};
