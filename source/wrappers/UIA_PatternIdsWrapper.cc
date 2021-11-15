#include "UIA_PatternIdsWrapper.h"

Napi::Object UIA_PatternIdsWrapper::New(Napi::Env env)
{
    auto automationPatterns = Napi::Object::New(env);

    automationPatterns.Set("InvokePatternId", Napi::Number::New(env, UIA_InvokePatternId));
    automationPatterns.Set("SelectionPatternId", Napi::Number::New(env, UIA_SelectionPatternId));
    automationPatterns.Set("ValuePatternId", Napi::Number::New(env, UIA_ValuePatternId));
    automationPatterns.Set("RangeValuePatternId", Napi::Number::New(env, UIA_RangeValuePatternId));
    automationPatterns.Set("ScrollPatternId", Napi::Number::New(env, UIA_ScrollPatternId));
    automationPatterns.Set("ExpandCollapsePatternId", Napi::Number::New(env, UIA_ExpandCollapsePatternId));
    automationPatterns.Set("GridPatternId", Napi::Number::New(env, UIA_GridPatternId));
    automationPatterns.Set("GridItemPatternId", Napi::Number::New(env, UIA_GridItemPatternId));
    automationPatterns.Set("MultipleViewPatternId", Napi::Number::New(env, UIA_MultipleViewPatternId));
    automationPatterns.Set("WindowPatternId", Napi::Number::New(env, UIA_WindowPatternId));
    automationPatterns.Set("SelectionItemPatternId", Napi::Number::New(env, UIA_SelectionItemPatternId));
    automationPatterns.Set("DockPatternId", Napi::Number::New(env, UIA_DockPatternId));
    automationPatterns.Set("TablePatternId", Napi::Number::New(env, UIA_TablePatternId));
    automationPatterns.Set("TableItemPatternId", Napi::Number::New(env, UIA_TableItemPatternId));
    automationPatterns.Set("TextPatternId", Napi::Number::New(env, UIA_TextPatternId));
    automationPatterns.Set("TogglePatternId", Napi::Number::New(env, UIA_TogglePatternId));
    automationPatterns.Set("TransformPatternId", Napi::Number::New(env, UIA_TransformPatternId));
    automationPatterns.Set("ScrollItemPatternId", Napi::Number::New(env, UIA_ScrollItemPatternId));
    automationPatterns.Set("LegacyIAccessiblePatternId", Napi::Number::New(env, UIA_LegacyIAccessiblePatternId));
    automationPatterns.Set("ItemContainerPatternId", Napi::Number::New(env, UIA_ItemContainerPatternId));
    automationPatterns.Set("VirtualizedItemPatternId", Napi::Number::New(env, UIA_VirtualizedItemPatternId));
    automationPatterns.Set("SynchronizedInputPatternId", Napi::Number::New(env, UIA_SynchronizedInputPatternId));
    automationPatterns.Set("ObjectModelPatternId", Napi::Number::New(env, UIA_ObjectModelPatternId));
    automationPatterns.Set("AnnotationPatternId", Napi::Number::New(env, UIA_AnnotationPatternId));
    automationPatterns.Set("TextPattern2Id", Napi::Number::New(env, UIA_TextPattern2Id));
    automationPatterns.Set("StylesPatternId", Napi::Number::New(env, UIA_StylesPatternId));
    automationPatterns.Set("SpreadsheetPatternId", Napi::Number::New(env, UIA_SpreadsheetPatternId));
    automationPatterns.Set("SpreadsheetItemPatternId", Napi::Number::New(env, UIA_SpreadsheetItemPatternId));
    automationPatterns.Set("TransformPattern2Id", Napi::Number::New(env, UIA_TransformPattern2Id));
    automationPatterns.Set("TextChildPatternId", Napi::Number::New(env, UIA_TextChildPatternId));
    automationPatterns.Set("DragPatternId", Napi::Number::New(env, UIA_DragPatternId));
    automationPatterns.Set("DropTargetPatternId", Napi::Number::New(env, UIA_DropTargetPatternId));
    automationPatterns.Set("TextEditPatternId", Napi::Number::New(env, UIA_TextEditPatternId));
    automationPatterns.Set("CustomNavigationPatternId", Napi::Number::New(env, UIA_CustomNavigationPatternId));
    automationPatterns.Set("SelectionPattern2Id", Napi::Number::New(env, UIA_SelectionPattern2Id));

    return automationPatterns;
}
