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
        variant.vt = VT_I4;
        variant.iVal = local.ToNumber().Int32Value();
    }
    else if (local.IsString())
    {
        auto value = local.ToString();

        variant.vt = VT_BSTR;
        variant.bstrVal = _com_util::ConvertStringToBSTR(value.Utf8Value().c_str());
    }
    else if (local.IsBoolean())
    {
        variant.vt = VT_BOOL;
        variant.boolVal = local.ToBoolean();
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