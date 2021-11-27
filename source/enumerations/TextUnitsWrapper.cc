#include "TextUnitsWrapper.h"

Napi::Object TextUnitsWrapper::New(Napi::Env env)
{
    auto textUnits = Napi::Object::New(env);

    textUnits.Set("Character", Napi::Number::New(env, TextUnit::TextUnit_Character));
    textUnits.Set("Format", Napi::Number::New(env, TextUnit::TextUnit_Format));
    textUnits.Set("Word", Napi::Number::New(env, TextUnit::TextUnit_Word));
    textUnits.Set("Line", Napi::Number::New(env, TextUnit::TextUnit_Line));
    textUnits.Set("Paragraph", Napi::Number::New(env, TextUnit::TextUnit_Paragraph));
    textUnits.Set("Page", Napi::Number::New(env, TextUnit::TextUnit_Page));
    textUnits.Set("Document", Napi::Number::New(env, TextUnit::TextUnit_Document));
    
    return textUnits;
}
