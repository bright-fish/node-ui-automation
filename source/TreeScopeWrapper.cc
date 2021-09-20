#include "Library.h"

using Napi::Object;

Napi::Object TreeScopeWrapper::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Object treeScope = Napi::Object::New(env);

    treeScope.Set("TreeScope_None", Napi::Number::New(env, TreeScope_None));
    treeScope.Set("TreeScope_Element", Napi::Number::New(env, TreeScope_Element));
    treeScope.Set("TreeScope_Children", Napi::Number::New(env, TreeScope_Children));
    treeScope.Set("TreeScope_Descendants", Napi::Number::New(env, TreeScope_Descendants));
    treeScope.Set("TreeScope_Parent", Napi::Number::New(env, TreeScope_Parent));
    treeScope.Set("TreeScope_Ancestors", Napi::Number::New(env, TreeScope_Ancestors));
    treeScope.Set("TreeScope_Subtree", Napi::Number::New(env, TreeScope_Subtree));

    exports.Set("TreeScope", treeScope);

    return exports;
}
