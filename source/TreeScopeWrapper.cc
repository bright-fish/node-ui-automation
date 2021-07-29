#include "Library.h"

using v8::Isolate;
using v8::Local;
using v8::Object;

NAN_MODULE_INIT(TreeScopeWrapper::Init)
{
    auto isolate = target->GetIsolate();

    Local<Object> treeScope = Object::New(isolate);

    Nan::Set(treeScope, Nan::New("TreeScope_None").ToLocalChecked(), Nan::New(TreeScope_None));
    Nan::Set(treeScope, Nan::New("TreeScope_Element").ToLocalChecked(), Nan::New(TreeScope_Element));
    Nan::Set(treeScope, Nan::New("TreeScope_Children").ToLocalChecked(), Nan::New(TreeScope_Children));
    Nan::Set(treeScope, Nan::New("TreeScope_Descendants").ToLocalChecked(), Nan::New(TreeScope_Descendants));
    Nan::Set(treeScope, Nan::New("TreeScope_Parent").ToLocalChecked(), Nan::New(TreeScope_Parent));
    Nan::Set(treeScope, Nan::New("TreeScope_Ancestors").ToLocalChecked(), Nan::New(TreeScope_Ancestors));
    Nan::Set(treeScope, Nan::New("TreeScope_Subtree").ToLocalChecked(), Nan::New(TreeScope_Subtree));

    Nan::Set(target, Nan::New("TreeScope").ToLocalChecked(), treeScope);
}
