#include "PatternIdsWrapper.h"

Napi::Object PatternIdsWrapper::New(Napi::Env env)
{
    auto patternIds = Napi::Object::New(env);

    patternIds.Set("InvokePatternId", Napi::Number::New(env, UIA_InvokePatternId));
    patternIds.Set("SelectionPatternId", Napi::Number::New(env, UIA_SelectionPatternId));
    patternIds.Set("ValuePatternId", Napi::Number::New(env, UIA_ValuePatternId));
    patternIds.Set("RangeValuePatternId", Napi::Number::New(env, UIA_RangeValuePatternId));
    patternIds.Set("ScrollPatternId", Napi::Number::New(env, UIA_ScrollPatternId));
    patternIds.Set("ExpandCollapsePatternId", Napi::Number::New(env, UIA_ExpandCollapsePatternId));
    patternIds.Set("GridPatternId", Napi::Number::New(env, UIA_GridPatternId));
    patternIds.Set("GridItemPatternId", Napi::Number::New(env, UIA_GridItemPatternId));
    patternIds.Set("MultipleViewPatternId", Napi::Number::New(env, UIA_MultipleViewPatternId));
    patternIds.Set("WindowPatternId", Napi::Number::New(env, UIA_WindowPatternId));
    patternIds.Set("SelectionItemPatternId", Napi::Number::New(env, UIA_SelectionItemPatternId));
    patternIds.Set("DockPatternId", Napi::Number::New(env, UIA_DockPatternId));
    patternIds.Set("TablePatternId", Napi::Number::New(env, UIA_TablePatternId));
    patternIds.Set("TableItemPatternId", Napi::Number::New(env, UIA_TableItemPatternId));
    patternIds.Set("TextPatternId", Napi::Number::New(env, UIA_TextPatternId));
    patternIds.Set("TogglePatternId", Napi::Number::New(env, UIA_TogglePatternId));
    patternIds.Set("TransformPatternId", Napi::Number::New(env, UIA_TransformPatternId));
    patternIds.Set("ScrollItemPatternId", Napi::Number::New(env, UIA_ScrollItemPatternId));
    patternIds.Set("LegacyIAccessiblePatternId", Napi::Number::New(env, UIA_LegacyIAccessiblePatternId));
    patternIds.Set("ItemContainerPatternId", Napi::Number::New(env, UIA_ItemContainerPatternId));
    patternIds.Set("VirtualizedItemPatternId", Napi::Number::New(env, UIA_VirtualizedItemPatternId));
    patternIds.Set("SynchronizedInputPatternId", Napi::Number::New(env, UIA_SynchronizedInputPatternId));
    patternIds.Set("ObjectModelPatternId", Napi::Number::New(env, UIA_ObjectModelPatternId));
    patternIds.Set("AnnotationPatternId", Napi::Number::New(env, UIA_AnnotationPatternId));
    patternIds.Set("TextPattern2Id", Napi::Number::New(env, UIA_TextPattern2Id));
    patternIds.Set("StylesPatternId", Napi::Number::New(env, UIA_StylesPatternId));
    patternIds.Set("SpreadsheetPatternId", Napi::Number::New(env, UIA_SpreadsheetPatternId));
    patternIds.Set("SpreadsheetItemPatternId", Napi::Number::New(env, UIA_SpreadsheetItemPatternId));
    patternIds.Set("TransformPattern2Id", Napi::Number::New(env, UIA_TransformPattern2Id));
    patternIds.Set("TextChildPatternId", Napi::Number::New(env, UIA_TextChildPatternId));
    patternIds.Set("DragPatternId", Napi::Number::New(env, UIA_DragPatternId));
    patternIds.Set("DropTargetPatternId", Napi::Number::New(env, UIA_DropTargetPatternId));
    patternIds.Set("TextEditPatternId", Napi::Number::New(env, UIA_TextEditPatternId));
    patternIds.Set("CustomNavigationPatternId", Napi::Number::New(env, UIA_CustomNavigationPatternId));
    patternIds.Set("SelectionPattern2Id", Napi::Number::New(env, UIA_SelectionPattern2Id));

    return patternIds;
}
