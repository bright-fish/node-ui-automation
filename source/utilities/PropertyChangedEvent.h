#pragma once

struct PropertyChangedEvent
{
    ATL::CComPtr<IUIAutomationElement> pSender;
    PROPERTYID propertyId;
    VARIANT newValue;
};