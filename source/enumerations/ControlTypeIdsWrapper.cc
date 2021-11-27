#include "ControlTypeIdsWrapper.h"

Napi::Object ControlTypeIdsWrapper::New(Napi::Env env)
{
  Napi::Object controlTypeIds = Napi::Object::New(env);

  controlTypeIds.Set("ButtonControlTypeId", Napi::Number::New(env, UIA_ButtonControlTypeId));
  controlTypeIds.Set("CalendarControlTypeId", Napi::Number::New(env, UIA_CalendarControlTypeId));
  controlTypeIds.Set("CheckBoxControlTypeId", Napi::Number::New(env, UIA_CheckBoxControlTypeId));
  controlTypeIds.Set("ComboBoxControlTypeId", Napi::Number::New(env, UIA_ComboBoxControlTypeId));
  controlTypeIds.Set("EditControlTypeId", Napi::Number::New(env, UIA_EditControlTypeId));
  controlTypeIds.Set("HyperlinkControlTypeId", Napi::Number::New(env, UIA_HyperlinkControlTypeId));
  controlTypeIds.Set("ImageControlTypeId", Napi::Number::New(env, UIA_ImageControlTypeId));
  controlTypeIds.Set("ListItemControlTypeId", Napi::Number::New(env, UIA_ListItemControlTypeId));
  controlTypeIds.Set("ListControlTypeId", Napi::Number::New(env, UIA_ListControlTypeId));
  controlTypeIds.Set("MenuControlTypeId", Napi::Number::New(env, UIA_MenuControlTypeId));
  controlTypeIds.Set("MenuBarControlTypeId", Napi::Number::New(env, UIA_MenuBarControlTypeId));
  controlTypeIds.Set("MenuItemControlTypeId", Napi::Number::New(env, UIA_MenuItemControlTypeId));
  controlTypeIds.Set("ProgressBarControlTypeId", Napi::Number::New(env, UIA_ProgressBarControlTypeId));
  controlTypeIds.Set("RadioButtonControlTypeId", Napi::Number::New(env, UIA_RadioButtonControlTypeId));
  controlTypeIds.Set("ScrollBarControlTypeId", Napi::Number::New(env, UIA_ScrollBarControlTypeId));
  controlTypeIds.Set("SliderControlTypeId", Napi::Number::New(env, UIA_SliderControlTypeId));
  controlTypeIds.Set("SpinnerControlTypeId", Napi::Number::New(env, UIA_SpinnerControlTypeId));
  controlTypeIds.Set("StatusBarControlTypeId", Napi::Number::New(env, UIA_StatusBarControlTypeId));
  controlTypeIds.Set("TabControlTypeId", Napi::Number::New(env, UIA_TabControlTypeId));
  controlTypeIds.Set("TabItemControlTypeId", Napi::Number::New(env, UIA_TabItemControlTypeId));
  controlTypeIds.Set("TextControlTypeId", Napi::Number::New(env, UIA_TextControlTypeId));
  controlTypeIds.Set("ToolBarControlTypeId", Napi::Number::New(env, UIA_ToolBarControlTypeId));
  controlTypeIds.Set("ToolTipControlTypeId", Napi::Number::New(env, UIA_ToolTipControlTypeId));
  controlTypeIds.Set("TreeControlTypeId", Napi::Number::New(env, UIA_TreeControlTypeId));
  controlTypeIds.Set("TreeItemControlTypeId", Napi::Number::New(env, UIA_TreeItemControlTypeId));
  controlTypeIds.Set("CustomControlTypeId", Napi::Number::New(env, UIA_CustomControlTypeId));
  controlTypeIds.Set("GroupControlTypeId", Napi::Number::New(env, UIA_GroupControlTypeId));
  controlTypeIds.Set("ThumbControlTypeId", Napi::Number::New(env, UIA_ThumbControlTypeId));
  controlTypeIds.Set("DataGridControlTypeId", Napi::Number::New(env, UIA_DataGridControlTypeId));
  controlTypeIds.Set("DataItemControlTypeId", Napi::Number::New(env, UIA_DataItemControlTypeId));
  controlTypeIds.Set("DocumentControlTypeId", Napi::Number::New(env, UIA_DocumentControlTypeId));
  controlTypeIds.Set("SplitButtonControlTypeId", Napi::Number::New(env, UIA_SplitButtonControlTypeId));
  controlTypeIds.Set("WindowControlTypeId", Napi::Number::New(env, UIA_WindowControlTypeId));
  controlTypeIds.Set("PaneControlTypeId", Napi::Number::New(env, UIA_PaneControlTypeId));
  controlTypeIds.Set("HeaderControlTypeId", Napi::Number::New(env, UIA_HeaderControlTypeId));
  controlTypeIds.Set("HeaderItemControlTypeId", Napi::Number::New(env, UIA_HeaderItemControlTypeId));
  controlTypeIds.Set("TableControlTypeId", Napi::Number::New(env, UIA_TableControlTypeId));
  controlTypeIds.Set("TitleBarControlTypeId", Napi::Number::New(env, UIA_TitleBarControlTypeId));
  controlTypeIds.Set("SeparatorControlTypeId", Napi::Number::New(env, UIA_SeparatorControlTypeId));
  controlTypeIds.Set("SemanticZoomControlTypeId", Napi::Number::New(env, UIA_SemanticZoomControlTypeId));
  controlTypeIds.Set("AppBarControlTypeId", Napi::Number::New(env, UIA_AppBarControlTypeId));

  return controlTypeIds;
}
