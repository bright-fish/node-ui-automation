#include "ScrollAmountsWrapper.h"

Napi::Object ScrollAmountsWrapper::New(Napi::Env env)
{
    auto scrollAmounts = Napi::Object::New(env);

    scrollAmounts.Set("LargeDecrement", Napi::Number::New(env, ScrollAmount_LargeDecrement));
    scrollAmounts.Set("LargeIncrement", Napi::Number::New(env, ScrollAmount_LargeIncrement));
    scrollAmounts.Set("NoAmount", Napi::Number::New(env, ScrollAmount_NoAmount));
    scrollAmounts.Set("SmallDecrement", Napi::Number::New(env, ScrollAmount_SmallDecrement));
    scrollAmounts.Set("SmallIncrement", Napi::Number::New(env, ScrollAmount_SmallIncrement));

    return scrollAmounts;
}
