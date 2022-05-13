#pragma once

#include "../utilities/ComAutoPointer.h"

struct PropertyChangedEvent
{
    ComAutoPointer<IUIAutomationElement> pSender = NULL;
    PROPERTYID propertyId;
    VARIANT newValue;
};