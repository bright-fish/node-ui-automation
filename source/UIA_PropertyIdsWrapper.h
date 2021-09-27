#pragma once

#include "Shared.h"

class UIA_PropertyIdsWrapper
{
public:
  static Napi::Object Export(Napi::Env env, Napi::Object exports);
};
