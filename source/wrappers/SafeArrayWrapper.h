#include "../Shared.h"

class SafeArrayWrapper
{
public:
    SAFEARRAY *m_pSafeArray = NULL;

    Napi::Object GetElement(Napi::CallbackInfo &info);
    Napi::Object PutElement(Napi::CallbackInfo &info);
    void Destroy();
};