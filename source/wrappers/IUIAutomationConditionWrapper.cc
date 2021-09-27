#include "Wrappers.h"
#include "../AutomationAddon.h"

Napi::FunctionReference *IUIAutomationConditionWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IUIAutomationCondition", {});

    auto functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IUIAutomationConditionWrapper::New(Napi::Env env, IUIAutomationCondition *pCondition)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationConditionWrapperConstructor->New({Napi::External<IUIAutomationCondition>::New(env, pCondition)});
}

IUIAutomationConditionWrapper::IUIAutomationConditionWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationConditionWrapper>(info)
{
    if (info.Length() != 1)
    {
        throw Napi::TypeError::New(info.Env(), "IUIAutomationCondition constructor missing parameter.");
    }

    m_pCondition = info[0].As<Napi::External<IUIAutomationCondition>>().Data();
}
