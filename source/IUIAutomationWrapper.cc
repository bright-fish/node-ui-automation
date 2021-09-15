#include "Library.h"

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationWrapper::constructor;

IUIAutomationWrapper::IUIAutomationWrapper()
{
    HRESULT hr = CoInitialize(NULL);

    if (FAILED(hr))
    {
    }

    hr = CoCreateInstance(__uuidof(CUIAutomation8), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pAutomation));

    if (FAILED(hr))
    {
        // todo: Make it an error.
        wprintf(L"Failed to create a CUIAutomation8, HR: 0x%08x\n", hr);
        return;
    }
}

IUIAutomationWrapper::~IUIAutomationWrapper()
{
    CoUninitialize();
}

void IUIAutomationWrapper::GetProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    IUIAutomationWrapper *pAutomationWrapper = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    Nan::Utf8String utf8PropertyName(property);
    std::string sPropertyName(*utf8PropertyName);

    if (sPropertyName == "rawViewWalker")
    {
        IUIAutomationTreeWalker *pTreeWalker;

        auto hResult = pAutomationWrapper->m_pAutomation->get_RawViewWalker(&pTreeWalker);

        auto pTreeWalkerWrapper = IUIAutomationTreeWalkerWrapper::NewInstance(isolate, pTreeWalker);

        info.GetReturnValue()
            .Set(pTreeWalkerWrapper);

        return;
    }
    else if (sPropertyName == "rawViewCondition")
    {
        IUIAutomationCondition *pRawViewCondition;

        auto hResult = pAutomationWrapper->m_pAutomation->get_RawViewCondition(&pRawViewCondition);

        auto pRawViewConditionWrapper = IUIAutomationConditionWrapper::NewInstance(isolate, pRawViewCondition);

        info.GetReturnValue()
            .Set(pRawViewConditionWrapper);

        return;
    }
    else if (sPropertyName == "contentViewWalker")
    {
        IUIAutomationTreeWalker *pTreeWalker;

        auto hResult = pAutomationWrapper->m_pAutomation->get_ContentViewWalker(&pTreeWalker);

        auto pTreeWalkerWrapper = IUIAutomationTreeWalkerWrapper::NewInstance(isolate, pTreeWalker);

        info.GetReturnValue()
            .Set(pTreeWalkerWrapper);

        return;
    }
    else if (sPropertyName == "contentViewCondition")
    {
        IUIAutomationCondition *pContentViewCondition;

        auto hResult = pAutomationWrapper->m_pAutomation->get_ContentViewCondition(&pContentViewCondition);

        auto pContentViewConditionWrapper = IUIAutomationConditionWrapper::NewInstance(isolate, pContentViewCondition);

        info.GetReturnValue()
            .Set(pContentViewConditionWrapper);

        return;
    }
    else if (sPropertyName == "controlViewWalker")
    {
        IUIAutomationTreeWalker *pTreeWalker;

        auto hResult = pAutomationWrapper->m_pAutomation->get_ControlViewWalker(&pTreeWalker);

        auto pTreeWalkerWrapper = IUIAutomationTreeWalkerWrapper::NewInstance(isolate, pTreeWalker);

        info.GetReturnValue()
            .Set(pTreeWalkerWrapper);

        return;
    }
    else if (sPropertyName == "controlViewCondition")
    {
        IUIAutomationCondition *pControlViewCondition;

        auto hResult = pAutomationWrapper->m_pAutomation->get_ControlViewCondition(&pControlViewCondition);

        auto pControlViewConditionWrapper = IUIAutomationConditionWrapper::NewInstance(isolate, pControlViewCondition);

        info.GetReturnValue()
            .Set(pControlViewConditionWrapper);

        return;
    }
    else if (sPropertyName == "proxyFactoryMapping")
    {
        IUIAutomationProxyFactoryMapping *pProxyFactoryMapping;

        auto hResult = pAutomationWrapper->m_pAutomation->get_ProxyFactoryMapping(&pProxyFactoryMapping);

        auto pProxyFactoryMappingWrapper = IUIAutomationProxyFactoryMappingWrapper::NewInstance(isolate, pProxyFactoryMapping);

        info.GetReturnValue()
            .Set(pProxyFactoryMappingWrapper);

        return;
    }
    else if (sPropertyName == "reservedMixedAttributeValue")
    {
        IUnknown *pReservedMixedAttributeValue;

        auto hResult = pAutomationWrapper->m_pAutomation->get_ReservedMixedAttributeValue(&pReservedMixedAttributeValue);

        auto pReservedMixedAttributeValueWrapper = IUnknownWrapper::NewInstance(isolate, pReservedMixedAttributeValue);

        info.GetReturnValue()
            .Set(pReservedMixedAttributeValueWrapper);

        return;
    }
    else if (sPropertyName == "reservedNotSupportedValue")
    {
        IUnknown *pReservedNotSupportedValue;

        auto hResult = pAutomationWrapper->m_pAutomation->get_ReservedNotSupportedValue(&pReservedNotSupportedValue);

        auto pReservedNotSupportedValueWrapper = IUnknownWrapper::NewInstance(isolate, pReservedNotSupportedValue);

        info.GetReturnValue()
            .Set(pReservedNotSupportedValueWrapper);

        return;
    }
    else
    {
        throw std::exception("Not Implemented. ");
    }
}

