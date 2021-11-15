#include "TreeScopeWrapper.h"

Napi::Object TreeScopeWrapper::New(Napi::Env env)
{
    Napi::Object treeScope = Napi::Object::New(env);

    treeScope.Set("None", Napi::Number::New(env, TreeScope_None));
    treeScope.Set("Element", Napi::Number::New(env, TreeScope_Element));
    treeScope.Set("Children", Napi::Number::New(env, TreeScope_Children));
    treeScope.Set("Descendants", Napi::Number::New(env, TreeScope_Descendants));
    treeScope.Set("Parent", Napi::Number::New(env, TreeScope_Parent));
    treeScope.Set("Ancestors", Napi::Number::New(env, TreeScope_Ancestors));
    treeScope.Set("Subtree", Napi::Number::New(env, TreeScope_Subtree));

    return treeScope;
}
