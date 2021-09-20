#include "IUIAutomationCacheRequestWrapper.h"

IUIAutomationCacheRequestWrapper::IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info, IUIAutomationCacheRequest *pCacheRequest) : IUIAutomationCacheRequestWrapper(info)
{
    m_pCacheRequest = pCacheRequest;
}

IUIAutomationCacheRequestWrapper::IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>(info)
{
}


Napi::Object IUIAutomationCacheRequestWrapper::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Function function = DefineClass(env, "IUIAutomationCacheRequest", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}
