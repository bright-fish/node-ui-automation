#include "IUIAutomationTextEditPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "IUIAutomationTextRangeWrapper.h"
#include "../utilities/ComAutoPointer.h"

Napi::FunctionReference *IUIAutomationTextEditPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTextEditPatternWrapper::GetDocumentRange>("documentRange"),
        InstanceAccessor<&IUIAutomationTextEditPatternWrapper::GetSupportedTextSelection>("supportedTextSelection"),

        InstanceMethod<&IUIAutomationTextEditPatternWrapper::GetSelection>("getSelection"),
        InstanceMethod<&IUIAutomationTextEditPatternWrapper::GetVisibleRanges>("getVisibleRanges"),
        InstanceMethod<&IUIAutomationTextEditPatternWrapper::RangeFromChild>("rangeFromChild"),
        InstanceMethod<&IUIAutomationTextEditPatternWrapper::RangeFromPoint>("rangeFromPoint"),
        InstanceMethod<&IUIAutomationTextEditPatternWrapper::GetActiveComposition>("getActiveComposition"),
        InstanceMethod<&IUIAutomationTextEditPatternWrapper::GetConversionTarget>("getConversionTarget"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTextEditPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTextEditPatternWrapper::New(Napi::Env env, IUIAutomationTextEditPattern *pITextEditProvider)
{
    if (pITextEditProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTextEditPatternWrapperConstructor->New({Napi::External<IUIAutomationTextEditPattern>::New(env, pITextEditProvider)});
}

IUIAutomationTextEditPatternWrapper::IUIAutomationTextEditPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTextEditPatternWrapper>(info)
{
    m_textEditPattern = info[0].As<Napi::External<IUIAutomationTextEditPattern>>().Data();
}

IUIAutomationTextEditPatternWrapper::~IUIAutomationTextEditPatternWrapper()
{
    m_textEditPattern.Release();
}

Napi::Value IUIAutomationTextEditPatternWrapper::GetDocumentRange(const Napi::CallbackInfo &info)
{
    IUIAutomationTextRange *textRange;
    auto hResult = m_textEditPattern->get_DocumentRange(&textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextEditPatternWrapper::GetSupportedTextSelection(const Napi::CallbackInfo &info)
{
    SupportedTextSelection supportedTextSelection;
    auto hResult = m_textEditPattern->get_SupportedTextSelection(&supportedTextSelection);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), supportedTextSelection);
}

Napi::Value IUIAutomationTextEditPatternWrapper::GetSelection(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationTextRangeArray> textRangeArray = NULL;

    auto hResult = m_textEditPattern->GetSelection(&textRangeArray);

    HandleResult(info, hResult);

    int length = 0;

    hResult = textRangeArray->get_Length(&length);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (int i = 0; i < length; i++)
    {
        ComAutoPointer<IUIAutomationTextRange> textRange = NULL;
        hResult = textRangeArray->GetElement(i, &textRange);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationTextRangeWrapper::New(info.Env(), textRange));
    }

    return output;
}

Napi::Value IUIAutomationTextEditPatternWrapper::GetVisibleRanges(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationTextRangeArray> textRangeArray = NULL;

    auto hResult = m_textEditPattern->GetVisibleRanges(&textRangeArray);

    HandleResult(info, hResult);

    int length = 0;

    hResult = textRangeArray->get_Length(&length);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (int i = 0; i < length; i++)
    {
        ComAutoPointer<IUIAutomationTextRange> textRange = NULL;
        hResult = textRangeArray->GetElement(i, &textRange);

        HandleResult(info, hResult);

        output.Set(i, IUIAutomationTextRangeWrapper::New(info.Env(), textRange));
    }

    return output;
}

Napi::Value IUIAutomationTextEditPatternWrapper::RangeFromChild(const Napi::CallbackInfo &info)
{
    auto child = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    ComAutoPointer<IUIAutomationTextRange> textRange = NULL;

    auto hResult = m_textEditPattern->RangeFromChild(child->m_pElement, &textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextEditPatternWrapper::RangeFromPoint(const Napi::CallbackInfo &info)
{
    auto input = info[0].ToObject();

    POINT point;
    point.x = input.Get("x").ToNumber().Int32Value();
    point.y = input.Get("y").ToNumber().Int32Value();

    ComAutoPointer<IUIAutomationTextRange> textRange = NULL;

    auto hResult = m_textEditPattern->RangeFromPoint(point, &textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextEditPatternWrapper::GetActiveComposition(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationTextRange> textRange = NULL;
    auto hResult = m_textEditPattern->GetActiveComposition(&textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextEditPatternWrapper::GetConversionTarget(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationTextRange> textRange = NULL;
    auto hResult = m_textEditPattern->GetConversionTarget(&textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}