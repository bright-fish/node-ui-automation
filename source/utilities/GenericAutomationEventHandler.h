#include "../Shared.h"

class GenericAutomationEventHandler : public IUIAutomationEventHandler
{
private:
    LONG _refCount;

public:
    GenericAutomationEventHandler();
    ~GenericAutomationEventHandler();
    
    ULONG STDMETHODCALLTYPE AddRef();
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
    ULONG STDMETHODCALLTYPE Release();
    HRESULT STDMETHODCALLTYPE HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID);
};
