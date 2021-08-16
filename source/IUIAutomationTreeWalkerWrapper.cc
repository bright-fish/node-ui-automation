#include "IUIAutomationTreeWalkerWrapper.h"
#include "IUIAutomationElementWrapper.h"

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationTreeWalkerWrapper::constructor;

NAN_MODULE_INIT(IUIAutomationTreeWalkerWrapper::Init)
{
    auto isolate = target->GetIsolate();

    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();

    functionTemplate->SetClassName(Nan::New("IUIAutomationTreeWalker").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();

    instanceTemplate->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(functionTemplate, "getFirstChildElement", GetFirstChildElement);
    Nan::SetPrototypeMethod(functionTemplate, "getFirstChildElementBuildCache", GetFirstChildElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "GetLastChildElement", GetLastChildElement);
    Nan::SetPrototypeMethod(functionTemplate, "GetLastChildElementBuildCache", GetLastChildElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "GetNextSiblingElement", GetNextSiblingElement);
    Nan::SetPrototypeMethod(functionTemplate, "GetNextSiblingElementBuildCache", GetNextSiblingElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "GetParentElement", GetParentElement);
    Nan::SetPrototypeMethod(functionTemplate, "GetParentElementBuildCache", GetParentElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "GetPreviousSiblingElement", GetPreviousSiblingElement);
    Nan::SetPrototypeMethod(functionTemplate, "GetPreviousSiblingElementBuildCache", GetPreviousSiblingElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "NormalizeElement", NormalizeElement);
    Nan::SetPrototypeMethod(functionTemplate, "NormalizeElementBuildCache", NormalizeElementBuildCache);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());

    // Nan::Set(target, Nan::New("IUIAutomationTreeWalker").ToLocalChecked(), Nan::GetFunction(functionTemplate).ToLocalChecked());
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

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetFirstChildElement)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    IUIAutomationElement *pFirstChildElement = NULL;
    HRESULT hResult = pTreeWalker->GetFirstChildElement(pElement, &pFirstChildElement);

    auto firstChildElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pFirstChildElement);

    info.GetReturnValue().Set(firstChildElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetFirstChildElementBuildCache)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    auto pCacheRequestRaw = info[0].As<v8::External>()->Value();
    auto pCacheRequest = static_cast<IUIAutomationCacheRequest *>(pCacheRequestRaw);

    IUIAutomationElement *pFirstChildElement = NULL;
    HRESULT hResult = pTreeWalker->GetFirstChildElementBuildCache(pElement, pCacheRequest, &pFirstChildElement);

    auto firstChildElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pFirstChildElement);

    info.GetReturnValue().Set(firstChildElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetLastChildElement)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    IUIAutomationElement *pLastChildElement = NULL;
    HRESULT hResult = pTreeWalker->GetLastChildElement(pElement, &pLastChildElement);

    auto lastChildElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pLastChildElement);

    info.GetReturnValue().Set(lastChildElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetLastChildElementBuildCache)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    auto pCacheRequestRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pCacheRequest = static_cast<IUIAutomationCacheRequest *>(pCacheRequestRaw);

    IUIAutomationElement *pLastChildElement = NULL;
    HRESULT hResult = pTreeWalker->GetLastChildElementBuildCache(pElement, pCacheRequest, &pLastChildElement);

    auto lastChildElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pLastChildElement);

    info.GetReturnValue().Set(lastChildElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetNextSiblingElement)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    IUIAutomationElement *pNextSiblingElement = NULL;
    HRESULT hResult = pTreeWalker->GetNextSiblingElement(pElement, &pNextSiblingElement);

    auto nextSiblingElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pNextSiblingElement);

    info.GetReturnValue().Set(nextSiblingElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetNextSiblingElementBuildCache)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    auto pCacheRequestRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pCacheRequest = static_cast<IUIAutomationCacheRequest *>(pCacheRequestRaw);

    IUIAutomationElement *pNextSiblingElement = NULL;
    HRESULT hResult = pTreeWalker->GetNextSiblingElementBuildCache(pElement, pCacheRequest, &pNextSiblingElement);

    auto nextSiblingElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pNextSiblingElement);

    info.GetReturnValue().Set(nextSiblingElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetParentElement)
{
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetParentElementBuildCache)
{
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElement)
{
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElementBuildCache)
{
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::NormalizeElement)
{
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::NormalizeElementBuildCache)
{
}
