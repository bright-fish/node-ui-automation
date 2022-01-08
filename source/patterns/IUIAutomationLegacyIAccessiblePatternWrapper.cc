#include "IUIAutomationLegacyIAccessiblePatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationLegacyIAccessiblePatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedChildId>("cachedChildId"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedDefaultAction>("cachedDefaultAction"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedDescription>("cachedDescription"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedHelp>("cachedHelp"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedKeyboardShortcut>("cachedKeyboardShortcut"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedName>("cachedName"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedRole>("cachedRole"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedState>("cachedState"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedValue>("cachedValue"),

        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentChildId>("currentChildId"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentDefaultAction>("currentDefaultAction"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentDescription>("currentDescription"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentHelp>("currentHelp"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentKeyboardShortcut>("currentKeyboardShortcut"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentName>("currentName"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentRole>("currentRole"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentState>("currentState"),
        InstanceAccessor<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentValue>("currentValue"),

        InstanceMethod<&IUIAutomationLegacyIAccessiblePatternWrapper::DoDefaultAction>("doDefaultAction"),
        // skipping: InstanceMethod<&IUIAutomationLegacyIAccessiblePatternWrapper::GetIAccessible>("getAccessible"),
        InstanceMethod<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedSelection>("getCachedSelection"),
        InstanceMethod<&IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentSelection>("getCurrentSelection"),
        InstanceMethod<&IUIAutomationLegacyIAccessiblePatternWrapper::Select>("select"),
        InstanceMethod<&IUIAutomationLegacyIAccessiblePatternWrapper::SetValue>("setValue"),
    };

    Napi::Function function = DefineClass(env, "ILegacyIAccessibleProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::New(Napi::Env env, IUIAutomationLegacyIAccessiblePattern *pLegacyIAccessiblePattern)
{
    if (pLegacyIAccessiblePattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationLegacyIAccessiblePatternWrapperConstructor->New({Napi::External<IUIAutomationLegacyIAccessiblePattern>::New(env, pLegacyIAccessiblePattern)});
}

IUIAutomationLegacyIAccessiblePatternWrapper::IUIAutomationLegacyIAccessiblePatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationLegacyIAccessiblePatternWrapper>(info)
{
    m_legacyIAccessiblePattern = info[0].As<Napi::External<IUIAutomationLegacyIAccessiblePattern>>().Data();
}

IUIAutomationLegacyIAccessiblePatternWrapper::~IUIAutomationLegacyIAccessiblePatternWrapper()
{
    m_legacyIAccessiblePattern.Release();
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedChildId(const Napi::CallbackInfo &info)
{
    int childId;
    auto hResult = m_legacyIAccessiblePattern->get_CachedChildId(&childId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), childId);
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedDefaultAction(const Napi::CallbackInfo &info)
{
    BSTR defaultAction;
    auto hResult = m_legacyIAccessiblePattern->get_CachedDefaultAction(&defaultAction);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(defaultAction));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedDescription(const Napi::CallbackInfo &info)
{
    BSTR description;
    auto hResult = m_legacyIAccessiblePattern->get_CachedDescription(&description);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(description));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedHelp(const Napi::CallbackInfo &info)
{
    BSTR help;
    auto hResult = m_legacyIAccessiblePattern->get_CachedHelp(&help);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(help));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedKeyboardShortcut(const Napi::CallbackInfo &info)
{
    BSTR keyboardShortcut;
    auto hResult = m_legacyIAccessiblePattern->get_CachedKeyboardShortcut(&keyboardShortcut);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(keyboardShortcut));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedName(const Napi::CallbackInfo &info)
{
    BSTR name;
    auto hResult = m_legacyIAccessiblePattern->get_CachedName(&name);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(name));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedRole(const Napi::CallbackInfo &info)
{
    DWORD role;
    auto hResult = m_legacyIAccessiblePattern->get_CachedRole(&role);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), role);
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedState(const Napi::CallbackInfo &info)
{
    DWORD state;
    auto hResult = m_legacyIAccessiblePattern->get_CachedState(&state);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), state);
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedValue(const Napi::CallbackInfo &info)
{
    BSTR value;
    auto hResult = m_legacyIAccessiblePattern->get_CachedValue(&value);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(value));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentChildId(const Napi::CallbackInfo &info)
{
    int childId;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentChildId(&childId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), childId);
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentDefaultAction(const Napi::CallbackInfo &info)
{
    BSTR defaultAction;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentDefaultAction(&defaultAction);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(defaultAction));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentDescription(const Napi::CallbackInfo &info)
{
    BSTR description;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentDescription(&description);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(description));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentHelp(const Napi::CallbackInfo &info)
{
    BSTR help;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentHelp(&help);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(help));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentKeyboardShortcut(const Napi::CallbackInfo &info)
{
    BSTR keyboardShortcut;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentKeyboardShortcut(&keyboardShortcut);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(keyboardShortcut));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentName(const Napi::CallbackInfo &info)
{
    BSTR name;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentName(&name);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(name));
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentRole(const Napi::CallbackInfo &info)
{
    DWORD role;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentRole(&role);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), role);
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentState(const Napi::CallbackInfo &info)
{
    DWORD state;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentState(&state);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), state);
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentValue(const Napi::CallbackInfo &info)
{
    BSTR value;
    auto hResult = m_legacyIAccessiblePattern->get_CurrentValue(&value);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(value));
}

void IUIAutomationLegacyIAccessiblePatternWrapper::DoDefaultAction(const Napi::CallbackInfo &info)
{
    auto hResult = m_legacyIAccessiblePattern->DoDefaultAction();

    HandleResult(info, hResult);
}

// skipping: current value doesnt appear high enough to warrent the effort.
// Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetIAccessible(const Napi::CallbackInfo &info)
// {
//     IAccessible *pIAccessible;
//     auto hResult = m_pILegacyIAccessibleProvider->GetIAccessible(&pIAccessible);

//     HandleResult(info, hResult);

//     return IAccessibleWrapper::New(info.Env(), pIAccessible);
// }

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCachedSelection(const Napi::CallbackInfo &info)
{
    // todo: Verify this functions correctly.  Most likely it does not.

    ATL::CComPtr<IUIAutomationElementArray> cachedSelection;

    auto hResult = m_legacyIAccessiblePattern->GetCachedSelection(&cachedSelection);

    HandleResult(info, hResult);

    int length = 0;

    hResult = cachedSelection->get_Length(&length);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;

        hResult = cachedSelection->GetElement(i, &element);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationElementWrapper::New(info.Env(), element));
    }

    return output;
}

Napi::Value IUIAutomationLegacyIAccessiblePatternWrapper::GetCurrentSelection(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElementArray> currentSelection;

    auto hResult = m_legacyIAccessiblePattern->GetCurrentSelection(&currentSelection);

    HandleResult(info, hResult);

    int length = 0;

    hResult = currentSelection->get_Length(&length);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;

        hResult = currentSelection->GetElement(i, &element);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationElementWrapper::New(info.Env(), element));
    }

    return output;
}

void IUIAutomationLegacyIAccessiblePatternWrapper::Select(const Napi::CallbackInfo &info)
{
    long selectFlags = info[0].ToNumber().Int32Value();

    auto hResult = m_legacyIAccessiblePattern->Select(selectFlags);

    HandleResult(info, hResult);
}

void IUIAutomationLegacyIAccessiblePatternWrapper::SetValue(const Napi::CallbackInfo &info)
{
    CComBSTR value = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());

    auto hResult = m_legacyIAccessiblePattern->SetValue(value);

    HandleResult(info, hResult);
}