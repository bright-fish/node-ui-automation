#include "IUIAutomationSpreadsheetPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"


Napi::FunctionReference *IUIAutomationSpreadsheetPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationSpreadsheetPatternWrapper::GetItemByName>("getItemByName"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationSpreadsheetPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationSpreadsheetPatternWrapper::New(Napi::Env env, IUIAutomationSpreadsheetPattern *pSpreadsheetPattern)
{
    if (pSpreadsheetPattern == NULL)
    {
        return env.Null();
    }
    
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationSpreadsheetPatternWrapperConstructor->New({Napi::External<IUIAutomationSpreadsheetPattern>::New(env, pSpreadsheetPattern)});
}

IUIAutomationSpreadsheetPatternWrapper::IUIAutomationSpreadsheetPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationSpreadsheetPatternWrapper>(info)
{
    m_spreadsheetPattern = info[0].As<Napi::External<IUIAutomationSpreadsheetPattern>>().Data();
}

IUIAutomationSpreadsheetPatternWrapper::~IUIAutomationSpreadsheetPatternWrapper()
{
    m_spreadsheetPattern.Release();
}

Napi::Value IUIAutomationSpreadsheetPatternWrapper::GetItemByName(const Napi::CallbackInfo &info)
{
    CComBSTR name = _com_util::ConvertStringToBSTR(info[0].ToString().Utf8Value().c_str());

    ATL::CComPtr<IUIAutomationElement> pItem;
    
    auto hResult = m_spreadsheetPattern->GetItemByName(name, &pItem);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pItem);
}
