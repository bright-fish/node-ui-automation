#include "ITableItemProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *ITableItemProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&ITableItemProviderWrapper::GetColumnHeaderItems>("getColumnHeaderItems"),
        InstanceMethod<&ITableItemProviderWrapper::GetRowHeaderItems>("getRowHeaderItems"),

    };

    Napi::Function function = DefineClass(env, "ITableItemProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ITableItemProviderWrapper::New(Napi::Env env, ITableItemProvider *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITableItemProviderWrapperConstructor->New({Napi::External<ITableItemProvider>::New(env, pInvokeProvider)});
}

ITableItemProviderWrapper::ITableItemProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITableItemProviderWrapper>(info)
{
    m_pITableItemProvider = info[0].As<Napi::External<ITableItemProvider>>().Data();
}

ITableItemProviderWrapper::~ITableItemProviderWrapper()
{
    m_pITableItemProvider->Release();
}

Napi::Value ITableItemProviderWrapper::GetColumnHeaderItems(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> columnHeaderItems;

    auto hResult = m_pITableItemProvider->GetColumnHeaderItems(&columnHeaderItems.m_psa);

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

Napi::Value ITableItemProviderWrapper::GetRowHeaderItems(const Napi::CallbackInfo &info)
{
    CComSafeArray<VARIANT> rowHeaderItems;

    auto hResult = m_pITableItemProvider->GetRowHeaderItems(&rowHeaderItems.m_psa);

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