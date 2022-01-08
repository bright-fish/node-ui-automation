#include "IUIAutomationTextPattern2Wrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "IUIAutomationTextRangeWrapper.h"

Napi::FunctionReference *IUIAutomationTextPattern2Wrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTextPattern2Wrapper::GetDocumentRange>("documentRange"),
        InstanceAccessor<&IUIAutomationTextPattern2Wrapper::GetSupportedTextSelection>("supportedTextSelection"),

        InstanceMethod<&IUIAutomationTextPattern2Wrapper::GetSelection>("getSelection"),
        InstanceMethod<&IUIAutomationTextPattern2Wrapper::GetVisibleRanges>("getVisibleRanges"),
        InstanceMethod<&IUIAutomationTextPattern2Wrapper::RangeFromChild>("rangeFromChild"),
        InstanceMethod<&IUIAutomationTextPattern2Wrapper::RangeFromPoint>("rangeFromPoint"),
        InstanceMethod<&IUIAutomationTextPattern2Wrapper::GetCaretRange>("getCaretRange"),
        InstanceMethod<&IUIAutomationTextPattern2Wrapper::RangeFromAnnotation>("rangeFromAnnotation"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTextPattern2", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTextPattern2Wrapper::New(Napi::Env env, IUIAutomationTextPattern2 *pITextProvider2)
{
    if (pITextProvider2 == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITextProvider2WrapperConstructor->New({Napi::External<IUIAutomationTextPattern2>::New(env, pITextProvider2)});
}

IUIAutomationTextPattern2Wrapper::IUIAutomationTextPattern2Wrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTextPattern2Wrapper>(info)
{
    m_pITextProvider2 = info[0].As<Napi::External<IUIAutomationTextPattern2>>().Data();
}

IUIAutomationTextPattern2Wrapper::~IUIAutomationTextPattern2Wrapper()
{
    m_pITextProvider2.Release();
}

Napi::Value IUIAutomationTextPattern2Wrapper::GetDocumentRange(const Napi::CallbackInfo &info)
{
    IUIAutomationTextRange *documentRange;
    auto hResult = m_pITextProvider2->get_DocumentRange(&documentRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), documentRange);
}

Napi::Value IUIAutomationTextPattern2Wrapper::GetSupportedTextSelection(const Napi::CallbackInfo &info)
{
    SupportedTextSelection supportedTextSelection;

    auto hResult = m_pITextProvider2->get_SupportedTextSelection(&supportedTextSelection);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), supportedTextSelection);
}

Napi::Value IUIAutomationTextPattern2Wrapper::GetSelection(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationTextRangeArray> textRangeArray;

    auto hResult = m_pITextProvider2->GetSelection(&textRangeArray);

    HandleResult(info, hResult);

    int length = 0;

    hResult = textRangeArray->get_Length(&length);

    HandleResult(info, hResult);

    Napi::Array output;

    for (int i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationTextRange> textRange;
        hResult = textRangeArray->GetElement(i, &textRange);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationTextRangeWrapper::New(info.Env(), textRange));
    }

    return output;
}

Napi::Value IUIAutomationTextPattern2Wrapper::GetVisibleRanges(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationTextRangeArray> textRangeArray;

    auto hResult = m_pITextProvider2->GetVisibleRanges(&textRangeArray);

    HandleResult(info, hResult);

    int length = 0;

    hResult = textRangeArray->get_Length(&length);

    HandleResult(info, hResult);

    Napi::Array output;

    for (int i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationTextRange> textRange;
        hResult = textRangeArray->GetElement(i, &textRange);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationTextRangeWrapper::New(info.Env(), textRange));
    }

    return output;
}

Napi::Value IUIAutomationTextPattern2Wrapper::RangeFromChild(const Napi::CallbackInfo &info)
{
    auto child = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    ATL::CComPtr<IUIAutomationTextRange> textRange;

    auto hResult = m_pITextProvider2->RangeFromChild(child->m_pElement, &textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextPattern2Wrapper::RangeFromPoint(const Napi::CallbackInfo &info)
{
    auto input = info[0].ToObject();

    POINT point;
    point.x = input.Get("x").ToNumber().Int32Value();
    point.y = input.Get("y").ToNumber().Int32Value();

    ATL::CComPtr<IUIAutomationTextRange> textRange;

    auto hResult = m_pITextProvider2->RangeFromPoint(point, &textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextPattern2Wrapper::GetCaretRange(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationTextRange> textRange;
    BOOL isActive;

    auto hResult = m_pITextProvider2->GetCaretRange(&isActive, &textRange);

    HandleResult(info, hResult);
    auto output = Napi::Object::New(info.Env());

    output.Set("isActive", Napi::Boolean::New(info.Env(), isActive));
    output.Set("value", IUIAutomationTextRangeWrapper::New(info.Env(), textRange));

    return output;
}

Napi::Value IUIAutomationTextPattern2Wrapper::RangeFromAnnotation(const Napi::CallbackInfo &info)
{
    auto annotationElement = IUIAutomationElementWrapper::Unwrap(info[0].ToObject());

    CComPtr<IUIAutomationTextRange> textRangeProvider;
    auto hResult = m_pITextProvider2->RangeFromAnnotation(annotationElement->m_pElement, &textRangeProvider);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRangeProvider);
}
