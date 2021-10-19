#include "../Shared.h"

class StructureChangedEventHandler : public IUIAutomationStructureChangedEventHandler
{
private:
    LONG _refCount;
    Napi::ThreadSafeFunction m_threadSafeFunction;

public:
    StructureChangedEventHandler(Napi::ThreadSafeFunction threadSafeFunction);
    ~StructureChangedEventHandler();

    ULONG STDMETHODCALLTYPE AddRef();
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppInterface);
    ULONG STDMETHODCALLTYPE Release();

    HRESULT STDMETHODCALLTYPE HandleStructureChangedEvent(IUIAutomationElement *sender, StructureChangeType changeType, SAFEARRAY *runtimeId);
};