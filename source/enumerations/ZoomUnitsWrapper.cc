#include "ZoomUnitsWrapper.h"

Napi::Object ZoomUnitsWrapper::New(Napi::Env env)
{
    auto zoomUnits = Napi::Object::New(env);

    zoomUnits.Set("NoAmount", Napi::Number::New(env, ZoomUnit::ZoomUnit_NoAmount));
    zoomUnits.Set("LargeDecrement", Napi::Number::New(env, ZoomUnit::ZoomUnit_LargeDecrement));
    zoomUnits.Set("SmallDecrement", Napi::Number::New(env, ZoomUnit::ZoomUnit_SmallDecrement));
    zoomUnits.Set("LargeIncrement", Napi::Number::New(env, ZoomUnit::ZoomUnit_LargeIncrement));
    zoomUnits.Set("SmallIncrement", Napi::Number::New(env, ZoomUnit::ZoomUnit_SmallIncrement));

    return zoomUnits;
}
