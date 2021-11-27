#pragma once
#include "../Shared.h"

class IWindowProviderWrapper : public Napi::ObjectWrap<IWindowProviderWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IWindowProvider *pIWindowProvider);

    IWindowProviderWrapper(const Napi::CallbackInfo &info);
    ~IWindowProviderWrapper();

    Napi::Value GetCanMaximize(const Napi::CallbackInfo &info);
    Napi::Value GetCanMinimize(const Napi::CallbackInfo &info);
    Napi::Value GetIsModal(const Napi::CallbackInfo &info);
    Napi::Value GetIsTopmost(const Napi::CallbackInfo &info);
    Napi::Value GetWindowInteractionState(const Napi::CallbackInfo &info);
    Napi::Value GetWindowVisualState(const Napi::CallbackInfo &info);

    void Close(const Napi::CallbackInfo &info);
    void SetVisualState(const Napi::CallbackInfo &info);
    Napi::Value WaitForInputIdle(const Napi::CallbackInfo &info);
    
private:
    IWindowProvider *m_pIWindowProvider;
};
