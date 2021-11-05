#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationWrapper::CreateCacheRequest>("createCacheRequest"),
        InstanceMethod<&IUIAutomationWrapper::AddAutomationEventHandler>("addAutomationEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::AddFocusChangedEventHandler>("addFocusChangedEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::AddPropertyChangedEventHandler>("addPropertyChangedEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::AddStructureChangedEventHandler>("addStructureChangedEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::CheckNotSupported>("checkNotSupported"),
        InstanceMethod<&IUIAutomationWrapper::CompareElements>("compareElements"),
        InstanceMethod<&IUIAutomationWrapper::CreateAndCondition>("createAndCondition"),
        InstanceMethod<&IUIAutomationWrapper::CreateFalseCondition>("createFalseCondition"),
        InstanceMethod<&IUIAutomationWrapper::CreateNotCondition>("createNotCondition"),
        InstanceMethod<&IUIAutomationWrapper::CreateOrCondition>("createOrCondition"),
        InstanceMethod<&IUIAutomationWrapper::CreatePropertyCondition>("createPropertyCondition"),
        InstanceMethod<&IUIAutomationWrapper::CreateTreeWalker>("createTreeWalker"),
        InstanceMethod<&IUIAutomationWrapper::CreateTrueCondition>("createTrueCondition"),
        InstanceMethod<&IUIAutomationWrapper::ElementFromPoint>("elementFromPoint"),
        InstanceMethod<&IUIAutomationWrapper::ElementFromPointBuildCache>("elementFromPointBuildCache"),
        InstanceMethod<&IUIAutomationWrapper::GetFocusedElement>("getFocusedElement"),
        InstanceMethod<&IUIAutomationWrapper::GetFocusedElementBuildCache>("getFocusedElementBuildCache"),
        InstanceMethod<&IUIAutomationWrapper::GetPatternProgrammaticName>("getPatternProgrammaticName"),
        InstanceMethod<&IUIAutomationWrapper::GetPropertyProgrammaticName>("getPropertyProgrammaticName"),
        InstanceMethod<&IUIAutomationWrapper::GetRootElement>("getRootElement"),
        InstanceMethod<&IUIAutomationWrapper::GetRootElementBuildCache>("getRootElementBuildCache"),
        InstanceMethod<&IUIAutomationWrapper::RemoveAllEventHandlers>("removeAllEventHandlers"),
        InstanceMethod<&IUIAutomationWrapper::RemoveAutomationEventHandler>("removeAutomationEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::RemoveFocusChangedEventHandler>("removeFocusChangedEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::RemovePropertyChangedEventHandler>("removePropertyChangedEventHandler"),
        InstanceMethod<&IUIAutomationWrapper::RemoveStructureChangedEventHandler>("removeStructureChangedEventHandler"),

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
    auto hResult = m_pAutomation.CoCreateInstance(CLSID_CUIAutomation, NULL, CLSCTX_INPROC_SERVER);

    HandleResult(info, hResult);
}

IUIAutomationWrapper::~IUIAutomationWrapper()
{
    m_pAutomation.Release();
}

Napi::Value IUIAutomationWrapper::GetRawViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_RawViewWalker(&pTreeWalker);

    HandleResult(info, hResult);

    return IUIAutomationTreeWalkerWrapper::New(info.Env(), pTreeWalker);
}

Napi::Value IUIAutomationWrapper::GetRawViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pRawViewCondition;

    auto hResult = m_pAutomation->get_RawViewCondition(&pRawViewCondition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), pRawViewCondition);
}

Napi::Value IUIAutomationWrapper::GetContentViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_ContentViewWalker(&pTreeWalker);

    HandleResult(info, hResult);

    return IUIAutomationTreeWalkerWrapper::New(info.Env(), pTreeWalker);
}

Napi::Value IUIAutomationWrapper::GetContentViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pContentViewCondition;

    auto hResult = m_pAutomation->get_ContentViewCondition(&pContentViewCondition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), pContentViewCondition);
}

