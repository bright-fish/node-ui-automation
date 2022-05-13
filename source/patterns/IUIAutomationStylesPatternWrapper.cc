#include "IUIAutomationStylesPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationStylesPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationStylesPatternWrapper::GetCachedExtendedProperties>("cachedExtendedProperties"),
        InstanceAccessor<&IUIAutomationStylesPatternWrapper::GetCachedFillColor>("cachedFillColor"),
        InstanceAccessor<&IUIAutomationStylesPatternWrapper::GetCachedFillPatternColor>("cachedFillPatternColor"),
        InstanceAccessor<&IUIAutomationStylesPatternWrapper::GetCachedFillPatternStyle>("cachedFillPatternStyle"),
        InstanceAccessor<&IUIAutomationStylesPatternWrapper::GetCachedShape>("cachedShape"),
        InstanceAccessor<&IUIAutomationStylesPatternWrapper::GetCachedStyleId>("cachedStyleId"),
        InstanceAccessor<&IUIAutomationStylesPatternWrapper::GetCachedStyleName>("cachedStyleName"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationStylesPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationStylesPatternWrapper::New(Napi::Env env, IUIAutomationStylesPattern *pStylesPattern)
{
    if (pStylesPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationStylesPatternWrapperConstructor->New({Napi::External<IUIAutomationStylesPattern>::New(env, pStylesPattern)});
}

IUIAutomationStylesPatternWrapper::IUIAutomationStylesPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationStylesPatternWrapper>(info)
{
    m_stylesPattern = info[0].As<Napi::External<IUIAutomationStylesPattern>>().Data();
}

IUIAutomationStylesPatternWrapper::~IUIAutomationStylesPatternWrapper()
{
    m_stylesPattern.Release();
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCachedExtendedProperties(const Napi::CallbackInfo &info)
{
    BSTR extendedProperties;
    auto hResult = m_stylesPattern->get_CachedExtendedProperties(&extendedProperties);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(extendedProperties));
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCachedFillColor(const Napi::CallbackInfo &info)
{
    int fillColor;
    auto hResult = m_stylesPattern->get_CachedFillColor(&fillColor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), fillColor);
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCachedFillPatternColor(const Napi::CallbackInfo &info)
{
    int fillPatternColor;
    auto hResult = m_stylesPattern->get_CachedFillPatternColor(&fillPatternColor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), fillPatternColor);
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCachedFillPatternStyle(const Napi::CallbackInfo &info)
{
    BSTR fillPatternStyle;
    auto hResult = m_stylesPattern->get_CachedFillPatternStyle(&fillPatternStyle);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(fillPatternStyle));
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCachedShape(const Napi::CallbackInfo &info)
{
    BSTR shape;
    auto hResult = m_stylesPattern->get_CachedShape(&shape);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(shape));
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCachedStyleId(const Napi::CallbackInfo &info)
{
    int styleId;
    auto hResult = m_stylesPattern->get_CachedStyleId(&styleId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), styleId);
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCachedStyleName(const Napi::CallbackInfo &info)
{
    BSTR styleName;
    auto hResult = m_stylesPattern->get_CachedStyleName(&styleName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(styleName));
}


Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentExtendedProperties(const Napi::CallbackInfo &info)
{
    BSTR extendedProperties;
    auto hResult = m_stylesPattern->get_CurrentExtendedProperties(&extendedProperties);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(extendedProperties));
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentFillColor(const Napi::CallbackInfo &info)
{
    int fillColor;
    auto hResult = m_stylesPattern->get_CurrentFillColor(&fillColor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), fillColor);
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentFillPatternColor(const Napi::CallbackInfo &info)
{
    int fillPatternColor;
    auto hResult = m_stylesPattern->get_CurrentFillPatternColor(&fillPatternColor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), fillPatternColor);
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentFillPatternStyle(const Napi::CallbackInfo &info)
{
    BSTR fillPatternStyle;
    auto hResult = m_stylesPattern->get_CurrentFillPatternStyle(&fillPatternStyle);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(fillPatternStyle));
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentShape(const Napi::CallbackInfo &info)
{
    BSTR shape;
    auto hResult = m_stylesPattern->get_CurrentShape(&shape);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(shape));
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentStyleId(const Napi::CallbackInfo &info)
{
    int styleId;
    auto hResult = m_stylesPattern->get_CurrentStyleId(&styleId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), styleId);
}

Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentStyleName(const Napi::CallbackInfo &info)
{
    BSTR styleName;
    auto hResult = m_stylesPattern->get_CurrentStyleName(&styleName);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(styleName));
}



Napi::Value IUIAutomationStylesPatternWrapper::GetCachedExtendedPropertiesAsArray(const Napi::CallbackInfo &info)
{
    int propertyCount = 0;
    ExtendedProperty **ppExtendedProperties = NULL;

    auto hResult = m_stylesPattern->GetCachedExtendedPropertiesAsArray(ppExtendedProperties, &propertyCount);

    HandleResult(info, hResult);

    Napi::Array output;

    for (int i = 0; i < propertyCount; i++)
    {
        auto pExtendedProperty = ppExtendedProperties[i * sizeof(ExtendedProperty)];

        Napi::Object extendedProperty;
        extendedProperty.Set("propertyName", Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(pExtendedProperty->PropertyName)));
        extendedProperty.Set("propertyValue", Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(pExtendedProperty->PropertyValue)));

        output.Set(i, extendedProperty);
    }

    return output;}


Napi::Value IUIAutomationStylesPatternWrapper::GetCurrentExtendedPropertiesAsArray(const Napi::CallbackInfo &info)
{
    int propertyCount = 0;
    ExtendedProperty **ppExtendedProperties = NULL;

    auto hResult = m_stylesPattern->GetCurrentExtendedPropertiesAsArray(ppExtendedProperties, &propertyCount);

    HandleResult(info, hResult);

    Napi::Array output;

    for (int i = 0; i < propertyCount; i++)
    {
        auto pExtendedProperty = ppExtendedProperties[i * sizeof(ExtendedProperty)];

        Napi::Object extendedProperty;
        extendedProperty.Set("propertyName", Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(pExtendedProperty->PropertyName)));
        extendedProperty.Set("propertyValue", Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(pExtendedProperty->PropertyValue)));

        output.Set(i, extendedProperty);
    }

    return output;
}
