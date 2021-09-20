
#include "Library.h"

Napi::Object IUIAutomationConditionWrapper::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Function function = DefineClass(env, "IUIAutomationCondition", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

IUIAutomationConditionWrapper::IUIAutomationConditionWrapper(const Napi::CallbackInfo &info, IUIAutomationCondition *pCondition) : IUIAutomationConditionWrapper(info)
{
    m_pCondition = pCondition;
}

IUIAutomationConditionWrapper::IUIAutomationConditionWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationConditionWrapper>(info)
{
}
