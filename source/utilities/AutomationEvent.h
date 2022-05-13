#pragma once

#include "../Shared.h"
#include "../utilities/ComAutoPointer.h"

struct AutomationEvent
{
    ComAutoPointer<IUIAutomationElement> pSender = NULL;
    EVENTID eventID;
};
