#include "ProviderOptionsWrapper.h"

Napi::Object ProviderOptionsWrapper::New(Napi::Env env)
{
    auto providerOptions = Napi::Object::New(env);

    providerOptions.Set("ClientSideProvider", Napi::Number::New(env, ProviderOptions::ProviderOptions_ClientSideProvider));
    providerOptions.Set("ServerSideProvider", Napi::Number::New(env, ProviderOptions::ProviderOptions_ServerSideProvider));
    providerOptions.Set("NonClientAreaProvider", Napi::Number::New(env, ProviderOptions::ProviderOptions_NonClientAreaProvider));
    providerOptions.Set("OverrideProvider", Napi::Number::New(env, ProviderOptions::ProviderOptions_OverrideProvider));
    providerOptions.Set("ProviderOwnsSetFocus", Napi::Number::New(env, ProviderOptions::ProviderOptions_ProviderOwnsSetFocus));
    providerOptions.Set("UseComThreading", Napi::Number::New(env, ProviderOptions::ProviderOptions_UseComThreading));
    providerOptions.Set("RefuseNonClientSupport", Napi::Number::New(env, ProviderOptions::ProviderOptions_RefuseNonClientSupport));
    providerOptions.Set("HasNativeIAccessible", Napi::Number::New(env, ProviderOptions::ProviderOptions_HasNativeIAccessible));
    providerOptions.Set("UseClientCoordinates", Napi::Number::New(env, ProviderOptions::ProviderOptions_UseClientCoordinates));

    return providerOptions;
}
