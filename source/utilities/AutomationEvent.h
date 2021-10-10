#pragma once

#include "../Shared.h"

struct AutomationEvent
{
    IUIAutomationElement *pSender;
    EVENTID eventID;
};
