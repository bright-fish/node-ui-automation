#pragma once

#include "../Shared.h"

class IUIAutomationElementArrayWrapper : public Napi::ObjectWrap<IUIAutomationElementArrayWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Object New(Napi::Env env, IUIAutomationElementArray * pElementArray);

  IUIAutomationElementArray *m_pElementArray;

  IUIAutomationElementArrayWrapper(const Napi::CallbackInfo &info);
  // ~IUIAutomationElementArrayWrapper();

  Napi::Value GetElement(const Napi::CallbackInfo &info);
};
