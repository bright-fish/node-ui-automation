#include "Library.h"

Napi::Object IUIAutomationElementArrayWrapper::Init(Napi::Env env, Napi::Object exports)
{
    auto classDefinition = {
        InstanceMethod("getElement", &GetElement),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationElementArray", classDefinition);

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

IUIAutomationElementArrayWrapper::IUIAutomationElementArrayWrapper(const Napi::CallbackInfo &info, IUIAutomationElementArray *pElementArray) : IUIAutomationElementArrayWrapper(info)
{
    m_pElementArray = pElementArray;
}
IUIAutomationElementArrayWrapper::IUIAutomationElementArrayWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationElementArrayWrapper>(info)
{
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

    auto pElementWrapper = new IUIAutomationElementWrapper(info, pElement);

    return pElementWrapper->Value();
}
