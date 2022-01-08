#include "Wrappers.h"
#include "../AutomationAddon.h"

Napi::FunctionReference *RectWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&RectWrapper::GetBottom>("bottom"),
        InstanceAccessor<&RectWrapper::GetTop>("top"),
        InstanceAccessor<&RectWrapper::GetLeft>("left"),
        InstanceAccessor<&RectWrapper::GetRight>("right"),
    };

    Napi::Function function = DefineClass(env, "RECT", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value RectWrapper::New(Napi::Env env, RECT *pRECT)
{
    if (pRECT == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->RECTWrapperConstructor->New({Napi::External<RECT>::New(env, pRECT)});
}

RectWrapper::RectWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<RectWrapper>(info)
{
    if (info.Length() != 1)
    {
        throw Napi::TypeError::New(info.Env(), "RECT constructor is missing parameters.");
    }

    m_pRECT = *info[0].As<Napi::External<RECT>>().Data();
}

Napi::Value RectWrapper::GetBottom(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), m_pRECT.bottom);
}

Napi::Value RectWrapper::GetLeft(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), m_pRECT.left);
}

Napi::Value RectWrapper::GetRight(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), m_pRECT.right);
}

Napi::Value RectWrapper::GetTop(const Napi::CallbackInfo &info)
{
    return Napi::Number::New(info.Env(), m_pRECT.top);
}
