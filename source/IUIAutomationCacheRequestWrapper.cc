#include "IUIAutomationCacheRequestWrapper.h"

Nan::Persistent<v8::Function> IUIAutomationCacheRequestWrapper::constructor;

NAN_MODULE_INIT(IUIAutomationCacheRequestWrapper::Init)
{
    auto isolate = target->GetIsolate();

    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();

    functionTemplate->SetClassName(Nan::New("IUIAutomationCacheRequest").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();

    instanceTemplate->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

v8::Local<v8::Value> IUIAutomationCacheRequestWrapper::NewInstance(v8::Isolate *isolate, IUIAutomationCacheRequest *pCacheRequest)
{
    if (!pCacheRequest)
    {
        return v8::Null(isolate);
    }

    auto context = isolate->GetCurrentContext();

    auto constructorFunction = v8::Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    instance->SetInternalField(0, v8::External::New(isolate, pCacheRequest));

    return instance;
}
