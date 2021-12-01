#include "ITextEditProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
#include "ITextRangeProviderWrapper.h"

Napi::FunctionReference *ITextEditProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&ITextEditProviderWrapper::GetActiveComposition>("getActiveComposition"),
        InstanceMethod<&ITextEditProviderWrapper::GetConversionTarget>("getConversionTarget"),
    };

    Napi::Function function = DefineClass(env, "ITextEditProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ITextEditProviderWrapper::New(Napi::Env env, ITextEditProvider *pITextEditProvider)
{
    if (pITextEditProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITextEditProviderWrapperConstructor->New({Napi::External<ITextEditProvider>::New(env, pITextEditProvider)});
}

ITextEditProviderWrapper::ITextEditProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITextEditProviderWrapper>(info)
{
    m_pITextEditProvider = info[0].As<Napi::External<ITextEditProvider>>().Data();
}

ITextEditProviderWrapper::~ITextEditProviderWrapper()
{
    m_pITextEditProvider->Release();
}

Napi::Value ITextEditProviderWrapper::GetActiveComposition(const Napi::CallbackInfo &info)
{
    ITextRangeProvider *textRange;
    auto hResult = m_pITextEditProvider->GetActiveComposition(&textRange);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRange);
}

Napi::Value ITextEditProviderWrapper::GetConversionTarget(const Napi::CallbackInfo &info)
{
    ITextRangeProvider *textRange;
    auto hResult = m_pITextEditProvider->GetConversionTarget(&textRange);

    HandleResult(info, hResult);

    return ITextRangeProviderWrapper::New(info.Env(), textRange);
}