#pragma once

#include "Shared.h"

class RectWrapper
{
public:
  static NAN_MODULE_INIT(Init);
  static v8::Local<v8::Value> NewInstance(v8::Isolate *isolate, RECT *boundingRectangle);
  static void RectWrapper::GetProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info);

private:
  static Nan::Persistent<v8::Function> constructor;
};
