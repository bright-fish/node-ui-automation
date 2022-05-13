#include "IUIAutomationItemContainerPatternWrapper.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../wrappers/Wrappers.h"
#include "../utilities/ComAutoPointer.h"

Napi::FunctionReference *IUIAutomationItemContainerPatternWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationItemContainerPatternWrapper::FindItemByProperty>("findItemByProperty"),
    };

    Napi::Function function = DefineClass(env, "IItemContainerProvider", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationItemContainerPatternWrapper::New(Napi::Env env, IUIAutomationItemContainerPattern *pItemContainerPattern)
{
    if (pItemContainerPattern == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationItemContainerPatternWrapperConstructor->New({Napi::External<IUIAutomationItemContainerPattern>::New(env, pItemContainerPattern)});
}

IUIAutomationItemContainerPatternWrapper::IUIAutomationItemContainerPatternWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationItemContainerPatternWrapper>(info)
{
    m_itemContainerPattern = info[0].As<Napi::External<IUIAutomationItemContainerPattern>>().Data();
}

IUIAutomationItemContainerPatternWrapper::~IUIAutomationItemContainerPatternWrapper()
{
    m_itemContainerPattern.Release();
}

Napi::Value IUIAutomationItemContainerPatternWrapper::FindItemByProperty(const Napi::CallbackInfo &info)
{
    auto pStartAfterWrapper = Napi::ObjectWrap<IUIAutomationElementWrapper>::Unwrap(info[0].ToObject());

    auto propertyId = static_cast<PROPERTYID>(info[1].ToNumber().Int32Value());

    auto variant = ToVariant(info.Env(), info[2]);

    ComAutoPointer<IUIAutomationElement> pFound = NULL;
    
    auto hResult = m_itemContainerPattern->FindItemByProperty(pStartAfterWrapper->m_pElement, propertyId, variant, &pFound);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pFound);
}