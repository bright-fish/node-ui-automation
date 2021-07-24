#pragma once

#include "Shared.h"


class IUIAutomationWrapper : public Nan::ObjectWrap {
  public:
    static NAN_MODULE_INIT(Init);

  private:
    IUIAutomation* m_pAutomation;

    explicit IUIAutomationWrapper();
    ~IUIAutomationWrapper();

    static NAN_METHOD(New);
    static NAN_METHOD(GetRootElement);
    static Nan::Persistent<v8::Function> constructor;
};

