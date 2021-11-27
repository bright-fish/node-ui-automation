#include "ElementModesWrapper.h"

Napi::Object ElementModesWrapper::New(Napi::Env env)
{
  Napi::Object automationElementMode = Napi::Object::New(env);

  automationElementMode.Set("None", Napi::Number::New(env, AutomationElementMode::AutomationElementMode_None));
  automationElementMode.Set("Full", Napi::Number::New(env, AutomationElementMode::AutomationElementMode_Full));

  return automationElementMode;
}
