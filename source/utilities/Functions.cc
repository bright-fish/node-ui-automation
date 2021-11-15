#include "Functions.h"
#include "../Shared.h" 

void HandleResult(const Napi::CallbackInfo &info, HRESULT hResult)
{
    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(info.Env(), error.ErrorMessage());
    }
}

VARIANT ToVariant(Napi::Env env, Napi::Value local)
{
    VARIANT variant;

    if (local.IsUndefined())
    {
        variant.vt = VT_EMPTY;
    }
    else if (local.IsNull())
    {
        variant.vt = VT_EMPTY;
    }
    else if (local.IsNumber())
    {
        variant = ATL::CComVariant(local.ToNumber().Int32Value());
    }
    else if (local.IsString())
    {
        variant = ATL::CComVariant(_com_util::ConvertStringToBSTR(local.ToString().Utf8Value().c_str()));
    }
    else if (local.IsBoolean())
    {
        variant = ATL::CComVariant(local.ToBoolean());
    }
    else
    {
        throw Napi::Error::New(env, "Unsupported variant data type.");
    }

    return variant;
}

Napi::Value FromVariant(Napi::Env env, VARIANT variant)
{
    switch (variant.vt)
    {
    case VT_I4:
        return Napi::Number::New(env, variant.iVal);
    case VT_EMPTY:
        return env.Null();
    case VT_BSTR:
        return Napi::String::New(env, _com_util::ConvertBSTRToString(variant.bstrVal));
    default:
        throw std::domain_error("Unsupported variant type.");
    }
}