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
    RECTWrapperConstructor = RectWrapper::Initialize(env);
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

    IUIAutomationAnnotationPatternWrapperConstructor = IUIAutomationAnnotationPatternWrapper::Initialize(env);
    IUIAutomationDockPatternWrapperConstructor = IUIAutomationDockPatternWrapper::Initialize(env);
    IUIAutomationDragPatternWrapperConstructor = IUIAutomationDragPatternWrapper::Initialize(env);
    IUIAutomationDropTargetPatternWrapperConstructor = IUIAutomationDropTargetPatternWrapper::Initialize(env);
    IUIAutomationExpandCollapsePatternWrapperConstructor = IUIAutomationExpandCollapsePatternWrapper::Initialize(env);
    IUIAutomationGridItemPatternWrapperConstructor = IUIAutomationGridItemPatternWrapper::Initialize(env);
    IUIAutomationGridPatternWrapperConstructor = IUIAutomationGridPatternWrapper::Initialize(env);
    IUIAutomationInvokePatternWrapperConstructor = IUIAutomationInvokePatternWrapper::Initialize(env);
    IUIAutomationItemContainerPatternWrapperConstructor = IUIAutomationItemContainerPatternWrapper::Initialize(env);
    IUIAutomationMultipleViewPatternWrapperConstructor = IUIAutomationMultipleViewPatternWrapper::Initialize(env);
    IUIAutomationRangeValuePatternWrapperConstructor = IUIAutomationRangeValuePatternWrapper::Initialize(env);
    IUIAutomationScrollItemPatternWrapperConstructor = IUIAutomationScrollItemPatternWrapper::Initialize(env);
    IUIAutomationScrollPatternWrapperConstructor = IUIAutomationScrollPatternWrapper::Initialize(env);
    IUIAutomationSelectionItemPatternWrapperConstructor = IUIAutomationSelectionItemPatternWrapper::Initialize(env);
    IUIAutomationSelectionPatternWrapperConstructor = IUIAutomationSelectionPatternWrapper::Initialize(env);
    ISelectionProvider2WrapperConstructor = IUIAutomationSelectionPattern2Wrapper::Initialize(env);
    IUIAutomationSpreadsheetItemPatternWrapperConstructor = IUIAutomationSpreadsheetItemPatternWrapper::Initialize(env);
    IUIAutomationSpreadsheetPatternWrapperConstructor = IUIAutomationSpreadsheetPatternWrapper::Initialize(env);
    IUIAutomationStylesPatternWrapperConstructor = IUIAutomationStylesPatternWrapper::Initialize(env);
    IUIAutomationSynchronizedInputPatternWrapperConstructor = IUIAutomationSynchronizedInputPatternWrapper::Initialize(env);
    IUIAutomationTableItemPatternWrapperConstructor = IUIAutomationTableItemPatternWrapper::Initialize(env);
    IUIAutomationTextChildPatternWrapperConstructor = IUIAutomationTextChildPatternWrapper::Initialize(env);
    IUIAutomationTextEditPatternWrapperConstructor = IUIAutomationTextEditPatternWrapper::Initialize(env);
    IUIAutomationTextPatternWrapperConstructor = IUIAutomationTextPatternWrapper::Initialize(env);
    ITextProvider2WrapperConstructor = IUIAutomationTextPattern2Wrapper::Initialize(env);
    IUIAutomationTogglePatternWrapperConstructor = IUIAutomationTogglePatternWrapper::Initialize(env);
    IUIAutomationTransformPatternWrapperConstructor = IUIAutomationTransformPatternWrapper::Initialize(env);
    ITransformProvider2WrapperConstructor = IUIAutomationTransformPatternWrapper::Initialize(env);
    IUIAutomationValuePatternWrapperConstructor = IUIAutomationValuePatternWrapper::Initialize(env);
    IUIAutomationVirtualizedItemPatternWrapperConstructor = IUIAutomationVirtualizedItemPatternWrapper::Initialize(env);
    IUIAutomationWindowPatternWrapperConstructor = IUIAutomationWindowPatternWrapper::Initialize(env);

    IUIAutomationTextRangePatternWrapperConstructor = IUIAutomationTextRangeWrapper::Initialize(env);

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
        InstanceValue("ScrollAmounts", ScrollAmountsWrapper::New(env)),
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
