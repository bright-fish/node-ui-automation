#include "../Shared.h"

class PropertyChangedEventHandler : public IUIAutomationPropertyChangedEventHandler
{
private:
    LONG _refCount;
    Napi::ThreadSafeFunction m_threadSafeFunction;

public:
    PropertyChangedEventHandler(Napi::ThreadSafeFunction threadSafeFunction);
    ~PropertyChangedEventHandler();

    ULONG STDMETHODCALLTYPE AddRef();
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
    ULONG STDMETHODCALLTYPE Release();

    HRESULT HandlePropertyChangedEvent(IUIAutomationElement *sender, PROPERTYID propertyId, VARIANT newValue);
};