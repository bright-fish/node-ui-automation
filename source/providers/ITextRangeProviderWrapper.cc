#include "ITextRangeProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
// skipping:  #include "IAccessibleWrapper.h"

Napi::FunctionReference *ITextRangeProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&ITextRangeProviderWrapper::AddToSelection>("addToSelection"),
        InstanceMethod<&ITextRangeProviderWrapper::Clone>("clone"),
        InstanceMethod<&ITextRangeProviderWrapper::Compare>("compare"),
        InstanceMethod<&ITextRangeProviderWrapper::CompareEndpoints>("compareEndpoints"),
        InstanceMethod<&ITextRangeProviderWrapper::ExpandToEnclosingUnit>("expandToEnclosingUnit"),
        InstanceMethod<&ITextRangeProviderWrapper::FindAttribute>("findAttribute"),
        InstanceMethod<&ITextRangeProviderWrapper::FindText>("findText"),
        InstanceMethod<&ITextRangeProviderWrapper::GetAttributeValue>("getAttributeValue"),
        InstanceMethod<&ITextRangeProviderWrapper::GetBoundingRectangles>("getBoundingRectangles"),
        InstanceMethod<&ITextRangeProviderWrapper::GetChildren>("getChildren"),
        InstanceMethod<&ITextRangeProviderWrapper::GetEnclosingElement>("getEnclosingElement"),
        InstanceMethod<&ITextRangeProviderWrapper::GetText>("getText"),
        InstanceMethod<&ITextRangeProviderWrapper::Move>("move"),
        InstanceMethod<&ITextRangeProviderWrapper::MoveEndpointByRange>("moveEndpointByRange"),
        InstanceMethod<&ITextRangeProviderWrapper::MoveEndpointByUnit>("moveEndpointByUnit"),
        InstanceMethod<&ITextRangeProviderWrapper::RemoveFromSelection>("removeFromSelection"),
        InstanceMethod<&ITextRangeProviderWrapper::ScrollIntoView>("scrollIntoView"),
        InstanceMethod<&ITextRangeProviderWrapper::Select>("select"),
    };

    Napi::Function function = DefineClass(env, "ITextRangeProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ITextRangeProviderWrapper::New(Napi::Env env, ITextRangeProvider *pITextRangeProvider)
{
    if (pITextRangeProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITextRangeProviderWrapperConstructor->New({Napi::External<ITextRangeProvider>::New(env, pITextRangeProvider)});
}

ITextRangeProviderWrapper::ITextRangeProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITextRangeProviderWrapper>(info)
{
    m_pITextRangeProvider = info[0].As<Napi::External<ITextRangeProvider>>().Data();
}

ITextRangeProviderWrapper::~ITextRangeProviderWrapper()
{
    m_pITextRangeProvider->Release();
}

void ITextRangeProviderWrapper::AddToSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_pITextRangeProvider->AddToSelection();

    HandleResult(info, hResult);
}

Napi::Value ITextRangeProviderWrapper::Clone(const Napi::CallbackInfo &info)
{
    ITextRangeProvider *clonedTextRangeProvider;
    auto hResult = m_pITextRangeProvider->Clone(&clonedTextRangeProvider);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), clonedTextRangeProvider);
}

Napi::Value ITextRangeProviderWrapper::Compare(const Napi::CallbackInfo &info)
{
    auto range = ObjectWrap<ITextRangeProviderWrapper>::Unwrap(info[0].ToObject());

    BOOL areEqual;
    auto hResult = m_pITextRangeProvider->Compare(range->m_pITextRangeProvider, &areEqual);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), areEqual);
}

Napi::Value ITextRangeProviderWrapper::CompareEndpoints(const Napi::CallbackInfo &info)
{
    auto endpoint = static_cast<TextPatternRangeEndpoint>(info[0].ToNumber().Int32Value());

    auto targetRange = ObjectWrap<ITextRangeProviderWrapper>::Unwrap(info[1].ToObject());

    auto targetEndpoint = static_cast<TextPatternRangeEndpoint>(info[2].ToNumber().Int32Value());

    BOOL areEqual;
    auto hResult = m_pITextRangeProvider->CompareEndpoints(endpoint, targetRange->m_pITextRangeProvider, targetEndpoint, &areEqual);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), areEqual);
}

void ITextRangeProviderWrapper::ExpandToEnclosingUnit(const Napi::CallbackInfo &info)
{
    auto textUnit = static_cast<TextUnit>(info[0].ToNumber().Int32Value());

    auto hResult = m_pITextRangeProvider->ExpandToEnclosingUnit(textUnit);

    HandleResult(info, hResult);
}

