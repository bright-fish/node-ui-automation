#include "ISelectionProvider2Wrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *ISelectionProvider2Wrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ISelectionProvider2Wrapper::GetCanSelectMultiple>("canSelectMultiple"),
        InstanceAccessor<&ISelectionProvider2Wrapper::GetIsSelectionRequired>("isSelectionRequired"),
        InstanceAccessor<&ISelectionProvider2Wrapper::GetCurrentSelectedItem>("currentSelectedItem"),
        InstanceAccessor<&ISelectionProvider2Wrapper::GetFirstSelectedItem>("firstSelectedItem"),
        InstanceAccessor<&ISelectionProvider2Wrapper::GetItemCount>("itemCount"),
        InstanceAccessor<&ISelectionProvider2Wrapper::GetLastSelectedItem>("lastSelectedItem"),

        InstanceMethod<&ISelectionProvider2Wrapper::GetSelection>("getSelection"),
    };

    Napi::Function function = DefineClass(env, "ISelectionProvider2", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ISelectionProvider2Wrapper::New(Napi::Env env, ISelectionProvider2 *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ISelectionProvider2WrapperConstructor->New({Napi::External<ISelectionProvider2>::New(env, pInvokeProvider)});
}

ISelectionProvider2Wrapper::ISelectionProvider2Wrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ISelectionProvider2Wrapper>(info)
{
    m_pISelectionProvider2 = info[0].As<Napi::External<ISelectionProvider2>>().Data();
}

ISelectionProvider2Wrapper::~ISelectionProvider2Wrapper()
{
    m_pISelectionProvider2->Release();
}

Napi::Value ISelectionProvider2Wrapper::GetCanSelectMultiple(const Napi::CallbackInfo &info)
{
    BOOL canSelectMultiple;
    auto hResult = m_pISelectionProvider2->get_CanSelectMultiple(&canSelectMultiple);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canSelectMultiple);
}

Napi::Value ISelectionProvider2Wrapper::GetIsSelectionRequired(const Napi::CallbackInfo &info)
{
    BOOL isSelectionRequired;
    auto hResult = m_pISelectionProvider2->get_IsSelectionRequired(&isSelectionRequired);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelectionRequired);
}

Napi::Value ISelectionProvider2Wrapper::GetCurrentSelectedItem(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *pCurrentSelectedItem;
    auto hResult = m_pISelectionProvider2->get_CurrentSelectedItem(&pCurrentSelectedItem);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), pCurrentSelectedItem);
}

Napi::Value ISelectionProvider2Wrapper::GetFirstSelectedItem(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *pFirstSelectedItem;
    auto hResult = m_pISelectionProvider2->get_FirstSelectedItem(&pFirstSelectedItem);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), pFirstSelectedItem);
}

Napi::Value ISelectionProvider2Wrapper::GetItemCount(const Napi::CallbackInfo &info)
{
    int itemCount;
    auto hResult = m_pISelectionProvider2->get_ItemCount(&itemCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), itemCount);
}

Napi::Value ISelectionProvider2Wrapper::GetLastSelectedItem(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *pLastSelectedItem;
    auto hResult = m_pISelectionProvider2->get_LastSelectedItem(&pLastSelectedItem);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pLastSelectedItem);
}

Napi::Value ISelectionProvider2Wrapper::GetSelection(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> selection;
    auto hResult = m_pISelectionProvider2->GetSelection(&selection.m_psa);

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
