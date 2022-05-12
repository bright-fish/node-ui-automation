#include "IUIAutomationGridItemPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationGridItemPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCachedColumn>("cachedColumn"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCachedColumnSpan>("cachedColumnSpan"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCachedContainingGrid>("cachedContainingGrid"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCachedRow>("cachedRow"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCachedRowSpan>("cachedRowSpan"),

        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCurrentColumn>("currentColumn"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCurrentColumnSpan>("currentColumnSpan"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCurrentContainingGrid>("currentContainingGrid"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCurrentRow>("currentRow"),
        InstanceAccessor<&IUIAutomationGridItemPatternWrapper::GetCurrentRowSpan>("currentRowSpan"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationGridItemPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationGridItemPatternWrapper::New(Napi::Env env, IUIAutomationGridItemPattern *pGridItemPattern)
{
    if (pGridItemPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationGridItemPatternWrapperConstructor->New({Napi::External<IUIAutomationGridItemPattern>::New(env, pGridItemPattern)});
}

IUIAutomationGridItemPatternWrapper::IUIAutomationGridItemPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationGridItemPatternWrapper>(info)
{
    m_gridItemPattern = info[0].As<Napi::External<IUIAutomationGridItemPattern>>().Data();
}

IUIAutomationGridItemPatternWrapper::~IUIAutomationGridItemPatternWrapper()
{
    m_gridItemPattern.Release();
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCachedColumn(const Napi::CallbackInfo &info)
{
    int column = 0;
    auto hResult = m_gridItemPattern->get_CachedColumn(&column);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), column);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCachedColumnSpan(const Napi::CallbackInfo &info)
{
    int columnSpan = 0;
    auto hResult = m_gridItemPattern->get_CachedColumnSpan(&columnSpan);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), columnSpan);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCachedContainingGrid(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> containingGrid = NULL;
    auto hResult = m_gridItemPattern->get_CachedContainingGrid(&containingGrid);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), containingGrid);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCachedRow(const Napi::CallbackInfo &info)
{
    int value = 0;

    auto hResult = m_gridItemPattern->get_CachedRow(&value);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), value);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCachedRowSpan(const Napi::CallbackInfo &info)
{
    int rowSpan = 0;
    auto hResult = m_gridItemPattern->get_CachedRowSpan(&rowSpan);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowSpan);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCurrentColumn(const Napi::CallbackInfo &info)
{
    int column = 0;

    auto hResult = m_gridItemPattern->get_CurrentColumn(&column);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), column);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCurrentColumnSpan(const Napi::CallbackInfo &info)
{
    int columnSpan = 0;

    auto hResult = m_gridItemPattern->get_CurrentColumnSpan(&columnSpan);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), columnSpan);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCurrentContainingGrid(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> containingGrid = NULL;

    auto hResult = m_gridItemPattern->get_CurrentContainingGrid(&containingGrid);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), containingGrid);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCurrentRow(const Napi::CallbackInfo &info)
{
    int value = 0;

    auto hResult = m_gridItemPattern->get_CurrentRow(&value);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), value);
}

Napi::Value IUIAutomationGridItemPatternWrapper::GetCurrentRowSpan(const Napi::CallbackInfo &info)
{
    int rowSpan = 0;
    
    auto hResult = m_gridItemPattern->get_CurrentRowSpan(&rowSpan);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowSpan);
}
