#include "IGridProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IGridProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IGridProviderWrapper::GetColumnCount>("columnCount"),
        InstanceAccessor<&IGridProviderWrapper::GetRowCount>("rowCount"),
        InstanceMethod<&IGridProviderWrapper::GetItem>("getItem"),
    };

    Napi::Function function = DefineClass(env, "IGridProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IGridProviderWrapper::New(Napi::Env env, IGridProvider *pIGridProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IGridProviderWrapperConstructor->New({Napi::External<IGridProvider>::New(env, pIGridProvider)});
}

IGridProviderWrapper::IGridProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IGridProviderWrapper>(info)
{
    m_pGridProvider = info[0].As<Napi::External<IGridProvider>>().Data();
}

IGridProviderWrapper::~IGridProviderWrapper()
{
    m_pGridProvider->Release();
}

Napi::Value IGridProviderWrapper::GetColumnCount(const Napi::CallbackInfo &info)
{
    int columnCount;
    auto hResult = m_pGridProvider->get_ColumnCount(&columnCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), columnCount);
}

Napi::Value IGridProviderWrapper::GetRowCount(const Napi::CallbackInfo &info)
{
    int rowCount;
    auto hResult = m_pGridProvider->get_RowCount(&rowCount);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowCount);
}

Napi::Value IGridProviderWrapper::GetItem(const Napi::CallbackInfo &info)
{
    auto row = info[0].ToNumber().Uint32Value();
    
    auto column = info[1].ToNumber().Uint32Value();

    IRawElementProviderSimple *pRawElementProviderSimple;
    auto hResult = m_pGridProvider->GetItem(row, column, &pRawElementProviderSimple);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pRawElementProviderSimple);
}
