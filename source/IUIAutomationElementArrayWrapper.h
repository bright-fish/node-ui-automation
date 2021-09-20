#pragma once

#include "Shared.h"

class IUIAutomationElementArrayWrapper : public Napi::ObjectWrap<IUIAutomationElementArrayWrapper>
{
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports);

  IUIAutomationElementArray *m_pElementArray;

  IUIAutomationElementArrayWrapper(const Napi::CallbackInfo &info);
  IUIAutomationElementArrayWrapper(const Napi::CallbackInfo &info, IUIAutomationElementArray* pElementArray);

  Napi::Value GetElement(const Napi::CallbackInfo &info);

};
