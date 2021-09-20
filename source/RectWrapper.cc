#include "RectWrapper.h"

Napi::Object RectWrapper::Init(Napi::Env env, Napi::Object exports)
{
    auto classDefinition = {
        InstanceAccessor<&RectWrapper::GetBottom>("bottom"),
        InstanceAccessor<&RectWrapper::GetTop>("top"),
        InstanceAccessor<&RectWrapper::GetLeft>("left"),
        InstanceAccessor<&RectWrapper::GetRight>("right"),
    };

    Napi::Function function = DefineClass(env, "RECT", classDefinition);

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

RectWrapper::RectWrapper(const Napi::CallbackInfo &info, RECT *pRECT) : RectWrapper(info)
{
    m_pRECT = *pRECT;
}

RectWrapper::RectWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<RectWrapper>(info)
{
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

