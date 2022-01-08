#include "IUIAutomationTransformPattern2Wrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "IUIAutomationTextRangeWrapper.h"

Napi::FunctionReference *IUIAutomationTransformPattern2Wrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCachedCanMove>("cachedCanMove"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCachedCanResize>("cachedCanResize"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCachedCanRotate>("cachedCanRotate"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCachedCanZoom>("cachedCanZoom"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCachedZoomLevel>("cachedZoomLevel"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCachedZoomMaximum>("cachedZoomMaximum"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCachedZoomMinimum>("cachedZoomMinimum"),
        
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCurrentCanMove>("currentCanMove"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCurrentCanResize>("currentCanResize"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCurrentCanRotate>("currentCanRotate"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCurrentCanZoom>("currentCanZoom"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCurrentZoomLevel>("currentZoomLevel"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCurrentZoomMaximum>("currentZoomMaximum"),
        InstanceAccessor<&IUIAutomationTransformPattern2Wrapper::GetCurrentZoomMinimum>("currentZoomMinimum"),

        InstanceMethod<&IUIAutomationTransformPattern2Wrapper::Move>("move"),
        InstanceMethod<&IUIAutomationTransformPattern2Wrapper::Resize>("resize"),
        InstanceMethod<&IUIAutomationTransformPattern2Wrapper::Rotate>("rotate"),
        InstanceMethod<&IUIAutomationTransformPattern2Wrapper::Zoom>("zoom"),
        InstanceMethod<&IUIAutomationTransformPattern2Wrapper::ZoomByUnit>("zoomByUnit"),

    };

    Napi::Function function = DefineClass(env, "IUIAutomationTransformPattern2", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTransformPattern2Wrapper::New(Napi::Env env, IUIAutomationTransformPattern2 *pTransformPattern2)
{
    if (pTransformPattern2 == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->ITransformProvider2WrapperConstructor->New({Napi::External<IUIAutomationTransformPattern2>::New(env, pTransformPattern2)});
}

IUIAutomationTransformPattern2Wrapper::IUIAutomationTransformPattern2Wrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTransformPattern2Wrapper>(info)
{
    m_tranformPattern2 = info[0].As<Napi::External<IUIAutomationTransformPattern2>>().Data();
}

IUIAutomationTransformPattern2Wrapper::~IUIAutomationTransformPattern2Wrapper()
{
    m_tranformPattern2.Release();
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCachedCanMove(const Napi::CallbackInfo &info)
{
    BOOL canMove;
    auto hResult = m_tranformPattern2->get_CachedCanMove(&canMove);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMove);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCachedCanResize(const Napi::CallbackInfo &info)
{
    BOOL canResize;

    auto hResult = m_tranformPattern2->get_CachedCanResize(&canResize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canResize);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCachedCanRotate(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_tranformPattern2->get_CachedCanRotate(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCachedCanZoom(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_tranformPattern2->get_CachedCanZoom(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCachedZoomLevel(const Napi::CallbackInfo &info)
{
    double zoomLevel;

    auto hResult = m_tranformPattern2->get_CachedZoomLevel(&zoomLevel);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomLevel);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCachedZoomMaximum(const Napi::CallbackInfo &info)
{
    double zoomMaximum;

    auto hResult = m_tranformPattern2->get_CachedZoomMaximum(&zoomMaximum);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomMaximum);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCachedZoomMinimum(const Napi::CallbackInfo &info)
{
    double zoomMinimum;

    auto hResult = m_tranformPattern2->get_CachedZoomMinimum(&zoomMinimum);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomMinimum);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCurrentCanMove(const Napi::CallbackInfo &info)
{
    BOOL canMove;
    auto hResult = m_tranformPattern2->get_CurrentCanMove(&canMove);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMove);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCurrentCanResize(const Napi::CallbackInfo &info)
{
    BOOL canResize;

    auto hResult = m_tranformPattern2->get_CurrentCanResize(&canResize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canResize);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCurrentCanRotate(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_tranformPattern2->get_CurrentCanRotate(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCurrentCanZoom(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_tranformPattern2->get_CurrentCanZoom(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCurrentZoomLevel(const Napi::CallbackInfo &info)
{
    double zoomLevel;

    auto hResult = m_tranformPattern2->get_CurrentZoomLevel(&zoomLevel);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomLevel);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCurrentZoomMaximum(const Napi::CallbackInfo &info)
{
    double zoomMaximum;

    auto hResult = m_tranformPattern2->get_CurrentZoomMaximum(&zoomMaximum);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomMaximum);
}

Napi::Value IUIAutomationTransformPattern2Wrapper::GetCurrentZoomMinimum(const Napi::CallbackInfo &info)
{
    double zoomMinimum;

    auto hResult = m_tranformPattern2->get_CurrentZoomMinimum(&zoomMinimum);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), zoomMinimum);
}


void IUIAutomationTransformPattern2Wrapper::Move(const Napi::CallbackInfo &info)
{
    auto x = info[0].ToNumber();
    auto y = info[1].ToNumber();

    auto hResult = m_tranformPattern2->Move(x, y);

    HandleResult(info, hResult);
}

void IUIAutomationTransformPattern2Wrapper::Resize(const Napi::CallbackInfo &info)
{
    auto width = info[0].ToNumber();
    auto height = info[1].ToNumber();

    auto hResult = m_tranformPattern2->Resize(width, height);

    HandleResult(info, hResult);
}

void IUIAutomationTransformPattern2Wrapper::Rotate(const Napi::CallbackInfo &info)
{
    auto degrees = info[0].ToNumber();

    auto hResult = m_tranformPattern2->Rotate(degrees);

    HandleResult(info, hResult);
}

void IUIAutomationTransformPattern2Wrapper::Zoom(const Napi::CallbackInfo &info)
{
    auto zoom = info[0].ToNumber();

    auto hResult = m_tranformPattern2->Zoom(zoom);

    HandleResult(info, hResult);
}

void IUIAutomationTransformPattern2Wrapper::ZoomByUnit(const Napi::CallbackInfo &info)
{
    auto zoomUnit = static_cast<ZoomUnit>(info[0].ToNumber().Int32Value());

    auto hResult = m_tranformPattern2->ZoomByUnit(zoomUnit);

    HandleResult(info, hResult);
}
