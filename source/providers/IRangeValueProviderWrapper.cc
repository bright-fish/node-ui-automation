#include "IRangeValueProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IRangeValueProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IRangeValueProviderWrapper::GetIsReadOnly>("isReadOnly"),
        InstanceAccessor<&IRangeValueProviderWrapper::GetLargeChange>("largeChange"),
        InstanceAccessor<&IRangeValueProviderWrapper::GetMaximum>("maximum"),
        InstanceAccessor<&IRangeValueProviderWrapper::GetMinimum>("minimum"),
        InstanceAccessor<&IRangeValueProviderWrapper::GetSmallChange>("smallChange"),
        InstanceAccessor<&IRangeValueProviderWrapper::GetValue>("value"),

        InstanceMethod<&IRangeValueProviderWrapper::SetValue>("setValue"),
    };

    Napi::Function function = DefineClass(env, "IRangeValueProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IRangeValueProviderWrapper::New(Napi::Env env, IRangeValueProvider *pIRangeValueProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IRangeValueProviderWrapperConstructor->New({Napi::External<IRangeValueProvider>::New(env, pIRangeValueProvider)});
}

IRangeValueProviderWrapper::IRangeValueProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IRangeValueProviderWrapper>(info)
{
    m_pIRangeValueProvider = info[0].As<Napi::External<IRangeValueProvider>>().Data();
}

IRangeValueProviderWrapper::~IRangeValueProviderWrapper()
{
    m_pIRangeValueProvider->Release();
}

Napi::Value IRangeValueProviderWrapper::GetIsReadOnly(const Napi::CallbackInfo &info)
{
    BOOL isReadOnly;
    auto hResult = m_pIRangeValueProvider->get_IsReadOnly(&isReadOnly);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isReadOnly);
}

Napi::Value IRangeValueProviderWrapper::GetLargeChange(const Napi::CallbackInfo &info)
{
    double largeChange;
    auto hResult = m_pIRangeValueProvider->get_LargeChange(&largeChange);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), largeChange);
}

Napi::Value IRangeValueProviderWrapper::GetMaximum(const Napi::CallbackInfo &info)
{
    double maximum;
    auto hResult = m_pIRangeValueProvider->get_Maximum(&maximum);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), maximum);
}

Napi::Value IRangeValueProviderWrapper::GetMinimum(const Napi::CallbackInfo &info)
{
    double minimum;
    auto hResult = m_pIRangeValueProvider->get_Minimum(&minimum);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), minimum);
}

Napi::Value IRangeValueProviderWrapper::GetSmallChange(const Napi::CallbackInfo &info)
{
    double smallChange;
    auto hResult = m_pIRangeValueProvider->get_SmallChange(&smallChange);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), smallChange);
}

Napi::Value IRangeValueProviderWrapper::GetValue(const Napi::CallbackInfo &info)
{
    double value;
    auto hResult = m_pIRangeValueProvider->get_Value(&value);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), value);
}

void IRangeValueProviderWrapper::SetValue(const Napi::CallbackInfo &info)
{
    auto value = info[0].ToNumber().DoubleValue();

    auto hResult = m_pIRangeValueProvider->SetValue(value);

    HandleResult(info, hResult);
}
