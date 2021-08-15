#include "IUIAutomationTreeWalkerWrapper.h"

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationTreeWalkerWrapper::constructor;

NAN_MODULE_INIT(IUIAutomationTreeWalkerWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("IUIAutomationTreeWalker").ToLocalChecked());
    functionTemplate->InstanceTemplate()->SetInternalFieldCount(1);

    // Nan::SetPrototypeMethod(functionTemplate, "getRootElement", );

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
    Nan::Set(target, Nan::New("IUIAutomationTreeWalker").ToLocalChecked(), Nan::GetFunction(functionTemplate).ToLocalChecked());
}


Local<v8::Value> IUIAutomationTreeWalkerWrapper::NewInstance(v8::Isolate *isolate, IUIAutomationTreeWalker *pTreeWalker)
{
    if (!pTreeWalker)
    {
        return v8::Null(isolate);
    }

    auto context = isolate->GetCurrentContext();

    Local<v8::Function> constructorFunction = Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    instance->SetInternalField(0, v8::External::New(isolate, pTreeWalker));

    return instance;
}
