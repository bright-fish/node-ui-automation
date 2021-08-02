#include "Library.h"

using v8::Local;
using v8::Object;
using v8::Value;

Nan::Persistent<v8::Function> IUIAutomationConditionWrapper::constructor;

NAN_MODULE_INIT(IUIAutomationConditionWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("IUIAutomationCondition").ToLocalChecked());
    functionTemplate->InstanceTemplate()->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

Local<Object> IUIAutomationConditionWrapper::NewInstance(const Nan::FunctionCallbackInfo<v8::Value> &info, IUIAutomationCondition *pCondition)
{
    auto isolate = info.GetIsolate();
    auto context = isolate->GetCurrentContext();

    auto constructorFunction = Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    instance->SetInternalField(0, v8::External::New(isolate, pCondition));

    return instance;
}
