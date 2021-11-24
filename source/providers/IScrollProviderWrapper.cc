#include "IScrollProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IScrollProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IScrollProviderWrapper::GetHorizontallyScrollable>("horizontallyScrollable"),
        InstanceAccessor<&IScrollProviderWrapper::GetHorizontalScrollPercent>("horizontalScrollPercent"),
        InstanceAccessor<&IScrollProviderWrapper::GetHorizontalViewSize>("horizontalViewSize"),
        InstanceAccessor<&IScrollProviderWrapper::GetVerticallyScrollable>("verticallyScrollable"),
        InstanceAccessor<&IScrollProviderWrapper::GetVerticalScrollPercent>("verticalScrollPercent"),
        InstanceAccessor<&IScrollProviderWrapper::GetVerticalViewSize>("verticalViewSize"),

        InstanceMethod<&IScrollProviderWrapper::Scroll>("scroll"),
        InstanceMethod<&IScrollProviderWrapper::SetScrollPercent>("setScrollPercent"),
    };

    Napi::Function function = DefineClass(env, "IScrollProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IScrollProviderWrapper::New(Napi::Env env, IScrollProvider *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IScrollProviderWrapperConstructor->New({Napi::External<IScrollProvider>::New(env, pInvokeProvider)});
}

IScrollProviderWrapper::IScrollProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IScrollProviderWrapper>(info)
{
    m_pIScrollProvider = info[0].As<Napi::External<IScrollProvider>>().Data();
}

IScrollProviderWrapper::~IScrollProviderWrapper()
{
    m_pIScrollProvider->Release();
}

Napi::Value IScrollProviderWrapper::GetHorizontallyScrollable(const Napi::CallbackInfo &info)
{
    BOOL horizontallyScrollable;
    auto hResult = m_pIScrollProvider->get_HorizontallyScrollable(&horizontallyScrollable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), horizontallyScrollable);
}

Napi::Value IScrollProviderWrapper::GetHorizontalScrollPercent(const Napi::CallbackInfo &info)
{
    double horizontalScrollPercent;
    auto hResult = m_pIScrollProvider->get_HorizontalScrollPercent(&horizontalScrollPercent);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), horizontalScrollPercent);
}

Napi::Value IScrollProviderWrapper::GetHorizontalViewSize(const Napi::CallbackInfo &info)
{
    double horizontalViewSize;
    auto hResult = m_pIScrollProvider->get_HorizontalViewSize(&horizontalViewSize);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), horizontalViewSize);
}

Napi::Value IScrollProviderWrapper::GetVerticallyScrollable(const Napi::CallbackInfo &info)
{
    BOOL verticallyScrollable;
    auto hResult = m_pIScrollProvider->get_VerticallyScrollable(&verticallyScrollable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), verticallyScrollable);
}

Napi::Value IScrollProviderWrapper::GetVerticalScrollPercent(const Napi::CallbackInfo &info)
{
    double verticalScrollPercent;
    auto hResult = m_pIScrollProvider->get_VerticalScrollPercent(&verticalScrollPercent);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), verticalScrollPercent);
}

Napi::Value IScrollProviderWrapper::GetVerticalViewSize(const Napi::CallbackInfo &info)
{
    double verticalViewSize;
    auto hResult = m_pIScrollProvider->get_VerticalViewSize(&verticalViewSize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), verticalViewSize);
}

void IScrollProviderWrapper::Scroll(const Napi::CallbackInfo &info)
{
    auto horizontalAmount = static_cast<ScrollAmount>(info[0].ToNumber().Int32Value());
    auto verticalAmount = static_cast<ScrollAmount>(info[1].ToNumber().Int32Value());

    auto hResult = m_pIScrollProvider->Scroll(horizontalAmount, verticalAmount);

    HandleResult(info, hResult);
}

void IScrollProviderWrapper::SetScrollPercent(const Napi::CallbackInfo &info)
{
    auto horizontalAmount = info[0].ToNumber().DoubleValue();
    auto verticalAmount = info[1].ToNumber().DoubleValue();

    auto hResult = m_pIScrollProvider->SetScrollPercent(horizontalAmount, verticalAmount);

    HandleResult(info, hResult);
}