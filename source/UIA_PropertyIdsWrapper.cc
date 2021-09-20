#include "Library.h"

using Napi::Object;

Napi::Object UIA_PropertyIdsWrapper::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("UIA_NamePropertyId", Napi::Number::New(env, UIA_NamePropertyId));
    exports.Set("UIA_NativeWindowHandlePropertyId", Napi::Number::New(env, UIA_NativeWindowHandlePropertyId));
    exports.Set("UIA_NavigationLandmarkTypeId", Napi::Number::New(env, UIA_NavigationLandmarkTypeId));
    exports.Set("UIA_RuntimeIdPropertyId", Napi::Number::New(env, UIA_RuntimeIdPropertyId));
    exports.Set("UIA_BoundingRectanglePropertyId", Napi::Number::New(env, UIA_BoundingRectanglePropertyId));
    exports.Set("UIA_ProcessIdPropertyId", Napi::Number::New(env, UIA_ProcessIdPropertyId));
    exports.Set("UIA_ControlTypePropertyId", Napi::Number::New(env, UIA_ControlTypePropertyId));
    exports.Set("UIA_LocalizedControlTypePropertyId", Napi::Number::New(env, UIA_LocalizedControlTypePropertyId));
    exports.Set("UIA_NamePropertyId", Napi::Number::New(env, UIA_NamePropertyId));
    exports.Set("UIA_AcceleratorKeyPropertyId", Napi::Number::New(env, UIA_AcceleratorKeyPropertyId));
    exports.Set("UIA_AccessKeyPropertyId", Napi::Number::New(env, UIA_AccessKeyPropertyId));
    exports.Set("UIA_HasKeyboardFocusPropertyId", Napi::Number::New(env, UIA_HasKeyboardFocusPropertyId));
    exports.Set("UIA_IsKeyboardFocusablePropertyId", Napi::Number::New(env, UIA_IsKeyboardFocusablePropertyId));
    exports.Set("UIA_IsEnabledPropertyId", Napi::Number::New(env, UIA_IsEnabledPropertyId));
    exports.Set("UIA_AutomationIdPropertyId", Napi::Number::New(env, UIA_AutomationIdPropertyId));
    exports.Set("UIA_ClassNamePropertyId", Napi::Number::New(env, UIA_ClassNamePropertyId));
    exports.Set("UIA_HelpTextPropertyId", Napi::Number::New(env, UIA_HelpTextPropertyId));
    exports.Set("UIA_ClickablePointPropertyId", Napi::Number::New(env, UIA_ClickablePointPropertyId));
    exports.Set("UIA_CulturePropertyId", Napi::Number::New(env, UIA_CulturePropertyId));
    exports.Set("UIA_IsControlElementPropertyId", Napi::Number::New(env, UIA_IsControlElementPropertyId));
    exports.Set("UIA_IsContentElementPropertyId", Napi::Number::New(env, UIA_IsContentElementPropertyId));
    exports.Set("UIA_LabeledByPropertyId", Napi::Number::New(env, UIA_LabeledByPropertyId));
    exports.Set("UIA_IsPasswordPropertyId", Napi::Number::New(env, UIA_IsPasswordPropertyId));
    exports.Set("UIA_NativeWindowHandlePropertyId", Napi::Number::New(env, UIA_NativeWindowHandlePropertyId));
    exports.Set("UIA_ItemTypePropertyId", Napi::Number::New(env, UIA_ItemTypePropertyId));
    exports.Set("UIA_IsOffscreenPropertyId", Napi::Number::New(env, UIA_IsOffscreenPropertyId));
    exports.Set("UIA_OrientationPropertyId", Napi::Number::New(env, UIA_OrientationPropertyId));
    exports.Set("UIA_FrameworkIdPropertyId", Napi::Number::New(env, UIA_FrameworkIdPropertyId));
    exports.Set("UIA_IsRequiredForFormPropertyId", Napi::Number::New(env, UIA_IsRequiredForFormPropertyId));
    exports.Set("UIA_ItemStatusPropertyId", Napi::Number::New(env, UIA_ItemStatusPropertyId));
    exports.Set("UIA_IsDockPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsDockPatternAvailablePropertyId));
    exports.Set("UIA_IsExpandCollapsePatternAvailablePropertyId", Napi::Number::New(env, UIA_IsExpandCollapsePatternAvailablePropertyId));
    exports.Set("UIA_IsGridItemPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsGridItemPatternAvailablePropertyId));
    exports.Set("UIA_IsGridPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsGridPatternAvailablePropertyId));
    exports.Set("UIA_IsInvokePatternAvailablePropertyId", Napi::Number::New(env, UIA_IsInvokePatternAvailablePropertyId));
    exports.Set("UIA_IsMultipleViewPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsMultipleViewPatternAvailablePropertyId));
    exports.Set("UIA_IsRangeValuePatternAvailablePropertyId", Napi::Number::New(env, UIA_IsRangeValuePatternAvailablePropertyId));
    exports.Set("UIA_IsScrollPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsScrollPatternAvailablePropertyId));
    exports.Set("UIA_IsScrollItemPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsScrollItemPatternAvailablePropertyId));
    exports.Set("UIA_IsSelectionItemPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsSelectionItemPatternAvailablePropertyId));
    exports.Set("UIA_IsSelectionPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsSelectionPatternAvailablePropertyId));
    exports.Set("UIA_IsTablePatternAvailablePropertyId", Napi::Number::New(env, UIA_IsTablePatternAvailablePropertyId));
    exports.Set("UIA_IsTableItemPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsTableItemPatternAvailablePropertyId));
    exports.Set("UIA_IsTextPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsTextPatternAvailablePropertyId));
    exports.Set("UIA_IsTogglePatternAvailablePropertyId", Napi::Number::New(env, UIA_IsTogglePatternAvailablePropertyId));
    exports.Set("UIA_IsTransformPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsTransformPatternAvailablePropertyId));
    exports.Set("UIA_IsValuePatternAvailablePropertyId", Napi::Number::New(env, UIA_IsValuePatternAvailablePropertyId));
    exports.Set("UIA_IsWindowPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsWindowPatternAvailablePropertyId));
    exports.Set("UIA_ValueValuePropertyId", Napi::Number::New(env, UIA_ValueValuePropertyId));
    exports.Set("UIA_ValueIsReadOnlyPropertyId", Napi::Number::New(env, UIA_ValueIsReadOnlyPropertyId));
    exports.Set("UIA_RangeValueValuePropertyId", Napi::Number::New(env, UIA_RangeValueValuePropertyId));
    exports.Set("UIA_RangeValueIsReadOnlyPropertyId", Napi::Number::New(env, UIA_RangeValueIsReadOnlyPropertyId));
    exports.Set("UIA_RangeValueMinimumPropertyId", Napi::Number::New(env, UIA_RangeValueMinimumPropertyId));
    exports.Set("UIA_RangeValueMaximumPropertyId", Napi::Number::New(env, UIA_RangeValueMaximumPropertyId));
    exports.Set("UIA_RangeValueLargeChangePropertyId", Napi::Number::New(env, UIA_RangeValueLargeChangePropertyId));
    exports.Set("UIA_RangeValueSmallChangePropertyId", Napi::Number::New(env, UIA_RangeValueSmallChangePropertyId));
    exports.Set("UIA_ScrollHorizontalScrollPercentPropertyId", Napi::Number::New(env, UIA_ScrollHorizontalScrollPercentPropertyId));
    exports.Set("UIA_ScrollHorizontalViewSizePropertyId", Napi::Number::New(env, UIA_ScrollHorizontalViewSizePropertyId));
    exports.Set("UIA_ScrollVerticalScrollPercentPropertyId", Napi::Number::New(env, UIA_ScrollVerticalScrollPercentPropertyId));
    exports.Set("UIA_ScrollVerticalViewSizePropertyId", Napi::Number::New(env, UIA_ScrollVerticalViewSizePropertyId));
    exports.Set("UIA_ScrollHorizontallyScrollablePropertyId", Napi::Number::New(env, UIA_ScrollHorizontallyScrollablePropertyId));
    exports.Set("UIA_ScrollVerticallyScrollablePropertyId", Napi::Number::New(env, UIA_ScrollVerticallyScrollablePropertyId));
    exports.Set("UIA_SelectionSelectionPropertyId", Napi::Number::New(env, UIA_SelectionSelectionPropertyId));
    exports.Set("UIA_SelectionCanSelectMultiplePropertyId", Napi::Number::New(env, UIA_SelectionCanSelectMultiplePropertyId));
    exports.Set("UIA_SelectionIsSelectionRequiredPropertyId", Napi::Number::New(env, UIA_SelectionIsSelectionRequiredPropertyId));
    exports.Set("UIA_GridRowCountPropertyId", Napi::Number::New(env, UIA_GridRowCountPropertyId));
    exports.Set("UIA_GridColumnCountPropertyId", Napi::Number::New(env, UIA_GridColumnCountPropertyId));
    exports.Set("UIA_GridItemRowPropertyId", Napi::Number::New(env, UIA_GridItemRowPropertyId));
    exports.Set("UIA_GridItemColumnPropertyId", Napi::Number::New(env, UIA_GridItemColumnPropertyId));
    exports.Set("UIA_GridItemRowSpanPropertyId", Napi::Number::New(env, UIA_GridItemRowSpanPropertyId));
    exports.Set("UIA_GridItemColumnSpanPropertyId", Napi::Number::New(env, UIA_GridItemColumnSpanPropertyId));
    exports.Set("UIA_GridItemContainingGridPropertyId", Napi::Number::New(env, UIA_GridItemContainingGridPropertyId));
    exports.Set("UIA_DockDockPositionPropertyId", Napi::Number::New(env, UIA_DockDockPositionPropertyId));
    exports.Set("UIA_ExpandCollapseExpandCollapseStatePropertyId", Napi::Number::New(env, UIA_ExpandCollapseExpandCollapseStatePropertyId));
    exports.Set("UIA_MultipleViewCurrentViewPropertyId", Napi::Number::New(env, UIA_MultipleViewCurrentViewPropertyId));
    exports.Set("UIA_MultipleViewSupportedViewsPropertyId", Napi::Number::New(env, UIA_MultipleViewSupportedViewsPropertyId));
    exports.Set("UIA_WindowCanMaximizePropertyId", Napi::Number::New(env, UIA_WindowCanMaximizePropertyId));
    exports.Set("UIA_WindowCanMinimizePropertyId", Napi::Number::New(env, UIA_WindowCanMinimizePropertyId));
    exports.Set("UIA_WindowWindowVisualStatePropertyId", Napi::Number::New(env, UIA_WindowWindowVisualStatePropertyId));
    exports.Set("UIA_WindowWindowInteractionStatePropertyId", Napi::Number::New(env, UIA_WindowWindowInteractionStatePropertyId));
    exports.Set("UIA_WindowIsModalPropertyId", Napi::Number::New(env, UIA_WindowIsModalPropertyId));
    exports.Set("UIA_WindowIsTopmostPropertyId", Napi::Number::New(env, UIA_WindowIsTopmostPropertyId));
    exports.Set("UIA_SelectionItemIsSelectedPropertyId", Napi::Number::New(env, UIA_SelectionItemIsSelectedPropertyId));
    exports.Set("UIA_SelectionItemSelectionContainerPropertyId", Napi::Number::New(env, UIA_SelectionItemSelectionContainerPropertyId));
    exports.Set("UIA_TableRowHeadersPropertyId", Napi::Number::New(env, UIA_TableRowHeadersPropertyId));
    exports.Set("UIA_TableColumnHeadersPropertyId", Napi::Number::New(env, UIA_TableColumnHeadersPropertyId));
    exports.Set("UIA_TableRowOrColumnMajorPropertyId", Napi::Number::New(env, UIA_TableRowOrColumnMajorPropertyId));
    exports.Set("UIA_TableItemRowHeaderItemsPropertyId", Napi::Number::New(env, UIA_TableItemRowHeaderItemsPropertyId));
    exports.Set("UIA_TableItemColumnHeaderItemsPropertyId", Napi::Number::New(env, UIA_TableItemColumnHeaderItemsPropertyId));
    exports.Set("UIA_ToggleToggleStatePropertyId", Napi::Number::New(env, UIA_ToggleToggleStatePropertyId));
    exports.Set("UIA_TransformCanMovePropertyId", Napi::Number::New(env, UIA_TransformCanMovePropertyId));
    exports.Set("UIA_TransformCanResizePropertyId", Napi::Number::New(env, UIA_TransformCanResizePropertyId));
    exports.Set("UIA_TransformCanRotatePropertyId", Napi::Number::New(env, UIA_TransformCanRotatePropertyId));
    exports.Set("UIA_IsLegacyIAccessiblePatternAvailablePropertyId", Napi::Number::New(env, UIA_IsLegacyIAccessiblePatternAvailablePropertyId));
    exports.Set("UIA_LegacyIAccessibleChildIdPropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleChildIdPropertyId));
    exports.Set("UIA_LegacyIAccessibleNamePropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleNamePropertyId));
    exports.Set("UIA_LegacyIAccessibleValuePropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleValuePropertyId));
    exports.Set("UIA_LegacyIAccessibleDescriptionPropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleDescriptionPropertyId));
    exports.Set("UIA_LegacyIAccessibleRolePropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleRolePropertyId));
    exports.Set("UIA_LegacyIAccessibleStatePropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleStatePropertyId));
    exports.Set("UIA_LegacyIAccessibleHelpPropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleHelpPropertyId));
    exports.Set("UIA_LegacyIAccessibleKeyboardShortcutPropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleKeyboardShortcutPropertyId));
    exports.Set("UIA_LegacyIAccessibleSelectionPropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleSelectionPropertyId));
    exports.Set("UIA_LegacyIAccessibleDefaultActionPropertyId", Napi::Number::New(env, UIA_LegacyIAccessibleDefaultActionPropertyId));
    exports.Set("UIA_AriaRolePropertyId", Napi::Number::New(env, UIA_AriaRolePropertyId));
    exports.Set("UIA_AriaPropertiesPropertyId", Napi::Number::New(env, UIA_AriaPropertiesPropertyId));
    exports.Set("UIA_IsDataValidForFormPropertyId", Napi::Number::New(env, UIA_IsDataValidForFormPropertyId));
    exports.Set("UIA_ControllerForPropertyId", Napi::Number::New(env, UIA_ControllerForPropertyId));
    exports.Set("UIA_DescribedByPropertyId", Napi::Number::New(env, UIA_DescribedByPropertyId));
    exports.Set("UIA_FlowsToPropertyId", Napi::Number::New(env, UIA_FlowsToPropertyId));
    exports.Set("UIA_ProviderDescriptionPropertyId", Napi::Number::New(env, UIA_ProviderDescriptionPropertyId));
    exports.Set("UIA_IsItemContainerPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsItemContainerPatternAvailablePropertyId));
    exports.Set("UIA_IsVirtualizedItemPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsVirtualizedItemPatternAvailablePropertyId));
    exports.Set("UIA_IsSynchronizedInputPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsSynchronizedInputPatternAvailablePropertyId));
    exports.Set("UIA_OptimizeForVisualContentPropertyId", Napi::Number::New(env, UIA_OptimizeForVisualContentPropertyId));
    exports.Set("UIA_IsObjectModelPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsObjectModelPatternAvailablePropertyId));
    exports.Set("UIA_AnnotationAnnotationTypeIdPropertyId", Napi::Number::New(env, UIA_AnnotationAnnotationTypeIdPropertyId));
    exports.Set("UIA_AnnotationAnnotationTypeNamePropertyId", Napi::Number::New(env, UIA_AnnotationAnnotationTypeNamePropertyId));
    exports.Set("UIA_AnnotationAuthorPropertyId", Napi::Number::New(env, UIA_AnnotationAuthorPropertyId));
    exports.Set("UIA_AnnotationDateTimePropertyId", Napi::Number::New(env, UIA_AnnotationDateTimePropertyId));
    exports.Set("UIA_AnnotationTargetPropertyId", Napi::Number::New(env, UIA_AnnotationTargetPropertyId));
    exports.Set("UIA_IsAnnotationPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsAnnotationPatternAvailablePropertyId));
    exports.Set("UIA_IsTextPattern2AvailablePropertyId", Napi::Number::New(env, UIA_IsTextPattern2AvailablePropertyId));
    exports.Set("UIA_StylesStyleIdPropertyId", Napi::Number::New(env, UIA_StylesStyleIdPropertyId));
    exports.Set("UIA_StylesStyleNamePropertyId", Napi::Number::New(env, UIA_StylesStyleNamePropertyId));
    exports.Set("UIA_StylesFillColorPropertyId", Napi::Number::New(env, UIA_StylesFillColorPropertyId));
    exports.Set("UIA_StylesFillPatternStylePropertyId", Napi::Number::New(env, UIA_StylesFillPatternStylePropertyId));
    exports.Set("UIA_StylesShapePropertyId", Napi::Number::New(env, UIA_StylesShapePropertyId));
    exports.Set("UIA_StylesFillPatternColorPropertyId", Napi::Number::New(env, UIA_StylesFillPatternColorPropertyId));
    exports.Set("UIA_StylesExtendedPropertiesPropertyId", Napi::Number::New(env, UIA_StylesExtendedPropertiesPropertyId));
    exports.Set("UIA_IsStylesPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsStylesPatternAvailablePropertyId));
    exports.Set("UIA_IsSpreadsheetPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsSpreadsheetPatternAvailablePropertyId));
    exports.Set("UIA_SpreadsheetItemFormulaPropertyId", Napi::Number::New(env, UIA_SpreadsheetItemFormulaPropertyId));
    exports.Set("UIA_SpreadsheetItemAnnotationObjectsPropertyId", Napi::Number::New(env, UIA_SpreadsheetItemAnnotationObjectsPropertyId));
    exports.Set("UIA_SpreadsheetItemAnnotationTypesPropertyId", Napi::Number::New(env, UIA_SpreadsheetItemAnnotationTypesPropertyId));
    exports.Set("UIA_IsSpreadsheetItemPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsSpreadsheetItemPatternAvailablePropertyId));
    exports.Set("UIA_Transform2CanZoomPropertyId", Napi::Number::New(env, UIA_Transform2CanZoomPropertyId));
    exports.Set("UIA_IsTransformPattern2AvailablePropertyId", Napi::Number::New(env, UIA_IsTransformPattern2AvailablePropertyId));
    exports.Set("UIA_LiveSettingPropertyId", Napi::Number::New(env, UIA_LiveSettingPropertyId));
    exports.Set("UIA_IsTextChildPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsTextChildPatternAvailablePropertyId));
    exports.Set("UIA_IsDragPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsDragPatternAvailablePropertyId));
    exports.Set("UIA_DragIsGrabbedPropertyId", Napi::Number::New(env, UIA_DragIsGrabbedPropertyId));
    exports.Set("UIA_DragDropEffectPropertyId", Napi::Number::New(env, UIA_DragDropEffectPropertyId));
    exports.Set("UIA_DragDropEffectsPropertyId", Napi::Number::New(env, UIA_DragDropEffectsPropertyId));
    exports.Set("UIA_IsDropTargetPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsDropTargetPatternAvailablePropertyId));
    exports.Set("UIA_DropTargetDropTargetEffectPropertyId", Napi::Number::New(env, UIA_DropTargetDropTargetEffectPropertyId));
    exports.Set("UIA_DropTargetDropTargetEffectsPropertyId", Napi::Number::New(env, UIA_DropTargetDropTargetEffectsPropertyId));
    exports.Set("UIA_DragGrabbedItemsPropertyId", Napi::Number::New(env, UIA_DragGrabbedItemsPropertyId));
    exports.Set("UIA_Transform2ZoomLevelPropertyId", Napi::Number::New(env, UIA_Transform2ZoomLevelPropertyId));
    exports.Set("UIA_Transform2ZoomMinimumPropertyId", Napi::Number::New(env, UIA_Transform2ZoomMinimumPropertyId));
    exports.Set("UIA_Transform2ZoomMaximumPropertyId", Napi::Number::New(env, UIA_Transform2ZoomMaximumPropertyId));
    exports.Set("UIA_FlowsFromPropertyId", Napi::Number::New(env, UIA_FlowsFromPropertyId));
    exports.Set("UIA_IsTextEditPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsTextEditPatternAvailablePropertyId));
    exports.Set("UIA_IsPeripheralPropertyId", Napi::Number::New(env, UIA_IsPeripheralPropertyId));
    exports.Set("UIA_IsCustomNavigationPatternAvailablePropertyId", Napi::Number::New(env, UIA_IsCustomNavigationPatternAvailablePropertyId));
    exports.Set("UIA_PositionInSetPropertyId", Napi::Number::New(env, UIA_PositionInSetPropertyId));
    exports.Set("UIA_SizeOfSetPropertyId", Napi::Number::New(env, UIA_SizeOfSetPropertyId));
    exports.Set("UIA_LevelPropertyId", Napi::Number::New(env, UIA_LevelPropertyId));
    exports.Set("UIA_AnnotationTypesPropertyId", Napi::Number::New(env, UIA_AnnotationTypesPropertyId));
    exports.Set("UIA_AnnotationObjectsPropertyId", Napi::Number::New(env, UIA_AnnotationObjectsPropertyId));
    exports.Set("UIA_LandmarkTypePropertyId", Napi::Number::New(env, UIA_LandmarkTypePropertyId));
    exports.Set("UIA_LocalizedLandmarkTypePropertyId", Napi::Number::New(env, UIA_LocalizedLandmarkTypePropertyId));
    exports.Set("UIA_FullDescriptionPropertyId", Napi::Number::New(env, UIA_FullDescriptionPropertyId));
    exports.Set("UIA_FillColorPropertyId", Napi::Number::New(env, UIA_FillColorPropertyId));
    exports.Set("UIA_OutlineColorPropertyId", Napi::Number::New(env, UIA_OutlineColorPropertyId));
    exports.Set("UIA_FillTypePropertyId", Napi::Number::New(env, UIA_FillTypePropertyId));
    exports.Set("UIA_VisualEffectsPropertyId", Napi::Number::New(env, UIA_VisualEffectsPropertyId));
    exports.Set("UIA_OutlineThicknessPropertyId", Napi::Number::New(env, UIA_OutlineThicknessPropertyId));
    exports.Set("UIA_CenterPointPropertyId", Napi::Number::New(env, UIA_CenterPointPropertyId));
    exports.Set("UIA_RotationPropertyId", Napi::Number::New(env, UIA_RotationPropertyId));
    exports.Set("UIA_SizePropertyId", Napi::Number::New(env, UIA_SizePropertyId));
    exports.Set("UIA_IsSelectionPattern2AvailablePropertyId", Napi::Number::New(env, UIA_IsSelectionPattern2AvailablePropertyId));
    exports.Set("UIA_Selection2FirstSelectedItemPropertyId", Napi::Number::New(env, UIA_Selection2FirstSelectedItemPropertyId));
    exports.Set("UIA_Selection2LastSelectedItemPropertyId", Napi::Number::New(env, UIA_Selection2LastSelectedItemPropertyId));
    exports.Set("UIA_Selection2CurrentSelectedItemPropertyId", Napi::Number::New(env, UIA_Selection2CurrentSelectedItemPropertyId));
    exports.Set("UIA_Selection2ItemCountPropertyId", Napi::Number::New(env, UIA_Selection2ItemCountPropertyId));
    exports.Set("UIA_HeadingLevelPropertyId", Napi::Number::New(env, UIA_HeadingLevelPropertyId));
    exports.Set("UIA_IsDialogPropertyId", Napi::Number::New(env, UIA_IsDialogPropertyId));

    return exports;
}
