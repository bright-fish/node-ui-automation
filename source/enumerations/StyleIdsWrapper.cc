#include "StyleIdsWrapper.h"

Napi::Object StyleIdsWrapper::New(Napi::Env env)
{
    auto automationStyles = Napi::Object::New(env);

    automationStyles.Set("Custom", Napi::Number::New(env, StyleId_Custom));
    automationStyles.Set("Heading1", Napi::Number::New(env, StyleId_Heading1));
    automationStyles.Set("Heading2", Napi::Number::New(env, StyleId_Heading2));
    automationStyles.Set("Heading3", Napi::Number::New(env, StyleId_Heading3));
    automationStyles.Set("Heading4", Napi::Number::New(env, StyleId_Heading4));
    automationStyles.Set("Heading5", Napi::Number::New(env, StyleId_Heading5));
    automationStyles.Set("Heading6", Napi::Number::New(env, StyleId_Heading6));
    automationStyles.Set("Heading7", Napi::Number::New(env, StyleId_Heading7));
    automationStyles.Set("Heading8", Napi::Number::New(env, StyleId_Heading8));
    automationStyles.Set("Heading9", Napi::Number::New(env, StyleId_Heading9));
    automationStyles.Set("Title", Napi::Number::New(env, StyleId_Title));
    automationStyles.Set("Subtitle", Napi::Number::New(env, StyleId_Subtitle));
    automationStyles.Set("Normal", Napi::Number::New(env, StyleId_Normal));
    automationStyles.Set("Emphasis", Napi::Number::New(env, StyleId_Emphasis));
    automationStyles.Set("Quote", Napi::Number::New(env, StyleId_Quote));
    automationStyles.Set("BulletedList", Napi::Number::New(env, StyleId_BulletedList));
    automationStyles.Set("NumberedList", Napi::Number::New(env, StyleId_NumberedList));

    return automationStyles;
}
