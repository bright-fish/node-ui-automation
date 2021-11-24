#include "IDragProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IDragProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IDragProviderWrapper::GetDropEffects>("dropEffects"),
        InstanceAccessor<&IDragProviderWrapper::GetDropEffect>("dropEffect"),
        InstanceAccessor<&IDragProviderWrapper::GetIsGrabbed>("isGrabbed"),
        
        InstanceMethod<&IDragProviderWrapper::GetGrabbedItems>("getGrabbedItems"),
    };

    Napi::Function function = DefineClass(env, "IDragProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IDragProviderWrapper::New(Napi::Env env, IDragProvider *pIDragProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IDragProviderWrapperConstructor->New({Napi::External<IDragProvider>::New(env, pIDragProvider)});
}

IDragProviderWrapper::IDragProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IDragProviderWrapper>(info)
{
    m_pIDragProvider = info[0].As<Napi::External<IDragProvider>>().Data();
}

IDragProviderWrapper::~IDragProviderWrapper()
{
    m_pIDragProvider->Release();
}

Napi::Value IDragProviderWrapper::GetDropEffects(const Napi::CallbackInfo &info)
{
    CComSafeArray<BSTR> dropEffects;
    auto hResult = m_pIDragProvider->get_DropEffects(&dropEffects.m_psa);

    HandleResult(info, hResult);

    auto array = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < dropEffects.GetCount(); i++)
    {
        auto dropEffect = Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffects.GetAt(i)));
        
        array.Set(i, dropEffect);
    }

    return array;
}

Napi::Value IDragProviderWrapper::GetDropEffect(const Napi::CallbackInfo &info)
{
    BSTR dropEffect;
    auto hResult = m_pIDragProvider->get_DropEffect(&dropEffect);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffect));
}

Napi::Value IDragProviderWrapper::GetIsGrabbed(const Napi::CallbackInfo &info)
{
    BOOL isGrabbed;
    auto hResult = m_pIDragProvider->get_IsGrabbed(&isGrabbed);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isGrabbed);
}

Napi::Value IDragProviderWrapper::GetGrabbedItems(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> grabbedItems;
    auto hResult = m_pIDragProvider->GetGrabbedItems(&grabbedItems.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < grabbedItems.GetCount(); i++)
    {
        auto variant = grabbedItems.GetAt(i);

        auto rawElementProviderSimpleWrapper = IRawElementProviderSimpleWrapper::New(info.Env(), static_cast<IRawElementProviderSimple *>(variant.punkVal));

        output.Set(i, rawElementProviderSimpleWrapper);
    }

    return output;
}
