#include "Shared.h"
#include "Library.h"

using v8::Local;
using v8::Object;

void InitAll(Local<Object> exports)
{
    IUIAutomationWrapper::Init(exports);
    IUIAutomationElementWrapper::Init(exports);
    UIA_PropertyIdsWrapper::Init(exports);
    TreeScopeWrapper::Init(exports);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)