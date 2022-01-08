#include "IUIAutomationRangeValuePatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationRangeValuePatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCachedIsReadOnly>("cachedIsReadOnly"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCachedLargeChange>("cachedLargeChange"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCachedMaximum>("cachedMaximum"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCachedMinimum>("cachedMinimum"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCachedSmallChange>("cachedSmallChange"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCachedValue>("cachedValue"),

        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCurrentIsReadOnly>("currentIsReadOnly"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCurrentLargeChange>("currentLargeChange"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCurrentMaximum>("currentMaximum"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCurrentMinimum>("currentMinimum"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCurrentSmallChange>("currentSmallChange"),
        InstanceAccessor<&IUIAutomationRangeValuePatternWrapper::GetCurrentValue>("currentValue"),

        InstanceMethod<&IUIAutomationRangeValuePatternWrapper::SetValue>("setValue"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationRangeValuePattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationRangeValuePatternWrapper::New(Napi::Env env, IUIAutomationRangeValuePattern *pRangeValuePattern)
{
    if (pRangeValuePattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationRangeValuePatternWrapperConstructor->New({Napi::External<IUIAutomationRangeValuePattern>::New(env, pRangeValuePattern)});
}

IUIAutomationRangeValuePatternWrapper::IUIAutomationRangeValuePatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationRangeValuePatternWrapper>(info)
{
    m_rangeValuePattern = info[0].As<Napi::External<IUIAutomationRangeValuePattern>>().Data();
}

IUIAutomationRangeValuePatternWrapper::~IUIAutomationRangeValuePatternWrapper()
{
    m_rangeValuePattern.Release();
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCachedIsReadOnly(const Napi::CallbackInfo &info)
{
    BOOL isReadOnly;
    auto hResult = m_rangeValuePattern->get_CachedIsReadOnly(&isReadOnly);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isReadOnly);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCachedLargeChange(const Napi::CallbackInfo &info)
{
    double largeChange;
    auto hResult = m_rangeValuePattern->get_CachedLargeChange(&largeChange);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), largeChange);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCachedMaximum(const Napi::CallbackInfo &info)
{
    double maximum;
    auto hResult = m_rangeValuePattern->get_CachedMaximum(&maximum);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), maximum);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCachedMinimum(const Napi::CallbackInfo &info)
{
    double minimum;
    auto hResult = m_rangeValuePattern->get_CachedMinimum(&minimum);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), minimum);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCachedSmallChange(const Napi::CallbackInfo &info)
{
    double smallChange;
    auto hResult = m_rangeValuePattern->get_CachedSmallChange(&smallChange);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), smallChange);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCachedValue(const Napi::CallbackInfo &info)
{
    double value;
    auto hResult = m_rangeValuePattern->get_CachedValue(&value);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), value);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCurrentIsReadOnly(const Napi::CallbackInfo &info)
{
    BOOL isReadOnly;
    auto hResult = m_rangeValuePattern->get_CurrentIsReadOnly(&isReadOnly);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isReadOnly);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCurrentLargeChange(const Napi::CallbackInfo &info)
{
    double largeChange;
    auto hResult = m_rangeValuePattern->get_CurrentLargeChange(&largeChange);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), largeChange);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCurrentMaximum(const Napi::CallbackInfo &info)
{
    double maximum;
    auto hResult = m_rangeValuePattern->get_CurrentMaximum(&maximum);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), maximum);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCurrentMinimum(const Napi::CallbackInfo &info)
{
    double minimum;
    auto hResult = m_rangeValuePattern->get_CurrentMinimum(&minimum);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), minimum);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCurrentSmallChange(const Napi::CallbackInfo &info)
{
    double smallChange;
    auto hResult = m_rangeValuePattern->get_CurrentSmallChange(&smallChange);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), smallChange);
}

Napi::Value IUIAutomationRangeValuePatternWrapper::GetCurrentValue(const Napi::CallbackInfo &info)
{
    double value;
    auto hResult = m_rangeValuePattern->get_CurrentValue(&value);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), value);
}

void IUIAutomationRangeValuePatternWrapper::SetValue(const Napi::CallbackInfo &info)
{
    auto value = info[0].ToNumber().DoubleValue();

    auto hResult = m_rangeValuePattern->SetValue(value);

    HandleResult(info, hResult);
}
