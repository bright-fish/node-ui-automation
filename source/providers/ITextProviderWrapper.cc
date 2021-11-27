#include "ITextProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
#include "ITextRangeProviderWrapper.h"

Napi::FunctionReference *ITextProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ITextProviderWrapper::GetDocumentRange>("documentRange"),
        InstanceAccessor<&ITextProviderWrapper::GetSupportedTextSelection>("supportedTextSelection"),

        InstanceMethod<&ITextProviderWrapper::GetSelection>("getSelection"),
        InstanceMethod<&ITextProviderWrapper::GetVisibleRanges>("getVisibleRanges"),
        InstanceMethod<&ITextProviderWrapper::RangeFromChild>("rangeFromChild"),
        InstanceMethod<&ITextProviderWrapper::RangeFromPoint>("rangeFromPoint"),
    };

    Napi::Function function = DefineClass(env, "ITextProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ITextProviderWrapper::New(Napi::Env env, ITextProvider *pITextProvider)
{
    if (pITextProvider == NULL)
    {
        return env.Null();
    }
    
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITextProviderWrapperConstructor->New({Napi::External<ITextProvider>::New(env, pITextProvider)});
}

ITextProviderWrapper::ITextProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITextProviderWrapper>(info)
{
    m_pITextProvider = info[0].As<Napi::External<ITextProvider>>().Data();
}

ITextProviderWrapper::~ITextProviderWrapper()
{
    m_pITextProvider->Release();
}

Napi::Value ITextProviderWrapper::GetDocumentRange(const Napi::CallbackInfo &info)
{
    ITextRangeProvider *rowOrColumnMajor;
    auto hResult = m_pITextProvider->get_DocumentRange(&rowOrColumnMajor);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), rowOrColumnMajor);
}

Napi::Value ITextProviderWrapper::GetSupportedTextSelection(const Napi::CallbackInfo &info)
{
    SupportedTextSelection supportedTextSelection;

    auto hResult = m_pITextProvider->get_SupportedTextSelection(&supportedTextSelection);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), supportedTextSelection);
}

Napi::Value ITextProviderWrapper::GetSelection(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> columnHeaderItems;

    auto hResult = m_pITextProvider->GetSelection(&columnHeaderItems.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < columnHeaderItems.GetCount(); i++)
    {
        auto variant = columnHeaderItems.GetAt(i);

        auto columnHeaderItem = static_cast<ITextRangeProvider *>(variant.punkVal);

        auto columnHeaderItemWrapper = ITextRangeProviderWrapper::New(info.Env(), columnHeaderItem);

        output.Set(i, columnHeaderItemWrapper);
    }

    return output;
}

Napi::Value ITextProviderWrapper::GetVisibleRanges(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> visibleRanges;

    auto hResult = m_pITextProvider->GetVisibleRanges(&visibleRanges.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < visibleRanges.GetCount(); i++)
    {
        auto variant = visibleRanges.GetAt(i);

        auto visibleTextRange = static_cast<ITextRangeProvider *>(variant.punkVal);

        auto visibleTextRangeWrapper = ITextRangeProviderWrapper::New(info.Env(), visibleTextRange);

        output.Set(i, visibleTextRangeWrapper);
    }

    return output;
}

Napi::Value ITextProviderWrapper::RangeFromChild(const Napi::CallbackInfo &info)
{
    auto childElement = IRawElementProviderSimpleWrapper::Unwrap(info[0].ToObject());

    ITextRangeProvider *textRangeProvider;
    auto hResult = m_pITextProvider->RangeFromChild(childElement->m_pRawElementProviderSimple, &textRangeProvider);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRangeProvider);
}

Napi::Value ITextProviderWrapper::RangeFromPoint(const Napi::CallbackInfo &info)
{
    auto point = info[0].ToObject();

    UiaPoint uiaPoint;
    uiaPoint.x = point.Get("x").ToNumber();
    uiaPoint.y = point.Get("y").ToNumber();

    ITextRangeProvider *textRangeProvider;
    auto hResult = m_pITextProvider->RangeFromPoint(uiaPoint, &textRangeProvider);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRangeProvider);
}
