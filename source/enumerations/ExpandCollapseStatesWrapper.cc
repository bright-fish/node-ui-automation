#include "ExpandCollapseStatesWrapper.h"

Napi::Object ExpandCollapseStatesWrapper::New(Napi::Env env)
{
    auto automationEvents = Napi::Object::New(env);

    automationEvents.Set("Collapsed", Napi::Number::New(env, ExpandCollapseState::ExpandCollapseState_Collapsed));
    automationEvents.Set("Expanded", Napi::Number::New(env, ExpandCollapseState::ExpandCollapseState_Expanded));
    automationEvents.Set("PartiallyExpanded", Napi::Number::New(env, ExpandCollapseState::ExpandCollapseState_PartiallyExpanded));
    automationEvents.Set("LeafNode", Napi::Number::New(env, ExpandCollapseState::ExpandCollapseState_LeafNode));

    return automationEvents;
}
