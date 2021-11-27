#include "WindowVisualStatesWrapper.h"

Napi::Object WindowVisualStatesWrapper::New(Napi::Env env)
{
    auto windowVisualStates = Napi::Object::New(env);

    windowVisualStates.Set("Normal", Napi::Number::New(env, WindowVisualState::WindowVisualState_Normal));
    windowVisualStates.Set("Maximized", Napi::Number::New(env, WindowVisualState::WindowVisualState_Maximized));
    windowVisualStates.Set("Minimized", Napi::Number::New(env, WindowVisualState::WindowVisualState_Minimized));

    return windowVisualStates;
}
