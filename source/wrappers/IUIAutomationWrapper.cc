#include "Wrappers.h"
#include "../AutomationAddon.h"

Napi::FunctionReference *IUIAutomationWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationWrapper::GetRootElement>("getRootElement"),
        InstanceMethod<&IUIAutomationWrapper::CreatePropertyCondition>("createPropertyCondition"),
        InstanceMethod<&IUIAutomationWrapper::CreateCacheRequest>("createCacheRequest"),
        InstanceMethod<&IUIAutomationWrapper::AddAutomationEventHandler>("addAutomationEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::AddFocusChangedEventHandler>("addFocusChangedEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::AddPropertyChangedEventHandler>("addPropertyChangedEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::AddStructureChangedEventHandler>("addStructureChangedEventHandler"),

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

    auto prototype = DefineClass(env, "IUIAutomation", classDefinition);

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(prototype);

    return constructor;
}

IUIAutomationWrapper::IUIAutomationWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationWrapper>(info)
{
    try
    {
        // todo: Need to get parameter of CUIAutomation. Use the uuid if its present from uuids of the CUIAutomation classes/structs.

        auto hResult = CoCreateInstance(__uuidof(CUIAutomation8), NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_pAutomation));

        if (FAILED(hResult))
        {
            throw _com_error(hResult);
        }
    }
    catch (_com_error &error)
    {
        throw Napi::Error::New(info.Env(), error.ErrorMessage());
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

    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(info.Env(), error.ErrorMessage());
    }

    return IUIAutomationTreeWalkerWrapper::New(info.Env(), pTreeWalker);
}

Napi::Value IUIAutomationWrapper::GetRawViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pRawViewCondition;

    auto hResult = m_pAutomation->get_RawViewCondition(&pRawViewCondition);

    return IUIAutomationConditionWrapper::New(info.Env(), pRawViewCondition);
}

Napi::Value IUIAutomationWrapper::GetContentViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_ContentViewWalker(&pTreeWalker);

    return IUIAutomationTreeWalkerWrapper::New(info.Env(), pTreeWalker);
}

Napi::Value IUIAutomationWrapper::GetContentViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pContentViewCondition;

    auto hResult = m_pAutomation->get_ContentViewCondition(&pContentViewCondition);

    return IUIAutomationConditionWrapper::New(info.Env(), pContentViewCondition);
}

Napi::Value IUIAutomationWrapper::GetControlViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_ControlViewWalker(&pTreeWalker);

    return IUIAutomationTreeWalkerWrapper::New(info.Env(), pTreeWalker);
}

Napi::Value IUIAutomationWrapper::GetControlViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pControlViewCondition;

    auto hResult = m_pAutomation->get_ControlViewCondition(&pControlViewCondition);

    auto pControlViewConditionWrapper = IUIAutomationConditionWrapper::New(info.Env(), pControlViewCondition);

    return pControlViewConditionWrapper;
}

Napi::Value IUIAutomationWrapper::GetProxyFactoryMapping(const Napi::CallbackInfo &info)
{
    IUIAutomationProxyFactoryMapping *pProxyFactoryMapping;

    auto hResult = m_pAutomation->get_ProxyFactoryMapping(&pProxyFactoryMapping);

    auto pProxyFactoryMappingWrapper = IUIAutomationProxyFactoryMappingWrapper::New(info.Env(), pProxyFactoryMapping);

    return pProxyFactoryMappingWrapper;
}

Napi::Value IUIAutomationWrapper::GetReservedMixedAttributeValue(const Napi::CallbackInfo &info)
{
    IUnknown *pReservedMixedAttributeValue;

    auto hResult = m_pAutomation->get_ReservedMixedAttributeValue(&pReservedMixedAttributeValue);

    auto pReservedMixedAttributeValueWrapper = IUnknownWrapper::New(info.Env(), pReservedMixedAttributeValue);

    return pReservedMixedAttributeValueWrapper;
}

Napi::Value IUIAutomationWrapper::GetReservedNotSupportedValue(const Napi::CallbackInfo &info)
{
    IUnknown *pReservedNotSupportedValue;

    auto hResult = m_pAutomation->get_ReservedNotSupportedValue(&pReservedNotSupportedValue);

    auto pReservedNotSupportedValueWrapper = IUnknownWrapper::New(info.Env(), pReservedNotSupportedValue);

    return pReservedNotSupportedValueWrapper;
}

Napi::Value IUIAutomationWrapper::GetRootElement(const Napi::CallbackInfo &info)
{
    IUIAutomationElement *pRootElement = NULL;
    HRESULT hResult = m_pAutomation->GetRootElement(&pRootElement);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    auto pElementWrapper = IUIAutomationElementWrapper::New(info.Env(), pRootElement);

    return pElementWrapper;
}

Napi::Value IUIAutomationWrapper::CreatePropertyCondition(const Napi::CallbackInfo &info)
{
    try
    {
        auto propertyIdIndex = info[0].ToNumber().Int32Value();
        auto propertyId = static_cast<PROPERTYID>(propertyIdIndex);

        auto variant = ToVariant(info[1]);

        IUIAutomationCondition *pCondition = NULL;

        HRESULT hResult = m_pAutomation->CreatePropertyCondition(propertyId, variant, &pCondition);

        if (FAILED(hResult))
        {
            _com_raise_error(hResult);
        }

        auto pConditionWrapper = IUIAutomationConditionWrapper::New(info.Env(), pCondition);

        return pConditionWrapper;
    }
    catch (_com_error &error)
    {
        auto size = wcslen((wchar_t *)error.ErrorMessage());

        char *cpErrorMessage = NULL;
        wcstombs(cpErrorMessage, (wchar_t *)error.ErrorMessage(), size);

        throw Napi::Error::New(info.Env(), cpErrorMessage);
    }
}

