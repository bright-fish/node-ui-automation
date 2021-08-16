#pragma once

#include "Shared.h"

class IUIAutomationTreeWalkerWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(v8::Isolate *isolate, IUIAutomationTreeWalker *pTreeWalker);

  static void GetProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info);

  static NAN_METHOD(GetFirstChildElement);
  static NAN_METHOD(GetFirstChildElementBuildCache);
  static NAN_METHOD(GetLastChildElement);
  static NAN_METHOD(GetLastChildElementBuildCache);
  static NAN_METHOD(GetNextSiblingElement);
  static NAN_METHOD(GetNextSiblingElementBuildCache);
  static NAN_METHOD(GetParentElement);
  static NAN_METHOD(GetParentElementBuildCache);
  static NAN_METHOD(GetPreviousSiblingElement);
  static NAN_METHOD(GetPreviousSiblingElementBuildCache);
  static NAN_METHOD(NormalizeElement);
  static NAN_METHOD(NormalizeElementBuildCache);

private:
  static Nan::Persistent<v8::Function> constructor;
};
