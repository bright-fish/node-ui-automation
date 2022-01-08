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
    Napi::FunctionReference *IAccessibleWrapperConstructor;

    Napi::FunctionReference *RECTWrapperConstructor;
    Napi::FunctionReference *IUIAutomationFocusChangedEventHandlerWrapperConstructor;
    Napi::FunctionReference *IUIAutomationPropertyChangedEventHandlerWrapperConstructor;
    Napi::FunctionReference *IUIAutomationStructureChangedEventHandlerWrapperConstructor;

    Napi::FunctionReference *IUIAutomationAnnotationPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationDockPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationDragPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationDropTargetPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationExpandCollapsePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationGridItemPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationGridPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationInvokePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationItemContainerPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationLegacyIAccessiblePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationMultipleViewPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationRangeValuePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationScrollItemPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationScrollPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationSelectionItemPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationSelectionPatternWrapperConstructor;
    Napi::FunctionReference *ISelectionProvider2WrapperConstructor;
    Napi::FunctionReference *IUIAutomationSpreadsheetPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationSpreadsheetItemPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationStylesPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationSynchronizedInputPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTableItemPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTablePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTextChildPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTextRangePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTextEditPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTextPatternWrapperConstructor;
    Napi::FunctionReference *ITextProvider2WrapperConstructor;
    Napi::FunctionReference *IUIAutomationTogglePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationTransformPatternWrapperConstructor;
    Napi::FunctionReference *ITransformProvider2WrapperConstructor;
    Napi::FunctionReference *IUIAutomationValuePatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationVirtualizedItemPatternWrapperConstructor;
    Napi::FunctionReference *IUIAutomationWindowPatternWrapperConstructor;

    Napi::FunctionReference *IRawElementProviderSimpleWrapperConstructor;

    // todo: add all the constructors for the providers here.
    
    AutomationAddon(Napi::Env env, Napi::Object exports);
    ~AutomationAddon();
};