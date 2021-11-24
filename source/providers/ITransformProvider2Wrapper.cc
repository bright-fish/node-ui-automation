#include "ITransformProvider2Wrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "IRawElementProviderSimpleWrapper.h"
#include "ITextRangeProviderWrapper.h"

Napi::FunctionReference *ITransformProvider2Wrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&ITransformProvider2Wrapper::GetCanMove>("canMove"),
        InstanceAccessor<&ITransformProvider2Wrapper::GetCanResize>("canResize"),
        InstanceAccessor<&ITransformProvider2Wrapper::GetCanRotate>("canRotate"),
        InstanceAccessor<&ITransformProvider2Wrapper::GetCanZoom>("canZoom"),
        InstanceAccessor<&ITransformProvider2Wrapper::GetZoomLevel>("zoomLevel"),
        InstanceAccessor<&ITransformProvider2Wrapper::GetZoomMaximum>("zoomMaximum"),
        InstanceAccessor<&ITransformProvider2Wrapper::GetZoomMinimum>("zoomMinimum"),

        InstanceMethod<&ITransformProvider2Wrapper::Move>("move"),
        InstanceMethod<&ITransformProvider2Wrapper::Resize>("resize"),
        InstanceMethod<&ITransformProvider2Wrapper::Rotate>("rotate"),
        InstanceMethod<&ITransformProvider2Wrapper::Zoom>("zoom"),
        InstanceMethod<&ITransformProvider2Wrapper::ZoomByUnit>("zoomByUnit"),

    };

    Napi::Function function = DefineClass(env, "ITransformProvider2", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object ITransformProvider2Wrapper::New(Napi::Env env, ITransformProvider2 *pInvokeProvider)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITransformProvider2WrapperConstructor->New({Napi::External<ITransformProvider2>::New(env, pInvokeProvider)});
}

ITransformProvider2Wrapper::ITransformProvider2Wrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<ITransformProvider2Wrapper>(info)
{
    m_pITransformProvider2 = info[0].As<Napi::External<ITransformProvider2>>().Data();
}

ITransformProvider2Wrapper::~ITransformProvider2Wrapper()
{
    m_pITransformProvider2->Release();
}

Napi::Value ITransformProvider2Wrapper::GetCanMove(const Napi::CallbackInfo &info)
{
    BOOL canMove;
    auto hResult = m_pITransformProvider2->get_CanMove(&canMove);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMove);
}

Napi::Value ITransformProvider2Wrapper::GetCanResize(const Napi::CallbackInfo &info)
{
    BOOL canResize;

    auto hResult = m_pITransformProvider2->get_CanResize(&canResize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canResize);
}

Napi::Value ITransformProvider2Wrapper::GetCanRotate(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_pITransformProvider2->get_CanRotate(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}

Napi::Value ITransformProvider2Wrapper::GetCanZoom(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_pITransformProvider2->get_CanZoom(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}

Napi::Value ITransformProvider2Wrapper::GetZoomLevel(const Napi::CallbackInfo &info)
{
    double zoomLevel;

    auto hResult = m_pITransformProvider2->get_ZoomLevel(&zoomLevel);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomLevel);
}

Napi::Value ITransformProvider2Wrapper::GetZoomMaximum(const Napi::CallbackInfo &info)
{
    double zoomMaximum;

    auto hResult = m_pITransformProvider2->get_ZoomMaximum(&zoomMaximum);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomMaximum);
}

Napi::Value ITransformProvider2Wrapper::GetZoomMinimum(const Napi::CallbackInfo &info)
{
    double zoomMinimum;

    auto hResult = m_pITransformProvider2->get_ZoomMinimum(&zoomMinimum);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomMinimum);
}


void ITransformProvider2Wrapper::Move(const Napi::CallbackInfo &info)
{
    auto x = info[0].ToNumber();
    auto y = info[1].ToNumber();

    auto hResult = m_pITransformProvider2->Move(x, y);

    HandleResult(info, hResult);
}

void ITransformProvider2Wrapper::Resize(const Napi::CallbackInfo &info)
{
    auto width = info[0].ToNumber();
    auto height = info[1].ToNumber();

    auto hResult = m_pITransformProvider2->Resize(width, height);

    HandleResult(info, hResult);
}

void ITransformProvider2Wrapper::Rotate(const Napi::CallbackInfo &info)
{
    auto degrees = info[0].ToNumber();

    auto hResult = m_pITransformProvider2->Rotate(degrees);

    HandleResult(info, hResult);
}

void ITransformProvider2Wrapper::Zoom(const Napi::CallbackInfo &info)
{
    auto zoom = info[0].ToNumber();

    auto hResult = m_pITransformProvider2->Zoom(zoom);

    HandleResult(info, hResult);
}

void ITransformProvider2Wrapper::ZoomByUnit(const Napi::CallbackInfo &info)
{
    auto zoomUnit = static_cast<ZoomUnit>(info[0].ToNumber().Int32Value());

    auto hResult = m_pITransformProvider2->ZoomByUnit(zoomUnit);

    HandleResult(info, hResult);
}
