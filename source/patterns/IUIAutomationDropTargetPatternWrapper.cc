#include "IUIAutomationDropTargetPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationDropTargetPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationDropTargetPatternWrapper::GetCachedDropTargetEffect>("cachedDropTargetEffect"),
        InstanceAccessor<&IUIAutomationDropTargetPatternWrapper::GetCachedDropTargetEffects>("cachedDopTargetEffects"),
        InstanceAccessor<&IUIAutomationDropTargetPatternWrapper::GetCurrentDropTargetEffect>("currentDropTargetEffect"),
        InstanceAccessor<&IUIAutomationDropTargetPatternWrapper::GetCurrentDropTargetEffects>("currentDropTargetEffects"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationDropTargetPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationDropTargetPatternWrapper::New(Napi::Env env, IUIAutomationDropTargetPattern *pDropTargetPattern)
{
    if (pDropTargetPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationDropTargetPatternWrapperConstructor->New({Napi::External<IUIAutomationDropTargetPattern>::New(env, pDropTargetPattern)});
}

IUIAutomationDropTargetPatternWrapper::IUIAutomationDropTargetPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationDropTargetPatternWrapper>(info)
{
    m_dropTargetPattern = info[0].As<Napi::External<IUIAutomationDropTargetPattern>>().Data();
}

IUIAutomationDropTargetPatternWrapper::~IUIAutomationDropTargetPatternWrapper()
{
    m_dropTargetPattern.Release();
}

Napi::Value IUIAutomationDropTargetPatternWrapper::GetCachedDropTargetEffect(const Napi::CallbackInfo &info)
{
    BSTR dropEffect;
    auto hResult = m_dropTargetPattern->get_CachedDropTargetEffect(&dropEffect);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffect));
}

Napi::Value IUIAutomationDropTargetPatternWrapper::GetCachedDropTargetEffects(const Napi::CallbackInfo &info)
{
    CComSafeArray<BSTR> dropEffects;
    auto hResult = m_dropTargetPattern->get_CachedDropTargetEffects(&dropEffects.m_psa);

    HandleResult(info, hResult);

    auto array = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < dropEffects.GetCount(); i++)
    {
        auto dropEffect = Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffects.GetAt(i)));

        array.Set(i, dropEffect);
    }

    return array;
}

Napi::Value IUIAutomationDropTargetPatternWrapper::GetCurrentDropTargetEffect(const Napi::CallbackInfo &info)
{
    BSTR dropEffect;
    auto hResult = m_dropTargetPattern->get_CurrentDropTargetEffect(&dropEffect);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffect));
}

Napi::Value IUIAutomationDropTargetPatternWrapper::GetCurrentDropTargetEffects(const Napi::CallbackInfo &info)
{
    CComSafeArray<BSTR> dropEffects;
    auto hResult = m_dropTargetPattern->get_CurrentDropTargetEffects(&dropEffects.m_psa);

    HandleResult(info, hResult);

    auto array = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < dropEffects.GetCount(); i++)
    {
        auto dropEffect = Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffects.GetAt(i)));

        array.Set(i, dropEffect);
    }

    return array;
}
