#pragma once

#include "Shared.h"

class UIA_EventIdsWrapper
{
public:
  static Napi::Object Export(Napi::Env env, Napi::Object exports);
};
