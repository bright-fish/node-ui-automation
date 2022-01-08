#pragma once

#include "../Shared.h"

void HandleResult(const Napi::CallbackInfo &info, HRESULT hResult);
VARIANT ToVariant(Napi::Env env, Napi::Value local);
Napi::Value FromVariant(Napi::Env env, VARIANT variant);
Napi::Value GetPatternProviderByPatternId(const Napi::CallbackInfo &info, IUnknown *pProvider, PATTERNID patternId);
