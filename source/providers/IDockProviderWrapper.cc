#include "IDockProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IDockProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IDockProviderWrapper::GetDockPosition>("dockPosition"),
        InstanceMethod<&IDockProviderWrapper::SetDockPosition>("setDockPosition"),
    };

    Napi::Function function = DefineClass(env, "IDockProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IDockProviderWrapper::New(Napi::Env env, IDockProvider *pDockProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IDockProviderWrapperConstructor->New({Napi::External<IDockProvider>::New(env, pDockProvider)});
}

IDockProviderWrapper::IDockProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IDockProviderWrapper>(info)
{
    m_pIDockProvider = info[0].As<Napi::External<IDockProvider>>().Data();
}

IDockProviderWrapper::~IDockProviderWrapper()
{
    m_pIDockProvider->Release();
}

Napi::Value IDockProviderWrapper::GetDockPosition(const Napi::CallbackInfo &info)
{
    DockPosition dockPosition;
    auto hResult = m_pIDockProvider->get_DockPosition(&dockPosition);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), dockPosition);
}

void IDockProviderWrapper::SetDockPosition(const Napi::CallbackInfo &info)
{
    auto dockPosition = static_cast<DockPosition>(info[0].ToNumber().Int32Value());

    auto hResult = m_pIDockProvider->SetDockPosition(dockPosition);

    HandleResult(info, hResult);
}