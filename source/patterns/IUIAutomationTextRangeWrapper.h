#pragma once
#include "../Shared.h"

class IUIAutomationTextRangeWrapper : public Napi::ObjectWrap<IUIAutomationTextRangeWrapper>
{
public:
    static Napi::FunctionReference *Initialize(Napi::Env env);
    static Napi::Value New(Napi::Env env, IUIAutomationTextRange *pITextRangeProvider);

    void AddToSelection(const Napi::CallbackInfo &info);
    Napi::Value Clone(const Napi::CallbackInfo &info);
    Napi::Value Compare(const Napi::CallbackInfo &info);
    Napi::Value CompareEndpoints(const Napi::CallbackInfo &info);
    void ExpandToEnclosingUnit(const Napi::CallbackInfo &info);
    Napi::Value FindAttribute(const Napi::CallbackInfo &info);
    Napi::Value FindText(const Napi::CallbackInfo &info);
    Napi::Value GetAttributeValue(const Napi::CallbackInfo &info);
    Napi::Value GetBoundingRectangles(const Napi::CallbackInfo &info);
    Napi::Value GetChildren(const Napi::CallbackInfo &info);
    Napi::Value GetEnclosingElement(const Napi::CallbackInfo &info);
    Napi::Value GetText(const Napi::CallbackInfo &info);
    Napi::Value Move(const Napi::CallbackInfo &info);
    void MoveEndpointByRange(const Napi::CallbackInfo &info);
    Napi::Value MoveEndpointByUnit(const Napi::CallbackInfo &info);
    void RemoveFromSelection(const Napi::CallbackInfo &info);
    void ScrollIntoView(const Napi::CallbackInfo &info);
    void Select(const Napi::CallbackInfo &info);

    IUIAutomationTextRangeWrapper(const Napi::CallbackInfo &info);
    ~IUIAutomationTextRangeWrapper();

private:
    IUIAutomationTextRange *m_textRange;
};
