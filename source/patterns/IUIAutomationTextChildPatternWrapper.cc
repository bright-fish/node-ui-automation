#include "IUIAutomationTextChildPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "IUIAutomationTextRangeWrapper.h"

Napi::FunctionReference *IUIAutomationTextChildPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceAccessor<&IUIAutomationTextChildPatternWrapper::GetTextContainer>("textContainer"),
        InstanceAccessor<&IUIAutomationTextChildPatternWrapper::GetTextRange>("textRange"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationTextChildPattern", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationTextChildPatternWrapper::New(Napi::Env env, IUIAutomationTextChildPattern *pTextChildProvider)
{
    if (pTextChildProvider == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationTextChildPatternWrapperConstructor->New({Napi::External<IUIAutomationTextChildPattern>::New(env, pTextChildProvider)});
}

IUIAutomationTextChildPatternWrapper::IUIAutomationTextChildPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationTextChildPatternWrapper>(info)
{
    m_textChildPattern = info[0].As<Napi::External<IUIAutomationTextChildPattern>>().Data();
}

IUIAutomationTextChildPatternWrapper::~IUIAutomationTextChildPatternWrapper()
{
    m_textChildPattern.Release();
}

Napi::Value IUIAutomationTextChildPatternWrapper::GetTextContainer(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationElement> pTextContainer = NULL;
    auto hResult = m_textChildPattern->get_TextContainer(&pTextContainer);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pTextContainer);
}

Napi::Value IUIAutomationTextChildPatternWrapper::GetTextRange(const Napi::CallbackInfo &info)
{
    ATL::CComPtr<IUIAutomationTextRange> textRange = NULL;

    auto hResult = m_textChildPattern->get_TextRange(&textRange);

    HandleResult(info, hResult);

    return IUIAutomationTextRangeWrapper::New(info.Env(), textRange);
}