#include "ISelectionProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *ISelectionProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ISelectionProviderWrapper::GetCanSelectMultiple>("canSelectMultiple"),
        InstanceAccessor<&ISelectionProviderWrapper::GetIsSelectionRequired>("isSelectionRequired"),

        InstanceMethod<&ISelectionProviderWrapper::GetSelection>("getSelection"),
    };

    Napi::Function function = DefineClass(env, "ISelectionProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ISelectionProviderWrapper::New(Napi::Env env, ISelectionProvider *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ISelectionProviderWrapperConstructor->New({Napi::External<ISelectionProvider>::New(env, pInvokeProvider)});
}

ISelectionProviderWrapper::ISelectionProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ISelectionProviderWrapper>(info)
{
    m_pISelectionProvider = info[0].As<Napi::External<ISelectionProvider>>().Data();
}

ISelectionProviderWrapper::~ISelectionProviderWrapper()
{
    m_pISelectionProvider->Release();
}

Napi::Value ISelectionProviderWrapper::GetCanSelectMultiple(const Napi::CallbackInfo &info)
{
    BOOL canSelectMultiple;
    auto hResult = m_pISelectionProvider->get_CanSelectMultiple(&canSelectMultiple);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canSelectMultiple);
}

Napi::Value ISelectionProviderWrapper::GetIsSelectionRequired(const Napi::CallbackInfo &info)
{
    BOOL isSelectionRequired;
    auto hResult = m_pISelectionProvider->get_IsSelectionRequired(&isSelectionRequired);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelectionRequired);
}

Napi::Value ISelectionProviderWrapper::GetSelection(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> selection;
    auto hResult = m_pISelectionProvider->GetSelection(&selection.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < selection.GetCount(); i++)
    {
        auto variant = selection.GetAt(i);

        auto selectedElement = static_cast<IRawElementProviderSimple *>(variant.punkVal);

        output.Set(i, IRawElementProviderSimpleWrapper::New(info.Env(), selectedElement));
    }

    return output;
}
