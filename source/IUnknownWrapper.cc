#include "Library.h"

using v8::Local;
using v8::Object;
using v8::Value;

Nan::Persistent<v8::Function> IUnknownWrapper::constructor;

NAN_MODULE_INIT(IUnknownWrapper::Init)
{
    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("IUnkown").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();
    instanceTemplate->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

Local<Object> IUnknownWrapper::NewInstance(v8::Isolate *pIsolate, IUnknown *pIUnknown)
{
    auto context = pIsolate->GetCurrentContext();

    auto constructorFunction = Local<v8::Function>::New(pIsolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    instance->SetInternalField(0, v8::External::New(pIsolate, pIUnknown));

    return instance;
}
