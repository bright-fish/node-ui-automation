#pragma once

#include "Shared.h"

class TreeScopeWrapper
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);
};
