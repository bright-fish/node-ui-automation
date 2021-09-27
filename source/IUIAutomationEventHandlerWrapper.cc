// #include "IUIAutomationEventHandlerWrapper.h"

// Napi::FunctionReference *IUIAutomationEventHandlerWrapper::Initialize(Napi::Env env)
// {
//     // todo: This class needs a good deal of work.  
//     // first the class must be a COM object which means it needs to be registered.  
//     // once the object is registered it must be created with the com libraries to be useable with with the proxy I believe.  
//     // if not registration is required then that means I am doing it wrong in other projects.   

//     Napi::Function function = DefineClass(env, "IUIAutomationEventHandler", {});

//     Napi::FunctionReference *constructor = new Napi::FunctionReference();

//     *constructor = Napi::Persistent(function);

//     return constructor;
// }

// IUIAutomationEventHandlerWrapper::IUIAutomationEventHandlerWrapper() : _refCount(1)
// {
// }

// IUIAutomationEventHandlerWrapper::~IUIAutomationEventHandlerWrapper()
// {
// }

// ULONG STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::AddRef()
// {
//     return InterlockedIncrement(&_refCount);
// }

// ULONG STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::Release()
// {
//     ULONG output = InterlockedDecrement(&_refCount);

//     if (output == 0)
//     {
//         delete this;
//         return 0;
//     }

//     return output;
// }

// HRESULT STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::QueryInterface(REFIID riid, void **ppInterface)
// {
//     if (riid == __uuidof(IUnknown))
//         *ppInterface = static_cast<IUIAutomationEventHandler *>(this);
//     else if (riid == __uuidof(IUIAutomationEventHandler))
//         *ppInterface = static_cast<IUIAutomationEventHandler *>(this);
//     else
//     {
//         *ppInterface = NULL;
//         return E_NOINTERFACE;
//     }

//     this->AddRef();

//     return S_OK;
// }

// HRESULT STDMETHODCALLTYPE IUIAutomationEventHandlerWrapper::HandleAutomationEvent(IUIAutomationElement *pSender, EVENTID eventID)
// {
//     // todo: get the callback from javascript.
//     // then call the callback.
//     // what about the case where you dont want to return S_OK?

//     return S_OK;
// }
