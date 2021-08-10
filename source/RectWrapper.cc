#include "RectWrapper.h"

Nan::Persistent<v8::Function> RectWrapper::constructor;

NAN_MODULE_INIT(RectWrapper::Init)
{
    auto isolate = target->GetIsolate();

    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("RECT").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();

    instanceTemplate->SetInternalFieldCount(1);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

void RectWrapper::GetProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto rectRaw = info.Holder()->GetInternalField(0).As<v8::External>()->Value();
    auto rect = static_cast<RECT *>(rectRaw);

    Nan::Utf8String utf8PropertyName(property);
    std::string sPropertyName(*utf8PropertyName);

    if (sPropertyName == "bottom")
    {
        info.GetReturnValue()
            .Set(v8::Int32::New(isolate, (int)rect->bottom));

        return;
    }
    else if (sPropertyName == "left")
    {
        info.GetReturnValue()
            .Set(v8::Int32::New(isolate, (int)rect->left));

        return;
    }
    else if (sPropertyName == "right")
    {
        info.GetReturnValue()
            .Set(v8::Int32::New(isolate, (int)rect->right));

        return;
    }
    else if (sPropertyName == "top")
    {
        info.GetReturnValue()
            .Set(v8::Int32::New(isolate, (int)rect->top));

        return;
    }
    else
    {
        throw std::exception("Not Implemented. ");
    }
}

v8::Local<v8::Value> RectWrapper::NewInstance(v8::Isolate *isolate, RECT *boundingRectangle)
{
    if (!boundingRectangle)
    {
        return v8::Null(isolate);
    }
    
    auto context = isolate->GetCurrentContext();

    v8::Local<v8::Function> constructorFunction = v8::Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    instance->Set(context, v8::String::NewFromUtf8(isolate, "bottom").ToLocalChecked(), v8::Int32::New(isolate, boundingRectangle->bottom));
    instance->Set(context, v8::String::NewFromUtf8(isolate, "left").ToLocalChecked(), v8::Int32::New(isolate, boundingRectangle->left));
    instance->Set(context, v8::String::NewFromUtf8(isolate, "right").ToLocalChecked(), v8::Int32::New(isolate, boundingRectangle->right));
    instance->Set(context, v8::String::NewFromUtf8(isolate, "top").ToLocalChecked(), v8::Int32::New(isolate, boundingRectangle->top));

    instance->SetInternalField(0, v8::External::New(isolate, boundingRectangle));

    return instance;
}
