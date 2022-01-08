#include "IUIAutomationGridPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationGridPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationGridPatternWrapper::GetCachedColumnCount>("cachedColumnCount"),
        InstanceAccessor<&IUIAutomationGridPatternWrapper::GetCachedRowCount>("cachedRowCount"),
        InstanceAccessor<&IUIAutomationGridPatternWrapper::GetCurrentColumnCount>("currentColumnCount"),
        InstanceAccessor<&IUIAutomationGridPatternWrapper::GetCurrentRowCount>("currentRowCount"),

        InstanceMethod<&IUIAutomationGridPatternWrapper::GetItem>("getItem"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationGridPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationGridPatternWrapper::New(Napi::Env env, IUIAutomationGridPattern *pGridPattern)
{
    if (pGridPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationGridPatternWrapperConstructor->New({Napi::External<IUIAutomationGridPattern>::New(env, pGridPattern)});
}

IUIAutomationGridPatternWrapper::IUIAutomationGridPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationGridPatternWrapper>(info)
{
    m_gridPattern = info[0].As<Napi::External<IUIAutomationGridPattern>>().Data();
}

IUIAutomationGridPatternWrapper::~IUIAutomationGridPatternWrapper()
{
    m_gridPattern.Release();
}

Napi::Value IUIAutomationGridPatternWrapper::GetCachedColumnCount(const Napi::CallbackInfo &info)
{
    int columnCount = 0;

    auto hResult = m_gridPattern->get_CachedColumnCount(&columnCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), columnCount);
}

Napi::Value IUIAutomationGridPatternWrapper::GetCachedRowCount(const Napi::CallbackInfo &info)
{
    int rowCount = 0;
    
    auto hResult = m_gridPattern->get_CachedRowCount(&rowCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowCount);
}


Napi::Value IUIAutomationGridPatternWrapper::GetCurrentColumnCount(const Napi::CallbackInfo &info)
{
    int columnCount = 0;

    auto hResult = m_gridPattern->get_CurrentColumnCount(&columnCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), columnCount);
}

Napi::Value IUIAutomationGridPatternWrapper::GetCurrentRowCount(const Napi::CallbackInfo &info)
{
    int rowCount = 0;
    
    auto hResult = m_gridPattern->get_CurrentRowCount(&rowCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowCount);
}


Napi::Value IUIAutomationGridPatternWrapper::GetItem(const Napi::CallbackInfo &info)
{
    auto row = info[0].ToNumber().Uint32Value();
    auto column = info[1].ToNumber().Uint32Value();

    ATL::CComPtr<IUIAutomationElement> item;

    auto hResult = m_gridPattern->GetItem(row, column, &item);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), item);
}
