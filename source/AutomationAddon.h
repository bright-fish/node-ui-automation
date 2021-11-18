#pragma once

#include "Shared.h"

class AutomationAddon : public Napi::Addon<AutomationAddon>
{
public:
    Napi::FunctionReference *IUIAutomationWrapperConstructor;
    Napi::FunctionReference *IUIAutomationConditionWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTreeWalkerWrapperConstructor;
    Napi::FunctionReference *IUIAutomationCacheRequestWrapperConstructor;
    Napi::FunctionReference *IUIAutomationElementArrayWrapperConstructor;
    Napi::FunctionReference *IUIAutomationElementWrapperConstructor;
    Napi::FunctionReference *IUIAutomationEventHandlerWrapperConstructor;
    Napi::FunctionReference *IUIAutomationProxyFactoryMappingWrapperConstructor;
    Napi::FunctionReference *IUnknownWrapperConstructor;
    Napi::FunctionReference *RECTWrapperConstructor;
    Napi::FunctionReference *IUIAutomationFocusChangedEventHandlerWrapperConstructor;
    Napi::FunctionReference *IUIAutomationPropertyChangedEventHandlerWrapperConstructor;
    Napi::FunctionReference *IUIAutomationStructureChangedEventHandlerWrapperConstructor;
    Napi::FunctionReference *IInvokeProviderWrapperConstructor;
    Napi::FunctionReference *IRawElementProviderSimpleWrapperConstructor;
    
    AutomationAddon(Napi::Env env, Napi::Object exports);
    ~AutomationAddon();
};