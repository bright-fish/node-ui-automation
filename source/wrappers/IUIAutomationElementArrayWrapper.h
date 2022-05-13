#pragma once

#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationElementArrayWrapper : public Napi::ObjectWrap<IUIAutomationElementArrayWrapper>
{
public:
  static Napi::FunctionReference *Initialize(Napi::Env env);
  static Napi::Value New(Napi::Env env, IUIAutomationElementArray * pElementArray);

  ComAutoPointer<IUIAutomationElementArray> m_pElementArray = NULL;

  IUIAutomationElementArrayWrapper(const Napi::CallbackInfo &info);
  ~IUIAutomationElementArrayWrapper();

  Napi::Value GetElement(const Napi::CallbackInfo &info);
};
