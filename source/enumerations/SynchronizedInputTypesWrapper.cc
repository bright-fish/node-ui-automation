#include "SynchronizedInputTypesWrapper.h"

Napi::Object SynchronizedInputTypesWrapper::New(Napi::Env env)
{
    auto synchronizedInputTypes = Napi::Object::New(env);

    synchronizedInputTypes.Set("KeyUp", Napi::Number::New(env, SynchronizedInputType::SynchronizedInputType_KeyUp));
    synchronizedInputTypes.Set("KeyDown", Napi::Number::New(env, SynchronizedInputType::SynchronizedInputType_KeyDown));
    synchronizedInputTypes.Set("LeftMouseUp", Napi::Number::New(env, SynchronizedInputType::SynchronizedInputType_LeftMouseUp));
    synchronizedInputTypes.Set("LeftMouseDown", Napi::Number::New(env, SynchronizedInputType::SynchronizedInputType_LeftMouseDown));
    synchronizedInputTypes.Set("RightMouseUp", Napi::Number::New(env, SynchronizedInputType::SynchronizedInputType_RightMouseUp));
    synchronizedInputTypes.Set("RightMouseDown", Napi::Number::New(env, SynchronizedInputType::SynchronizedInputType_RightMouseDown));

    return synchronizedInputTypes;
}
