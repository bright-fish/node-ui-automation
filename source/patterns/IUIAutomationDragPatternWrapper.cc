#include "IUIAutomationDragPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "../utilities/ComAutoPointer.h"
#include "../utilities/AutoSafeArray.h"

Napi::FunctionReference *IUIAutomationDragPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationDragPatternWrapper::GetCachedDropEffects>("cachedDropEffects"),
        InstanceAccessor<&IUIAutomationDragPatternWrapper::GetCachedDropEffect>("cachedDropEffect"),
        InstanceAccessor<&IUIAutomationDragPatternWrapper::GetCachedIsGrabbed>("cachedIsGrabbed"),
        InstanceAccessor<&IUIAutomationDragPatternWrapper::GetCurrentDropEffects>("currentDropEffects"),
        InstanceAccessor<&IUIAutomationDragPatternWrapper::GetCurrentDropEffect>("currentDropEffect"),
        InstanceAccessor<&IUIAutomationDragPatternWrapper::GetCurrentIsGrabbed>("currentIsGrabbed"),

        InstanceMethod<&IUIAutomationDragPatternWrapper::GetCachedGrabbedItems>("getCachedGrabbedItems"),
        InstanceMethod<&IUIAutomationDragPatternWrapper::GetCurrentGrabbedItems>("getCurrentGrabbedItems"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationDragPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationDragPatternWrapper::New(Napi::Env env, IUIAutomationDragPattern *pDragPattern)
{
    if (pDragPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationDragPatternWrapperConstructor->New({Napi::External<IUIAutomationDragPattern>::New(env, pDragPattern)});
}

IUIAutomationDragPatternWrapper::IUIAutomationDragPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationDragPatternWrapper>(info)
{
    m_dragPattern = info[0].As<Napi::External<IUIAutomationDragPattern>>().Data();
}

IUIAutomationDragPatternWrapper::~IUIAutomationDragPatternWrapper()
{
    m_dragPattern.Release();
}

Napi::Value IUIAutomationDragPatternWrapper::GetCachedDropEffects(const Napi::CallbackInfo &info)
{
    AutoSafeArray<BSTR> pSafeArray;

    auto hResult = m_dragPattern->get_CachedDropEffects(&pSafeArray.m_psa);

    HandleResult(info, hResult);

    auto array = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < pSafeArray.GetCount(); i++)
    {
        auto dropEffect = Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(pSafeArray.GetAt(i)));

        array.Set(i, dropEffect);
    }

    return array;
}

Napi::Value IUIAutomationDragPatternWrapper::GetCachedDropEffect(const Napi::CallbackInfo &info)
{
    BSTR dropEffect;
    auto hResult = m_dragPattern->get_CachedDropEffect(&dropEffect);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffect));
}

Napi::Value IUIAutomationDragPatternWrapper::GetCachedIsGrabbed(const Napi::CallbackInfo &info)
{
    BOOL isGrabbed;
    auto hResult = m_dragPattern->get_CachedIsGrabbed(&isGrabbed);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isGrabbed);
}

Napi::Value IUIAutomationDragPatternWrapper::GetCurrentDropEffects(const Napi::CallbackInfo &info)
{
    AutoSafeArray<BSTR> pSafeArray;
    
    auto hResult = m_dragPattern->get_CurrentDropEffects(&pSafeArray.m_psa);

    HandleResult(info, hResult);

    auto array = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < pSafeArray.GetCount(); i++)
    {
        auto dropEffect = Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(pSafeArray.GetAt(i)));

        array.Set(i, dropEffect);
    }

    return array;
}

Napi::Value IUIAutomationDragPatternWrapper::GetCurrentDropEffect(const Napi::CallbackInfo &info)
{
    BSTR dropEffect;
    auto hResult = m_dragPattern->get_CurrentDropEffect(&dropEffect);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(dropEffect));
}

Napi::Value IUIAutomationDragPatternWrapper::GetCurrentIsGrabbed(const Napi::CallbackInfo &info)
{
    BOOL isGrabbed;
    auto hResult = m_dragPattern->get_CurrentIsGrabbed(&isGrabbed);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isGrabbed);
}

Napi::Value IUIAutomationDragPatternWrapper::GetCachedGrabbedItems(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElementArray> grabbedItems = NULL;
    auto hResult = m_dragPattern->GetCachedGrabbedItems(&grabbedItems);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), grabbedItems);
}

Napi::Value IUIAutomationDragPatternWrapper::GetCurrentGrabbedItems(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElementArray> grabbedItems = NULL;
    auto hResult = m_dragPattern->GetCurrentGrabbedItems(&grabbedItems);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), grabbedItems);
}
