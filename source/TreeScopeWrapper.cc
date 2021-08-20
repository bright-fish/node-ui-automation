#include "Library.h"

using v8::Isolate;
using v8::Local;
using v8::Object;

NAN_MODULE_INIT(TreeScopeWrapper::Init)
{
    auto isolate = target->GetIsolate();

    Local<Object> treeScope = Object::New(isolate);

    Nan::Set(treeScope, Nan::New("None").ToLocalChecked(), Nan::New(TreeScope_None));
    Nan::Set(treeScope, Nan::New("Element").ToLocalChecked(), Nan::New(TreeScope_Element));
    Nan::Set(treeScope, Nan::New("Children").ToLocalChecked(), Nan::New(TreeScope_Children));
    Nan::Set(treeScope, Nan::New("Descendants").ToLocalChecked(), Nan::New(TreeScope_Descendants));
    Nan::Set(treeScope, Nan::New("Parent").ToLocalChecked(), Nan::New(TreeScope_Parent));
    Nan::Set(treeScope, Nan::New("Ancestors").ToLocalChecked(), Nan::New(TreeScope_Ancestors));
    Nan::Set(treeScope, Nan::New("Subtree").ToLocalChecked(), Nan::New(TreeScope_Subtree));

    Nan::Set(target, Nan::New("TreeScope").ToLocalChecked(), treeScope);
}
