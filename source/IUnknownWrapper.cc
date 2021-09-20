#include "Library.h"

using Napi::Object;
using Napi::Value;

IUnknownWrapper::IUnknownWrapper(const Napi::CallbackInfo &info, IUnknown *pIUnknown) : IUnknownWrapper(info)
{
    m_pIUnknown = pIUnknown;
}

IUnknownWrapper::IUnknownWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUnknownWrapper>(info)
{
}

Napi::Object IUnknownWrapper::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Function function = DefineClass(env, "IUnknown", {});

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}
