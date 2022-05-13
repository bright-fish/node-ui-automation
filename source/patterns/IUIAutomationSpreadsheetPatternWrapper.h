#pragma once
#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

class IUIAutomationSpreadsheetPatternWrapper : public Napi::ObjectWrap<IUIAutomationSpreadsheetPatternWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationSpreadsheetPattern *pSpreadsheetPattern);

    IUIAutomationSpreadsheetPatternWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationSpreadsheetPatternWrapper();

    Napi::Value GetItemByName(const Napi::CallbackInfo &info);
private:
    ComAutoPointer<IUIAutomationSpreadsheetPattern> m_spreadsheetPattern = NULL;
};