Napi::Value IUIAutomationWrapper::GetControlViewWalker(const Napi::CallbackInfo &info)
{
    IUIAutomationTreeWalker *pTreeWalker;

    auto hResult = m_pAutomation->get_ControlViewWalker(&pTreeWalker);

    HandleResult(info, hResult);

    return IUIAutomationTreeWalkerWrapper::New(info.Env(), pTreeWalker);
}

Napi::Value IUIAutomationWrapper::GetControlViewCondition(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *pControlViewCondition;

    auto hResult = m_pAutomation->get_ControlViewCondition(&pControlViewCondition);

    HandleResult(info, hResult);

    auto pControlViewConditionWrapper = IUIAutomationConditionWrapper::New(info.Env(), pControlViewCondition);

    return pControlViewConditionWrapper;
}

Napi::Value IUIAutomationWrapper::GetProxyFactoryMapping(const Napi::CallbackInfo &info)
{
    IUIAutomationProxyFactoryMapping *pProxyFactoryMapping;

    auto hResult = m_pAutomation->get_ProxyFactoryMapping(&pProxyFactoryMapping);

    HandleResult(info, hResult);

    auto pProxyFactoryMappingWrapper = IUIAutomationProxyFactoryMappingWrapper::New(info.Env(), pProxyFactoryMapping);

    return pProxyFactoryMappingWrapper;
}

Napi::Value IUIAutomationWrapper::GetReservedMixedAttributeValue(const Napi::CallbackInfo &info)
{
    IUnknown *pReservedMixedAttributeValue;

    auto hResult = m_pAutomation->get_ReservedMixedAttributeValue(&pReservedMixedAttributeValue);

    HandleResult(info, hResult);

    auto pReservedMixedAttributeValueWrapper = IUnknownWrapper::New(info.Env(), pReservedMixedAttributeValue);

    return pReservedMixedAttributeValueWrapper;
}

Napi::Value IUIAutomationWrapper::GetReservedNotSupportedValue(const Napi::CallbackInfo &info)
{
    IUnknown *pReservedNotSupportedValue;

    auto hResult = m_pAutomation->get_ReservedNotSupportedValue(&pReservedNotSupportedValue);

    HandleResult(info, hResult);

    auto pReservedNotSupportedValueWrapper = IUnknownWrapper::New(info.Env(), pReservedNotSupportedValue);

    return pReservedNotSupportedValueWrapper;
}

Napi::Value IUIAutomationWrapper::CreateCacheRequest(const Napi::CallbackInfo &info)
{
    IUIAutomationCacheRequest *pCacheRequest = NULL;

    HRESULT hResult = m_pAutomation->CreateCacheRequest(&pCacheRequest);

    HandleResult(info, hResult);

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

    HandleResult(info, hResult);
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

    HandleResult(info, hResult);
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

            HandleResult(info, hResult);
        }
    }

    auto hResult = m_pAutomation->AddPropertyChangedEventHandler(pElement, treeScope, pCacheRequest, pPropertyChangedEventHandler->m_pPropertyChangedEventHandler, pSafeArray);

    HandleResult(info, hResult);
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

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationWrapper::CheckNotSupported(const Napi::CallbackInfo &info)
{
    auto variant = ToVariant(info.Env(), info[0]);

    BOOL isNotSupported;
    auto hResult = m_pAutomation->CheckNotSupported(variant, &isNotSupported);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isNotSupported);
}

Napi::Value IUIAutomationWrapper::CompareElements(const Napi::CallbackInfo &info)
{
    auto elementWrapperOne = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    auto elementWrapperTwo = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[1].ToObject());

    BOOL bAreEqual;
    auto hResult = m_pAutomation->CompareElements(elementWrapperOne->m_pElement, elementWrapperTwo->m_pElement, &bAreEqual);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), bAreEqual);
}

Napi::Value IUIAutomationWrapper::CreateAndCondition(const Napi::CallbackInfo &info)
{
    auto conditionWrapperOne = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[0].ToObject());
    auto conditionWrapperTwo = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[1].ToObject());

    ATL::CComPtr<IUIAutomationCondition> pAutomationCondition;
    auto hResult = m_pAutomation->CreateAndCondition(conditionWrapperOne->m_pCondition, conditionWrapperTwo->m_pCondition, &pAutomationCondition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), pAutomationCondition);
}

