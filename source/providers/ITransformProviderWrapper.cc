#include "ITransformProviderWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
#include "ITextRangeProviderWrapper.h"

Napi::FunctionReference *ITransformProviderWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ITransformProviderWrapper::GetCanMove>("canMove"),
        InstanceAccessor<&ITransformProviderWrapper::GetCanResize>("canResize"),
        InstanceAccessor<&ITransformProviderWrapper::GetCanRotate>("canRotate"),

        InstanceMethod<&ITransformProviderWrapper::Move>("move"),
        InstanceMethod<&ITransformProviderWrapper::Resize>("resize"),
        InstanceMethod<&ITransformProviderWrapper::Rotate>("rotate"),
    };

    Napi::Function function = DefineClass(env, "ITransformProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value ITransformProviderWrapper::New(Napi::Env env, ITransformProvider *pITransformProvider)
{
    if (pITransformProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITransformProviderWrapperConstructor->New({Napi::External<ITransformProvider>::New(env, pITransformProvider)});
}

ITransformProviderWrapper::ITransformProviderWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITransformProviderWrapper>(info)
{
    m_pITransformProvider = info[0].As<Napi::External<ITransformProvider>>().Data();
}

ITransformProviderWrapper::~ITransformProviderWrapper()
{
    m_pITransformProvider->Release();
}

Napi::Value ITransformProviderWrapper::GetCanMove(const Napi::CallbackInfo &info)
{
    BOOL canMove;
    auto hResult = m_pITransformProvider->get_CanMove(&canMove);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMove);
}

Napi::Value ITransformProviderWrapper::GetCanResize(const Napi::CallbackInfo &info)
{
    BOOL canResize;

    auto hResult = m_pITransformProvider->get_CanResize(&canResize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canResize);
}

Napi::Value ITransformProviderWrapper::GetCanRotate(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_pITransformProvider->get_CanRotate(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}

void ITransformProviderWrapper::Move(const Napi::CallbackInfo &info)
{
    auto x = info[0].ToNumber();
    auto y = info[1].ToNumber();

    auto hResult = m_pITransformProvider->Move(x, y);

    HandleResult(info, hResult);
}

void ITransformProviderWrapper::Resize(const Napi::CallbackInfo &info)
{
    auto width = info[0].ToNumber();
    auto height = info[1].ToNumber();

    auto hResult = m_pITransformProvider->Resize(width, height);

    HandleResult(info, hResult);
}

void ITransformProviderWrapper::Rotate(const Napi::CallbackInfo &info)
{
    auto degrees = info[0].ToNumber();

    auto hResult = m_pITransformProvider->Rotate(degrees);

    HandleResult(info, hResult);
}