Napi::Value IUIAutomationWrapper::CreateCacheRequest(const Napi::CallbackInfo &info)
{
    IUIAutomationCacheRequest *pCacheRequest = NULL;

    HRESULT hResult = m_pAutomation->CreateCacheRequest(&pCacheRequest);

    if (FAILED(hResult))
    {
        _com_raise_error(hResult);
    }

    auto cacheRequestWrapper = IUIAutomationCacheRequestWrapper::New(info.Env(), pCacheRequest);

    return cacheRequestWrapper;
}

void IUIAutomationWrapper::AddAutomationEventHandler(const Napi::CallbackInfo &info)
{
    auto eventId = static_cast<EVENTID>(info[0].ToNumber().Int32Value());
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[1].ToObject());
    auto treeScope = static_cast<TreeScope>(info[2].ToNumber().Int32Value());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[3].ToObject());
    auto pEventHandlerWrapper = Napi::ObjectWrap<IUIAutomationEventHandlerWrapper>::Unwrap(info[4].ToObject());

    HRESULT hResult = m_pAutomation->AddAutomationEventHandler(eventId, pElementWrapper->m_pElement, treeScope, NULL, pEventHandlerWrapper->m_pEventHandler);

    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(info.Env(), error.ErrorMessage());
    }
}

void IUIAutomationWrapper::AddFocusChangedEventHandler(const Napi::CallbackInfo &info)
{
    IUIAutomationCacheRequest *pCacheRequest = NULL;

    if (!info[0].IsNull())
    {
        auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[0].ToObject());
        pCacheRequest = pCacheRequestWrapper->m_pCacheRequest;
    }

    auto pFocusChangedEventHandlerWrapper = Napi::ObjectWrap<IUIAutomationFocusChangedEventHandlerWrapper>::Unwrap(info[1].ToObject());

    HRESULT hResult = m_pAutomation->AddFocusChangedEventHandler(pCacheRequest, pFocusChangedEventHandlerWrapper->m_pFocusChangedEventHandler);

    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(info.Env(), error.ErrorMessage());
    }
}

void IUIAutomationWrapper::AddPropertyChangedEventHandler(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElement> pElement;

    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    pElement = pElementWrapper->m_pElement;

    auto treeScope = static_cast<TreeScope>(info[1].As<Napi::Number>().Uint32Value());

    IUIAutomationCacheRequest *pCacheRequest = NULL;
    if (!info[2].IsNull())
    {
        auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[2].ToObject());
        pCacheRequest = pCacheRequestWrapper->m_pCacheRequest;
    }

    auto pPropertyChangedEventHandler = Napi::ObjectWrap<IUIAutomationPropertyChangedEventHandlerWrapper>::Unwrap(info[3].ToObject());

    SAFEARRAY *pSafeArray = NULL;
    if (!info[4].IsNull())
    {
        auto propertyIds = info[4].As<Napi::Array>();

        // ATL::CCom
        SAFEARRAYBOUND safeArrayBound;
        safeArrayBound.lLbound = 0;
        safeArrayBound.cElements = propertyIds.Length();

        pSafeArray = SafeArrayCreate(VT_INT, 1, &safeArrayBound);

        for (uint32_t i = 0; i < propertyIds.Length(); i++)
        {
            Napi::Value propertyIdValue = propertyIds[i];
    
            auto propertyId = propertyIdValue.ToNumber().Uint32Value();
            auto hResult = SafeArrayPutElement(pSafeArray, (long *)&i, &propertyId);

            if (FAILED(hResult))
            {
                auto error = _com_error(hResult);
                throw Napi::Error::New(info.Env(), error.ErrorMessage());
            }
        }
    }

    auto hResult = m_pAutomation->AddPropertyChangedEventHandler(pElement, treeScope, pCacheRequest, pPropertyChangedEventHandler->m_pPropertyChangedEventHandler, pSafeArray);

    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(info.Env(), error.ErrorMessage());
    }
}

void IUIAutomationWrapper::AddStructureChangedEventHandler(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElement> pElement;

    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    pElement = pElementWrapper->m_pElement;

    auto treeScope = static_cast<TreeScope>(info[1].As<Napi::Number>().Uint32Value());

    IUIAutomationCacheRequest *pCacheRequest = NULL;
    if (!info[2].IsNull())
    {
        auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[2].ToObject());
        pCacheRequest = pCacheRequestWrapper->m_pCacheRequest;
    }

    auto pStructureChangedEventHandler = Napi::ObjectWrap<IUIAutomationStructureChangedEventHandlerWrapper>::Unwrap(info[3].ToObject());

    auto hResult = m_pAutomation->AddStructureChangedEventHandler(pElement, treeScope, pCacheRequest, pStructureChangedEventHandler->m_pStructureChangedEventHandler);

    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(info.Env(), error.ErrorMessage());
    }
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
