#include "ToggleStatesWrapper.h"

Napi::Object ToggleStatesWrapper::New(Napi::Env env)
{
    auto toggleStates = Napi::Object::New(env);

    toggleStates.Set("Off", Napi::Number::New(env, ToggleState::ToggleState_Off));
    toggleStates.Set("On", Napi::Number::New(env, ToggleState::ToggleState_On));
    toggleStates.Set("Indeterminate", Napi::Number::New(env, ToggleState::ToggleState_Indeterminate));
    
    return toggleStates;
}
