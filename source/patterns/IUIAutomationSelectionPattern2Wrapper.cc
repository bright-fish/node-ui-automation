#include "IUIAutomationSelectionPattern2Wrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationSelectionPattern2Wrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCachedCanSelectMultiple>("cachedCanSelectMultiple"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCachedIsSelectionRequired>("cachedIsSelectionRequired"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCachedCurrentSelectedItem>("cachedCurrentSelectedItem"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCachedFirstSelectedItem>("cachedFirstSelectedItem"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCachedItemCount>("cachedItemCount"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCachedLastSelectedItem>("cachedLastSelectedItem"),

        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCurrentCanSelectMultiple>("currentCanSelectMultiple"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCurrentIsSelectionRequired>("currentIsSelectionRequired"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCurrentCurrentSelectedItem>("currentCurrentSelectedItem"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCurrentFirstSelectedItem>("currentFirstSelectedItem"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCurrentItemCount>("currentItemCount"),
        InstanceAccessor<&IUIAutomationSelectionPattern2Wrapper::GetCurrentLastSelectedItem>("currentLastSelectedItem"),

        InstanceMethod<&IUIAutomationSelectionPattern2Wrapper::GetCachedSelection>("getCachedSelection"),
        InstanceMethod<&IUIAutomationSelectionPattern2Wrapper::GetCurrentSelection>("getCurrentSelection"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationSelectionPattern2", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::New(Napi::Env env, IUIAutomationSelectionPattern2 *pSelectionPattern2)
{
    if (pSelectionPattern2 == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ISelectionProvider2WrapperConstructor->New({Napi::External<IUIAutomationSelectionPattern2>::New(env, pSelectionPattern2)});
}

IUIAutomationSelectionPattern2Wrapper::IUIAutomationSelectionPattern2Wrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationSelectionPattern2Wrapper>(info)
{
    m_selectionPattern2 = info[0].As<Napi::External<IUIAutomationSelectionPattern2>>().Data();
}

IUIAutomationSelectionPattern2Wrapper::~IUIAutomationSelectionPattern2Wrapper()
{
    m_selectionPattern2.Release();
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCachedCanSelectMultiple(const Napi::CallbackInfo &info)
{
    BOOL canSelectMultiple;
    auto hResult = m_selectionPattern2->get_CachedCanSelectMultiple(&canSelectMultiple);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canSelectMultiple);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCachedIsSelectionRequired(const Napi::CallbackInfo &info)
{
    BOOL isSelectionRequired;
    auto hResult = m_selectionPattern2->get_CachedIsSelectionRequired(&isSelectionRequired);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelectionRequired);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCachedCurrentSelectedItem(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pCurrentSelectedItem;

    auto hResult = m_selectionPattern2->get_CachedCurrentSelectedItem(&pCurrentSelectedItem);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), pCurrentSelectedItem);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCachedFirstSelectedItem(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pFirstSelectedItem;

    auto hResult = m_selectionPattern2->get_CachedFirstSelectedItem(&pFirstSelectedItem);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), pFirstSelectedItem);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCachedItemCount(const Napi::CallbackInfo &info)
{
    int itemCount;

    auto hResult = m_selectionPattern2->get_CachedItemCount(&itemCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), itemCount);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCachedLastSelectedItem(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pLastSelectedItem;

    auto hResult = m_selectionPattern2->get_CachedLastSelectedItem(&pLastSelectedItem);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pLastSelectedItem);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCurrentCanSelectMultiple(const Napi::CallbackInfo &info)
{
    BOOL canSelectMultiple;
    auto hResult = m_selectionPattern2->get_CurrentCanSelectMultiple(&canSelectMultiple);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canSelectMultiple);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCurrentIsSelectionRequired(const Napi::CallbackInfo &info)
{
    BOOL isSelectionRequired;
    auto hResult = m_selectionPattern2->get_CurrentIsSelectionRequired(&isSelectionRequired);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelectionRequired);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCurrentCurrentSelectedItem(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pCurrentSelectedItem;

    auto hResult = m_selectionPattern2->get_CurrentCurrentSelectedItem(&pCurrentSelectedItem);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), pCurrentSelectedItem);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCurrentFirstSelectedItem(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pFirstSelectedItem;

    auto hResult = m_selectionPattern2->get_CurrentFirstSelectedItem(&pFirstSelectedItem);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), pFirstSelectedItem);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCurrentItemCount(const Napi::CallbackInfo &info)
{
    int itemCount;

    auto hResult = m_selectionPattern2->get_CurrentItemCount(&itemCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), itemCount);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCurrentLastSelectedItem(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pLastSelectedItem;

    auto hResult = m_selectionPattern2->get_CurrentLastSelectedItem(&pLastSelectedItem);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pLastSelectedItem);
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCachedSelection(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElementArray> selection;

    auto hResult = m_selectionPattern2->GetCachedSelection(&selection);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = selection->get_Length(&length);

    for (long i = 0; i < length; i++)
    {

        CComPtr<IUIAutomationElement> element;

        hResult = selection->GetElement(i, &element);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationElementWrapper::New(info.Env(), element));
    }

    return output;
}

Napi::Value IUIAutomationSelectionPattern2Wrapper::GetCurrentSelection(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElementArray> selection;

    auto hResult = m_selectionPattern2->GetCurrentSelection(&selection);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = selection->get_Length(&length);

    for (long i = 0; i < length; i++)
    {
        CComPtr<IUIAutomationElement> element;

        hResult = selection->GetElement(i, &element);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationElementWrapper::New(info.Env(), element));
    }

    return output;
}
