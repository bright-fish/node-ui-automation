#include "WindowInteractionStatesWrapper.h"

Napi::Object WindowInteractionStatesWrapper::New(Napi::Env env)
{
    auto zoomUnits = Napi::Object::New(env);

    zoomUnits.Set("Running", Napi::Number::New(env, WindowInteractionState::WindowInteractionState_Running));
    zoomUnits.Set("Closing", Napi::Number::New(env, WindowInteractionState::WindowInteractionState_Closing));
    zoomUnits.Set("ReadyForUserInteraction", Napi::Number::New(env, WindowInteractionState::WindowInteractionState_ReadyForUserInteraction));
    zoomUnits.Set("BlockedByModalWindow", Napi::Number::New(env, WindowInteractionState::WindowInteractionState_BlockedByModalWindow));
    zoomUnits.Set("NotResponding", Napi::Number::New(env, WindowInteractionState::WindowInteractionState_NotResponding));

    return zoomUnits;
}