Napi::Value ITextRangeProviderWrapper::FindAttribute(const Napi::CallbackInfo &info)
{
    auto textAttributeId = static_cast<TEXTATTRIBUTEID>(info[0].ToNumber().Int32Value());
    auto variant = ToVariant(info.Env(), info[1]);
    auto backward = info[2].ToBoolean().Value();

    ITextRangeProvider *outputTextRange;
    auto hResult = m_pITextRangeProvider->FindAttribute(textAttributeId, variant, backward, &outputTextRange);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), outputTextRange);
}

Napi::Value ITextRangeProviderWrapper::FindText(const Napi::CallbackInfo &info)
{
    auto text = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());
    auto backward = info[1].ToBoolean().Value();
    auto ignoreCase = info[2].ToBoolean().Value();

    ITextRangeProvider *outputTextRange;
    auto hResult = m_pITextRangeProvider->FindText(text, backward, ignoreCase, &outputTextRange);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), outputTextRange);
}

Napi::Value ITextRangeProviderWrapper::GetAttributeValue(const Napi::CallbackInfo &info)
{
    auto attributeId = static_cast<TEXTATTRIBUTEID>(info[0].ToNumber().Int32Value());

    CComVariant variant;
    auto hResult = m_pITextRangeProvider->GetAttributeValue(attributeId, &variant);

    HandleResult(info, hResult);

    return FromVariant(info.Env(), variant);
}

Napi::Value ITextRangeProviderWrapper::GetBoundingRectangles(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> boundingRectangles;
    auto hResult = m_pITextRangeProvider->GetBoundingRectangles(&boundingRectangles.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < boundingRectangles.GetCount(); i++)
    {
        auto variant = boundingRectangles.GetAt(i);

        // todo: somehow finish this.
    }

    return output;
}

Napi::Value ITextRangeProviderWrapper::GetChildren(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> children;
    auto hResult = m_pITextRangeProvider->GetChildren(&children.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < children.GetCount(); i++)
    {
        auto variant = children.GetAt(i);

        auto selectedElement = static_cast<IRawElementProviderSimple *>(variant.punkVal);

        output.Set(i, IRawElementProviderSimpleWrapper::New(info.Env(), selectedElement));
    }

    return output;
}

Napi::Value ITextRangeProviderWrapper::GetEnclosingElement(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *enclosingElement;
    auto hResult = m_pITextRangeProvider->GetEnclosingElement(&enclosingElement);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), enclosingElement);
}

Napi::Value ITextRangeProviderWrapper::GetText(const Napi::CallbackInfo &info)
{
    long maxLength = info[0].ToNumber().Int32Value();

    CComBSTR text;
    auto hResult = m_pITextRangeProvider->GetText(maxLength, &text);

    HandleResult(info, hResult);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(text));
}

Napi::Value ITextRangeProviderWrapper::Move(const Napi::CallbackInfo &info)
{
    auto textUnit = static_cast<TextUnit>(info[0].ToNumber().Int32Value());
    auto count = info[1].ToNumber().Int32Value();

    int output;

    auto hResult = m_pITextRangeProvider->Move(textUnit, count, &output);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), output);
}

void ITextRangeProviderWrapper::MoveEndpointByRange(const Napi::CallbackInfo &info)
{
    TextPatternRangeEndpoint endpoint = static_cast<TextPatternRangeEndpoint>(info[0].ToNumber().Int32Value());
    auto textRange = ITextRangeProviderWrapper::Unwrap(info[1].ToObject());
    TextPatternRangeEndpoint targetEndpoint = static_cast<TextPatternRangeEndpoint>(info[2].ToNumber().Int32Value());

    auto hResult = m_pITextRangeProvider->MoveEndpointByRange(endpoint, textRange->m_pITextRangeProvider, targetEndpoint);

    HandleResult(info, hResult);
}

Napi::Value ITextRangeProviderWrapper::MoveEndpointByUnit(const Napi::CallbackInfo &info)
{
    TextPatternRangeEndpoint endpoint = static_cast<TextPatternRangeEndpoint>(info[0].ToNumber().Int32Value());
    auto textUnit = static_cast<TextUnit>(info[1].ToNumber().Int32Value());
    auto count = info[2].ToNumber().Int32Value();

    int output;
    auto hResult = m_pITextRangeProvider->MoveEndpointByUnit(endpoint, textUnit, count, &output);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), output);
}

void ITextRangeProviderWrapper::RemoveFromSelection(const Napi::CallbackInfo &info)
{
    auto hResult = m_pITextRangeProvider->RemoveFromSelection();

    HandleResult(info, hResult);
}

void ITextRangeProviderWrapper::ScrollIntoView(const Napi::CallbackInfo &info)
{
    auto alignToTop = info[0].ToBoolean().Value();

    auto hResult = m_pITextRangeProvider->ScrollIntoView(alignToTop);

    HandleResult(info, hResult);
}

void ITextRangeProviderWrapper::Select(const Napi::CallbackInfo &info)
{
    auto hResult = m_pITextRangeProvider->Select();

    HandleResult(info, hResult);
}