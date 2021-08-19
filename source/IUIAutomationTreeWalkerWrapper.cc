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
    Nan::SetPrototypeMethod(functionTemplate, "getLastChildElement", GetLastChildElement);
    Nan::SetPrototypeMethod(functionTemplate, "getLastChildElementBuildCache", GetLastChildElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "getNextSiblingElement", GetNextSiblingElement);
    Nan::SetPrototypeMethod(functionTemplate, "getNextSiblingElementBuildCache", GetNextSiblingElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "getParentElement", GetParentElement);
    Nan::SetPrototypeMethod(functionTemplate, "getParentElementBuildCache", GetParentElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "getPreviousSiblingElement", GetPreviousSiblingElement);
    Nan::SetPrototypeMethod(functionTemplate, "getPreviousSiblingElementBuildCache", GetPreviousSiblingElementBuildCache);
    Nan::SetPrototypeMethod(functionTemplate, "normalizeElement", NormalizeElement);
    Nan::SetPrototypeMethod(functionTemplate, "normalizeElementBuildCache", NormalizeElementBuildCache);

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

    auto pCacheRequestRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
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
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    IUIAutomationElement *pParentElement = NULL;
    HRESULT hResult = pTreeWalker->GetParentElement(pElement, &pParentElement);

    auto parentElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pParentElement);

    info.GetReturnValue().Set(parentElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetParentElementBuildCache)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    auto pCacheRequestRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pCacheRequest = static_cast<IUIAutomationCacheRequest *>(pCacheRequestRaw);

    IUIAutomationElement *parentElement = NULL;
    HRESULT hResult = pTreeWalker->GetParentElementBuildCache(pElement, pCacheRequest, &parentElement);

    auto parentElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, parentElement);

    info.GetReturnValue().Set(parentElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElement)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    IUIAutomationElement *pPreviousSiblingElement = NULL;
    HRESULT hResult = pTreeWalker->GetPreviousSiblingElement(pElement, &pPreviousSiblingElement);

    auto previousSiblingElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pPreviousSiblingElement);

    info.GetReturnValue().Set(previousSiblingElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElementBuildCache)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    auto pCacheRequestRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pCacheRequest = static_cast<IUIAutomationCacheRequest *>(pCacheRequestRaw);

    IUIAutomationElement *previousSiblingElement = NULL;
    HRESULT hResult = pTreeWalker->GetPreviousSiblingElementBuildCache(pElement, pCacheRequest, &previousSiblingElement);

    auto previousSiblingElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, previousSiblingElement);

    info.GetReturnValue().Set(previousSiblingElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::NormalizeElement)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    IUIAutomationElement *pNormalizedElemment = NULL;
    HRESULT hResult = pTreeWalker->NormalizeElement(pElement, &pNormalizedElemment);

    auto normalizedElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pNormalizedElemment);

    info.GetReturnValue().Set(normalizedElementWrapper);
}

NAN_METHOD(IUIAutomationTreeWalkerWrapper::NormalizeElementBuildCache)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pTreeWalkerRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pTreeWalker = static_cast<IUIAutomationTreeWalker *>(pTreeWalkerRaw);

    auto pElementRaw = info[0].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    auto pCacheRequestRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pCacheRequest = static_cast<IUIAutomationCacheRequest *>(pCacheRequestRaw);

    IUIAutomationElement *pNormalizedElement = NULL;
    HRESULT hResult = pTreeWalker->GetPreviousSiblingElementBuildCache(pElement, pCacheRequest, &pNormalizedElement);

    auto normalizedElementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pNormalizedElement);

    info.GetReturnValue().Set(normalizedElementWrapper);
}
