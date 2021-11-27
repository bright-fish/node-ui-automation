#include "Library.h"

AutomationAddon::AutomationAddon(Napi::Env env, Napi::Object exports)
{
    HRESULT hResult = CoInitializeEx(NULL, COINIT_MULTITHREADED);

    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(env, error.ErrorMessage());
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

    IAnnotationProviderWrapperConstructor = IAnnotationProviderWrapper::Initialize(env);
    IDockProviderWrapperConstructor = IDockProviderWrapper::Initialize(env);
    IDragProviderWrapperConstructor = IDragProviderWrapper::Initialize(env);
    IDropTargetProviderWrapperConstructor = IDropTargetProviderWrapper::Initialize(env);
    IExpandCollapseProviderWrapperConstructor = IExpandCollapseProviderWrapper::Initialize(env);
    IGridItemProviderWrapperConstructor = IGridItemProviderWrapper::Initialize(env);
    IGridProviderWrapperConstructor = IGridProviderWrapper::Initialize(env);
    IInvokeProviderWrapperConstructor = IInvokeProviderWrapper::Initialize(env);
    IItemContainerProviderWrapperConstructor = IItemContainerProviderWrapper::Initialize(env);
    IMultipleViewProviderWrapperConstructor = IMultipleViewProviderWrapper::Initialize(env);
    IRangeValueProviderWrapperConstructor = IRangeValueProviderWrapper::Initialize(env);
    IScrollItemProviderWrapperConstructor = IScrollItemProviderWrapper::Initialize(env);
    IScrollProviderWrapperConstructor = IScrollProviderWrapper::Initialize(env);
    ISelectionItemProviderWrapperConstructor = ISelectionItemProviderWrapper::Initialize(env);
    ISelectionProviderWrapperConstructor = ISelectionProviderWrapper::Initialize(env);
    ISelectionProvider2WrapperConstructor = ISelectionProvider2Wrapper::Initialize(env);
    ISpreadsheetItemProviderWrapperConstructor = ISpreadsheetItemProviderWrapper::Initialize(env);
    ISpreadsheetProviderWrapperConstructor = ISpreadsheetProviderWrapper::Initialize(env);
    IStylesProviderWrapperConstructor = IStylesProviderWrapper::Initialize(env);
    ISynchronizedInputProviderWrapperConstructor = ISynchronizedInputProviderWrapper::Initialize(env);
    ITableItemProviderWrapperConstructor = ITableItemProviderWrapper::Initialize(env);
    ITextChildProviderWrapperConstructor = ITextChildProviderWrapper::Initialize(env);
    ITextEditProviderWrapperConstructor = ITextEditProviderWrapper::Initialize(env);
    ITextProviderWrapperConstructor = ITextProviderWrapper::Initialize(env);
    ITextProvider2WrapperConstructor = ITextProvider2Wrapper::Initialize(env);
    IToggleProviderWrapperConstructor = IToggleProviderWrapper::Initialize(env);
    ITransformProviderWrapperConstructor = ITransformProviderWrapper::Initialize(env);
    ITransformProvider2WrapperConstructor = ITransformProviderWrapper::Initialize(env);
    IValueProviderWrapperConstructor = IValueProviderWrapper::Initialize(env);
    IVirtualizedItemProviderWrapperConstructor = IVirtualizedItemProviderWrapper::Initialize(env);
    IWindowProviderWrapperConstructor = IWindowProviderWrapper::Initialize(env);

    IRawElementProviderSimpleWrapperConstructor = IRawElementProviderSimpleWrapper::Initialize(env);
    ITextRangeProviderWrapperConstructor = ITextRangeProviderWrapper::Initialize(env);

    auto addonDefinition = {
        InstanceValue("Automation", IUIAutomationWrapperConstructor->Value()),
        InstanceValue("AutomationEventHandler", IUIAutomationEventHandlerWrapperConstructor->Value()),
        InstanceValue("AutomationFocusChangedEventHandler", IUIAutomationFocusChangedEventHandlerWrapperConstructor->Value()),
        InstanceValue("AutomationPropertyChangedEventHandler", IUIAutomationPropertyChangedEventHandlerWrapperConstructor->Value()),
        InstanceValue("AutomationStructureChangedEventHandler", IUIAutomationStructureChangedEventHandlerWrapperConstructor->Value()),

        InstanceValue("AnnotationTypeIds", AnnotationTypeIdsWrapper::New(env)),
        InstanceValue("AttributeIds", AttributeIdsWrapper::New(env)),
        InstanceValue("ControlTypeIds", ControlTypeIdsWrapper::New(env)),
        InstanceValue("DockPositions", DockPositionsWrapper::New(env)),
        InstanceValue("ElementModes", ElementModesWrapper::New(env)),
        InstanceValue("EventIds", EventIdsWrapper::New(env)),
        InstanceValue("ExpandCollapseStates", ExpandCollapseStatesWrapper::New(env)),
        InstanceValue("OrientationTypes", OrientationTypesWrapper::New(env)),
        InstanceValue("PatternIds", PatternIdsWrapper::New(env)),
        InstanceValue("PropertyIds", PropertyIdsWrapper::New(env)),
        InstanceValue("ProviderOptions", ProviderOptionsWrapper::New(env)),
        InstanceValue("RowOrColumnMajor", RowOrColumnMajorWrapper::New(env)),
        InstanceValue("StyleIds", StyleIdsWrapper::New(env)),
        InstanceValue("SupportedTextSelections", SupportedTextSelectionsWrapper::New(env)),
        InstanceValue("SynchronizedInputTypes", SynchronizedInputTypesWrapper::New(env)),
        InstanceValue("TextPatternRangeEndpoints", TextPatternRangeEndpointWrapper::New(env)),
        InstanceValue("TextUnits", TextUnitsWrapper::New(env)),
        InstanceValue("ToggleStates", ToggleStatesWrapper::New(env)),
        InstanceValue("TreeScopes", TreeScopesWrapper::New(env)),
        InstanceValue("WindowInteractionStates", WindowInteractionStatesWrapper::New(env)),
        InstanceValue("WindowVisualStates", WindowVisualStatesWrapper::New(env)),
        InstanceValue("ZoomUnits", ZoomUnitsWrapper::New(env)),
    };

    DefineAddon(exports, addonDefinition);
}

AutomationAddon::~AutomationAddon()
{
    CoUninitialize();
}

NODE_API_ADDON(AutomationAddon)
