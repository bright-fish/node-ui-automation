#pragma once
#include "../Shared.h"

class AutomationElementModeWrapper
{
public:
  static Napi::Object New(Napi::Env env)
  {
    Napi::Object automationElementMode = Napi::Object::New(env);

    automationElementMode.Set("None", Napi::Number::New(env, AutomationElementMode_None));
    automationElementMode.Set("Full", Napi::Number::New(env, AutomationElementMode_Full));

    return automationElementMode;
  }
};