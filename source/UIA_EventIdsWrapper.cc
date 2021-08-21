#include "UIA_EventIdsWrapper.h"

using v8::Isolate;
using v8::Local;
using v8::Object;

NAN_MODULE_INIT(UIA_EventIdsWrapper::Init)
{
    Nan::Set(target, Nan::New("UIA_ToolTipOpenedEventId").ToLocalChecked(), Nan::New(UIA_ToolTipOpenedEventId));
    Nan::Set(target, Nan::New("UIA_ToolTipClosedEventId").ToLocalChecked(), Nan::New(UIA_ToolTipClosedEventId));
    Nan::Set(target, Nan::New("UIA_StructureChangedEventId").ToLocalChecked(), Nan::New(UIA_StructureChangedEventId));
    Nan::Set(target, Nan::New("UIA_MenuOpenedEventId").ToLocalChecked(), Nan::New(UIA_MenuOpenedEventId));
    Nan::Set(target, Nan::New("UIA_AutomationPropertyChangedEventId").ToLocalChecked(), Nan::New(UIA_AutomationPropertyChangedEventId));
    Nan::Set(target, Nan::New("UIA_AutomationFocusChangedEventId").ToLocalChecked(), Nan::New(UIA_AutomationFocusChangedEventId));
    Nan::Set(target, Nan::New("UIA_AsyncContentLoadedEventId").ToLocalChecked(), Nan::New(UIA_AsyncContentLoadedEventId));
    Nan::Set(target, Nan::New("UIA_MenuClosedEventId").ToLocalChecked(), Nan::New(UIA_MenuClosedEventId));
    Nan::Set(target, Nan::New("UIA_LayoutInvalidatedEventId").ToLocalChecked(), Nan::New(UIA_LayoutInvalidatedEventId));
    Nan::Set(target, Nan::New("UIA_Invoke_InvokedEventId").ToLocalChecked(), Nan::New(UIA_Invoke_InvokedEventId));
    Nan::Set(target, Nan::New("UIA_SelectionItem_ElementAddedToSelectionEventId").ToLocalChecked(), Nan::New(UIA_SelectionItem_ElementAddedToSelectionEventId));
    Nan::Set(target, Nan::New("UIA_SelectionItem_ElementRemovedFromSelectionEventId").ToLocalChecked(), Nan::New(UIA_SelectionItem_ElementRemovedFromSelectionEventId));
    Nan::Set(target, Nan::New("UIA_SelectionItem_ElementSelectedEventId").ToLocalChecked(), Nan::New(UIA_SelectionItem_ElementSelectedEventId));
    Nan::Set(target, Nan::New("UIA_Selection_InvalidatedEventId").ToLocalChecked(), Nan::New(UIA_Selection_InvalidatedEventId));
    Nan::Set(target, Nan::New("UIA_Text_TextSelectionChangedEventId").ToLocalChecked(), Nan::New(UIA_Text_TextSelectionChangedEventId));
    Nan::Set(target, Nan::New("UIA_Text_TextChangedEventId").ToLocalChecked(), Nan::New(UIA_Text_TextChangedEventId));
    Nan::Set(target, Nan::New("UIA_Window_WindowOpenedEventId").ToLocalChecked(), Nan::New(UIA_Window_WindowOpenedEventId));
    Nan::Set(target, Nan::New("UIA_Window_WindowClosedEventId").ToLocalChecked(), Nan::New(UIA_Window_WindowClosedEventId));
    Nan::Set(target, Nan::New("UIA_MenuModeStartEventId").ToLocalChecked(), Nan::New(UIA_MenuModeStartEventId));
    Nan::Set(target, Nan::New("UIA_MenuModeEndEventId").ToLocalChecked(), Nan::New(UIA_MenuModeEndEventId));
    Nan::Set(target, Nan::New("UIA_InputReachedTargetEventId").ToLocalChecked(), Nan::New(UIA_InputReachedTargetEventId));
    Nan::Set(target, Nan::New("UIA_InputReachedOtherElementEventId").ToLocalChecked(), Nan::New(UIA_InputReachedOtherElementEventId));
    Nan::Set(target, Nan::New("UIA_InputDiscardedEventId").ToLocalChecked(), Nan::New(UIA_InputDiscardedEventId));
    Nan::Set(target, Nan::New("UIA_SystemAlertEventId").ToLocalChecked(), Nan::New(UIA_SystemAlertEventId));
    Nan::Set(target, Nan::New("UIA_LiveRegionChangedEventId").ToLocalChecked(), Nan::New(UIA_LiveRegionChangedEventId));
    Nan::Set(target, Nan::New("UIA_HostedFragmentRootsInvalidatedEventId").ToLocalChecked(), Nan::New(UIA_HostedFragmentRootsInvalidatedEventId));
    Nan::Set(target, Nan::New("UIA_Drag_DragStartEventId").ToLocalChecked(), Nan::New(UIA_Drag_DragStartEventId));
    Nan::Set(target, Nan::New("UIA_Drag_DragCancelEventId").ToLocalChecked(), Nan::New(UIA_Drag_DragCancelEventId));
    Nan::Set(target, Nan::New("UIA_Drag_DragCompleteEventId").ToLocalChecked(), Nan::New(UIA_Drag_DragCompleteEventId));
    Nan::Set(target, Nan::New("UIA_DropTarget_DragEnterEventId").ToLocalChecked(), Nan::New(UIA_DropTarget_DragEnterEventId));
    Nan::Set(target, Nan::New("UIA_DropTarget_DragLeaveEventId").ToLocalChecked(), Nan::New(UIA_DropTarget_DragLeaveEventId));
    Nan::Set(target, Nan::New("UIA_DropTarget_DroppedEventId").ToLocalChecked(), Nan::New(UIA_DropTarget_DroppedEventId));
    Nan::Set(target, Nan::New("UIA_TextEdit_TextChangedEventId").ToLocalChecked(), Nan::New(UIA_TextEdit_TextChangedEventId));
    Nan::Set(target, Nan::New("UIA_TextEdit_ConversionTargetChangedEventId").ToLocalChecked(), Nan::New(UIA_TextEdit_ConversionTargetChangedEventId));
    Nan::Set(target, Nan::New("UIA_ChangesEventId").ToLocalChecked(), Nan::New(UIA_ChangesEventId));
    Nan::Set(target, Nan::New("UIA_NotificationEventId").ToLocalChecked(), Nan::New(UIA_NotificationEventId));
    Nan::Set(target, Nan::New("UIA_ActiveTextPositionChangedEventId").ToLocalChecked(), Nan::New(UIA_ActiveTextPositionChangedEventId));
}
