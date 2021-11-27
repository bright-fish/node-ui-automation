#include "OrientationTypesWrapper.h"

Napi::Object OrientationTypesWrapper::New(Napi::Env env)
{
    auto orientationTypes = Napi::Object::New(env);

    orientationTypes.Set("None", Napi::Number::New(env, OrientationType::OrientationType_None));
    orientationTypes.Set("Horizontal", Napi::Number::New(env, OrientationType::OrientationType_Horizontal));
    orientationTypes.Set("Vertical", Napi::Number::New(env, OrientationType::OrientationType_Vertical));

    return orientationTypes;
}
