#include "SupportedTextSelectionsWrapper.h"

Napi::Object SupportedTextSelectionsWrapper::New(Napi::Env env)
{
    auto supportedTextSelections = Napi::Object::New(env);

    supportedTextSelections.Set("None", Napi::Number::New(env, SupportedTextSelection::SupportedTextSelection_None));
    supportedTextSelections.Set("Single", Napi::Number::New(env, SupportedTextSelection::SupportedTextSelection_Single));
    supportedTextSelections.Set("Multiple", Napi::Number::New(env, SupportedTextSelection::SupportedTextSelection_Multiple));

    return supportedTextSelections;
}
