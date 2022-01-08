#include "IUIAutomationValuePatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationValuePatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationValuePatternWrapper::GetCachedIsReadOnly>("cachedIsReadOnly"),
        InstanceAccessor<&IUIAutomationValuePatternWrapper::GetCachedValue>("cachedValue"),
        InstanceAccessor<&IUIAutomationValuePatternWrapper::GetCurrentIsReadOnly>("currentIsReadOnly"),
        InstanceAccessor<&IUIAutomationValuePatternWrapper::GetCurrentValue>("currentValue"),

        InstanceMethod<&IUIAutomationValuePatternWrapper::SetValue>("setValue"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationValuePattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationValuePatternWrapper::New(Napi::Env env, IUIAutomationValuePattern *pValuePattern)
{
    if (pValuePattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationValuePatternWrapperConstructor->New({Napi::External<IUIAutomationValuePattern>::New(env, pValuePattern)});
}

IUIAutomationValuePatternWrapper::IUIAutomationValuePatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationValuePatternWrapper>(info)
{
    m_pIValueProvider = info[0].As<Napi::External<IUIAutomationValuePattern>>().Data();
}

IUIAutomationValuePatternWrapper::~IUIAutomationValuePatternWrapper()
{
    m_pIValueProvider.Release();
}

Napi::Value IUIAutomationValuePatternWrapper::GetCachedIsReadOnly(const Napi::CallbackInfo &info)
{
    BOOL isReadOnly;
    auto hResult = m_pIValueProvider->get_CachedIsReadOnly(&isReadOnly);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isReadOnly);
}

Napi::Value IUIAutomationValuePatternWrapper::GetCachedValue(const Napi::CallbackInfo &info)
{
    BSTR value;
    auto hResult = m_pIValueProvider->get_CachedValue(&value);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(value));
}


Napi::Value IUIAutomationValuePatternWrapper::GetCurrentIsReadOnly(const Napi::CallbackInfo &info)
{
    BOOL isReadOnly;
    auto hResult = m_pIValueProvider->get_CurrentIsReadOnly(&isReadOnly);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isReadOnly);
}

Napi::Value IUIAutomationValuePatternWrapper::GetCurrentValue(const Napi::CallbackInfo &info)
{
    BSTR value;
    auto hResult = m_pIValueProvider->get_CurrentValue(&value);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(value));
}


void IUIAutomationValuePatternWrapper::SetValue(const Napi::CallbackInfo &info)
{
    BSTR value = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());

    auto hResult = m_pIValueProvider->SetValue(value);

    HandleResult(info, hResult);
}
