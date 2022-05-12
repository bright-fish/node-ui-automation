#pragma once

struct PropertyChangedEvent
{
    ATL::CComPtr<IUIAutomationElement> pSender = NULL;
    PROPERTYID propertyId;
    VARIANT newValue;
};