#include "UIA_EventIdsWrapper.h"

Napi::Object UIA_EventIdsWrapper::New(Napi::Env env)
{
    auto automationEvents = Napi::Object::New(env);

    automationEvents.Set("ToolTipOpenedEventId", Napi::Number::New(env, UIA_ToolTipOpenedEventId));
    automationEvents.Set("ToolTipClosedEventId", Napi::Number::New(env, UIA_ToolTipClosedEventId));
    automationEvents.Set("StructureChangedEventId", Napi::Number::New(env, UIA_StructureChangedEventId));
    automationEvents.Set("MenuOpenedEventId", Napi::Number::New(env, UIA_MenuOpenedEventId));
    automationEvents.Set("AutomationPropertyChangedEventId", Napi::Number::New(env, UIA_AutomationPropertyChangedEventId));
    automationEvents.Set("AutomationFocusChangedEventId", Napi::Number::New(env, UIA_AutomationFocusChangedEventId));
    automationEvents.Set("AsyncContentLoadedEventId", Napi::Number::New(env, UIA_AsyncContentLoadedEventId));
    automationEvents.Set("MenuClosedEventId", Napi::Number::New(env, UIA_MenuClosedEventId));
    automationEvents.Set("LayoutInvalidatedEventId", Napi::Number::New(env, UIA_LayoutInvalidatedEventId));
    automationEvents.Set("Invoke_InvokedEventId", Napi::Number::New(env, UIA_Invoke_InvokedEventId));
    automationEvents.Set("SelectionItem_ElementAddedToSelectionEventId", Napi::Number::New(env, UIA_SelectionItem_ElementAddedToSelectionEventId));
    automationEvents.Set("SelectionItem_ElementRemovedFromSelectionEventId", Napi::Number::New(env, UIA_SelectionItem_ElementRemovedFromSelectionEventId));
    automationEvents.Set("SelectionItem_ElementSelectedEventId", Napi::Number::New(env, UIA_SelectionItem_ElementSelectedEventId));
    automationEvents.Set("Selection_InvalidatedEventId", Napi::Number::New(env, UIA_Selection_InvalidatedEventId));
    automationEvents.Set("Text_TextSelectionChangedEventId", Napi::Number::New(env, UIA_Text_TextSelectionChangedEventId));
    automationEvents.Set("Text_TextChangedEventId", Napi::Number::New(env, UIA_Text_TextChangedEventId));
    automationEvents.Set("Window_WindowOpenedEventId", Napi::Number::New(env, UIA_Window_WindowOpenedEventId));
    automationEvents.Set("Window_WindowClosedEventId", Napi::Number::New(env, UIA_Window_WindowClosedEventId));
    automationEvents.Set("MenuModeStartEventId", Napi::Number::New(env, UIA_MenuModeStartEventId));
    automationEvents.Set("MenuModeEndEventId", Napi::Number::New(env, UIA_MenuModeEndEventId));
    automationEvents.Set("InputReachedTargetEventId", Napi::Number::New(env, UIA_InputReachedTargetEventId));
    automationEvents.Set("InputReachedOtherElementEventId", Napi::Number::New(env, UIA_InputReachedOtherElementEventId));
    automationEvents.Set("InputDiscardedEventId", Napi::Number::New(env, UIA_InputDiscardedEventId));
    automationEvents.Set("SystemAlertEventId", Napi::Number::New(env, UIA_SystemAlertEventId));
    automationEvents.Set("LiveRegionChangedEventId", Napi::Number::New(env, UIA_LiveRegionChangedEventId));
    automationEvents.Set("HostedFragmentRootsInvalidatedEventId", Napi::Number::New(env, UIA_HostedFragmentRootsInvalidatedEventId));
    automationEvents.Set("Drag_DragStartEventId", Napi::Number::New(env, UIA_Drag_DragStartEventId));
    automationEvents.Set("Drag_DragCancelEventId", Napi::Number::New(env, UIA_Drag_DragCancelEventId));
    automationEvents.Set("Drag_DragCompleteEventId", Napi::Number::New(env, UIA_Drag_DragCompleteEventId));
    automationEvents.Set("DropTarget_DragEnterEventId", Napi::Number::New(env, UIA_DropTarget_DragEnterEventId));
    automationEvents.Set("DropTarget_DragLeaveEventId", Napi::Number::New(env, UIA_DropTarget_DragLeaveEventId));
    automationEvents.Set("DropTarget_DroppedEventId", Napi::Number::New(env, UIA_DropTarget_DroppedEventId));
    automationEvents.Set("TextEdit_TextChangedEventId", Napi::Number::New(env, UIA_TextEdit_TextChangedEventId));
    automationEvents.Set("TextEdit_ConversionTargetChangedEventId", Napi::Number::New(env, UIA_TextEdit_ConversionTargetChangedEventId));
    automationEvents.Set("ChangesEventId", Napi::Number::New(env, UIA_ChangesEventId));
    automationEvents.Set("NotificationEventId", Napi::Number::New(env, UIA_NotificationEventId));
    automationEvents.Set("ActiveTextPositionChangedEventId", Napi::Number::New(env, UIA_ActiveTextPositionChangedEventId));

    return automationEvents;
}
