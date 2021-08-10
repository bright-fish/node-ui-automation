#include "Library.h"

Nan::Persistent<v8::Function> IUIAutomationElementArrayWrapper::constructor;

NAN_MODULE_INIT(IUIAutomationElementArrayWrapper::Init)
{
    auto isolate = target->GetIsolate();

    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();

    functionTemplate->SetClassName(Nan::New("IUIAutomationElementArray").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();

    instanceTemplate->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(functionTemplate, "getElement", GetElement);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

// todo: indexer
// todo: iterator?
// todo:
v8::Local<v8::Value> IUIAutomationElementArrayWrapper::NewInstance(v8::Isolate *isolate, IUIAutomationElementArray *elementArray)
{
    if (!elementArray)
    {
        return v8::Null(isolate);
    }

    auto context = isolate->GetCurrentContext();

    auto constructorFunction = v8::Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    instance->SetInternalField(0, v8::External::New(isolate, elementArray));

    return instance;
}

NAN_METHOD(IUIAutomationElementArrayWrapper::GetElement)
{
    auto isolate = info.GetIsolate();
    auto context = isolate->GetCurrentContext();

    auto indexMaybe = info[0]->Int32Value(context);

    if (indexMaybe.IsNothing())
    {
        return info.GetReturnValue().SetNull();
    }

    auto index = indexMaybe.ToChecked();

    auto pAutomationElementArrayWrapperRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElementArrayWrapper = static_cast<IUIAutomationElementArray *>(pAutomationElementArrayWrapperRaw);

    IUIAutomationElement *pElement = NULL;
    auto hResult = pAutomationElementArrayWrapper->GetElement(index, &pElement);

    if (FAILED(hResult))
    {
        return info.GetReturnValue().SetNull();
    }

    info.GetReturnValue().Set(IUIAutomationElementWrapper::NewInstance(isolate, pElement));
}