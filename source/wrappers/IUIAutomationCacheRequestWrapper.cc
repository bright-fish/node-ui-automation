#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationCacheRequestWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationCacheRequestWrapper::AddPattern>("addPattern"),
        InstanceMethod<&IUIAutomationCacheRequestWrapper::AddProperty>("addProperty"),
        InstanceMethod<&IUIAutomationCacheRequestWrapper::Clone>("clone"),

        InstanceAccessor<&IUIAutomationCacheRequestWrapper::GetAutomationElementMode, &IUIAutomationCacheRequestWrapper::PutAutomationElementMode>("automationElementNode"),
        InstanceAccessor<&IUIAutomationCacheRequestWrapper::GetTreeFilter, &IUIAutomationCacheRequestWrapper::PutTreeFilter>("treeFilter"),
        InstanceAccessor<&IUIAutomationCacheRequestWrapper::GetTreeScope, &IUIAutomationCacheRequestWrapper::PutTreeScope>("treeScope"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationCacheRequest", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationCacheRequestWrapper::New(Napi::Env env, IUIAutomationCacheRequest *pCacheRequest)
{
    if (pCacheRequest == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationCacheRequestWrapperConstructor->New({Napi::External<IUIAutomationCacheRequest>::New(env, pCacheRequest)});
}

IUIAutomationCacheRequestWrapper::IUIAutomationCacheRequestWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>(info)
{
    if (info.Length() != 1)
    {
        throw Napi::TypeError::New(info.Env(), "IUIAutomationCacheRequest constructor missing parameter.");
    }

    m_pCacheRequest = info[0].As<Napi::External<IUIAutomationCacheRequest>>().Data();
}

IUIAutomationCacheRequestWrapper::~IUIAutomationCacheRequestWrapper()
{
    m_pCacheRequest.Release();
}

void IUIAutomationCacheRequestWrapper::AddPattern(const Napi::CallbackInfo &info)
{
    auto patternId = static_cast<PATTERNID>(info[0].ToNumber().Int32Value());

    auto hResult = m_pCacheRequest->AddPattern(patternId);

    HandleResult(info, hResult);
}

void IUIAutomationCacheRequestWrapper::AddProperty(const Napi::CallbackInfo &info)
{
    auto propertyId = static_cast<PROPERTYID>(info[0].ToNumber().Int32Value());

    auto hResult = m_pCacheRequest->AddProperty(propertyId);

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationCacheRequestWrapper::Clone(const Napi::CallbackInfo &info)
{
    IUIAutomationCacheRequest *cacheRequest;
    auto hResult = m_pCacheRequest->Clone(&cacheRequest);

    HandleResult(info, hResult);

    return IUIAutomationCacheRequestWrapper::New(info.Env(), cacheRequest);
}

Napi::Value IUIAutomationCacheRequestWrapper::GetAutomationElementMode(const Napi::CallbackInfo &info)
{
    AutomationElementMode elementMode;
    auto hResult = m_pCacheRequest->get_AutomationElementMode(&elementMode);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), elementMode);
}

void IUIAutomationCacheRequestWrapper::PutAutomationElementMode(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    AutomationElementMode elementMode = static_cast<AutomationElementMode>(value.ToNumber().Int32Value());

    auto hResult = m_pCacheRequest->put_AutomationElementMode(elementMode);

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationCacheRequestWrapper::GetTreeFilter(const Napi::CallbackInfo &info)
{
    IUIAutomationCondition *condition;
    auto hResult = m_pCacheRequest->get_TreeFilter(&condition);

    HandleResult(info, hResult);

    return IUIAutomationConditionWrapper::New(info.Env(), condition);
}

void IUIAutomationCacheRequestWrapper::PutTreeFilter(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    auto conditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[0].ToObject());

    auto hResult = m_pCacheRequest->put_TreeFilter(conditionWrapper->m_pCondition);

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationCacheRequestWrapper::GetTreeScope(const Napi::CallbackInfo &info)
{
    TreeScope treeScope;
    auto hResult = m_pCacheRequest->get_TreeScope(&treeScope);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), treeScope);
}

void IUIAutomationCacheRequestWrapper::PutTreeScope(const Napi::CallbackInfo &info, const Napi::Value &value)
{
    TreeScope treeScope = static_cast<TreeScope>(value.ToNumber().Int32Value());

    auto hResult = m_pCacheRequest->put_TreeScope(treeScope);

    HandleResult(info, hResult);
}
