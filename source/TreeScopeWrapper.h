#pragma once

#include "Shared.h"

class TreeScopeWrapper : public Nan::ObjectWrap
{
public:
  static NAN_MODULE_INIT(Init);
};
