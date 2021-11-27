#include "AttributeIdsWrapper.h"

Napi::Object AttributeIdsWrapper::New(Napi::Env env)
{
    auto attributeIds = Napi::Object::New(env);
    
    attributeIds.Set("AnimationStyleAttributeId", Napi::Number::New(env, UIA_AnimationStyleAttributeId));
    attributeIds.Set("BackgroundColorAttributeId", Napi::Number::New(env, UIA_BackgroundColorAttributeId));
    attributeIds.Set("BulletStyleAttributeId", Napi::Number::New(env, UIA_BulletStyleAttributeId));
    attributeIds.Set("CapStyleAttributeId", Napi::Number::New(env, UIA_CapStyleAttributeId));
    attributeIds.Set("CultureAttributeId", Napi::Number::New(env, UIA_CultureAttributeId));
    attributeIds.Set("FontNameAttributeId", Napi::Number::New(env, UIA_FontNameAttributeId));
    attributeIds.Set("FontSizeAttributeId", Napi::Number::New(env, UIA_FontSizeAttributeId));
    attributeIds.Set("FontWeightAttributeId", Napi::Number::New(env, UIA_FontWeightAttributeId));
    attributeIds.Set("ForegroundColorAttributeId", Napi::Number::New(env, UIA_ForegroundColorAttributeId));
    attributeIds.Set("HorizontalTextAlignmentAttributeId", Napi::Number::New(env, UIA_HorizontalTextAlignmentAttributeId));
    attributeIds.Set("IndentationFirstLineAttributeId", Napi::Number::New(env, UIA_IndentationFirstLineAttributeId));
    attributeIds.Set("IndentationLeadingAttributeId", Napi::Number::New(env, UIA_IndentationLeadingAttributeId));
    attributeIds.Set("IndentationTrailingAttributeId", Napi::Number::New(env, UIA_IndentationTrailingAttributeId));
    attributeIds.Set("IsHiddenAttributeId", Napi::Number::New(env, UIA_IsHiddenAttributeId));
    attributeIds.Set("IsItalicAttributeId", Napi::Number::New(env, UIA_IsItalicAttributeId));
    attributeIds.Set("IsReadOnlyAttributeId", Napi::Number::New(env, UIA_IsReadOnlyAttributeId));
    attributeIds.Set("IsSubscriptAttributeId", Napi::Number::New(env, UIA_IsSubscriptAttributeId));
    attributeIds.Set("IsSuperscriptAttributeId", Napi::Number::New(env, UIA_IsSuperscriptAttributeId));
    attributeIds.Set("MarginBottomAttributeId", Napi::Number::New(env, UIA_MarginBottomAttributeId));
    attributeIds.Set("MarginLeadingAttributeId", Napi::Number::New(env, UIA_MarginLeadingAttributeId));
    attributeIds.Set("MarginTopAttributeId", Napi::Number::New(env, UIA_MarginTopAttributeId));
    attributeIds.Set("MarginTrailingAttributeId", Napi::Number::New(env, UIA_MarginTrailingAttributeId));
    attributeIds.Set("OutlineStylesAttributeId", Napi::Number::New(env, UIA_OutlineStylesAttributeId));
    attributeIds.Set("OverlineColorAttributeId", Napi::Number::New(env, UIA_OverlineColorAttributeId));
    attributeIds.Set("OverlineStyleAttributeId", Napi::Number::New(env, UIA_OverlineStyleAttributeId));
    attributeIds.Set("StrikethroughColorAttributeId", Napi::Number::New(env, UIA_StrikethroughColorAttributeId));
    attributeIds.Set("StrikethroughStyleAttributeId", Napi::Number::New(env, UIA_StrikethroughStyleAttributeId));
    attributeIds.Set("TabsAttributeId", Napi::Number::New(env, UIA_TabsAttributeId));
    attributeIds.Set("TextFlowDirectionsAttributeId", Napi::Number::New(env, UIA_TextFlowDirectionsAttributeId));
    attributeIds.Set("UnderlineColorAttributeId", Napi::Number::New(env, UIA_UnderlineColorAttributeId));
    attributeIds.Set("UnderlineStyleAttributeId", Napi::Number::New(env, UIA_UnderlineStyleAttributeId));
    attributeIds.Set("AnnotationTypesAttributeId", Napi::Number::New(env, UIA_AnnotationTypesAttributeId));
    attributeIds.Set("AnnotationObjectsAttributeId", Napi::Number::New(env, UIA_AnnotationObjectsAttributeId));
    attributeIds.Set("StyleNameAttributeId", Napi::Number::New(env, UIA_StyleNameAttributeId));
    attributeIds.Set("StyleIdAttributeId", Napi::Number::New(env, UIA_StyleIdAttributeId));
    attributeIds.Set("LinkAttributeId", Napi::Number::New(env, UIA_LinkAttributeId));
    attributeIds.Set("IsActiveAttributeId", Napi::Number::New(env, UIA_IsActiveAttributeId));
    attributeIds.Set("SelectionActiveEndAttributeId", Napi::Number::New(env, UIA_SelectionActiveEndAttributeId));
    attributeIds.Set("CaretPositionAttributeId", Napi::Number::New(env, UIA_CaretPositionAttributeId));
    attributeIds.Set("CaretBidiModeAttributeId", Napi::Number::New(env, UIA_CaretBidiModeAttributeId));
    attributeIds.Set("LineSpacingAttributeId", Napi::Number::New(env, UIA_LineSpacingAttributeId));
    attributeIds.Set("BeforeParagraphSpacingAttributeId", Napi::Number::New(env, UIA_BeforeParagraphSpacingAttributeId));
    attributeIds.Set("AfterParagraphSpacingAttributeId", Napi::Number::New(env, UIA_AfterParagraphSpacingAttributeId));
    attributeIds.Set("SayAsInterpretAsAttributeId", Napi::Number::New(env, UIA_SayAsInterpretAsAttributeId));

    return attributeIds;
}
