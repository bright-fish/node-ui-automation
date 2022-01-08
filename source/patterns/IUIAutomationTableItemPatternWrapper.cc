#include "IUIAutomationTableItemPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationTableItemPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationTableItemPatternWrapper::GetCachedColumnHeaderItems>("getCachedColumnHeaderItems"),
        InstanceMethod<&IUIAutomationTableItemPatternWrapper::GetCachedRowHeaderItems>("getCachedRowHeaderItems"),
        InstanceMethod<&IUIAutomationTableItemPatternWrapper::GetCurrentColumnHeaderItems>("getCurrentColumnHeaderItems"),
        InstanceMethod<&IUIAutomationTableItemPatternWrapper::GetCurrentRowHeaderItems>("getCurrentRowHeaderItems"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTableItemPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTableItemPatternWrapper::New(Napi::Env env, IUIAutomationTableItemPattern *pTableItemPattern)
{
    if (pTableItemPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTableItemPatternWrapperConstructor->New({Napi::External<IUIAutomationTableItemPattern>::New(env, pTableItemPattern)});
}

IUIAutomationTableItemPatternWrapper::IUIAutomationTableItemPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTableItemPatternWrapper>(info)
{
    m_tableItemPattern = info[0].As<Napi::External<IUIAutomationTableItemPattern>>().Data();
}

IUIAutomationTableItemPatternWrapper::~IUIAutomationTableItemPatternWrapper()
{
    m_tableItemPattern.Release();
}

Napi::Value IUIAutomationTableItemPatternWrapper::GetCachedColumnHeaderItems(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElementArray> columnHeaderItems;

    auto hResult = m_tableItemPattern->GetCachedColumnHeaderItems(&columnHeaderItems);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = columnHeaderItems->get_Length(&length);

    HandleResult(info, hResult);

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;
        auto variant = columnHeaderItems->GetElement(i, &element);

        auto columnHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, columnHeaderItemWrapper);
    }

    return output;
}

Napi::Value IUIAutomationTableItemPatternWrapper::GetCachedRowHeaderItems(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElementArray> rowHeaderItems;

    auto hResult = m_tableItemPattern->GetCachedRowHeaderItems(&rowHeaderItems);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = rowHeaderItems->get_Length(&length);

    HandleResult(info, hResult);

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;
        auto variant = rowHeaderItems->GetElement(i, &element);

        auto rowHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, rowHeaderItemWrapper);
    }

    return output;
}

Napi::Value IUIAutomationTableItemPatternWrapper::GetCurrentColumnHeaderItems(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElementArray> columnHeaderItems;

    auto hResult = m_tableItemPattern->GetCurrentColumnHeaderItems(&columnHeaderItems);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = columnHeaderItems->get_Length(&length);

    HandleResult(info, hResult);

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;
        auto variant = columnHeaderItems->GetElement(i, &element);

        auto columnHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, columnHeaderItemWrapper);
    }

    return output;
}

Napi::Value IUIAutomationTableItemPatternWrapper::GetCurrentRowHeaderItems(const Napi::CallbackInfo &info)
{
    CComPtr<IUIAutomationElementArray> rowHeaderItems;

    auto hResult = m_tableItemPattern->GetCurrentRowHeaderItems(&rowHeaderItems);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    int length = 0;

    hResult = rowHeaderItems->get_Length(&length);

    HandleResult(info, hResult);

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;
        auto variant = rowHeaderItems->GetElement(i, &element);

        auto rowHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, rowHeaderItemWrapper);
    }

    return output;
}
