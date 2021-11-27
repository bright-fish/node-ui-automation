#include "IAccessibleWrapper.h"
#include "../AutomationAddon.h"

// skipping for now.  complexity is high and current value appears to be low.
// m_pIAccessible->get_accChild;
// m_pIAccessible->get_accChildCount;
// m_pIAccessible->get_accDefaultAction;
// m_pIAccessible->get_accDescription;
// m_pIAccessible->get_accFocus;
// m_pIAccessible->get_accHelp;
// m_pIAccessible->get_accHelpTopic;
// m_pIAccessible->get_accKeyboardShortcut;
// m_pIAccessible->get_accName;
// m_pIAccessible->put_accName;
// m_pIAccessible->get_accParent;
// m_pIAccessible->get_accRole;
// m_pIAccessible->get_accSelection;
// m_pIAccessible->get_accState;
// m_pIAccessible->get_accValue;
// m_pIAccessible->put_accValue;

Napi::FunctionReference *IAccessibleWrapper::Initialize(Napi::Env env)
{
    Napi::Function function = DefineClass(env, "IAccessible", {});

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IAccessibleWrapper::New(Napi::Env env, IAccessible *pIAccessible)
{
    if (pIAccessible == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IAccessibleWrapperConstructor->New({Napi::External<IAccessible>::New(env, pIAccessible)});
}

IAccessibleWrapper::IAccessibleWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IAccessibleWrapper>(info)
{
    m_pIAccessible = info[0].As<Napi::External<IAccessible>>().Data();
}

IAccessibleWrapper::~IAccessibleWrapper()
{
    m_pIAccessible->Release();
}
