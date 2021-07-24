#pragma once

#include "Shared.h"

class IUIAutomationElementWrapper : public Nan::ObjectWrap {
  public:
    static NAN_MODULE_INIT(Init);
    explicit IUIAutomationElementWrapper(IUIAutomationElement* element);

  private:
    IUIAutomationElement* m_pAutomationElement;

    ~IUIAutomationElementWrapper();

    static NAN_METHOD(FindFirst);
    static Nan::Persistent<v8::Function> constructor;
};

