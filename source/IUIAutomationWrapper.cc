#include "Library.h"

using Napi::Object;

IUIAutomationWrapper::IUIAutomationWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationWrapper>(info)
{
    HRESULT hr = CoInitialize(NULL);

    if (FAILED(hr))
    {
    }

    hr = CoCreateInstance(__uuidof(CUIAutomation8), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pAutomation));

    if (FAILED(hr))
    {
        // todo: Make it an error.
        wprintf(L"Failed to create CUIAutomation8, HR: 0x%08x\n", hr);
        return;
    }
}

IUIAutomationWrapper::~IUIAutomationWrapper()
{
    CoUninitialize();
}

Napi::Value IUIAutomationWrapper::GetRawViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_RawViewWalker(&pTreeWalker);

    auto pTreeWalkerWrapper = new IUIAutomationTreeWalkerWrapper(info, pTreeWalker);

    return pTreeWalkerWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetRawViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pRawViewCondition;

    auto hResult = m_pAutomation->get_RawViewCondition(&pRawViewCondition);

    auto pRawViewConditionWrapper = new IUIAutomationConditionWrapper(info, pRawViewCondition);

    return pRawViewConditionWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetContentViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_ContentViewWalker(&pTreeWalker);

    auto pTreeWalkerWrapper = new IUIAutomationTreeWalkerWrapper(info, pTreeWalker);

    return pTreeWalkerWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetContentViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pContentViewCondition;

    auto hResult = m_pAutomation->get_ContentViewCondition(&pContentViewCondition);

    auto pContentViewConditionWrapper = new IUIAutomationConditionWrapper(info, pContentViewCondition);

    return pContentViewConditionWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetControlViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_ControlViewWalker(&pTreeWalker);

    auto pTreeWalkerWrapper = new IUIAutomationTreeWalkerWrapper(info, pTreeWalker);

    return pTreeWalkerWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetControlViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pControlViewCondition;

    auto hResult = m_pAutomation->get_ControlViewCondition(&pControlViewCondition);

    auto pControlViewConditionWrapper = new IUIAutomationConditionWrapper(info, pControlViewCondition);

    return pControlViewConditionWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetProxyFactoryMapping(const Napi::CallbackInfo &info)
{
    IUIAutomationProxyFactoryMapping *pProxyFactoryMapping;

    auto hResult = m_pAutomation->get_ProxyFactoryMapping(&pProxyFactoryMapping);

    auto pProxyFactoryMappingWrapper = new IUIAutomationProxyFactoryMappingWrapper(info, pProxyFactoryMapping);

    return pProxyFactoryMappingWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetReservedMixedAttributeValue(const Napi::CallbackInfo &info)
{
    IUnknown *pReservedMixedAttributeValue;

    auto hResult = m_pAutomation->get_ReservedMixedAttributeValue(&pReservedMixedAttributeValue);

    auto pReservedMixedAttributeValueWrapper = new IUnknownWrapper(info, pReservedMixedAttributeValue);

    return pReservedMixedAttributeValueWrapper->Value();
}

Napi::Value IUIAutomationWrapper::GetReservedNotSupportedValue(const Napi::CallbackInfo &info)
{
    IUnknown *pReservedNotSupportedValue;

    auto hResult = m_pAutomation->get_ReservedNotSupportedValue(&pReservedNotSupportedValue);

    auto pReservedNotSupportedValueWrapper = new IUnknownWrapper(info, pReservedNotSupportedValue);

    return pReservedNotSupportedValueWrapper->Value();
}

Napi::Object IUIAutomationWrapper::Init(Napi::Env env, Napi::Object exports)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationWrapper::GetRootElement>("getRootElement"),
        InstanceMethod<&IUIAutomationWrapper::CreatePropertyCondition>("createPropertyCondition"),
        InstanceMethod<&IUIAutomationWrapper::CreateCacheRequest>("createCacheRequest"),

        InstanceAccessor<&IUIAutomationWrapper::GetRawViewCondition>("rawViewCondition"),
        InstanceAccessor<&IUIAutomationWrapper::GetRawViewWalker>("rawViewWalker"),
        InstanceAccessor<&IUIAutomationWrapper::GetContentViewCondition>("contentViewCondition"),
        InstanceAccessor<&IUIAutomationWrapper::GetContentViewWalker>("contentViewWalker"),
        InstanceAccessor<&IUIAutomationWrapper::GetControlViewCondition>("controlViewCondition"),
        InstanceAccessor<&IUIAutomationWrapper::GetControlViewWalker>("controlViewWalker"),
        InstanceAccessor<&IUIAutomationWrapper::GetProxyFactoryMapping>("proxyFactoryMapping"),
        InstanceAccessor<&IUIAutomationWrapper::GetReservedMixedAttributeValue>("reservedMixedAttributeValue"),
        InstanceAccessor<&IUIAutomationWrapper::GetReservedNotSupportedValue>("reservedNotSupportedValue"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomation", classDefinition);

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    exports.Set("IUIAutomation", function);

    return exports;
}

Napi::Value IUIAutomationWrapper::GetRootElement(const Napi::CallbackInfo &info)
{
    IUIAutomationElement *pRootElement = NULL;
    HRESULT hResult = m_pAutomation->GetRootElement(&pRootElement);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    auto pElementWrapper = new IUIAutomationElementWrapper(info, pRootElement);

    return pElementWrapper->Value();
}

Napi::Value IUIAutomationWrapper::CreatePropertyCondition(const Napi::CallbackInfo &info)
{
    auto propertyIdIndex = info[0].ToNumber().Int32Value();
    auto propertyId = static_cast<PROPERTYID>(propertyIdIndex);

    auto variant = ToVariant(info[1]);

    IUIAutomationCondition *pCondition = NULL;

    HRESULT hr = m_pAutomation->CreatePropertyCondition(propertyId, variant, &pCondition);

    if (FAILED(hr))
    {
    }

    auto pConditionWrapper = new IUIAutomationConditionWrapper(info, pCondition);

    return pConditionWrapper->Value();
}

Napi::Value IUIAutomationWrapper::CreateCacheRequest(const Napi::CallbackInfo &info)
{
    IUIAutomationCacheRequest *pCacheRequest = NULL;

    HRESULT hr = m_pAutomation->CreateCacheRequest(&pCacheRequest);

    if (FAILED(hr))
    {
    }

    auto cacheRequestWrapper = new IUIAutomationCacheRequestWrapper(info, pCacheRequest);

    return cacheRequestWrapper->Value();
}

Napi::Value IUIAutomationWrapper::AddAutomationEventHandler(const Napi::CallbackInfo &info)
{
    auto eventId = static_cast<EVENTID>(info[0].ToNumber().Int32Value());
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[1].ToObject());
    auto treeScope = static_cast<TreeScope>(info[2].ToNumber().Int32Value());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[3].ToObject());
    auto pEventHandlerWrapper = Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>::Unwrap(info[4].ToObject());

    // todo: For this class to be functional we will have to create a class that takes in a callback that can be executed when the event handler is triggered.
    // the pattern could remain the same, you get the class in node, inherit from it.  Then put the functions there.
    // Then the functions in node are called from the c++ code.

    HRESULT hr = m_pAutomation->AddAutomationEventHandler(eventId, pElementWrapper->m_pElement, treeScope, pCacheRequestWrapper->m_pCacheRequest, pEventHandlerWrapper);

    if (FAILED(hr))
    {
        return info.Env().Null();
    }

    auto cacheRequestWrapper = new IUIAutomationCacheRequestWrapper(info, pCacheRequestWrapper->m_pCacheRequest);

    return cacheRequestWrapper->Value();
}

VARIANT IUIAutomationWrapper::ToVariant(Napi::Value local)
{
    VARIANT variant;

    if (local.IsNumber())
    {
        variant.intVal = local.ToNumber().Int32Value();
        variant.vt = VT_INT;
    }
    else if (local.IsString())
    {
        auto value = local.ToString();
        variant.bstrVal = _com_util::ConvertStringToBSTR(value.Utf8Value().c_str());
        variant.vt = VT_BSTR;
    }
    else if (local.IsBoolean())
    {
        variant.boolVal = local.ToBoolean();
        variant.vt = VT_BOOL;
    }

    return variant;
}
