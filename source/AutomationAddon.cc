#include "Library.h"

AutomationAddon::AutomationAddon(Napi::Env env, Napi::Object exports)
{
    HRESULT hResult = CoInitializeEx(NULL, COINIT_MULTITHREADED);

    if (FAILED(hResult))
    {
        _com_raise_error(hResult);
    }

    IUnknownWrapperConstructor = IUnknownWrapper::Initialize(env);
    IUIAutomationWrapperConstructor = IUIAutomationWrapper::Initialize(env);
    IUIAutomationTreeWalkerWrapperConstructor = IUIAutomationTreeWalkerWrapper::Initialize(env);
    IUIAutomationConditionWrapperConstructor = IUIAutomationConditionWrapper::Initialize(env);
    IUIAutomationElementWrapperConstructor = IUIAutomationElementWrapper::Initialize(env);
    IUIAutomationCacheRequestWrapperConstructor = IUIAutomationCacheRequestWrapper::Initialize(env);
    IUIAutomationElementArrayWrapperConstructor = IUIAutomationElementArrayWrapper::Initialize(env);
    IUIAutomationProxyFactoryMappingWrapperConstructor = IUIAutomationProxyFactoryMappingWrapper::Initialize(env);
    IUIAutomationEventHandlerWrapperConstructor = IUIAutomationEventHandlerWrapper::Initialize(env);
    IUIAutomationFocusChangedEventHandlerWrapperConstructor = IUIAutomationFocusChangedEventHandlerWrapper::Initialize(env);
    IUIAutomationPropertyChangedEventHandlerWrapperConstructor = IUIAutomationPropertyChangedEventHandlerWrapper::Initialize(env);
    IUIAutomationStructureChangedEventHandlerWrapperConstructor = IUIAutomationStructureChangedEventHandlerWrapper::Initialize(env);
    IInvokeProviderWrapperConstructor = IInvokeProviderWrapper::Initialize(env);
    IRawElementProviderSimpleWrapperConstructor = IRawElementProviderSimpleWrapper::Initialize(env);
    
    auto addonDefinition = {
        InstanceValue("Automation", IUIAutomationWrapperConstructor->Value()),
        InstanceValue("AutomationEventHandler", IUIAutomationEventHandlerWrapperConstructor->Value()),
        InstanceValue("AutomationFocusChangedEventHandler", IUIAutomationFocusChangedEventHandlerWrapperConstructor->Value()),
        InstanceValue("AutomationPropertyChangedEventHandler", IUIAutomationPropertyChangedEventHandlerWrapperConstructor->Value()),
        InstanceValue("AutomationStructureChangedEventHandler", IUIAutomationStructureChangedEventHandlerWrapperConstructor->Value()),
        InstanceValue("TreeScopes", TreeScopeWrapper::New(env)),
        InstanceValue("AutomationElementModes", AutomationElementModeWrapper::New(env)),
        InstanceValue("AutomationProperties", UIA_PropertyIdsWrapper::New(env)),
        InstanceValue("AutomationEvents", UIA_EventIdsWrapper::New(env)),
        InstanceValue("AutomationPatterns", UIA_PatternIdsWrapper::New(env)),
    };

    DefineAddon(exports, addonDefinition);
}

AutomationAddon::~AutomationAddon()
{
    CoUninitialize();
}

NODE_API_ADDON(AutomationAddon)
