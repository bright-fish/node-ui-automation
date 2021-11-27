#include "IStylesProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IStylesProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IStylesProviderWrapper::GetExtendedProperties>("extendedProperties"),
        InstanceAccessor<&IStylesProviderWrapper::GetFillColor>("fillColor"),
        InstanceAccessor<&IStylesProviderWrapper::GetFillPatternColor>("fillPatternColor"),
        InstanceAccessor<&IStylesProviderWrapper::GetFillPatternStyle>("fillPatternStyle"),
        InstanceAccessor<&IStylesProviderWrapper::GetShape>("shape"),
        InstanceAccessor<&IStylesProviderWrapper::GetStyleId>("styleId"),
        InstanceAccessor<&IStylesProviderWrapper::GetStyleName>("styleName"),
    };

    Napi::Function function = DefineClass(env, "IStylesProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IStylesProviderWrapper::New(Napi::Env env, IStylesProvider *pIStylesProvider)
{
    if (pIStylesProvider == NULL)
    {
        return env.Null();
    }
    
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IStylesProviderWrapperConstructor->New({Napi::External<IStylesProvider>::New(env, pIStylesProvider)});
}

IStylesProviderWrapper::IStylesProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IStylesProviderWrapper>(info)
{
    m_pIStylesProvider = info[0].As<Napi::External<IStylesProvider>>().Data();
}

IStylesProviderWrapper::~IStylesProviderWrapper()
{
    m_pIStylesProvider->Release();
}

Napi::Value IStylesProviderWrapper::GetExtendedProperties(const Napi::CallbackInfo &info)
{
    CComBSTR extendedProperties;
    auto hResult = m_pIStylesProvider->get_ExtendedProperties(&extendedProperties);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(extendedProperties));
}

Napi::Value IStylesProviderWrapper::GetFillColor(const Napi::CallbackInfo &info)
{
    int fillColor;
    auto hResult = m_pIStylesProvider->get_FillColor(&fillColor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), fillColor);
}

Napi::Value IStylesProviderWrapper::GetFillPatternColor(const Napi::CallbackInfo &info)
{
    int fillPatternColor;
    auto hResult = m_pIStylesProvider->get_FillPatternColor(&fillPatternColor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), fillPatternColor);
}

Napi::Value IStylesProviderWrapper::GetFillPatternStyle(const Napi::CallbackInfo &info)
{
    BSTR fillPatternStyle;
    auto hResult = m_pIStylesProvider->get_FillPatternStyle(&fillPatternStyle);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(fillPatternStyle));
}

Napi::Value IStylesProviderWrapper::GetShape(const Napi::CallbackInfo &info)
{
    BSTR shape;
    auto hResult = m_pIStylesProvider->get_Shape(&shape);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(shape));
}

Napi::Value IStylesProviderWrapper::GetStyleId(const Napi::CallbackInfo &info)
{
    int styleId;
    auto hResult = m_pIStylesProvider->get_StyleId(&styleId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), styleId);
}

Napi::Value IStylesProviderWrapper::GetStyleName(const Napi::CallbackInfo &info)
{
    CComBSTR styleName;
    auto hResult = m_pIStylesProvider->get_StyleName(&styleName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(styleName));
}