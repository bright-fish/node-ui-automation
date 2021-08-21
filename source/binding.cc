#include "Shared.h"
#include "Library.h"

using v8::Local;
using v8::Object;

void InitAll(Local<Object> exports)
{
    UIA_PropertyIdsWrapper::Init(exports);
    UIA_EventIdsWrapper::Init(exports);
    TreeScopeWrapper::Init(exports);
    RectWrapper::Init(exports);

    IUnknownWrapper::Init(exports);

    IUIAutomationWrapper::Init(exports);
    IUIAutomationElementWrapper::Init(exports);
    IUIAutomationConditionWrapper::Init(exports);
    IUIAutomationElementArrayWrapper::Init(exports);
    IUIAutomationTreeWalkerWrapper::Init(exports);
    IUIAutomationCacheRequestWrapper::Init(exports);
    IUIAutomationProxyFactoryMappingWrapper::Init(exports);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, InitAll)