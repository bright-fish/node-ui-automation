#include "Library.h"

using v8::Isolate;
using v8::Local;
using v8::Object;

NAN_MODULE_INIT(UIA_PropertyIdsWrapper::Init)
{
    Local<Object> propertyIds = Object::New(isolate);

    Nan::Set(propertyIds, Nan::New("Name").ToLocalChecked(), Nan::New(UIA_NamePropertyId));
    Nan::Set(propertyIds, Nan::New("NativeWindowHandle").ToLocalChecked(), Nan::New(UIA_NativeWindowHandlePropertyId));
    Nan::Set(propertyIds, Nan::New("NavigationLand").ToLocalChecked(), Nan::New(UIA_NavigationLandmarkTypeId));
    Nan::Set(propertyIds, Nan::New("RuntimeId").ToLocalChecked(), Nan::New(UIA_RuntimeIdPropertyId));
    Nan::Set(propertyIds, Nan::New("BoundingRectangle").ToLocalChecked(), Nan::New(UIA_BoundingRectanglePropertyId));
    Nan::Set(propertyIds, Nan::New("ProcessId").ToLocalChecked(), Nan::New(UIA_ProcessIdPropertyId));
    Nan::Set(propertyIds, Nan::New("ControlType").ToLocalChecked(), Nan::New(UIA_ControlTypePropertyId));
    Nan::Set(propertyIds, Nan::New("LocalizedControlType").ToLocalChecked(), Nan::New(UIA_LocalizedControlTypePropertyId));
    Nan::Set(propertyIds, Nan::New("Name").ToLocalChecked(), Nan::New(UIA_NamePropertyId));
    Nan::Set(propertyIds, Nan::New("AcceleratorKey").ToLocalChecked(), Nan::New(UIA_AcceleratorKeyPropertyId));
    Nan::Set(propertyIds, Nan::New("AccessKey").ToLocalChecked(), Nan::New(UIA_AccessKeyPropertyId));
    Nan::Set(propertyIds, Nan::New("HasKeyboardFocus").ToLocalChecked(), Nan::New(UIA_HasKeyboardFocusPropertyId));
    Nan::Set(propertyIds, Nan::New("IsKeyboardFocusable").ToLocalChecked(), Nan::New(UIA_IsKeyboardFocusablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsEnabled").ToLocalChecked(), Nan::New(UIA_IsEnabledPropertyId));
    Nan::Set(propertyIds, Nan::New("AutomationId").ToLocalChecked(), Nan::New(UIA_AutomationIdPropertyId));
    Nan::Set(propertyIds, Nan::New("ClassName").ToLocalChecked(), Nan::New(UIA_ClassNamePropertyId));
    Nan::Set(propertyIds, Nan::New("HelpText").ToLocalChecked(), Nan::New(UIA_HelpTextPropertyId));
    Nan::Set(propertyIds, Nan::New("ClickablePoint").ToLocalChecked(), Nan::New(UIA_ClickablePointPropertyId));
    Nan::Set(propertyIds, Nan::New("Culture").ToLocalChecked(), Nan::New(UIA_CulturePropertyId));
    Nan::Set(propertyIds, Nan::New("IsControlElement").ToLocalChecked(), Nan::New(UIA_IsControlElementPropertyId));
    Nan::Set(propertyIds, Nan::New("IsContentElement").ToLocalChecked(), Nan::New(UIA_IsContentElementPropertyId));
    Nan::Set(propertyIds, Nan::New("LabeledBy").ToLocalChecked(), Nan::New(UIA_LabeledByPropertyId));
    Nan::Set(propertyIds, Nan::New("IsPassword").ToLocalChecked(), Nan::New(UIA_IsPasswordPropertyId));
    Nan::Set(propertyIds, Nan::New("NativeWindowHandle").ToLocalChecked(), Nan::New(UIA_NativeWindowHandlePropertyId));
    Nan::Set(propertyIds, Nan::New("ItemType").ToLocalChecked(), Nan::New(UIA_ItemTypePropertyId));
    Nan::Set(propertyIds, Nan::New("IsOffscreen").ToLocalChecked(), Nan::New(UIA_IsOffscreenPropertyId));
    Nan::Set(propertyIds, Nan::New("Orientation").ToLocalChecked(), Nan::New(UIA_OrientationPropertyId));
    Nan::Set(propertyIds, Nan::New("FrameworkId").ToLocalChecked(), Nan::New(UIA_FrameworkIdPropertyId));
    Nan::Set(propertyIds, Nan::New("IsRequiredForForm").ToLocalChecked(), Nan::New(UIA_IsRequiredForFormPropertyId));
    Nan::Set(propertyIds, Nan::New("ItemStatus").ToLocalChecked(), Nan::New(UIA_ItemStatusPropertyId));
    Nan::Set(propertyIds, Nan::New("IsDockPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsDockPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsExpandCollapsePatternAvailable").ToLocalChecked(), Nan::New(UIA_IsExpandCollapsePatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsGridItemPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsGridItemPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsGridPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsGridPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsInvokePatternAvailable").ToLocalChecked(), Nan::New(UIA_IsInvokePatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsMultipleViewPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsMultipleViewPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsRangeValuePatternAvailable").ToLocalChecked(), Nan::New(UIA_IsRangeValuePatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsScrollPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsScrollPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsScrollItemPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsScrollItemPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsSelectionItemPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsSelectionItemPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsSelectionPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsSelectionPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsTablePatternAvailable").ToLocalChecked(), Nan::New(UIA_IsTablePatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsTableItemPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsTableItemPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsTextPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsTextPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsTogglePatternAvailable").ToLocalChecked(), Nan::New(UIA_IsTogglePatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsTransformPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsTransformPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsValuePatternAvailable").ToLocalChecked(), Nan::New(UIA_IsValuePatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsWindowPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsWindowPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("ValueValue").ToLocalChecked(), Nan::New(UIA_ValueValuePropertyId));
    Nan::Set(propertyIds, Nan::New("ValueIsReadOnly").ToLocalChecked(), Nan::New(UIA_ValueIsReadOnlyPropertyId));
    Nan::Set(propertyIds, Nan::New("RangeValueValue").ToLocalChecked(), Nan::New(UIA_RangeValueValuePropertyId));
    Nan::Set(propertyIds, Nan::New("RangeValueIsReadOnly").ToLocalChecked(), Nan::New(UIA_RangeValueIsReadOnlyPropertyId));
    Nan::Set(propertyIds, Nan::New("RangeValueMinimum").ToLocalChecked(), Nan::New(UIA_RangeValueMinimumPropertyId));
    Nan::Set(propertyIds, Nan::New("RangeValueMaximum").ToLocalChecked(), Nan::New(UIA_RangeValueMaximumPropertyId));
    Nan::Set(propertyIds, Nan::New("RangeValueLargeChange").ToLocalChecked(), Nan::New(UIA_RangeValueLargeChangePropertyId));
    Nan::Set(propertyIds, Nan::New("RangeValueSmallChange").ToLocalChecked(), Nan::New(UIA_RangeValueSmallChangePropertyId));
    Nan::Set(propertyIds, Nan::New("ScrollHorizontalScrollPercent").ToLocalChecked(), Nan::New(UIA_ScrollHorizontalScrollPercentPropertyId));
    Nan::Set(propertyIds, Nan::New("ScrollHorizontalViewSize").ToLocalChecked(), Nan::New(UIA_ScrollHorizontalViewSizePropertyId));
    Nan::Set(propertyIds, Nan::New("ScrollVerticalScrollPercent").ToLocalChecked(), Nan::New(UIA_ScrollVerticalScrollPercentPropertyId));
    Nan::Set(propertyIds, Nan::New("ScrollVerticalViewSize").ToLocalChecked(), Nan::New(UIA_ScrollVerticalViewSizePropertyId));
    Nan::Set(propertyIds, Nan::New("ScrollHorizontallyScrollable").ToLocalChecked(), Nan::New(UIA_ScrollHorizontallyScrollablePropertyId));
    Nan::Set(propertyIds, Nan::New("ScrollVerticallyScrollable").ToLocalChecked(), Nan::New(UIA_ScrollVerticallyScrollablePropertyId));
    Nan::Set(propertyIds, Nan::New("SelectionSelection").ToLocalChecked(), Nan::New(UIA_SelectionSelectionPropertyId));
    Nan::Set(propertyIds, Nan::New("SelectionCanSelectMultiple").ToLocalChecked(), Nan::New(UIA_SelectionCanSelectMultiplePropertyId));
    Nan::Set(propertyIds, Nan::New("SelectionIsSelectionRequired").ToLocalChecked(), Nan::New(UIA_SelectionIsSelectionRequiredPropertyId));
    Nan::Set(propertyIds, Nan::New("GridRowCount").ToLocalChecked(), Nan::New(UIA_GridRowCountPropertyId));
    Nan::Set(propertyIds, Nan::New("GridColumnCount").ToLocalChecked(), Nan::New(UIA_GridColumnCountPropertyId));
    Nan::Set(propertyIds, Nan::New("GridItemRow").ToLocalChecked(), Nan::New(UIA_GridItemRowPropertyId));
    Nan::Set(propertyIds, Nan::New("GridItemColumn").ToLocalChecked(), Nan::New(UIA_GridItemColumnPropertyId));
    Nan::Set(propertyIds, Nan::New("GridItemRowSpan").ToLocalChecked(), Nan::New(UIA_GridItemRowSpanPropertyId));
    Nan::Set(propertyIds, Nan::New("GridItemColumnSpan").ToLocalChecked(), Nan::New(UIA_GridItemColumnSpanPropertyId));
    Nan::Set(propertyIds, Nan::New("GridItemContainingGrid").ToLocalChecked(), Nan::New(UIA_GridItemContainingGridPropertyId));
    Nan::Set(propertyIds, Nan::New("DockDockPosition").ToLocalChecked(), Nan::New(UIA_DockDockPositionPropertyId));
    Nan::Set(propertyIds, Nan::New("ExpandCollapseExpandCollapseState").ToLocalChecked(), Nan::New(UIA_ExpandCollapseExpandCollapseStatePropertyId));
    Nan::Set(propertyIds, Nan::New("MultipleViewCurrentView").ToLocalChecked(), Nan::New(UIA_MultipleViewCurrentViewPropertyId));
    Nan::Set(propertyIds, Nan::New("MultipleViewSupportedViews").ToLocalChecked(), Nan::New(UIA_MultipleViewSupportedViewsPropertyId));
    Nan::Set(propertyIds, Nan::New("WindowCanMaximize").ToLocalChecked(), Nan::New(UIA_WindowCanMaximizePropertyId));
    Nan::Set(propertyIds, Nan::New("WindowCanMinimize").ToLocalChecked(), Nan::New(UIA_WindowCanMinimizePropertyId));
    Nan::Set(propertyIds, Nan::New("WindowWindowVisualState").ToLocalChecked(), Nan::New(UIA_WindowWindowVisualStatePropertyId));
    Nan::Set(propertyIds, Nan::New("WindowWindowInteractionState").ToLocalChecked(), Nan::New(UIA_WindowWindowInteractionStatePropertyId));
    Nan::Set(propertyIds, Nan::New("WindowIsModal").ToLocalChecked(), Nan::New(UIA_WindowIsModalPropertyId));
    Nan::Set(propertyIds, Nan::New("WindowIsTopmost").ToLocalChecked(), Nan::New(UIA_WindowIsTopmostPropertyId));
    Nan::Set(propertyIds, Nan::New("SelectionItemIsSelected").ToLocalChecked(), Nan::New(UIA_SelectionItemIsSelectedPropertyId));
    Nan::Set(propertyIds, Nan::New("SelectionItemSelectionContainer").ToLocalChecked(), Nan::New(UIA_SelectionItemSelectionContainerPropertyId));
    Nan::Set(propertyIds, Nan::New("TableRowHeaders").ToLocalChecked(), Nan::New(UIA_TableRowHeadersPropertyId));
    Nan::Set(propertyIds, Nan::New("TableColumnHeaders").ToLocalChecked(), Nan::New(UIA_TableColumnHeadersPropertyId));
    Nan::Set(propertyIds, Nan::New("TableRowOrColumnMajor").ToLocalChecked(), Nan::New(UIA_TableRowOrColumnMajorPropertyId));
    Nan::Set(propertyIds, Nan::New("TableItemRowHeaderItems").ToLocalChecked(), Nan::New(UIA_TableItemRowHeaderItemsPropertyId));
    Nan::Set(propertyIds, Nan::New("TableItemColumnHeaderItems").ToLocalChecked(), Nan::New(UIA_TableItemColumnHeaderItemsPropertyId));
    Nan::Set(propertyIds, Nan::New("ToggleToggleState").ToLocalChecked(), Nan::New(UIA_ToggleToggleStatePropertyId));
    Nan::Set(propertyIds, Nan::New("TransformCanMove").ToLocalChecked(), Nan::New(UIA_TransformCanMovePropertyId));
    Nan::Set(propertyIds, Nan::New("TransformCanResize").ToLocalChecked(), Nan::New(UIA_TransformCanResizePropertyId));
    Nan::Set(propertyIds, Nan::New("TransformCanRotate").ToLocalChecked(), Nan::New(UIA_TransformCanRotatePropertyId));
    Nan::Set(propertyIds, Nan::New("IsLegacyIAccessiblePatternAvailable").ToLocalChecked(), Nan::New(UIA_IsLegacyIAccessiblePatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleChildId").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleChildIdPropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleName").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleNamePropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleValue").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleValuePropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleDescription").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleDescriptionPropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleRole").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleRolePropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleState").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleStatePropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleHelp").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleHelpPropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleKeyboardShortcut").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleKeyboardShortcutPropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleSelection").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleSelectionPropertyId));
    Nan::Set(propertyIds, Nan::New("LegacyIAccessibleDefaultAction").ToLocalChecked(), Nan::New(UIA_LegacyIAccessibleDefaultActionPropertyId));
    Nan::Set(propertyIds, Nan::New("AriaRole").ToLocalChecked(), Nan::New(UIA_AriaRolePropertyId));
    Nan::Set(propertyIds, Nan::New("AriaProperties").ToLocalChecked(), Nan::New(UIA_AriaPropertiesPropertyId));
    Nan::Set(propertyIds, Nan::New("IsDataValidForForm").ToLocalChecked(), Nan::New(UIA_IsDataValidForFormPropertyId));
    Nan::Set(propertyIds, Nan::New("ControllerFor").ToLocalChecked(), Nan::New(UIA_ControllerForPropertyId));
    Nan::Set(propertyIds, Nan::New("DescribedBy").ToLocalChecked(), Nan::New(UIA_DescribedByPropertyId));
    Nan::Set(propertyIds, Nan::New("FlowsTo").ToLocalChecked(), Nan::New(UIA_FlowsToPropertyId));
    Nan::Set(propertyIds, Nan::New("ProviderDescription").ToLocalChecked(), Nan::New(UIA_ProviderDescriptionPropertyId));
    Nan::Set(propertyIds, Nan::New("IsItemContainerPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsItemContainerPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsVirtualizedItemPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsVirtualizedItemPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsSynchronizedInputPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsSynchronizedInputPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("OptimizeForVisualContent").ToLocalChecked(), Nan::New(UIA_OptimizeForVisualContentPropertyId));
    Nan::Set(propertyIds, Nan::New("IsObjectModelPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsObjectModelPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("AnnotationAnnotationTypeId").ToLocalChecked(), Nan::New(UIA_AnnotationAnnotationTypeIdPropertyId));
    Nan::Set(propertyIds, Nan::New("AnnotationAnnotationTypeName").ToLocalChecked(), Nan::New(UIA_AnnotationAnnotationTypeNamePropertyId));
    Nan::Set(propertyIds, Nan::New("AnnotationAuthor").ToLocalChecked(), Nan::New(UIA_AnnotationAuthorPropertyId));
    Nan::Set(propertyIds, Nan::New("AnnotationDateTime").ToLocalChecked(), Nan::New(UIA_AnnotationDateTimePropertyId));
    Nan::Set(propertyIds, Nan::New("AnnotationTarget").ToLocalChecked(), Nan::New(UIA_AnnotationTargetPropertyId));
    Nan::Set(propertyIds, Nan::New("IsAnnotationPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsAnnotationPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsTextPattern2Available").ToLocalChecked(), Nan::New(UIA_IsTextPattern2AvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("StylesStyleId").ToLocalChecked(), Nan::New(UIA_StylesStyleIdPropertyId));
    Nan::Set(propertyIds, Nan::New("StylesStyleName").ToLocalChecked(), Nan::New(UIA_StylesStyleNamePropertyId));
    Nan::Set(propertyIds, Nan::New("StylesFillColor").ToLocalChecked(), Nan::New(UIA_StylesFillColorPropertyId));
    Nan::Set(propertyIds, Nan::New("StylesFillPatternStyle").ToLocalChecked(), Nan::New(UIA_StylesFillPatternStylePropertyId));
    Nan::Set(propertyIds, Nan::New("StylesShape").ToLocalChecked(), Nan::New(UIA_StylesShapePropertyId));
    Nan::Set(propertyIds, Nan::New("StylesFillPatternColor").ToLocalChecked(), Nan::New(UIA_StylesFillPatternColorPropertyId));
    Nan::Set(propertyIds, Nan::New("StylesExtendedProperties").ToLocalChecked(), Nan::New(UIA_StylesExtendedPropertiesPropertyId));
    Nan::Set(propertyIds, Nan::New("IsStylesPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsStylesPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsSpreadsheetPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsSpreadsheetPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("SpreadsheetItemFormula").ToLocalChecked(), Nan::New(UIA_SpreadsheetItemFormulaPropertyId));
    Nan::Set(propertyIds, Nan::New("SpreadsheetItemAnnotationObjects").ToLocalChecked(), Nan::New(UIA_SpreadsheetItemAnnotationObjectsPropertyId));
    Nan::Set(propertyIds, Nan::New("SpreadsheetItemAnnotationTypes").ToLocalChecked(), Nan::New(UIA_SpreadsheetItemAnnotationTypesPropertyId));
    Nan::Set(propertyIds, Nan::New("IsSpreadsheetItemPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsSpreadsheetItemPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("Transform2CanZoom").ToLocalChecked(), Nan::New(UIA_Transform2CanZoomPropertyId));
    Nan::Set(propertyIds, Nan::New("IsTransformPattern2Available").ToLocalChecked(), Nan::New(UIA_IsTransformPattern2AvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("LiveSetting").ToLocalChecked(), Nan::New(UIA_LiveSettingPropertyId));
    Nan::Set(propertyIds, Nan::New("IsTextChildPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsTextChildPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsDragPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsDragPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("DragIsGrabbed").ToLocalChecked(), Nan::New(UIA_DragIsGrabbedPropertyId));
    Nan::Set(propertyIds, Nan::New("DragDropEffect").ToLocalChecked(), Nan::New(UIA_DragDropEffectPropertyId));
    Nan::Set(propertyIds, Nan::New("DragDropEffects").ToLocalChecked(), Nan::New(UIA_DragDropEffectsPropertyId));
    Nan::Set(propertyIds, Nan::New("IsDropTargetPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsDropTargetPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("DropTargetDropTargetEffect").ToLocalChecked(), Nan::New(UIA_DropTargetDropTargetEffectPropertyId));
    Nan::Set(propertyIds, Nan::New("DropTargetDropTargetEffects").ToLocalChecked(), Nan::New(UIA_DropTargetDropTargetEffectsPropertyId));
    Nan::Set(propertyIds, Nan::New("DragGrabbedItems").ToLocalChecked(), Nan::New(UIA_DragGrabbedItemsPropertyId));
    Nan::Set(propertyIds, Nan::New("Transform2ZoomLevel").ToLocalChecked(), Nan::New(UIA_Transform2ZoomLevelPropertyId));
    Nan::Set(propertyIds, Nan::New("Transform2ZoomMinimum").ToLocalChecked(), Nan::New(UIA_Transform2ZoomMinimumPropertyId));
    Nan::Set(propertyIds, Nan::New("Transform2ZoomMaximum").ToLocalChecked(), Nan::New(UIA_Transform2ZoomMaximumPropertyId));
    Nan::Set(propertyIds, Nan::New("FlowsFrom").ToLocalChecked(), Nan::New(UIA_FlowsFromPropertyId));
    Nan::Set(propertyIds, Nan::New("IsTextEditPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsTextEditPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("IsPeripheral").ToLocalChecked(), Nan::New(UIA_IsPeripheralPropertyId));
    Nan::Set(propertyIds, Nan::New("IsCustomNavigationPatternAvailable").ToLocalChecked(), Nan::New(UIA_IsCustomNavigationPatternAvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("PositionInSet").ToLocalChecked(), Nan::New(UIA_PositionInSetPropertyId));
    Nan::Set(propertyIds, Nan::New("SizeOfSet").ToLocalChecked(), Nan::New(UIA_SizeOfSetPropertyId));
    Nan::Set(propertyIds, Nan::New("Level").ToLocalChecked(), Nan::New(UIA_LevelPropertyId));
    Nan::Set(propertyIds, Nan::New("AnnotationTypes").ToLocalChecked(), Nan::New(UIA_AnnotationTypesPropertyId));
    Nan::Set(propertyIds, Nan::New("AnnotationObjects").ToLocalChecked(), Nan::New(UIA_AnnotationObjectsPropertyId));
    Nan::Set(propertyIds, Nan::New("LandmarkType").ToLocalChecked(), Nan::New(UIA_LandmarkTypePropertyId));
    Nan::Set(propertyIds, Nan::New("LocalizedLandmarkType").ToLocalChecked(), Nan::New(UIA_LocalizedLandmarkTypePropertyId));
    Nan::Set(propertyIds, Nan::New("FullDescription").ToLocalChecked(), Nan::New(UIA_FullDescriptionPropertyId));
    Nan::Set(propertyIds, Nan::New("FillColor").ToLocalChecked(), Nan::New(UIA_FillColorPropertyId));
    Nan::Set(propertyIds, Nan::New("OutlineColor").ToLocalChecked(), Nan::New(UIA_OutlineColorPropertyId));
    Nan::Set(propertyIds, Nan::New("FillType").ToLocalChecked(), Nan::New(UIA_FillTypePropertyId));
    Nan::Set(propertyIds, Nan::New("VisualEffects").ToLocalChecked(), Nan::New(UIA_VisualEffectsPropertyId));
    Nan::Set(propertyIds, Nan::New("OutlineThickness").ToLocalChecked(), Nan::New(UIA_OutlineThicknessPropertyId));
    Nan::Set(propertyIds, Nan::New("CenterPoint").ToLocalChecked(), Nan::New(UIA_CenterPointPropertyId));
    Nan::Set(propertyIds, Nan::New("Rotation").ToLocalChecked(), Nan::New(UIA_RotationPropertyId));
    Nan::Set(propertyIds, Nan::New("Size").ToLocalChecked(), Nan::New(UIA_SizePropertyId));
    Nan::Set(propertyIds, Nan::New("IsSelectionPattern2Available").ToLocalChecked(), Nan::New(UIA_IsSelectionPattern2AvailablePropertyId));
    Nan::Set(propertyIds, Nan::New("Selection2FirstSelectedItem").ToLocalChecked(), Nan::New(UIA_Selection2FirstSelectedItemPropertyId));
    Nan::Set(propertyIds, Nan::New("Selection2LastSelectedItem").ToLocalChecked(), Nan::New(UIA_Selection2LastSelectedItemPropertyId));
    Nan::Set(propertyIds, Nan::New("Selection2CurrentSelectedItem").ToLocalChecked(), Nan::New(UIA_Selection2CurrentSelectedItemPropertyId));
    Nan::Set(propertyIds, Nan::New("Selection2ItemCount").ToLocalChecked(), Nan::New(UIA_Selection2ItemCountPropertyId));
    Nan::Set(propertyIds, Nan::New("HeadingLevel").ToLocalChecked(), Nan::New(UIA_HeadingLevelPropertyId));
    Nan::Set(propertyIds, Nan::New("IsDialog").ToLocalChecked(), Nan::New(UIA_IsDialogPropertyId));

    Nan::Set(target, Nan::New("PropertyIDs").ToLocalChecked(), propertyIds);
}
