#include "IUIAutomationElementWrapper.h"

#include "Library.h"
#include <comutil.h>
#include <stdio.h>

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationElementWrapper::constructor;

IUIAutomationElementWrapper::IUIAutomationElementWrapper(IUIAutomationElement *pAutomationElement)
{
    m_pAutomationElement = pAutomationElement;
}

IUIAutomationElementWrapper::~IUIAutomationElementWrapper()
{
}

void IUIAutomationElementWrapper::GetProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto pAutomationElementWrapperRaw = info.Holder()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElementWrapper = static_cast<IUIAutomationElementWrapper *>(pAutomationElementWrapperRaw);

    Nan::Utf8String utf8PropertyName(property);
    std::string sPropertyName(*utf8PropertyName);

    if (sPropertyName == "name")
    {
        BSTR name = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentName(&name);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(name)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "acceleratorKey")
    {
        BSTR acceloratorKey = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentAcceleratorKey(&acceloratorKey);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(acceloratorKey)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "accessKey")
    {
        BSTR accessKey = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentAccessKey(&accessKey);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(accessKey)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "ariaProperties")
    {
        BSTR ariaProperties = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentAriaProperties(&ariaProperties);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(ariaProperties)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "ariaRole")
    {
        BSTR ariaRole = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentAriaRole(&ariaRole);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(ariaRole)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "automationId")
    {
        BSTR automationId = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentAutomationId(&automationId);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(automationId)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "boundingRectangle")
    {
        RECT boundingRectangle;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentBoundingRectangle(&boundingRectangle);

        auto boundingRectangleWrapper = RectWrapper::NewInstance(isolate, &boundingRectangle);

        info.GetReturnValue()
            .Set(boundingRectangleWrapper);

        return;
    }
    else if (sPropertyName == "className")
    {
        BSTR className = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentClassName(&className);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(className)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "controllerFor")
    {
        IUIAutomationElementArray *controllerFor;
        pAutomationElementWrapper->m_pAutomationElement->get_CurrentControllerFor(&controllerFor);

        auto controllerForWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, controllerFor);

        info.GetReturnValue()
            .Set(controllerForWrapper);

        return;
    }
    else if (sPropertyName == "controlType")
    {
        CONTROLTYPEID controlTypeId = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentControlType(&controlTypeId);

        info.GetReturnValue().Set(v8::Int32::New(isolate, controlTypeId));

        return;
    }
    else if (sPropertyName == "culture")
    {
        int culture;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentCulture(&culture);

        info.GetReturnValue()
            .Set(v8::Int32::New(isolate, culture));

        return;
    }
    else if (sPropertyName == "describedBy")
    {
        IUIAutomationElementArray *describedBy;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentDescribedBy(&describedBy);

        auto describedByWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, describedBy);

        info.GetReturnValue()
            .Set(describedByWrapper);

        return;
    }
    else if (sPropertyName == "flowsTo")
    {
        IUIAutomationElementArray *flowsTo;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentFlowsTo(&flowsTo);

        auto flowsToWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, flowsTo);

        info.GetReturnValue()
            .Set(flowsToWrapper);

        return;
    }
    else if (sPropertyName == "frameworkId")
    {
        BSTR frameworkId = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentFrameworkId(&frameworkId);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(frameworkId)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "hasKeyboardFocus")
    {
        BOOL hasKeyboardFocus = NULL;
        pAutomationElementWrapper->m_pAutomationElement->get_CurrentHasKeyboardFocus(&hasKeyboardFocus);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, hasKeyboardFocus));

        return;
    }
    else if (sPropertyName == "helpText")
    {
        BSTR helpText = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentHelpText(&helpText);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(helpText)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "isContentElement")
    {
        BOOL isContentElement = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsContentElement(&isContentElement);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isContentElement));

        return;
    }
    else if (sPropertyName == "isControlElement")
    {
        BOOL isControlElement = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsControlElement(&isControlElement);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isControlElement));

        return;
    }
    else if (sPropertyName == "isDataValidForForm")
    {
        BOOL isDataValidForForm = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsDataValidForForm(&isDataValidForForm);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isDataValidForForm));

        return;
    }
    else if (sPropertyName == "isEnabled")
    {
        BOOL isEnabled = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsEnabled(&isEnabled);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isEnabled));

        return;
    }
    else if (sPropertyName == "isKeyboardFocusable")
    {
        BOOL isKeyboardFocusable = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsKeyboardFocusable(&isKeyboardFocusable);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isKeyboardFocusable));

        return;
    }
    else if (sPropertyName == "isOffscreen")
    {
        BOOL isOffscreen = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsOffscreen(&isOffscreen);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isOffscreen));

        return;
    }
    else if (sPropertyName == "isPassword")
    {
        BOOL isPassword = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsPassword(&isPassword);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isPassword));

        return;
    }
    else if (sPropertyName == "isRequiredForForm")
    {
        BOOL isRequiredForForm = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentIsRequiredForForm(&isRequiredForForm);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isRequiredForForm));

        return;
    }
    else if (sPropertyName == "itemStatus")
    {
        BSTR itemStatus = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentItemStatus(&itemStatus);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(itemStatus)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "itemType")
    {
        BSTR itemType = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentItemType(&itemType);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(itemType)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "labeledBy")
    {
        IUIAutomationElement *element;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentLabeledBy(&element);

        auto elementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, element);

        info.GetReturnValue()
            .Set(elementWrapper);

        return;
    }
    else if (sPropertyName == "localizedControlType")
    {
        BSTR localizedControlType = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentLocalizedControlType(&localizedControlType);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(localizedControlType)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "nativeWindowHandle")
    {
        UIA_HWND nativeWindowHandle;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentNativeWindowHandle(&nativeWindowHandle);

        info.GetReturnValue().Set(v8::External::New(isolate, nativeWindowHandle));

        return;
    }
    else if (sPropertyName == "orientation")
    {
        OrientationType orientationType;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentOrientation(&orientationType);

        info.GetReturnValue().Set(v8::Int32::New(isolate, orientationType));

        return;
    }
    else if (sPropertyName == "processId")
    {
        int processId;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentProcessId(&processId);

        info.GetReturnValue().Set(v8::Int32::New(isolate, processId));

        return;
    }
    else if (sPropertyName == "providerDescription")
    {
        BSTR providerDescription = NULL;

        pAutomationElementWrapper->m_pAutomationElement->get_CurrentProviderDescription(&providerDescription);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(providerDescription)).ToLocalChecked());

        return;
    }
    else
    {
        throw std::exception("Not Implemented. ");
    }
}

