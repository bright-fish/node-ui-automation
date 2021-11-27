#include "EventIdsWrapper.h"

Napi::Object EventIdsWrapper::New(Napi::Env env)
{
    auto eventIds = Napi::Object::New(env);

    eventIds.Set("ToolTipOpenedEventId", Napi::Number::New(env, UIA_ToolTipOpenedEventId));
    eventIds.Set("ToolTipClosedEventId", Napi::Number::New(env, UIA_ToolTipClosedEventId));
    eventIds.Set("StructureChangedEventId", Napi::Number::New(env, UIA_StructureChangedEventId));
    eventIds.Set("MenuOpenedEventId", Napi::Number::New(env, UIA_MenuOpenedEventId));
    eventIds.Set("AutomationPropertyChangedEventId", Napi::Number::New(env, UIA_AutomationPropertyChangedEventId));
    eventIds.Set("AutomationFocusChangedEventId", Napi::Number::New(env, UIA_AutomationFocusChangedEventId));
    eventIds.Set("AsyncContentLoadedEventId", Napi::Number::New(env, UIA_AsyncContentLoadedEventId));
    eventIds.Set("MenuClosedEventId", Napi::Number::New(env, UIA_MenuClosedEventId));
    eventIds.Set("LayoutInvalidatedEventId", Napi::Number::New(env, UIA_LayoutInvalidatedEventId));
    eventIds.Set("Invoke_InvokedEventId", Napi::Number::New(env, UIA_Invoke_InvokedEventId));
    eventIds.Set("SelectionItem_ElementAddedToSelectionEventId", Napi::Number::New(env, UIA_SelectionItem_ElementAddedToSelectionEventId));
    eventIds.Set("SelectionItem_ElementRemovedFromSelectionEventId", Napi::Number::New(env, UIA_SelectionItem_ElementRemovedFromSelectionEventId));
    eventIds.Set("SelectionItem_ElementSelectedEventId", Napi::Number::New(env, UIA_SelectionItem_ElementSelectedEventId));
    eventIds.Set("Selection_InvalidatedEventId", Napi::Number::New(env, UIA_Selection_InvalidatedEventId));
    eventIds.Set("Text_TextSelectionChangedEventId", Napi::Number::New(env, UIA_Text_TextSelectionChangedEventId));
    eventIds.Set("Text_TextChangedEventId", Napi::Number::New(env, UIA_Text_TextChangedEventId));
    eventIds.Set("Window_WindowOpenedEventId", Napi::Number::New(env, UIA_Window_WindowOpenedEventId));
    eventIds.Set("Window_WindowClosedEventId", Napi::Number::New(env, UIA_Window_WindowClosedEventId));
    eventIds.Set("MenuModeStartEventId", Napi::Number::New(env, UIA_MenuModeStartEventId));
    eventIds.Set("MenuModeEndEventId", Napi::Number::New(env, UIA_MenuModeEndEventId));
    eventIds.Set("InputReachedTargetEventId", Napi::Number::New(env, UIA_InputReachedTargetEventId));
    eventIds.Set("InputReachedOtherElementEventId", Napi::Number::New(env, UIA_InputReachedOtherElementEventId));
    eventIds.Set("InputDiscardedEventId", Napi::Number::New(env, UIA_InputDiscardedEventId));
    eventIds.Set("SystemAlertEventId", Napi::Number::New(env, UIA_SystemAlertEventId));
    eventIds.Set("LiveRegionChangedEventId", Napi::Number::New(env, UIA_LiveRegionChangedEventId));
    eventIds.Set("HostedFragmentRootsInvalidatedEventId", Napi::Number::New(env, UIA_HostedFragmentRootsInvalidatedEventId));
    eventIds.Set("Drag_DragStartEventId", Napi::Number::New(env, UIA_Drag_DragStartEventId));
    eventIds.Set("Drag_DragCancelEventId", Napi::Number::New(env, UIA_Drag_DragCancelEventId));
    eventIds.Set("Drag_DragCompleteEventId", Napi::Number::New(env, UIA_Drag_DragCompleteEventId));
    eventIds.Set("DropTarget_DragEnterEventId", Napi::Number::New(env, UIA_DropTarget_DragEnterEventId));
    eventIds.Set("DropTarget_DragLeaveEventId", Napi::Number::New(env, UIA_DropTarget_DragLeaveEventId));
    eventIds.Set("DropTarget_DroppedEventId", Napi::Number::New(env, UIA_DropTarget_DroppedEventId));
    eventIds.Set("TextEdit_TextChangedEventId", Napi::Number::New(env, UIA_TextEdit_TextChangedEventId));
    eventIds.Set("TextEdit_ConversionTargetChangedEventId", Napi::Number::New(env, UIA_TextEdit_ConversionTargetChangedEventId));
    eventIds.Set("ChangesEventId", Napi::Number::New(env, UIA_ChangesEventId));
    eventIds.Set("NotificationEventId", Napi::Number::New(env, UIA_NotificationEventId));
    eventIds.Set("ActiveTextPositionChangedEventId", Napi::Number::New(env, UIA_ActiveTextPositionChangedEventId));

    return eventIds;
}
