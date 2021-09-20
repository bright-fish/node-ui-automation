#include "IUIAutomationTreeWalkerWrapper.h"
#include "IUIAutomationElementWrapper.h"
#include "IUIAutomationCacheRequestWrapper.h"

using Napi::Object;

Napi::FunctionReference IUIAutomationTreeWalkerWrapper::constructor;

IUIAutomationTreeWalkerWrapper::IUIAutomationTreeWalkerWrapper(const Napi::CallbackInfo &info, IUIAutomationTreeWalker *pTreeWalker) : IUIAutomationTreeWalkerWrapper(info)
{
    m_pTreeWalker = pTreeWalker;
}

IUIAutomationTreeWalkerWrapper::IUIAutomationTreeWalkerWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTreeWalkerWrapper>(info)
{
}

Napi::Object IUIAutomationTreeWalkerWrapper::Init(Napi::Env env, Napi::Object exports)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetFirstChildElement>("getFirstChildElement"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetFirstChildElementBuildCache>("getFirstChildElementBuildCache"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetLastChildElement>("getLastChildElement"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetLastChildElementBuildCache>("getLastChildElementBuildCache"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetNextSiblingElement>("getNextSiblingElement"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetNextSiblingElementBuildCache>("getNextSiblingElementBuildCache"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetParentElement>("getParentElement"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetParentElementBuildCache>("getParentElementBuildCache"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElement>("getPreviousSiblingElement"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElementBuildCache>("getPreviousSiblingElementBuildCache"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::NormalizeElement>("normalizeElement"),
        InstanceMethod<&IUIAutomationTreeWalkerWrapper::NormalizeElementBuildCache>("normalizeElementBuildCache"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTreeWalker", classDefinition);

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetFirstChildElement(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    IUIAutomationElement *pFirstChildElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetFirstChildElement(pElementWrapper->m_pElement, &pFirstChildElement);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    auto firstChildElementWrapper = new IUIAutomationElementWrapper(info, pFirstChildElement);

    return firstChildElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetFirstChildElementBuildCache(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[1].ToObject());

    IUIAutomationElement *pFirstChildElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetFirstChildElementBuildCache(pElementWrapper->m_pElement, pCacheRequestWrapper->m_pCacheRequest, &pFirstChildElement);

    auto firstChildElementWrapper = new IUIAutomationElementWrapper(info, pFirstChildElement);

    return firstChildElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetLastChildElement(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    IUIAutomationElement *pLastChildElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetLastChildElement(pElementWrapper->m_pElement, &pLastChildElement);

    auto lastChildElementWrapper = new IUIAutomationElementWrapper(info, pLastChildElement);

    return lastChildElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetLastChildElementBuildCache(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[1].ToObject());

    IUIAutomationElement *pLastChildElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetLastChildElementBuildCache(pElementWrapper->m_pElement, pCacheRequestWrapper->m_pCacheRequest, &pLastChildElement);

    auto lastChildElementWrapper = new IUIAutomationElementWrapper(info, pLastChildElement);

    return lastChildElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetNextSiblingElement(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    IUIAutomationElement *pNextSiblingElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetNextSiblingElement(pElementWrapper->m_pElement, &pNextSiblingElement);

    auto nextSiblingElementWrapper = new IUIAutomationElementWrapper(info, pNextSiblingElement);

    return nextSiblingElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetNextSiblingElementBuildCache(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[1].ToObject());

    IUIAutomationElement *pNextSiblingElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetNextSiblingElementBuildCache(pElementWrapper->m_pElement, pCacheRequestWrapper->m_pCacheRequest, &pNextSiblingElement);

    auto nextSiblingElementWrapper = new IUIAutomationElementWrapper(info, pNextSiblingElement);

    return nextSiblingElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetParentElement(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    IUIAutomationElement *pParentElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetParentElement(pElementWrapper->m_pElement, &pParentElement);

    auto parentElementWrapper = new IUIAutomationElementWrapper(info, pParentElement);

    return parentElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetParentElementBuildCache(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[1].ToObject());

    IUIAutomationElement *parentElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetParentElementBuildCache(pElementWrapper->m_pElement, pCacheRequestWrapper->m_pCacheRequest, &parentElement);

    auto parentElementWrapper = new IUIAutomationElementWrapper(info, parentElement);

    return parentElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElement(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    IUIAutomationElement *pPreviousSiblingElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetPreviousSiblingElement(pElementWrapper->m_pElement, &pPreviousSiblingElement);

    auto previousSiblingElementWrapper = new IUIAutomationElementWrapper(info, pPreviousSiblingElement);

    return previousSiblingElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::GetPreviousSiblingElementBuildCache(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[1].ToObject());

    IUIAutomationElement *previousSiblingElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetPreviousSiblingElementBuildCache(pElementWrapper->m_pElement, pCacheRequestWrapper->m_pCacheRequest, &previousSiblingElement);

    auto previousSiblingElementWrapper = new IUIAutomationElementWrapper(info, previousSiblingElement);

    return previousSiblingElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::NormalizeElement(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    IUIAutomationElement *pNormalizedElemment = NULL;
    HRESULT hResult = m_pTreeWalker->NormalizeElement(pElementWrapper->m_pElement, &pNormalizedElemment);

    auto normalizedElementWrapper = new IUIAutomationElementWrapper(info, pNormalizedElemment);

    return normalizedElementWrapper->Value();
}

Napi::Value IUIAutomationTreeWalkerWrapper::NormalizeElementBuildCache(const Napi::CallbackInfo &info)
{
    auto pElementWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());
    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[1].ToObject());

    IUIAutomationElement *pNormalizedElement = NULL;
    HRESULT hResult = m_pTreeWalker->GetPreviousSiblingElementBuildCache(pElementWrapper->m_pElement, pCacheRequestWrapper->m_pCacheRequest, &pNormalizedElement);

    auto normalizedElementWrapper = new IUIAutomationElementWrapper(info, pNormalizedElement);

    return normalizedElementWrapper->Value();
}
