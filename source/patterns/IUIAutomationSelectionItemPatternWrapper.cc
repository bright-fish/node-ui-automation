#include "IUIAutomationSelectionItemPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "../utilities/ComAutoPointer.h"

Napi::FunctionReference *IUIAutomationSelectionItemPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationSelectionItemPatternWrapper::GetCachedIsSelected>("cachedIsSelected"),
        InstanceAccessor<&IUIAutomationSelectionItemPatternWrapper::GetCachedSelectionContainer>("cachedSelectionContainer"),
        InstanceAccessor<&IUIAutomationSelectionItemPatternWrapper::GetCurrentIsSelected>("currentIsSelected"),
        InstanceAccessor<&IUIAutomationSelectionItemPatternWrapper::GetCurrentSelectionContainer>("currentSelectionContainer"),

        InstanceMethod<&IUIAutomationSelectionItemPatternWrapper::AddToSelection>("addToSelection"),
        InstanceMethod<&IUIAutomationSelectionItemPatternWrapper::RemoveFromSelection>("removeFromSelection"),
        InstanceMethod<&IUIAutomationSelectionItemPatternWrapper::Select>("select"),
    };

    Napi::Function function = DefineClass(env, "ISelectionItemProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationSelectionItemPatternWrapper::New(Napi::Env env, IUIAutomationSelectionItemPattern *pSelectionItemPattern)
{
    if (pSelectionItemPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationSelectionItemPatternWrapperConstructor->New({Napi::External<IUIAutomationSelectionItemPattern>::New(env, pSelectionItemPattern)});
}

IUIAutomationSelectionItemPatternWrapper::IUIAutomationSelectionItemPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationSelectionItemPatternWrapper>(info)
{
    m_selectionItemPattern = info[0].As<Napi::External<IUIAutomationSelectionItemPattern>>().Data();
}

IUIAutomationSelectionItemPatternWrapper::~IUIAutomationSelectionItemPatternWrapper()
{
    m_selectionItemPattern.Release();
}

Napi::Value IUIAutomationSelectionItemPatternWrapper::GetCachedIsSelected(const Napi::CallbackInfo &info)
{
    BOOL isSelected;
    auto hResult = m_selectionItemPattern->get_CachedIsSelected(&isSelected);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelected);
}

Napi::Value IUIAutomationSelectionItemPatternWrapper::GetCachedSelectionContainer(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElement> pSelectionContainer = NULL;
    auto hResult = m_selectionItemPattern->get_CachedSelectionContainer(&pSelectionContainer);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pSelectionContainer);
}


Napi::Value IUIAutomationSelectionItemPatternWrapper::GetCurrentIsSelected(const Napi::CallbackInfo &info)
{
    BOOL isSelected;
    auto hResult = m_selectionItemPattern->get_CurrentIsSelected(&isSelected);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelected);
}

Napi::Value IUIAutomationSelectionItemPatternWrapper::GetCurrentSelectionContainer(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElement> pSelectionContainer = NULL;
    auto hResult = m_selectionItemPattern->get_CurrentSelectionContainer(&pSelectionContainer);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pSelectionContainer);
}


void IUIAutomationSelectionItemPatternWrapper::AddToSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_selectionItemPattern->AddToSelection();

    HandleResult(info, hResult);
}

void IUIAutomationSelectionItemPatternWrapper::RemoveFromSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_selectionItemPattern->RemoveFromSelection();

    HandleResult(info, hResult);
}

void IUIAutomationSelectionItemPatternWrapper::Select(const Napi::CallbackInfo &info)
{
    auto hResult = m_selectionItemPattern->Select();

    HandleResult(info, hResult);
}