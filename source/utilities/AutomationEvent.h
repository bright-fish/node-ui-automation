#pragma once

#include "../Shared.h"

struct AutomationEvent
{
    ATL::CComPtr<IUIAutomationElement> pSender = NULL;
    EVENTID eventID;
};
