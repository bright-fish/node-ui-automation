#include "Library.h"

Napi::FunctionReference *IUIAutomationCacheRequestWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationCacheRequest", {});

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IUIAutomationCacheRequestWrapper::New(Napi::Env env, IUIAutomationCacheRequest *pCacheRequest)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationCacheRequestWrapperConstructor->New({Napi::External<IUIAutomationCacheRequest>::New(env, pCacheRequest)});
}

IUIAutomationCacheRequestWrapper::IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>(info)
{
    if (info.Length() != 1)
    {
        throw Napi::TypeError::New(info.Env(), "IUIAutomationCacheRequest constructor missing parameter.");
    }

    m_pCacheRequest = info[0].As<Napi::External<IUIAutomationCacheRequest>>().Data();
}
