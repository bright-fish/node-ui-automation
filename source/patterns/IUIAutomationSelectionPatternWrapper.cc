#include "IUIAutomationSelectionPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationSelectionPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationSelectionPatternWrapper::GetCachedCanSelectMultiple>("cachedCanSelectMultiple"),
        InstanceAccessor<&IUIAutomationSelectionPatternWrapper::GetCachedIsSelectionRequired>("cachedIsSelectionRequired"),
        InstanceAccessor<&IUIAutomationSelectionPatternWrapper::GetCurrentCanSelectMultiple>("currentCanSelectMultiple"),
        InstanceAccessor<&IUIAutomationSelectionPatternWrapper::GetCurrentIsSelectionRequired>("currentIsSelectionRequired"),

        InstanceMethod<&IUIAutomationSelectionPatternWrapper::GetCachedSelection>("getCachedSelection"),
        InstanceMethod<&IUIAutomationSelectionPatternWrapper::GetCurrentSelection>("getCurrentSelection"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationSelectionPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationSelectionPatternWrapper::New(Napi::Env env, IUIAutomationSelectionPattern *pSelectionPattern)
{
    if (pSelectionPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationSelectionPatternWrapperConstructor->New({Napi::External<IUIAutomationSelectionPattern>::New(env, pSelectionPattern)});
}

IUIAutomationSelectionPatternWrapper::IUIAutomationSelectionPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationSelectionPatternWrapper>(info)
{
    m_selectionPattern = info[0].As<Napi::External<IUIAutomationSelectionPattern>>().Data();
}

IUIAutomationSelectionPatternWrapper::~IUIAutomationSelectionPatternWrapper()
{
    m_selectionPattern.Release();
}

Napi::Value IUIAutomationSelectionPatternWrapper::GetCachedCanSelectMultiple(const Napi::CallbackInfo &info)
{
    BOOL canSelectMultiple;
    auto hResult = m_selectionPattern->get_CachedCanSelectMultiple(&canSelectMultiple);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canSelectMultiple);
}

Napi::Value IUIAutomationSelectionPatternWrapper::GetCachedIsSelectionRequired(const Napi::CallbackInfo &info)
{
    BOOL isSelectionRequired;
    auto hResult = m_selectionPattern->get_CachedIsSelectionRequired(&isSelectionRequired);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelectionRequired);
}

Napi::Value IUIAutomationSelectionPatternWrapper::GetCurrentCanSelectMultiple(const Napi::CallbackInfo &info)
{
    BOOL canSelectMultiple;
    auto hResult = m_selectionPattern->get_CurrentCanSelectMultiple(&canSelectMultiple);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canSelectMultiple);
}

Napi::Value IUIAutomationSelectionPatternWrapper::GetCurrentIsSelectionRequired(const Napi::CallbackInfo &info)
{
    BOOL isSelectionRequired;
    auto hResult = m_selectionPattern->get_CurrentIsSelectionRequired(&isSelectionRequired);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isSelectionRequired);
}

Napi::Value IUIAutomationSelectionPatternWrapper::GetCachedSelection(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElementArray> selection = NULL;

    auto hResult = m_selectionPattern->GetCachedSelection(&selection);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = selection->get_Length(&length);

    HandleResult(info, hResult);

    for (long i = 0; i < length; i++)
    {
        ComAutoPointer<IUIAutomationElement> element = NULL;

        hResult = selection->GetElement(i, &element);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationElementWrapper::New(info.Env(), element));
    }

    return output;
}

Napi::Value IUIAutomationSelectionPatternWrapper::GetCurrentSelection(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElementArray> selection = NULL;
    auto hResult = m_selectionPattern->GetCurrentSelection(&selection);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = selection->get_Length(&length);

    HandleResult(info, hResult);

    for (long i = 0; i < length; i++)
    {
        ComAutoPointer<IUIAutomationElement> element = NULL;

        hResult = selection->GetElement(i, &element);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationElementWrapper::New(info.Env(), element));
    }

    return output;
}