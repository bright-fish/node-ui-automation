#include "ILegacyIAccessibleProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
// skipping:  #include "IAccessibleWrapper.h"

Napi::FunctionReference *ILegacyIAccessibleProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetChildId>("childId"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetDefaultAction>("defaultAction"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetDescription>("description"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetHelp>("help"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetKeyboardShortcut>("keyboardShortcut"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetName>("name"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetRole>("role"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetSelection>("selection"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetState>("state"),
        InstanceAccessor<&ILegacyIAccessibleProviderWrapper::GetValue>("value"),

        InstanceMethod<&ILegacyIAccessibleProviderWrapper::DoDefaultAction>("doDefaultAction"),
        // skipping: InstanceMethod<&ILegacyIAccessibleProviderWrapper::GetIAccessible>("getAccessible"),
        InstanceMethod<&ILegacyIAccessibleProviderWrapper::GetSelection>("getSelection"),
        InstanceMethod<&ILegacyIAccessibleProviderWrapper::Select>("select"),
        InstanceMethod<&ILegacyIAccessibleProviderWrapper::SetValue>("setValue"),
    };

    Napi::Function function = DefineClass(env, "ILegacyIAccessibleProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ILegacyIAccessibleProviderWrapper::New(Napi::Env env, ILegacyIAccessibleProvider *pILegacyIAccessibleProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ILegacyIAccessibleProviderWrapperConstructor->New({Napi::External<ILegacyIAccessibleProvider>::New(env, pILegacyIAccessibleProvider)});
}

ILegacyIAccessibleProviderWrapper::ILegacyIAccessibleProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ILegacyIAccessibleProviderWrapper>(info)
{
    m_pILegacyIAccessibleProvider = info[0].As<Napi::External<ILegacyIAccessibleProvider>>().Data();
}

ILegacyIAccessibleProviderWrapper::~ILegacyIAccessibleProviderWrapper()
{
    m_pILegacyIAccessibleProvider->Release();
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetChildId(const Napi::CallbackInfo &info)
{
    int childId;
    auto hResult = m_pILegacyIAccessibleProvider->get_ChildId(&childId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), childId);
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetDefaultAction(const Napi::CallbackInfo &info)
{
    BSTR defaultAction;
    auto hResult = m_pILegacyIAccessibleProvider->get_DefaultAction(&defaultAction);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(defaultAction));
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetDescription(const Napi::CallbackInfo &info)
{
    BSTR description;
    auto hResult = m_pILegacyIAccessibleProvider->get_Description(&description);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(description));
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetHelp(const Napi::CallbackInfo &info)
{
    BSTR help;
    auto hResult = m_pILegacyIAccessibleProvider->get_Help(&help);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(help));
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetKeyboardShortcut(const Napi::CallbackInfo &info)
{
    BSTR keyboardShortcut;
    auto hResult = m_pILegacyIAccessibleProvider->get_KeyboardShortcut(&keyboardShortcut);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(keyboardShortcut));
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetName(const Napi::CallbackInfo &info)
{
    BSTR name;
    auto hResult = m_pILegacyIAccessibleProvider->get_Name(&name);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(name));
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetRole(const Napi::CallbackInfo &info)
{
    DWORD role;
    auto hResult = m_pILegacyIAccessibleProvider->get_Role(&role);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), role);
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetState(const Napi::CallbackInfo &info)
{
    DWORD state;
    auto hResult = m_pILegacyIAccessibleProvider->get_State(&state);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), state);
}

Napi::Value ILegacyIAccessibleProviderWrapper::GetValue(const Napi::CallbackInfo &info)
{
    BSTR value;
    auto hResult = m_pILegacyIAccessibleProvider->get_Value(&value);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(value));
}

void ILegacyIAccessibleProviderWrapper::DoDefaultAction(const Napi::CallbackInfo &info)
{
    auto hResult = m_pILegacyIAccessibleProvider->DoDefaultAction();

    HandleResult(info, hResult);
}

// skipping: current value doesnt appear high enough to warrent the effort.
// Napi::Value ILegacyIAccessibleProviderWrapper::GetIAccessible(const Napi::CallbackInfo &info)
// {
//     IAccessible *pIAccessible;
//     auto hResult = m_pILegacyIAccessibleProvider->GetIAccessible(&pIAccessible);

//     HandleResult(info, hResult);

//     return IAccessibleWrapper::New(info.Env(), pIAccessible);
// }

Napi::Value ILegacyIAccessibleProviderWrapper::GetSelection(const Napi::CallbackInfo &info)
{
    // todo: Verify this functions correctly.  Most likely it does not.

    CComSafeArray<VARIANT> selections;
    auto hResult = m_pILegacyIAccessibleProvider->GetSelection(&selections.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < selections.GetCount(); i++)
    {
        auto variant = selections.GetAt(i);

        IRawElementProviderSimple *pRawElement = static_cast<IRawElementProviderSimple *>(variant.punkVal);

        output.Set(i, IRawElementProviderSimpleWrapper::New(info.Env(), pRawElement));
    }

    return output;
}

void ILegacyIAccessibleProviderWrapper::Select(const Napi::CallbackInfo &info)
{
    long selectFlags = info[0].ToNumber().Int32Value();

    auto hResult = m_pILegacyIAccessibleProvider->Select(selectFlags);

    HandleResult(info, hResult);
}

void ILegacyIAccessibleProviderWrapper::SetValue(const Napi::CallbackInfo &info)
{
    CComBSTR value = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());

    auto hResult = m_pILegacyIAccessibleProvider->SetValue(value);

    HandleResult(info, hResult);
}