#include "ITableProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *ITableProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ITableProviderWrapper::GetRowOrColumnMajor>("rowOrColumnMajor"),
        
        InstanceMethod<&ITableProviderWrapper::GetColumnHeaders>("getColumnHeaders"),
        InstanceMethod<&ITableProviderWrapper::GetRowHeaders>("getRowHeaders"),
    };

    Napi::Function function = DefineClass(env, "ITableProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ITableProviderWrapper::New(Napi::Env env, ITableProvider *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITableProviderWrapperConstructor->New({Napi::External<ITableProvider>::New(env, pInvokeProvider)});
}

ITableProviderWrapper::ITableProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITableProviderWrapper>(info)
{
    m_pITableProvider = info[0].As<Napi::External<ITableProvider>>().Data();
}

ITableProviderWrapper::~ITableProviderWrapper()
{
    m_pITableProvider->Release();
}


Napi::Value ITableProviderWrapper::GetRowOrColumnMajor(const Napi::CallbackInfo &info)
{
    RowOrColumnMajor rowOrColumnMajor;
    auto hResult = m_pITableProvider->get_RowOrColumnMajor(&rowOrColumnMajor);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowOrColumnMajor);
}

Napi::Value ITableProviderWrapper::GetColumnHeaders(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> columnHeaderItems;

    auto hResult = m_pITableProvider->GetColumnHeaders(&columnHeaderItems.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < columnHeaderItems.GetCount(); i++)
    {
        auto variant = columnHeaderItems.GetAt(i);

        auto columnHeaderItem = static_cast<IRawElementProviderSimple *>(variant.punkVal);

        auto columnHeaderItemWrapper = IRawElementProviderSimpleWrapper::New(info.Env(), columnHeaderItem);

        output.Set(i, columnHeaderItemWrapper);
    }

    return output;
}

Napi::Value ITableProviderWrapper::GetRowHeaders(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> rowHeaderItems;

    auto hResult = m_pITableProvider->GetRowHeaders(&rowHeaderItems.m_psa);

    HandleResult(info, hResult);

    auto output = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < rowHeaderItems.GetCount(); i++)
    {
        auto variant = rowHeaderItems.GetAt(i);

        auto rowHeaderItem = static_cast<IRawElementProviderSimple *>(variant.punkVal);

        auto rowHeaderItemWrapper = IRawElementProviderSimpleWrapper::New(info.Env(), rowHeaderItem);

        output.Set(i, rowHeaderItemWrapper);
    }

    return output;
}
