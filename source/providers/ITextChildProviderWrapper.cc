#include "ITextChildProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
#include "ITextRangeProviderWrapper.h"

Napi::FunctionReference *ITextChildProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ITextChildProviderWrapper::GetTextContainer>("textContainer"),
        InstanceAccessor<&ITextChildProviderWrapper::GetTextRange>("textRange"),
    };

    Napi::Function function = DefineClass(env, "ITextChildProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ITextChildProviderWrapper::New(Napi::Env env, ITextChildProvider *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITextChildProviderWrapperConstructor->New({Napi::External<ITextChildProvider>::New(env, pInvokeProvider)});
}

ITextChildProviderWrapper::ITextChildProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITextChildProviderWrapper>(info)
{
    m_pITextChildProvider = info[0].As<Napi::External<ITextChildProvider>>().Data();
}

ITextChildProviderWrapper::~ITextChildProviderWrapper()
{
    m_pITextChildProvider->Release();
}

Napi::Value ITextChildProviderWrapper::GetTextContainer(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *pTextContainer;
    auto hResult = m_pITextChildProvider->get_TextContainer(&pTextContainer);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pTextContainer);
}

Napi::Value ITextChildProviderWrapper::GetTextRange(const Napi::CallbackInfo &info)
{
    ITextRangeProvider *textRange;
    auto hResult = m_pITextChildProvider->get_TextRange(&textRange);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRange);
}