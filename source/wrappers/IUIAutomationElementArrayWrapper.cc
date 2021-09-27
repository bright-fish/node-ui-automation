#include "Wrappers.h"
#include "../AutomationAddon.h"

Napi::FunctionReference *IUIAutomationElementArrayWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod("getElement", &GetElement),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationElementArray", classDefinition);

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Object IUIAutomationElementArrayWrapper::New(Napi::Env env, IUIAutomationElementArray *pElementArray)
{
    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationElementArrayWrapperConstructor->New({Napi::External<IUIAutomationElementArray>::New(env, pElementArray)});
}

IUIAutomationElementArrayWrapper::IUIAutomationElementArrayWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationElementArrayWrapper>(info)
{
    if (info.Length() != 1)
    {
        throw Napi::TypeError::New(info.Env(), "IUIAutomationElementArray constructor missing parameters.");
    }

    m_pElementArray = info[0].As<Napi::External<IUIAutomationElementArray>>().Data();
}

// todo: indexer
// todo: iterator?
Napi::Value IUIAutomationElementArrayWrapper::GetElement(const Napi::CallbackInfo &info)
{
    auto number = info[0].ToNumber();

    if (number.IsUndefined())
    {
        return number.Env().Null();
    }

    IUIAutomationElement *pElement = NULL;
    auto hResult = m_pElementArray->GetElement(number.Int32Value(), &pElement);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    auto pElementWrapper = IUIAutomationElementWrapper::New(info.Env(), pElement);

    return pElementWrapper;
}
