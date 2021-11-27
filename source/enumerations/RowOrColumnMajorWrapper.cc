#include "RowOrColumnMajorWrapper.h"

Napi::Object RowOrColumnMajorWrapper::New(Napi::Env env)
{
    auto rowOrColumnMajor = Napi::Object::New(env);

    rowOrColumnMajor.Set("RowMajor", Napi::Number::New(env, RowOrColumnMajor::RowOrColumnMajor_RowMajor));
    rowOrColumnMajor.Set("ColumnMajor", Napi::Number::New(env, RowOrColumnMajor::RowOrColumnMajor_ColumnMajor));
    rowOrColumnMajor.Set("Indeterminate", Napi::Number::New(env, RowOrColumnMajor::RowOrColumnMajor_Indeterminate));

    return rowOrColumnMajor;
}
