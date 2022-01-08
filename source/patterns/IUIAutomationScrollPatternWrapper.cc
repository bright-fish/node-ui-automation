#include "IUIAutomationScrollPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"

Napi::FunctionReference *IUIAutomationScrollPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCachedHorizontallyScrollable>("cachedHorizontallyScrollable"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCachedHorizontalScrollPercent>("cachedHorizontalScrollPercent"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCachedHorizontalViewSize>("cachedHorizontalViewSize"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCachedVerticallyScrollable>("cachedVerticallyScrollable"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCachedVerticalScrollPercent>("cachedVerticalScrollPercent"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCachedVerticalViewSize>("cachedVerticalViewSize"),

        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCurrentHorizontallyScrollable>("currentHorizontallyScrollable"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCurrentHorizontalScrollPercent>("currentHorizontalScrollPercent"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCurrentHorizontalViewSize>("currentHorizontalViewSize"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCurrentVerticallyScrollable>("currentVerticallyScrollable"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCurrentVerticalScrollPercent>("currentVerticalScrollPercent"),
        InstanceAccessor<&IUIAutomationScrollPatternWrapper::GetCurrentVerticalViewSize>("currentVerticalViewSize"),

        InstanceMethod<&IUIAutomationScrollPatternWrapper::Scroll>("scroll"),
        InstanceMethod<&IUIAutomationScrollPatternWrapper::SetScrollPercent>("setScrollPercent"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationScrollPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationScrollPatternWrapper::New(Napi::Env env, IUIAutomationScrollPattern *pScrollPattern)
{
    if (pScrollPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationScrollPatternWrapperConstructor->New({Napi::External<IUIAutomationScrollPattern>::New(env, pScrollPattern)});
}

IUIAutomationScrollPatternWrapper::IUIAutomationScrollPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationScrollPatternWrapper>(info)
{
    m_scrollPattern = info[0].As<Napi::External<IUIAutomationScrollPattern>>().Data();
}

IUIAutomationScrollPatternWrapper::~IUIAutomationScrollPatternWrapper()
{
    m_scrollPattern.Release();
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCachedHorizontallyScrollable(const Napi::CallbackInfo &info)
{
    BOOL horizontallyScrollable;
    auto hResult = m_scrollPattern->get_CachedHorizontallyScrollable(&horizontallyScrollable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), horizontallyScrollable);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCachedHorizontalScrollPercent(const Napi::CallbackInfo &info)
{
    double horizontalScrollPercent;
    auto hResult = m_scrollPattern->get_CachedHorizontalScrollPercent(&horizontalScrollPercent);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), horizontalScrollPercent);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCachedHorizontalViewSize(const Napi::CallbackInfo &info)
{
    double horizontalViewSize;
    auto hResult = m_scrollPattern->get_CachedHorizontalViewSize(&horizontalViewSize);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), horizontalViewSize);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCachedVerticallyScrollable(const Napi::CallbackInfo &info)
{
    BOOL verticallyScrollable;
    auto hResult = m_scrollPattern->get_CachedVerticallyScrollable(&verticallyScrollable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), verticallyScrollable);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCachedVerticalScrollPercent(const Napi::CallbackInfo &info)
{
    double verticalScrollPercent;
    auto hResult = m_scrollPattern->get_CachedVerticalScrollPercent(&verticalScrollPercent);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), verticalScrollPercent);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCachedVerticalViewSize(const Napi::CallbackInfo &info)
{
    double verticalViewSize;
    auto hResult = m_scrollPattern->get_CachedVerticalViewSize(&verticalViewSize);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), verticalViewSize);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCurrentHorizontallyScrollable(const Napi::CallbackInfo &info)
{
    BOOL horizontallyScrollable;
    auto hResult = m_scrollPattern->get_CurrentHorizontallyScrollable(&horizontallyScrollable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), horizontallyScrollable);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCurrentHorizontalScrollPercent(const Napi::CallbackInfo &info)
{
    double horizontalScrollPercent;
    auto hResult = m_scrollPattern->get_CurrentHorizontalScrollPercent(&horizontalScrollPercent);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), horizontalScrollPercent);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCurrentHorizontalViewSize(const Napi::CallbackInfo &info)
{
    double horizontalViewSize;
    auto hResult = m_scrollPattern->get_CurrentHorizontalViewSize(&horizontalViewSize);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), horizontalViewSize);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCurrentVerticallyScrollable(const Napi::CallbackInfo &info)
{
    BOOL verticallyScrollable;
    auto hResult = m_scrollPattern->get_CurrentVerticallyScrollable(&verticallyScrollable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), verticallyScrollable);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCurrentVerticalScrollPercent(const Napi::CallbackInfo &info)
{
    double verticalScrollPercent;
    auto hResult = m_scrollPattern->get_CurrentVerticalScrollPercent(&verticalScrollPercent);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), verticalScrollPercent);
}

Napi::Value IUIAutomationScrollPatternWrapper::GetCurrentVerticalViewSize(const Napi::CallbackInfo &info)
{
    double verticalViewSize;
    auto hResult = m_scrollPattern->get_CurrentVerticalViewSize(&verticalViewSize);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), verticalViewSize);
}

void IUIAutomationScrollPatternWrapper::Scroll(const Napi::CallbackInfo &info)
{
    auto horizontalAmount = static_cast<ScrollAmount>(info[0].ToNumber().Int32Value());
    auto verticalAmount = static_cast<ScrollAmount>(info[1].ToNumber().Int32Value());

    auto hResult = m_scrollPattern->Scroll(horizontalAmount, verticalAmount);

    HandleResult(info, hResult);
}

void IUIAutomationScrollPatternWrapper::SetScrollPercent(const Napi::CallbackInfo &info)
{
    auto horizontalAmount = info[0].ToNumber().DoubleValue();
    auto verticalAmount = info[1].ToNumber().DoubleValue();

    auto hResult = m_scrollPattern->SetScrollPercent(horizontalAmount, verticalAmount);

    HandleResult(info, hResult);
}