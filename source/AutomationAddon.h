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

    Napi::FunctionReference *IAnnotationProviderWrapperConstructor;
    Napi::FunctionReference *IDockProviderWrapperConstructor;
    Napi::FunctionReference *IDragProviderWrapperConstructor;
    Napi::FunctionReference *IDropTargetProviderWrapperConstructor;
    Napi::FunctionReference *IExpandCollapseProviderWrapperConstructor;
    Napi::FunctionReference *IGridItemProviderWrapperConstructor;
    Napi::FunctionReference *IGridProviderWrapperConstructor;
    Napi::FunctionReference *IInvokeProviderWrapperConstructor;
    Napi::FunctionReference *IItemContainerProviderWrapperConstructor;
    Napi::FunctionReference *ILegacyIAccessibleProviderWrapperConstructor;
    Napi::FunctionReference *IMultipleViewProviderWrapperConstructor;
    Napi::FunctionReference *IRangeValueProviderWrapperConstructor;
    Napi::FunctionReference *IScrollItemProviderWrapperConstructor;
    Napi::FunctionReference *IScrollProviderWrapperConstructor;
    Napi::FunctionReference *ISelectionItemProviderWrapperConstructor;
    Napi::FunctionReference *ISelectionProviderWrapperConstructor;
    Napi::FunctionReference *ISelectionProvider2WrapperConstructor;
    Napi::FunctionReference *ISpreadsheetProviderWrapperConstructor;
    Napi::FunctionReference *ISpreadsheetItemProviderWrapperConstructor;
    Napi::FunctionReference *IStylesProviderWrapperConstructor;
    Napi::FunctionReference *ISynchronizedInputProviderWrapperConstructor;
    Napi::FunctionReference *ITableItemProviderWrapperConstructor;
    Napi::FunctionReference *ITableProviderWrapperConstructor;
    Napi::FunctionReference *ITextChildProviderWrapperConstructor;
    Napi::FunctionReference *ITextRangeProviderWrapperConstructor;
    Napi::FunctionReference *ITextEditProviderWrapperConstructor;
    Napi::FunctionReference *ITextProviderWrapperConstructor;
    Napi::FunctionReference *ITextProvider2WrapperConstructor;
    Napi::FunctionReference *IToggleProviderWrapperConstructor;
    Napi::FunctionReference *ITransformProviderWrapperConstructor;
    Napi::FunctionReference *ITransformProvider2WrapperConstructor;
    Napi::FunctionReference *IValueProviderWrapperConstructor;
    Napi::FunctionReference *IVirtualizedItemProviderWrapperConstructor;
    Napi::FunctionReference *IWindowProviderWrapperConstructor;

    Napi::FunctionReference *IRawElementProviderSimpleWrapperConstructor;

    // todo: add all the constructors for the providers here.
    
    AutomationAddon(Napi::Env env, Napi::Object exports);
    ~AutomationAddon();
};