Napi::Value IUIAutomationWrapper::CreateFalseCondition(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationCondition> pAutomationCondition;
    auto hResult = m_pAutomation->CreateFalseCondition(&pAutomationCondition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), pAutomationCondition);
}

Napi::Value IUIAutomationWrapper::CreateNotCondition(const Napi::CallbackInfo &info)
{
    auto conditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[0].ToObject());

    ATL::CComPtr<IUIAutomationCondition> pAutomationCondition;
    auto hResult = m_pAutomation->CreateNotCondition(conditionWrapper->m_pCondition, &pAutomationCondition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), pAutomationCondition);
}

Napi::Value IUIAutomationWrapper::CreateOrCondition(const Napi::CallbackInfo &info)
{
    auto conditionWrapperOne = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[0].ToObject());
    auto conditionWrapperTwo = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[0].ToObject());

    ATL::CComPtr<IUIAutomationCondition> pAutomationCondition;
    auto hResult = m_pAutomation->CreateOrCondition(conditionWrapperOne->m_pCondition, conditionWrapperTwo->m_pCondition, &pAutomationCondition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), pAutomationCondition);
}

Napi::Value IUIAutomationWrapper::CreatePropertyCondition(const Napi::CallbackInfo &info)
{
    auto propertyIdIndex = info[0].ToNumber().Int32Value();
    auto propertyId = static_cast<PROPERTYID>(propertyIdIndex);

    auto variant = ToVariant(info.Env(), info[1]);

    ATL::CComPtr<IUIAutomationCondition> pCondition;
    HRESULT hResult = m_pAutomation->CreatePropertyCondition(propertyId, variant, &pCondition);

    HandleResult(info, hResult);

    auto pConditionWrapper = IUIAutomationConditionWrapper::New(info.Env(), pCondition);

    return pConditionWrapper;
}

Napi::Value IUIAutomationWrapper::CreateTreeWalker(const Napi::CallbackInfo &info)
{
    auto conditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[0].ToObject());

    ATL::CComPtr<IUIAutomationTreeWalker> pTreeWalker;
    auto hResult = m_pAutomation->CreateTreeWalker(conditionWrapper->m_pCondition, &pTreeWalker);

    HandleResult(info, hResult);

    return IUIAutomationTreeWalkerWrapper::New(info.Env(), pTreeWalker);
}

Napi::Value IUIAutomationWrapper::CreateTrueCondition(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationCondition> pAutomationCondition;
    auto hResult = m_pAutomation->CreateTrueCondition(&pAutomationCondition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), pAutomationCondition);
}

Napi::Value IUIAutomationWrapper::ElementFromPoint(const Napi::CallbackInfo &info)
{
    auto pointObject = info[0].ToObject();

    POINT point;
    point.x = pointObject.Get("x").ToNumber().Uint32Value();
    point.y = pointObject.Get("y").ToNumber().Uint32Value();

    ATL::CComPtr<IUIAutomationElement> pAutomationElement;
    auto hResult = m_pAutomation->ElementFromPoint(point, &pAutomationElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pAutomationElement);
}

Napi::Value IUIAutomationWrapper::ElementFromPointBuildCache(const Napi::CallbackInfo &info)
{
    auto pointObject = info[0].ToObject();

    POINT point;
    point.x = pointObject.Get("x").ToNumber().Uint32Value();
    point.y = pointObject.Get("y").ToNumber().Uint32Value();

    auto cacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[1].ToObject());

    ATL::CComPtr<IUIAutomationElement> pAutomationElement;
    auto hResult = m_pAutomation->ElementFromPointBuildCache(point, cacheRequestWrapper->m_pCacheRequest, &pAutomationElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pAutomationElement);
}

Napi::Value IUIAutomationWrapper::GetFocusedElement(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pAutomationElement;
    auto hResult = m_pAutomation->GetFocusedElement(&pAutomationElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pAutomationElement);
}

