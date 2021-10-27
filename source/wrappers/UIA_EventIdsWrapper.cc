#include "UIA_EventIdsWrapper.h"

Napi::Object UIA_EventIdsWrapper::Export(Napi::Env env, Napi::Object exports)
{
    exports.Set("UIA_ToolTipOpenedEventId", Napi::Number::New(env, UIA_ToolTipOpenedEventId));
    exports.Set("UIA_ToolTipClosedEventId", Napi::Number::New(env, UIA_ToolTipClosedEventId));
    exports.Set("UIA_StructureChangedEventId", Napi::Number::New(env, UIA_StructureChangedEventId));
    exports.Set("UIA_MenuOpenedEventId", Napi::Number::New(env, UIA_MenuOpenedEventId));
    exports.Set("UIA_AutomationPropertyChangedEventId", Napi::Number::New(env, UIA_AutomationPropertyChangedEventId));
    exports.Set("UIA_AutomationFocusChangedEventId", Napi::Number::New(env, UIA_AutomationFocusChangedEventId));
    exports.Set("UIA_AsyncContentLoadedEventId", Napi::Number::New(env, UIA_AsyncContentLoadedEventId));
    exports.Set("UIA_MenuClosedEventId", Napi::Number::New(env, UIA_MenuClosedEventId));
    exports.Set("UIA_LayoutInvalidatedEventId", Napi::Number::New(env, UIA_LayoutInvalidatedEventId));
    exports.Set("UIA_Invoke_InvokedEventId", Napi::Number::New(env, UIA_Invoke_InvokedEventId));
    exports.Set("UIA_SelectionItem_ElementAddedToSelectionEventId", Napi::Number::New(env, UIA_SelectionItem_ElementAddedToSelectionEventId));
    exports.Set("UIA_SelectionItem_ElementRemovedFromSelectionEventId", Napi::Number::New(env, UIA_SelectionItem_ElementRemovedFromSelectionEventId));
    exports.Set("UIA_SelectionItem_ElementSelectedEventId", Napi::Number::New(env, UIA_SelectionItem_ElementSelectedEventId));
    exports.Set("UIA_Selection_InvalidatedEventId", Napi::Number::New(env, UIA_Selection_InvalidatedEventId));
    exports.Set("UIA_Text_TextSelectionChangedEventId", Napi::Number::New(env, UIA_Text_TextSelectionChangedEventId));
    exports.Set("UIA_Text_TextChangedEventId", Napi::Number::New(env, UIA_Text_TextChangedEventId));
    exports.Set("UIA_Window_WindowOpenedEventId", Napi::Number::New(env, UIA_Window_WindowOpenedEventId));
    exports.Set("UIA_Window_WindowClosedEventId", Napi::Number::New(env, UIA_Window_WindowClosedEventId));
    exports.Set("UIA_MenuModeStartEventId", Napi::Number::New(env, UIA_MenuModeStartEventId));
    exports.Set("UIA_MenuModeEndEventId", Napi::Number::New(env, UIA_MenuModeEndEventId));
    exports.Set("UIA_InputReachedTargetEventId", Napi::Number::New(env, UIA_InputReachedTargetEventId));
    exports.Set("UIA_InputReachedOtherElementEventId", Napi::Number::New(env, UIA_InputReachedOtherElementEventId));
    exports.Set("UIA_InputDiscardedEventId", Napi::Number::New(env, UIA_InputDiscardedEventId));
    exports.Set("UIA_SystemAlertEventId", Napi::Number::New(env, UIA_SystemAlertEventId));
    exports.Set("UIA_LiveRegionChangedEventId", Napi::Number::New(env, UIA_LiveRegionChangedEventId));
    exports.Set("UIA_HostedFragmentRootsInvalidatedEventId", Napi::Number::New(env, UIA_HostedFragmentRootsInvalidatedEventId));
    exports.Set("UIA_Drag_DragStartEventId", Napi::Number::New(env, UIA_Drag_DragStartEventId));
    exports.Set("UIA_Drag_DragCancelEventId", Napi::Number::New(env, UIA_Drag_DragCancelEventId));
    exports.Set("UIA_Drag_DragCompleteEventId", Napi::Number::New(env, UIA_Drag_DragCompleteEventId));
    exports.Set("UIA_DropTarget_DragEnterEventId", Napi::Number::New(env, UIA_DropTarget_DragEnterEventId));
    exports.Set("UIA_DropTarget_DragLeaveEventId", Napi::Number::New(env, UIA_DropTarget_DragLeaveEventId));
    exports.Set("UIA_DropTarget_DroppedEventId", Napi::Number::New(env, UIA_DropTarget_DroppedEventId));
    exports.Set("UIA_TextEdit_TextChangedEventId", Napi::Number::New(env, UIA_TextEdit_TextChangedEventId));
    exports.Set("UIA_TextEdit_ConversionTargetChangedEventId", Napi::Number::New(env, UIA_TextEdit_ConversionTargetChangedEventId));
    exports.Set("UIA_ChangesEventId", Napi::Number::New(env, UIA_ChangesEventId));
    exports.Set("UIA_NotificationEventId", Napi::Number::New(env, UIA_NotificationEventId));
    exports.Set("UIA_ActiveTextPositionChangedEventId", Napi::Number::New(env, UIA_ActiveTextPositionChangedEventId));

    return exports;
}