NAN_MODULE_INIT(IUIAutomationElementWrapper::Init)
{
    auto isolate = target->GetIsolate();

    v8::Local<v8::FunctionTemplate> functionTemplate = Nan::New<v8::FunctionTemplate>();
    functionTemplate->SetClassName(Nan::New("IUIAutomationElement").ToLocalChecked());

    auto instanceTemplate = functionTemplate->InstanceTemplate();

    instanceTemplate->SetInternalFieldCount(1);

    Nan::SetPrototypeMethod(functionTemplate, "findFirst", FindFirst);

    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "name").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "acceleratorKey").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "accessKey").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "ariaProperties").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "ariaRole").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "automationId").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "boundingRectangle").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "className").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "controllerFor").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "controlType").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "culture").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "describedBy").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "flowsTo").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "frameworkId").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "hasKeyboardFocus").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "helpText").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isContentElement").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isControlElement").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isDataValidForForm").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isEnabled").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isKeyboardFocusable").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isOffscreen").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isPassword").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "isRequiredForForm").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "itemStatus").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "itemType").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "labeledBy").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "localizedControlType").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "nativeWindowHandle").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "orientation").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "processId").ToLocalChecked(), GetProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "providerDescription").ToLocalChecked(), GetProperty);

    constructor.Reset(Nan::GetFunction(functionTemplate).ToLocalChecked());
}

Local<v8::Value> IUIAutomationElementWrapper::NewInstance(v8::Isolate *isolate, IUIAutomationElement *pElement)
{
    if (!pElement)
    {
        return v8::Null(isolate);
    }

    auto context = isolate->GetCurrentContext();

    Local<v8::Function> constructorFunction = Local<v8::Function>::New(isolate, constructor);

    auto instance = constructorFunction->NewInstance(context).ToLocalChecked();

    auto pElementWrapper = new IUIAutomationElementWrapper(pElement);

    instance->SetInternalField(0, v8::External::New(isolate, pElementWrapper));

    return instance;
}

void IUIAutomationElementWrapper::FindFirst(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pAutomationElementWrapperRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElementWrapper = static_cast<IUIAutomationElementWrapper *>(pAutomationElementWrapperRaw);

    auto treeScopeRaw = info[0].As<v8::Int32>()->Value();
    auto treeScope = static_cast<TreeScope>(treeScopeRaw);

    auto pConditionWrapperRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pConditionWrapper = static_cast<IUIAutomationCondition *>(pConditionWrapperRaw);

    IUIAutomationElement *pFoundElement = NULL;
    HRESULT hr = pAutomationElementWrapper->m_pAutomationElement->FindFirst(treeScope, pConditionWrapper, &pFoundElement);

    auto foundElement = IUIAutomationElementWrapper::NewInstance(isolate, pFoundElement);

    info.GetReturnValue().Set(foundElement);
}