Napi::Value IUIAutomationWrapper::GetFocusedElementBuildCache(const Napi::CallbackInfo &info)
{
    auto cacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[0].ToObject());

    ATL::CComPtr<IUIAutomationElement> pAutomationElement;
    auto hResult = m_pAutomation->GetFocusedElementBuildCache(cacheRequestWrapper->m_pCacheRequest, &pAutomationElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pAutomationElement);
}

Napi::Value IUIAutomationWrapper::GetPatternProgrammaticName(const Napi::CallbackInfo &info)
{
    auto patternId = static_cast<PATTERNID>(info[0].ToNumber().Uint32Value());
    BSTR patternName;

    auto hResult = m_pAutomation->GetPatternProgrammaticName(patternId, &patternName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(patternName));
}

Napi::Value IUIAutomationWrapper::GetPropertyProgrammaticName(const Napi::CallbackInfo &info)
{
    auto propertyId = static_cast<PROPERTYID>(info[0].ToNumber().Uint32Value());
    BSTR propertyName;

    auto hResult = m_pAutomation->GetPropertyProgrammaticName(propertyId, &propertyName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(propertyName));
}

Napi::Value IUIAutomationWrapper::GetRootElement(const Napi::CallbackInfo &info)
{
    IUIAutomationElement *pRootElement = NULL;
    HRESULT hResult = m_pAutomation->GetRootElement(&pRootElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pRootElement);
}

Napi::Value IUIAutomationWrapper::GetRootElementBuildCache(const Napi::CallbackInfo &info)
{
    auto cacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[0].ToObject());

    IUIAutomationElement *pRootElement = NULL;
    HRESULT hResult = m_pAutomation->GetRootElementBuildCache(cacheRequestWrapper->m_pCacheRequest, &pRootElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pRootElement);
}

void IUIAutomationWrapper::RemoveAllEventHandlers(const Napi::CallbackInfo &info)
{
    HRESULT hResult = m_pAutomation->RemoveAllEventHandlers();

    HandleResult(info, hResult);
}

void IUIAutomationWrapper::RemoveAutomationEventHandler(const Napi::CallbackInfo &info)
{
    auto eventId = static_cast<EVENTID>(info[0].ToNumber().Uint32Value());

    auto elementWrapper = ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[1].ToObject());

    auto eventHandlerWrapper = ObjectWrap<IUIAutomationEventHandlerWrapper>::Unwrap(info[2].ToObject());

    HRESULT hResult = m_pAutomation->RemoveAutomationEventHandler(eventId, elementWrapper->m_pElement, eventHandlerWrapper->m_pEventHandler);

    HandleResult(info, hResult);
}

void IUIAutomationWrapper::RemoveFocusChangedEventHandler(const Napi::CallbackInfo &info)
{
    auto eventHandlerWrapper = ObjectWrap<IUIAutomationFocusChangedEventHandlerWrapper>::Unwrap(info[0].ToObject());

    HRESULT hResult = m_pAutomation->RemoveFocusChangedEventHandler(eventHandlerWrapper->m_pFocusChangedEventHandler);

    HandleResult(info, hResult);
}

void IUIAutomationWrapper::RemovePropertyChangedEventHandler(const Napi::CallbackInfo &info)
{
    auto elementWrapper = ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    auto eventHandlerWrapper = ObjectWrap<IUIAutomationPropertyChangedEventHandlerWrapper>::Unwrap(info[1].ToObject());

    HRESULT hResult = m_pAutomation->RemovePropertyChangedEventHandler(elementWrapper->m_pElement, eventHandlerWrapper->m_pPropertyChangedEventHandler);

    HandleResult(info, hResult);
}

void IUIAutomationWrapper::RemoveStructureChangedEventHandler(const Napi::CallbackInfo &info)
{
    auto elementWrapper = ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    auto eventHandlerWrapper = ObjectWrap<IUIAutomationStructureChangedEventHandlerWrapper>::Unwrap(info[1].ToObject());

    HRESULT hResult = m_pAutomation->RemoveStructureChangedEventHandler(elementWrapper->m_pElement, eventHandlerWrapper->m_pStructureChangedEventHandler);

    HandleResult(info, hResult);
}
