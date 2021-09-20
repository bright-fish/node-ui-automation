#include "Shared.h"
#include "Library.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    UIA_PropertyIdsWrapper::Init(env, exports);
    UIA_EventIdsWrapper::Init(env, exports);
    TreeScopeWrapper::Init(env, exports);
    RectWrapper::Init(env, exports);

    IUnknownWrapper::Init(env, exports);

    IUIAutomationWrapper::Init(env, exports);
    IUIAutomationElementWrapper::Init(env, exports);
    IUIAutomationConditionWrapper::Init(env, exports);
    IUIAutomationElementArrayWrapper::Init(env, exports);
    IUIAutomationTreeWalkerWrapper::Init(env, exports);
    IUIAutomationCacheRequestWrapper::Init(env, exports);
    IUIAutomationProxyFactoryMappingWrapper::Init(env, exports);

    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, InitAll)