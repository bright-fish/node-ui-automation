#include "ITextProvider2Wrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
#include "ITextRangeProviderWrapper.h"

Napi::FunctionReference *ITextProvider2Wrapper::Initialize(Napi::Env env)
{

    auto classDefinition = {
        InstanceAccessor<&ITextProvider2Wrapper::GetDocumentRange>("documentRange"),
        InstanceAccessor<&ITextProvider2Wrapper::GetSupportedTextSelection>("supportedTextSelection"),

        InstanceMethod<&ITextProvider2Wrapper::GetSelection>("getSelection"),
        InstanceMethod<&ITextProvider2Wrapper::GetVisibleRanges>("getVisibleRanges"),
        InstanceMethod<&ITextProvider2Wrapper::RangeFromChild>("rangeFromChild"),
        InstanceMethod<&ITextProvider2Wrapper::RangeFromPoint>("rangeFromPoint"),
        InstanceMethod<&ITextProvider2Wrapper::GetCaretRange>("getCaretRange"),
        InstanceMethod<&ITextProvider2Wrapper::RangeFromAnnotation>("rangeFromAnnotation"),
    };

    Napi::Function function = DefineClass(env, "ITextProvider2", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ITextProvider2Wrapper::New(Napi::Env env, ITextProvider2 *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITextProvider2WrapperConstructor->New({Napi::External<ITextProvider2>::New(env, pInvokeProvider)});
}

ITextProvider2Wrapper::ITextProvider2Wrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITextProvider2Wrapper>(info)
{
    m_pITextProvider2 = info[0].As<Napi::External<ITextProvider2>>().Data();
}

ITextProvider2Wrapper::~ITextProvider2Wrapper()
{
    m_pITextProvider2->Release();
}

Napi::Value ITextProvider2Wrapper::GetDocumentRange(const Napi::CallbackInfo &info)
{
    ITextRangeProvider *rowOrColumnMajor;
    auto hResult = m_pITextProvider2->get_DocumentRange(&rowOrColumnMajor);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), rowOrColumnMajor);
}

Napi::Value ITextProvider2Wrapper::GetSupportedTextSelection(const Napi::CallbackInfo &info)
{
    SupportedTextSelection supportedTextSelection;

    auto hResult = m_pITextProvider2->get_SupportedTextSelection(&supportedTextSelection);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), supportedTextSelection);
}

Napi::Value ITextProvider2Wrapper::GetSelection(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> columnHeaderItems;

    auto hResult = m_pITextProvider2->GetSelection(&columnHeaderItems.m_psa);

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

Napi::Value ITextProvider2Wrapper::GetVisibleRanges(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> visibleRanges;

    auto hResult = m_pITextProvider2->GetVisibleRanges(&visibleRanges.m_psa);

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

Napi::Value ITextProvider2Wrapper::RangeFromChild(const Napi::CallbackInfo &info)
{
    auto childElement = IRawElementProviderSimpleWrapper::Unwrap(info[0].ToObject());

    ITextRangeProvider *textRangeProvider;
    auto hResult = m_pITextProvider2->RangeFromChild(childElement->m_pRawElementProviderSimple, &textRangeProvider);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRangeProvider);
}

Napi::Value ITextProvider2Wrapper::RangeFromPoint(const Napi::CallbackInfo &info)
{
    auto point = info[0].ToObject();

    UiaPoint uiaPoint;
    uiaPoint.x = point.Get("x").ToNumber();
    uiaPoint.y = point.Get("y").ToNumber();

    ITextRangeProvider *textRangeProvider;
    auto hResult = m_pITextProvider2->RangeFromPoint(uiaPoint, &textRangeProvider);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRangeProvider);
}

Napi::Value ITextProvider2Wrapper::GetCaretRange(const Napi::CallbackInfo &info)
{
    ITextRangeProvider *textRangeProvider;
    BOOL isActive;
    
    auto hResult = m_pITextProvider2->GetCaretRange(&isActive, &textRangeProvider);

    HandleResult(info, hResult);
    auto output = Napi::Object::New(info.Env());

    output.Set("isActive", Napi::Boolean::New(info.Env(), isActive));
    output.Set("value", ITextRangeProviderWrapper::New(info.Env(), textRangeProvider));

    return output;
}

Napi::Value ITextProvider2Wrapper::RangeFromAnnotation(const Napi::CallbackInfo &info)
{
    auto annotationElement = IRawElementProviderSimpleWrapper::Unwrap(info[0].ToObject());

    ITextRangeProvider *textRangeProvider;
    auto hResult = m_pITextProvider2->RangeFromAnnotation(annotationElement->m_pRawElementProviderSimple, &textRangeProvider);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRangeProvider);
}
