#include "IUIAutomationTextRangeWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
// skipping:  #include "IAccessibleWrapper.h"

Napi::FunctionReference *IUIAutomationTextRangeWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationTextRangeWrapper::AddToSelection>("addToSelection"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::Clone>("clone"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::Compare>("compare"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::CompareEndpoints>("compareEndpoints"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::ExpandToEnclosingUnit>("expandToEnclosingUnit"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::FindAttribute>("findAttribute"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::FindText>("findText"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::GetAttributeValue>("getAttributeValue"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::GetBoundingRectangles>("getBoundingRectangles"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::GetChildren>("getChildren"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::GetEnclosingElement>("getEnclosingElement"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::GetText>("getText"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::Move>("move"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::MoveEndpointByRange>("moveEndpointByRange"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::MoveEndpointByUnit>("moveEndpointByUnit"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::RemoveFromSelection>("removeFromSelection"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::ScrollIntoView>("scrollIntoView"),
        InstanceMethod<&IUIAutomationTextRangeWrapper::Select>("select"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTextRange", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTextRangeWrapper::New(Napi::Env env, IUIAutomationTextRange *pTextRange)
{
    if (pTextRange == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTextRangePatternWrapperConstructor->New({Napi::External<IUIAutomationTextRange>::New(env, pTextRange)});
}

IUIAutomationTextRangeWrapper::IUIAutomationTextRangeWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTextRangeWrapper>(info)
{
    m_textRange = info[0].As<Napi::External<IUIAutomationTextRange>>().Data();
}

IUIAutomationTextRangeWrapper::~IUIAutomationTextRangeWrapper()
{
    m_textRange->Release();
}

void IUIAutomationTextRangeWrapper::AddToSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_textRange->AddToSelection();

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationTextRangeWrapper::Clone(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationTextRange> clonedTextRangeProvider;
    auto hResult = m_textRange->Clone(&clonedTextRangeProvider);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), clonedTextRangeProvider);
}

Napi::Value IUIAutomationTextRangeWrapper::Compare(const Napi::CallbackInfo &info)
{
    auto range = ObjectWrap<IUIAutomationTextRangeWrapper>::Unwrap(info[0].ToObject());

    BOOL areEqual;
    auto hResult = m_textRange->Compare(range->m_textRange, &areEqual);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), areEqual);
}

Napi::Value IUIAutomationTextRangeWrapper::CompareEndpoints(const Napi::CallbackInfo &info)
{
    auto endpoint = static_cast<TextPatternRangeEndpoint>(info[0].ToNumber().Int32Value());

    auto targetRange = ObjectWrap<IUIAutomationTextRangeWrapper>::Unwrap(info[1].ToObject());

    auto targetEndpoint = static_cast<TextPatternRangeEndpoint>(info[2].ToNumber().Int32Value());

    BOOL areEqual;
    auto hResult = m_textRange->CompareEndpoints(endpoint, targetRange->m_textRange, targetEndpoint, &areEqual);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), areEqual);
}

void IUIAutomationTextRangeWrapper::ExpandToEnclosingUnit(const Napi::CallbackInfo &info)
{
    auto textUnit = static_cast<TextUnit>(info[0].ToNumber().Int32Value());

    auto hResult = m_textRange->ExpandToEnclosingUnit(textUnit);

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationTextRangeWrapper::FindAttribute(const Napi::CallbackInfo &info)
{
    auto textAttributeId = static_cast<TEXTATTRIBUTEID>(info[0].ToNumber().Int32Value());
    auto variant = ToVariant(info.Env(), info[1]);
    auto backward = info[2].ToBoolean().Value();

    ATL::CComPtr<IUIAutomationTextRange> outputTextRange;
    auto hResult = m_textRange->FindAttribute(textAttributeId, variant, backward, &outputTextRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), outputTextRange);
}

Napi::Value IUIAutomationTextRangeWrapper::FindText(const Napi::CallbackInfo &info)
{
    auto text = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());
    auto backward = info[1].ToBoolean().Value();
    auto ignoreCase = info[2].ToBoolean().Value();

    ATL::CComPtr<IUIAutomationTextRange> outputTextRange;
    auto hResult = m_textRange->FindText(text, backward, ignoreCase, &outputTextRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), outputTextRange);
}

Napi::Value IUIAutomationTextRangeWrapper::GetAttributeValue(const Napi::CallbackInfo &info)
{
    auto attributeId = static_cast<TEXTATTRIBUTEID>(info[0].ToNumber().Int32Value());

    CComVariant variant;
    auto hResult = m_textRange->GetAttributeValue(attributeId, &variant);

    HandleResult(info, hResult);

    return FromVariant(info.Env(), variant);
}

Napi::Value IUIAutomationTextRangeWrapper::GetBoundingRectangles(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> boundingRectangles;
    auto hResult = m_textRange->GetBoundingRectangles(&boundingRectangles.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < boundingRectangles.GetCount(); i++)
    {
        auto variant = boundingRectangles.GetAt(i);

        // todo: somehow finish this.
    }

    return output;
}

Napi::Value IUIAutomationTextRangeWrapper::GetChildren(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElementArray> children;

    auto hResult = m_textRange->GetChildren(&children);

    HandleResult(info, hResult);

    int length = 0;

    hResult = children->get_Length(&length);

    auto output = Napi::Array::New(info.Env());

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;

        auto variant = children->GetElement(i, &element);

        output.Set(i, IUIAutomationElementWrapper::New(info.Env(), element));
    }

    return output;
}

Napi::Value IUIAutomationTextRangeWrapper::GetEnclosingElement(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> enclosingElement;
    auto hResult = m_textRange->GetEnclosingElement(&enclosingElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), enclosingElement);
}

Napi::Value IUIAutomationTextRangeWrapper::GetText(const Napi::CallbackInfo &info)
{
    long maxLength = info[0].ToNumber().Int32Value();

    CComBSTR text;
    auto hResult = m_textRange->GetText(maxLength, &text);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(text));
}

Napi::Value IUIAutomationTextRangeWrapper::Move(const Napi::CallbackInfo &info)
{
    auto textUnit = static_cast<TextUnit>(info[0].ToNumber().Int32Value());
    auto count = info[1].ToNumber().Int32Value();

    int output;

    auto hResult = m_textRange->Move(textUnit, count, &output);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), output);
}

void IUIAutomationTextRangeWrapper::MoveEndpointByRange(const Napi::CallbackInfo &info)
{
    TextPatternRangeEndpoint endpoint = static_cast<TextPatternRangeEndpoint>(info[0].ToNumber().Int32Value());
    auto textRange = IUIAutomationTextRangeWrapper::Unwrap(info[1].ToObject());
    TextPatternRangeEndpoint targetEndpoint = static_cast<TextPatternRangeEndpoint>(info[2].ToNumber().Int32Value());

    auto hResult = m_textRange->MoveEndpointByRange(endpoint, textRange->m_textRange, targetEndpoint);

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationTextRangeWrapper::MoveEndpointByUnit(const Napi::CallbackInfo &info)
{
    TextPatternRangeEndpoint endpoint = static_cast<TextPatternRangeEndpoint>(info[0].ToNumber().Int32Value());
    auto textUnit = static_cast<TextUnit>(info[1].ToNumber().Int32Value());
    auto count = info[2].ToNumber().Int32Value();

    int output;
    auto hResult = m_textRange->MoveEndpointByUnit(endpoint, textUnit, count, &output);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), output);
}

void IUIAutomationTextRangeWrapper::RemoveFromSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_textRange->RemoveFromSelection();

    HandleResult(info, hResult);
}

void IUIAutomationTextRangeWrapper::ScrollIntoView(const Napi::CallbackInfo &info)
{
    auto alignToTop = info[0].ToBoolean().Value();

    auto hResult = m_textRange->ScrollIntoView(alignToTop);

    HandleResult(info, hResult);
}

void IUIAutomationTextRangeWrapper::Select(const Napi::CallbackInfo &info)
{
    auto hResult = m_textRange->Select();

    HandleResult(info, hResult);
}