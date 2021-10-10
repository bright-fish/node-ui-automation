#pragma once

struct PropertyChangedEvent
{
    IUIAutomationElement *pSender;
    PROPERTYID propertyId;
    VARIANT newValue;
};