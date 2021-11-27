#include "IValueProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IValueProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IValueProviderWrapper::GetIsReadOnly>("isReadOnly"),
        InstanceAccessor<&IValueProviderWrapper::GetValue>("value"),

        InstanceMethod<&IValueProviderWrapper::SetValue>("setValue"),
    };

    Napi::Function function = DefineClass(env, "IValueProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IValueProviderWrapper::New(Napi::Env env, IValueProvider *pIValueProvider)
{
    if (pIValueProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IValueProviderWrapperConstructor->New({Napi::External<IValueProvider>::New(env, pIValueProvider)});
}

IValueProviderWrapper::IValueProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IValueProviderWrapper>(info)
{
    m_pIValueProvider = info[0].As<Napi::External<IValueProvider>>().Data();
}

IValueProviderWrapper::~IValueProviderWrapper()
{
    m_pIValueProvider->Release();
}

Napi::Value IValueProviderWrapper::GetIsReadOnly(const Napi::CallbackInfo &info)
{
    BOOL isReadOnly;
    auto hResult = m_pIValueProvider->get_IsReadOnly(&isReadOnly);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), isReadOnly);
}

Napi::Value IValueProviderWrapper::GetValue(const Napi::CallbackInfo &info)
{
    BSTR value;
    auto hResult = m_pIValueProvider->get_Value(&value);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(value));
}

void IValueProviderWrapper::SetValue(const Napi::CallbackInfo &info)
{
    BSTR value = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());

    auto hResult = m_pIValueProvider->SetValue(value);

    HandleResult(info, hResult);
}
