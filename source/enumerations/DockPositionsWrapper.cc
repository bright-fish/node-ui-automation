#include "DockPositionsWrapper.h"

Napi::Object DockPositionsWrapper::New(Napi::Env env)
{
    auto automationEvents = Napi::Object::New(env);

    automationEvents.Set("Bottom", Napi::Number::New(env, DockPosition::DockPosition_Bottom));
    automationEvents.Set("Fill", Napi::Number::New(env, DockPosition::DockPosition_Fill));
    automationEvents.Set("Left", Napi::Number::New(env, DockPosition::DockPosition_Left));
    automationEvents.Set("None", Napi::Number::New(env, DockPosition::DockPosition_None));
    automationEvents.Set("Right", Napi::Number::New(env, DockPosition::DockPosition_Right));
    automationEvents.Set("Top", Napi::Number::New(env, DockPosition::DockPosition_Top));

    return automationEvents;
}
