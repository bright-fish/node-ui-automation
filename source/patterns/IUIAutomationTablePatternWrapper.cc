#include "IUIAutomationTablePatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"

Napi::FunctionReference *IUIAutomationTablePatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTablePatternWrapper::GetCachedRowOrColumnMajor>("cachedRowOrColumnMajor"),
        InstanceAccessor<&IUIAutomationTablePatternWrapper::GetCurrentRowOrColumnMajor>("currentRowOrColumnMajor"),

        InstanceMethod<&IUIAutomationTablePatternWrapper::GetCachedColumnHeaders>("getCachedColumnHeaders"),
        InstanceMethod<&IUIAutomationTablePatternWrapper::GetCachedRowHeaders>("getCachedRowHeaders"),
        InstanceMethod<&IUIAutomationTablePatternWrapper::GetCurrentColumnHeaders>("getCurrentColumnHeaders"),
        InstanceMethod<&IUIAutomationTablePatternWrapper::GetCurrentRowHeaders>("getCurrentRowHeaders"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTablePattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTablePatternWrapper::New(Napi::Env env, IUIAutomationTablePattern *pTablePattern)
{
    if (pTablePattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTablePatternWrapperConstructor->New({Napi::External<IUIAutomationTablePattern>::New(env, pTablePattern)});
}

IUIAutomationTablePatternWrapper::IUIAutomationTablePatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTablePatternWrapper>(info)
{
    m_tablePattern = info[0].As<Napi::External<IUIAutomationTablePattern>>().Data();
}

IUIAutomationTablePatternWrapper::~IUIAutomationTablePatternWrapper()
{
    m_tablePattern.Release();
}

Napi::Value IUIAutomationTablePatternWrapper::GetCachedRowOrColumnMajor(const Napi::CallbackInfo &info)
{
    RowOrColumnMajor rowOrColumnMajor;
    auto hResult = m_tablePattern->get_CachedRowOrColumnMajor(&rowOrColumnMajor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowOrColumnMajor);
}

Napi::Value IUIAutomationTablePatternWrapper::GetCurrentRowOrColumnMajor(const Napi::CallbackInfo &info)
{
    RowOrColumnMajor rowOrColumnMajor;
    auto hResult = m_tablePattern->get_CurrentRowOrColumnMajor(&rowOrColumnMajor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowOrColumnMajor);
}

Napi::Value IUIAutomationTablePatternWrapper::GetCachedColumnHeaders(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElementArray> columnHeaderItems;

    auto hResult = m_tablePattern->GetCachedColumnHeaders(&columnHeaderItems);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());
    int length = 0;

    hResult = columnHeaderItems->get_Length(&length);

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;
        hResult = columnHeaderItems->GetElement(i, &element);

        auto columnHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, columnHeaderItemWrapper);
    }

    return output;
}

Napi::Value IUIAutomationTablePatternWrapper::GetCachedRowHeaders(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElementArray> rowHeaderItems;

    auto hResult = m_tablePattern->GetCachedRowHeaders(&rowHeaderItems);

    HandleResult(info, hResult);

    int length = 0;

    hResult = rowHeaderItems->get_Length(&length);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;

        auto variant = rowHeaderItems->GetElement(i, &element);

        auto rowHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, rowHeaderItemWrapper);
    }

    return output;
}

Napi::Value IUIAutomationTablePatternWrapper::GetCurrentColumnHeaders(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElementArray> columnHeaderItems;

    auto hResult = m_tablePattern->GetCurrentColumnHeaders(&columnHeaderItems);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());
    int length = 0;

    hResult = columnHeaderItems->get_Length(&length);

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;
        hResult = columnHeaderItems->GetElement(i, &element);

        auto columnHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, columnHeaderItemWrapper);
    }

    return output;
}

Napi::Value IUIAutomationTablePatternWrapper::GetCurrentRowHeaders(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElementArray> rowHeaderItems;

    auto hResult = m_tablePattern->GetCurrentRowHeaders(&rowHeaderItems);

    HandleResult(info, hResult);

    int length = 0;

    hResult = rowHeaderItems->get_Length(&length);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (long i = 0; i < length; i++)
    {
        ATL::CComPtr<IUIAutomationElement> element;

        auto variant = rowHeaderItems->GetElement(i, &element);

        auto rowHeaderItemWrapper = IUIAutomationElementWrapper::New(info.Env(), element);

        output.Set(i, rowHeaderItemWrapper);
    }

    return output;
}
