#include "TreeScopesWrapper.h"

Napi::Object TreeScopesWrapper::New(Napi::Env env)
{
    Napi::Object treeScopes = Napi::Object::New(env);

    treeScopes.Set("None", Napi::Number::New(env, TreeScope_None));
    treeScopes.Set("Element", Napi::Number::New(env, TreeScope_Element));
    treeScopes.Set("Children", Napi::Number::New(env, TreeScope_Children));
    treeScopes.Set("Descendants", Napi::Number::New(env, TreeScope_Descendants));
    treeScopes.Set("Parent", Napi::Number::New(env, TreeScope_Parent));
    treeScopes.Set("Ancestors", Napi::Number::New(env, TreeScope_Ancestors));
    treeScopes.Set("Subtree", Napi::Number::New(env, TreeScope_Subtree));

    return treeScopes;
}
