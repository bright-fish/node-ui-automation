#include "IGridItemProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *IGridItemProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IGridItemProviderWrapper::GetColumn>("column"),
        InstanceAccessor<&IGridItemProviderWrapper::GetColumnSpan>("columnSpan"),
        InstanceAccessor<&IGridItemProviderWrapper::GetContainingGrid>("containingGrid"),
        InstanceAccessor<&IGridItemProviderWrapper::GetRow>("row"),
        InstanceAccessor<&IGridItemProviderWrapper::GetRowSpan>("rowSpan"),
    };

    Napi::Function function = DefineClass(env, "IAnnotationProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IGridItemProviderWrapper::New(Napi::Env env, IGridItemProvider *pIGridItemProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IGridItemProviderWrapperConstructor->New({Napi::External<IGridItemProvider>::New(env, pIGridItemProvider)});
}

IGridItemProviderWrapper::IGridItemProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IGridItemProviderWrapper>(info)
{
    m_pIGridItemProvider = info[0].As<Napi::External<IGridItemProvider>>().Data();
}

IGridItemProviderWrapper::~IGridItemProviderWrapper()
{
    m_pIGridItemProvider->Release();
}

Napi::Value IGridItemProviderWrapper::GetColumn(const Napi::CallbackInfo &info)
{
    int column;
    auto hResult = m_pIGridItemProvider->get_Column(&column);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), column);
}

Napi::Value IGridItemProviderWrapper::GetColumnSpan(const Napi::CallbackInfo &info)
{
    int columnSpan;
    auto hResult = m_pIGridItemProvider->get_ColumnSpan(&columnSpan);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), columnSpan);
}

Napi::Value IGridItemProviderWrapper::GetContainingGrid(const Napi::CallbackInfo &info)
{
    IRawElementProviderSimple *containingGrid;
    auto hResult = m_pIGridItemProvider->get_ContainingGrid(&containingGrid);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), containingGrid);
}

Napi::Value IGridItemProviderWrapper::GetRow(const Napi::CallbackInfo &info)
{
    int row;
    auto hResult = m_pIGridItemProvider->get_Row(&row);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), row);
}

Napi::Value IGridItemProviderWrapper::GetRowSpan(const Napi::CallbackInfo &info)
{
    int rowSpan;
    auto hResult = m_pIGridItemProvider->get_RowSpan(&rowSpan);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), rowSpan);
}