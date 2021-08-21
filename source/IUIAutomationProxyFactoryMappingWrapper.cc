#include "IUIAutomationProxyFactoryMappingWrapper.h"

using v8::Local;
using v8::Object;
using v8::Value;

Nan::Persistent<v8::Function> IUIAutomationProxyFactoryMappingWrapper::constructor;

NAN_MODULE_INIT(IUIAutomationProxyFactoryMappingWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("IUIAutomationProxyFactoryMapping").ToLocalChecked());
    functionTemplate->InstanceTemplate()->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

Local<Object> IUIAutomationProxyFactoryMappingWrapper::NewInstance(v8::Isolate *isolate, IUIAutomationProxyFactoryMapping *pProxyFactoryMapping)
{
    auto context = isolate->GetCurrentContext();

    auto constructorFunction = Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    instance->SetInternalField(0, v8::External::New(isolate, pProxyFactoryMapping));

    return instance;
}
