#include "ISpreadsheetProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"

Napi::FunctionReference *ISpreadsheetProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&ISpreadsheetProviderWrapper::GetItemByName>("getItemByName"),
    };

    Napi::Function function = DefineClass(env, "ISpreadsheetProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ISpreadsheetProviderWrapper::New(Napi::Env env, ISpreadsheetProvider *pISpreadsheetProvider)
{
    if (pISpreadsheetProvider == NULL)
    {
        return env.Null();
    }
    
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ISpreadsheetProviderWrapperConstructor->New({Napi::External<ISpreadsheetProvider>::New(env, pISpreadsheetProvider)});
}

ISpreadsheetProviderWrapper::ISpreadsheetProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ISpreadsheetProviderWrapper>(info)
{
    m_pISpreadsheetProvider = info[0].As<Napi::External<ISpreadsheetProvider>>().Data();
}

ISpreadsheetProviderWrapper::~ISpreadsheetProviderWrapper()
{
    m_pISpreadsheetProvider->Release();
}

Napi::Value ISpreadsheetProviderWrapper::GetItemByName(const Napi::CallbackInfo &info)
{
    CComBSTR name = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());

    IRawElementProviderSimple *pItem = NULL;
    auto hResult = m_pISpreadsheetProvider->GetItemByName(name, &pItem);

    HandleResult(info, hResult);

    return IRawElementProviderSimpleWrapper::New(info.Env(), pItem);
}
