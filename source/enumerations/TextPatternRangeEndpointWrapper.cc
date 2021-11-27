#include "TextPatternRangeEndpointWrapper.h"

Napi::Object TextPatternRangeEndpointWrapper::New(Napi::Env env)
{
    auto textPatternRangeEndpoint = Napi::Object::New(env);

    textPatternRangeEndpoint.Set("Start", Napi::Number::New(env, TextPatternRangeEndpoint::TextPatternRangeEndpoint_Start));
    textPatternRangeEndpoint.Set("End", Napi::Number::New(env, TextPatternRangeEndpoint::TextPatternRangeEndpoint_End));

    return textPatternRangeEndpoint;
}
