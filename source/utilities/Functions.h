#pragma once 

#include "../Shared.h"

VARIANT ToVariant(const Napi::CallbackInfo &info, Napi::Value local);
Napi::Value FromVariant(const Napi::CallbackInfo &info, VARIANT variant);