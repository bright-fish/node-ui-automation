#include "IRawElementProviderSimpleWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"


Napi::FunctionReference *IRawElementProviderSimpleWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IRawElementProviderSimpleWrapper::GetHostRawElementProvider>("hostRawElementProvider"),
        InstanceAccessor<&IRawElementProviderSimpleWrapper::GetProviderOptions>("providerOptions"),
        
        InstanceMethod<&IRawElementProviderSimpleWrapper::GetPatternProvider>("getPatternProvider"),
        InstanceMethod<&IRawElementProviderSimpleWrapper::GetPropertyValue>("getPropertyValue")
    };

    Napi::Function function = DefineClass(env, "IRawElementProviderSimple", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IRawElementProviderSimpleWrapper::New(Napi::Env env, IRawElementProviderSimple *pRawElementProviderSimple)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IRawElementProviderSimpleWrapperConstructor->New({Napi::External<IRawElementProviderSimple>::New(env, pRawElementProviderSimple)});
}

IRawElementProviderSimpleWrapper::IRawElementProviderSimpleWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IRawElementProviderSimpleWrapper>(info)
{
    m_pRawElementProviderSimple = info[0].As<Napi::External<IRawElementProviderSimple>>().Data();
}

IRawElementProviderSimpleWrapper::~IRawElementProviderSimpleWrapper()
{
    m_pRawElementProviderSimple->Release();
}

Napi::Value IRawElementProviderSimpleWrapper::GetHostRawElementProvider(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *pRawElementProviderSimple;

    auto hResult = m_pRawElementProviderSimple->get_HostRawElementProvider(&pRawElementProviderSimple);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pRawElementProviderSimple);
}

Napi::Value IRawElementProviderSimpleWrapper::GetProviderOptions(const Napi::CallbackInfo &info)
{
    ProviderOptions providerOptions;
    auto hResult = m_pRawElementProviderSimple->get_ProviderOptions(&providerOptions);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), providerOptions);
}

Napi::Value IRawElementProviderSimpleWrapper::GetPatternProvider(const Napi::CallbackInfo &info)
{
    auto patternId = static_cast<PATTERNID>(info[0].ToNumber().Int32Value());

    IUnknown *pPatternProvider;
    m_pRawElementProviderSimple->GetPatternProvider(patternId, &pPatternProvider);

    return GetPatternProviderByPatternId(info, pPatternProvider, patternId);
}

Napi::Value IRawElementProviderSimpleWrapper::GetPropertyValue(const Napi::CallbackInfo &info)
{
    auto propertyId = static_cast<PROPERTYID>(info[0].ToNumber().Int32Value());

    CComVariant variant;
    m_pRawElementProviderSimple->GetPropertyValue(propertyId, &variant);

    return FromVariant(info.Env(), variant);
}