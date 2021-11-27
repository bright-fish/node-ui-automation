#include "IDropTargetProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IDropTargetProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IDropTargetProviderWrapper::GetDropTargetEffect>("dropTargetEffect"),
        InstanceAccessor<&IDropTargetProviderWrapper::GetDropTargetEffects>("dropTargetEffects"),
    };

    Napi::Function function = DefineClass(env, "IDropTargetProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IDropTargetProviderWrapper::New(Napi::Env env, IDropTargetProvider *pIDropTargetProvider)
{
    if (pIDropTargetProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IDropTargetProviderWrapperConstructor->New({Napi::External<IDropTargetProvider>::New(env, pIDropTargetProvider)});
}

IDropTargetProviderWrapper::IDropTargetProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IDropTargetProviderWrapper>(info)
{
    m_pIDropTargetProvider = info[0].As<Napi::External<IDropTargetProvider>>().Data();
}

IDropTargetProviderWrapper::~IDropTargetProviderWrapper()
{
    m_pIDropTargetProvider->Release();
}

Napi::Value IDropTargetProviderWrapper::GetDropTargetEffect(const Napi::CallbackInfo &info)
{
    BSTR dropEffect;
    auto hResult = m_pIDropTargetProvider->get_DropTargetEffect(&dropEffect);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffect));
}

Napi::Value IDropTargetProviderWrapper::GetDropTargetEffects(const Napi::CallbackInfo &info)
{
    CComSafeArray<BSTR> dropEffects;
    auto hResult = m_pIDropTargetProvider->get_DropTargetEffects(&dropEffects.m_psa);

    HandleResult(info, hResult);

    auto array = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < dropEffects.GetCount(); i++)
    {
        auto dropEffect = Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffects.GetAt(i)));

        array.Set(i, dropEffect);
    }

    return array;
}
