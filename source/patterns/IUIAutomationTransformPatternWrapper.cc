#include "IUIAutomationTransformPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "IUIAutomationTextRangeWrapper.h"

Napi::FunctionReference *IUIAutomationTransformPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTransformPatternWrapper::GetCachedCanMove>("cachedCanMove"),
        InstanceAccessor<&IUIAutomationTransformPatternWrapper::GetCachedCanResize>("cachedCanResize"),
        InstanceAccessor<&IUIAutomationTransformPatternWrapper::GetCachedCanRotate>("cachedCanRotate"),

        InstanceAccessor<&IUIAutomationTransformPatternWrapper::GetCurrentCanMove>("currentCanMove"),
        InstanceAccessor<&IUIAutomationTransformPatternWrapper::GetCurrentCanResize>("currentCanResize"),
        InstanceAccessor<&IUIAutomationTransformPatternWrapper::GetCurrentCanRotate>("currentCanRotate"),


        InstanceMethod<&IUIAutomationTransformPatternWrapper::Move>("move"),
        InstanceMethod<&IUIAutomationTransformPatternWrapper::Resize>("resize"),
        InstanceMethod<&IUIAutomationTransformPatternWrapper::Rotate>("rotate"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTransformPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTransformPatternWrapper::New(Napi::Env env, IUIAutomationTransformPattern *pTransformPattern)
{
    if (pTransformPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTransformPatternWrapperConstructor->New({Napi::External<IUIAutomationTransformPattern>::New(env, pTransformPattern)});
}

IUIAutomationTransformPatternWrapper::IUIAutomationTransformPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTransformPatternWrapper>(info)
{
    m_tranformPattern = info[0].As<Napi::External<IUIAutomationTransformPattern>>().Data();
}

IUIAutomationTransformPatternWrapper::~IUIAutomationTransformPatternWrapper()
{
    m_tranformPattern.Release();
}

Napi::Value IUIAutomationTransformPatternWrapper::GetCachedCanMove(const Napi::CallbackInfo &info)
{
    BOOL canMove;
    auto hResult = m_tranformPattern->get_CachedCanMove(&canMove);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMove);
}

Napi::Value IUIAutomationTransformPatternWrapper::GetCachedCanResize(const Napi::CallbackInfo &info)
{
    BOOL canResize;

    auto hResult = m_tranformPattern->get_CachedCanResize(&canResize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canResize);
}

Napi::Value IUIAutomationTransformPatternWrapper::GetCachedCanRotate(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_tranformPattern->get_CachedCanRotate(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}



Napi::Value IUIAutomationTransformPatternWrapper::GetCurrentCanMove(const Napi::CallbackInfo &info)
{
    BOOL canMove;
    auto hResult = m_tranformPattern->get_CurrentCanMove(&canMove);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canMove);
}

Napi::Value IUIAutomationTransformPatternWrapper::GetCurrentCanResize(const Napi::CallbackInfo &info)
{
    BOOL canResize;

    auto hResult = m_tranformPattern->get_CurrentCanResize(&canResize);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canResize);
}

Napi::Value IUIAutomationTransformPatternWrapper::GetCurrentCanRotate(const Napi::CallbackInfo &info)
{
    BOOL canRotate;

    auto hResult = m_tranformPattern->get_CurrentCanRotate(&canRotate);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), canRotate);
}


void IUIAutomationTransformPatternWrapper::Move(const Napi::CallbackInfo &info)
{
    auto x = info[0].ToNumber();
    auto y = info[1].ToNumber();

    auto hResult = m_tranformPattern->Move(x, y);

    HandleResult(info, hResult);
}

void IUIAutomationTransformPatternWrapper::Resize(const Napi::CallbackInfo &info)
{
    auto width = info[0].ToNumber();
    auto height = info[1].ToNumber();

    auto hResult = m_tranformPattern->Resize(width, height);

    HandleResult(info, hResult);
}

void IUIAutomationTransformPatternWrapper::Rotate(const Napi::CallbackInfo &info)
{
    auto degrees = info[0].ToNumber();

    auto hResult = m_tranformPattern->Rotate(degrees);

    HandleResult(info, hResult);
}
