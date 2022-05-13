#include "IUIAutomationTextPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "IUIAutomationTextRangeWrapper.h"
#include "../utilities/ComAutoPointer.h"


Napi::FunctionReference *IUIAutomationTextPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTextPatternWrapper::GetDocumentRange>("documentRange"),
        InstanceAccessor<&IUIAutomationTextPatternWrapper::GetSupportedTextSelection>("supportedTextSelection"),

        InstanceMethod<&IUIAutomationTextPatternWrapper::GetSelection>("getSelection"),
        InstanceMethod<&IUIAutomationTextPatternWrapper::GetVisibleRanges>("getVisibleRanges"),
        InstanceMethod<&IUIAutomationTextPatternWrapper::RangeFromChild>("rangeFromChild"),
        InstanceMethod<&IUIAutomationTextPatternWrapper::RangeFromPoint>("rangeFromPoint"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTextPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTextPatternWrapper::New(Napi::Env env, IUIAutomationTextPattern *pTextPattern)
{
    if (pTextPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTextPatternWrapperConstructor->New({Napi::External<IUIAutomationTextPattern>::New(env, pTextPattern)});
}

IUIAutomationTextPatternWrapper::IUIAutomationTextPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTextPatternWrapper>(info)
{
    m_textPattern = info[0].As<Napi::External<IUIAutomationTextPattern>>().Data();
}

IUIAutomationTextPatternWrapper::~IUIAutomationTextPatternWrapper()
{
    m_textPattern.Release();
}

Napi::Value IUIAutomationTextPatternWrapper::GetDocumentRange(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationTextRange> textRange = NULL;
    auto hResult = m_textPattern->get_DocumentRange(&textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextPatternWrapper::GetSupportedTextSelection(const Napi::CallbackInfo &info)
{
    SupportedTextSelection supportedTextSelection;

    auto hResult = m_textPattern->get_SupportedTextSelection(&supportedTextSelection);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), supportedTextSelection);
}

Napi::Value IUIAutomationTextPatternWrapper::GetSelection(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationTextRangeArray> textRangeArray = NULL;

    auto hResult = m_textPattern->GetSelection(&textRangeArray);

    HandleResult(info, hResult);

    int length = 0;

    hResult = textRangeArray->get_Length(&length);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (long i = 0; i < length; i++)
    {
        ComAutoPointer<IUIAutomationTextRange> textRange = NULL;
        hResult = textRangeArray->GetElement(i, &textRange);

        auto columnHeaderItemWrapper = IUIAutomationTextRangeWrapper::New(info.Env(), textRange);

        output.Set(i, columnHeaderItemWrapper);
    }

    return output;
}

Napi::Value IUIAutomationTextPatternWrapper::GetVisibleRanges(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationTextRangeArray> textRangeArray = NULL;

    auto hResult = m_textPattern->GetVisibleRanges(&textRangeArray);

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

Napi::Value IUIAutomationTextPatternWrapper::RangeFromChild(const Napi::CallbackInfo &info)
{
    auto child = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    ComAutoPointer<IUIAutomationTextRange> textRange = NULL;

    auto hResult = m_textPattern->RangeFromChild(child->m_pElement, &textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}

Napi::Value IUIAutomationTextPatternWrapper::RangeFromPoint(const Napi::CallbackInfo &info)
{
    auto input = info[0].ToObject();

    POINT point;
    point.x = input.Get("x").ToNumber().Int32Value();
    point.y = input.Get("y").ToNumber().Int32Value();

    ComAutoPointer<IUIAutomationTextRange> textRange = NULL;

    auto hResult = m_textPattern->RangeFromPoint(point, &textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}
