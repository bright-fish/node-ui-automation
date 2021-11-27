#include "ISelectionItemProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *ISelectionItemProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ISelectionItemProviderWrapper::GetIsSelected>("isSelected"),
        InstanceAccessor<&ISelectionItemProviderWrapper::GetSelectionContainer>("selectionContainer"),

        InstanceMethod<&ISelectionItemProviderWrapper::AddToSelection>("addToSelection"),
        InstanceMethod<&ISelectionItemProviderWrapper::RemoveFromSelection>("removeFromSelection"),
        InstanceMethod<&ISelectionItemProviderWrapper::Select>("select"),
    };

    Napi::Function function = DefineClass(env, "ISelectionItemProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ISelectionItemProviderWrapper::New(Napi::Env env, ISelectionItemProvider *pISelectionItemProvider)
{
    if (pISelectionItemProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ISelectionItemProviderWrapperConstructor->New({Napi::External<ISelectionItemProvider>::New(env, pISelectionItemProvider)});
}

ISelectionItemProviderWrapper::ISelectionItemProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ISelectionItemProviderWrapper>(info)
{
    m_pISelectionItemProvider = info[0].As<Napi::External<ISelectionItemProvider>>().Data();
}

ISelectionItemProviderWrapper::~ISelectionItemProviderWrapper()
{
    m_pISelectionItemProvider->Release();
}

Napi::Value ISelectionItemProviderWrapper::GetIsSelected(const Napi::CallbackInfo &info)
{
    BOOL isSelected;
    auto hResult = m_pISelectionItemProvider->get_IsSelected(&isSelected);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelected);
}

Napi::Value ISelectionItemProviderWrapper::GetSelectionContainer(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *pSelectionContainer;
    auto hResult = m_pISelectionItemProvider->get_SelectionContainer(&pSelectionContainer);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pSelectionContainer);
}

void ISelectionItemProviderWrapper::AddToSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_pISelectionItemProvider->AddToSelection();

    HandleResult(info, hResult);
}

void ISelectionItemProviderWrapper::RemoveFromSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_pISelectionItemProvider->RemoveFromSelection();

    HandleResult(info, hResult);
}

void ISelectionItemProviderWrapper::Select(const Napi::CallbackInfo &info)
{
    auto hResult = m_pISelectionItemProvider->Select();

    HandleResult(info, hResult);
}