NAN_MODULE_INIT(IUIAutomationWrapper::Init)
{
    auto isolate = target->GetIsolate();

    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>(New);
    functionTemplate->SetClassName(Nan::New("IUIAutomation").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();

    instanceTemplate->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(functionTemplate, "getRootElement", GetRootElement);
    Nan::SetPrototypeMethod(functionTemplate, "createPropertyCondition", CreatePropertyCondition);
    Nan::SetPrototypeMethod(functionTemplate, "createCacheRequest", CreateCacheRequest);

    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "rawViewCondition").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "rawViewWalker").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "contentViewCondition").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "contentViewWalker").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "controlViewCondition").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "controlViewWalker").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "proxyFactoryMapping").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "reservedMixedAttributeValue").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "reservedNotSupportedValue").ToLocalChecked(), GetProperty);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());

    Nan::Set(target, Nan::New("IUIAutomation").ToLocalChecked(), Nan::GetFunction(functionTemplate).ToLocalChecked());
}

NAN_METHOD(IUIAutomationWrapper::New)
{
    if (info.IsConstructCall())
    {
        IUIAutomationWrapper *automationWrapper = new IUIAutomationWrapper();

        IUIAutomationTreeWalker *treeWalker;
        automationWrapper->m_pAutomation->get_ContentViewWalker(&treeWalker);

        automationWrapper->Wrap(info.This());
        info.GetReturnValue().Set(info.This());
    }
    else
    {
        const int argc = 1;
        v8::Local<v8::Value> argv[argc] = {};
        v8::Local<v8::Function> cons = Nan::New(constructor);
        info.GetReturnValue().Set(Nan::NewInstance(cons, argc, argv).ToLocalChecked());
    }
}

NAN_METHOD(IUIAutomationWrapper::GetRootElement)
{
    auto isolate = info.GetIsolate();

    IUIAutomationWrapper *pAutomationWrapper = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    IUIAutomationElement *pRootElement = NULL;
    HRESULT hr = pAutomationWrapper->m_pAutomation->GetRootElement(&pRootElement);

    if (FAILED(hr))
    {
    }

    auto elementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, pRootElement);

    info.GetReturnValue().Set(elementWrapper);
}

NAN_METHOD(IUIAutomationWrapper::CreatePropertyCondition)
{
    auto isolate = info.GetIsolate();

    auto propertyIdIndex = info[0].As<v8::Int32>()->Value();
    auto propertyId = static_cast<PROPERTYID>(propertyIdIndex);

    IUIAutomationWrapper *pAutomationWrapper = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    auto variant = ToVariant(isolate, info[1]);

    IUIAutomationCondition *pCondition = NULL;

    HRESULT hr = pAutomationWrapper->m_pAutomation->CreatePropertyCondition(propertyId, variant, &pCondition);

    if (FAILED(hr))
    {
    }

    auto condition = IUIAutomationConditionWrapper::NewInstance(isolate, pCondition);

    info.GetReturnValue().Set(condition);
}

NAN_METHOD(IUIAutomationWrapper::CreateCacheRequest)
{
    auto isolate = info.GetIsolate();

    IUIAutomationWrapper *pAutomationWrapper = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    IUIAutomationCacheRequest *pCacheRequest = NULL;

    HRESULT hr = pAutomationWrapper->m_pAutomation->CreateCacheRequest(&pCacheRequest);

    if (FAILED(hr))
    {
    }

    auto cacheRequestWrapper = IUIAutomationCacheRequestWrapper::NewInstance(isolate, pCacheRequest);

    info.GetReturnValue().Set(cacheRequestWrapper);
}

NAN_METHOD(IUIAutomationWrapper::AddAutomationEventHandler)
{
    auto isolate = info.GetIsolate();

    IUIAutomationWrapper *pAutomationWrapper = Nan::ObjectWrap::Unwrap<IUIAutomationWrapper>(info.This());

    auto eventIdRaw = info[0].As<v8::Int32>()->Value();
    auto eventId = static_cast<EVENTID>(eventIdRaw);

    auto pElementRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pElement = static_cast<IUIAutomationElement *>(pElementRaw);

    auto treeScopeRaw = info[2].As<v8::Int32>()->Value();
    auto treeScope = static_cast<TreeScope>(treeScopeRaw);

    auto pCacheRequestRaw = info[3].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pCacheRequest = static_cast<IUIAutomationCacheRequest *>(pCacheRequestRaw);

    auto pEventHandlerRaw = info[4].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pEventHandler = static_cast<IUIAutomationEventHandler *>(pEventHandlerRaw);

    // todo: For this class to be functional we will have to create a class that takes in a callback that can be executed when the event handler is triggered.  
    // the pattern could remain the same, you get the class in node, inherit from it.  Then put the functions there. 
    // Then the functions in node are called from the c++ code. 

    HRESULT hr = pAutomationWrapper->m_pAutomation->AddAutomationEventHandler(eventId, pElement, treeScope, pCacheRequest, pEventHandler);

    if (FAILED(hr))
    {
    }

    auto cacheRequestWrapper = IUIAutomationCacheRequestWrapper::NewInstance(isolate, pCacheRequest);

    info.GetReturnValue().Set(cacheRequestWrapper);
}

VARIANT IUIAutomationWrapper::ToVariant(v8::Isolate *isolate, v8::Local<v8::Value> local)
{
    auto context = isolate->GetCurrentContext();

    VARIANT variant;

    if (local->IsInt32())
    {
        variant.intVal = local->Int32Value(context).ToChecked();
        variant.vt = VT_INT;
    }
    else if (local->IsString())
    {
        auto value = *v8::String::Utf8Value(isolate, local);

        variant.bstrVal = _com_util::ConvertStringToBSTR(value);
        variant.vt = VT_BSTR;
    }
    else if (local->IsBoolean())
    {
        variant.boolVal = local->ToBoolean(isolate)->Value();
        variant.vt = VT_BOOL;
    }

    return variant;
}
