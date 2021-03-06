#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../utilities/ComAutoPointer.h"

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

Napi::Value IUIAutomationElementArrayWrapper::New(Napi::Env env, IUIAutomationElementArray *pElementArray)
{
    if (pElementArray == NULL)
    {
        return env.Null();
    }

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

IUIAutomationElementArrayWrapper::~IUIAutomationElementArrayWrapper()
{
    m_pElementArray.Release();
}

Napi::Value IUIAutomationElementArrayWrapper::GetElement(const Napi::CallbackInfo &info)
{
    auto number = info[0].ToNumber();

    if (number.IsUndefined())
    {
        return number.Env().Null();
    }

    ComAutoPointer<IUIAutomationElement> pElement = NULL;
    auto hResult = m_pElementArray->GetElement(number.Int32Value(), &pElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pElement);
}
