#include "shared.h"

#include "IUIAutomationWrapper.h"
#include "IUIAutomationElementWrapper.h"

using v8::Local;
using v8::Object;

void InitAll(Local<Object> exports)
{
    IUIAutomationWrapper::Init(exports);
    IUIAutomationElementWrapper::Init(exports);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)