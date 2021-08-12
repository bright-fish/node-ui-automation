#include "IUIAutomationElementWrapper.h"

#include "Library.h"
#include <comutil.h>
#include <stdio.h>

using v8::Local;
using v8::Object;

Nan::Persistent<v8::Function> IUIAutomationElementWrapper::constructor;

void IUIAutomationElementWrapper::GetCurrentProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto pAutomationElementRaw = info.Holder()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElement = static_cast<IUIAutomationElement*>(pAutomationElementRaw);

    Nan::Utf8String utf8PropertyName(property);
    std::string sPropertyName(*utf8PropertyName);

    if (sPropertyName == "currentName")
    {
        BSTR name = NULL;

        pAutomationElement->get_CurrentName(&name);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(name)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentAcceleratorKey")
    {
        BSTR acceloratorKey = NULL;

        pAutomationElement->get_CurrentAcceleratorKey(&acceloratorKey);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(acceloratorKey)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentAccessKey")
    {
        BSTR accessKey = NULL;

        pAutomationElement->get_CurrentAccessKey(&accessKey);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(accessKey)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentAriaProperties")
    {
        BSTR ariaProperties = NULL;

        pAutomationElement->get_CurrentAriaProperties(&ariaProperties);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(ariaProperties)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentAriaRole")
    {
        BSTR ariaRole = NULL;

        pAutomationElement->get_CurrentAriaRole(&ariaRole);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(ariaRole)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentAutomationId")
    {
        BSTR automationId = NULL;

        pAutomationElement->get_CurrentAutomationId(&automationId);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(automationId)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentBoundingRectangle")
    {
        RECT boundingRectangle;

        pAutomationElement->get_CurrentBoundingRectangle(&boundingRectangle);

        auto boundingRectangleWrapper = RectWrapper::NewInstance(isolate, &boundingRectangle);

        info.GetReturnValue()
            .Set(boundingRectangleWrapper);

        return;
    }
    else if (sPropertyName == "currentClassName")
    {
        BSTR className = NULL;

        pAutomationElement->get_CurrentClassName(&className);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(className)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentControllerFor")
    {
        IUIAutomationElementArray *controllerFor;
        pAutomationElement->get_CurrentControllerFor(&controllerFor);

        auto controllerForWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, controllerFor);

        info.GetReturnValue()
            .Set(controllerForWrapper);

        return;
    }
    else if (sPropertyName == "currentControlType")
    {
        CONTROLTYPEID controlTypeId = NULL;

        pAutomationElement->get_CurrentControlType(&controlTypeId);

        info.GetReturnValue().Set(v8::Int32::New(isolate, controlTypeId));

        return;
    }
    else if (sPropertyName == "currentCulture")
    {
        int culture;

        pAutomationElement->get_CurrentCulture(&culture);

        info.GetReturnValue()
            .Set(v8::Int32::New(isolate, culture));

        return;
    }
    else if (sPropertyName == "currentDescribedBy")
    {
        IUIAutomationElementArray *describedBy;

        pAutomationElement->get_CurrentDescribedBy(&describedBy);

        auto describedByWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, describedBy);

        info.GetReturnValue()
            .Set(describedByWrapper);

        return;
    }
    else if (sPropertyName == "currentFlowsTo")
    {
        IUIAutomationElementArray *flowsTo;

        pAutomationElement->get_CurrentFlowsTo(&flowsTo);

        auto flowsToWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, flowsTo);

        info.GetReturnValue()
            .Set(flowsToWrapper);

        return;
    }
    else if (sPropertyName == "currentFrameworkId")
    {
        BSTR frameworkId = NULL;

        pAutomationElement->get_CurrentFrameworkId(&frameworkId);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(frameworkId)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentHasKeyboardFocus")
    {
        BOOL hasKeyboardFocus = NULL;
        pAutomationElement->get_CurrentHasKeyboardFocus(&hasKeyboardFocus);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, hasKeyboardFocus));

        return;
    }
    else if (sPropertyName == "currentHelpText")
    {
        BSTR helpText = NULL;

        pAutomationElement->get_CurrentHelpText(&helpText);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(helpText)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentIsContentElement")
    {
        BOOL isContentElement = NULL;

        pAutomationElement->get_CurrentIsContentElement(&isContentElement);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isContentElement));

        return;
    }
    else if (sPropertyName == "currentIsControlElement")
    {
        BOOL isControlElement = NULL;

        pAutomationElement->get_CurrentIsControlElement(&isControlElement);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isControlElement));

        return;
    }
    else if (sPropertyName == "currentIsDataValidForForm")
    {
        BOOL isDataValidForForm = NULL;

        pAutomationElement->get_CurrentIsDataValidForForm(&isDataValidForForm);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isDataValidForForm));

        return;
    }
    else if (sPropertyName == "currentIsEnabled")
    {
        BOOL isEnabled = NULL;

        pAutomationElement->get_CurrentIsEnabled(&isEnabled);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isEnabled));

        return;
    }
    else if (sPropertyName == "currentIsKeyboardFocusable")
    {
        BOOL isKeyboardFocusable = NULL;

        pAutomationElement->get_CurrentIsKeyboardFocusable(&isKeyboardFocusable);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isKeyboardFocusable));

        return;
    }
    else if (sPropertyName == "currentIsOffscreen")
    {
        BOOL isOffscreen = NULL;

        pAutomationElement->get_CurrentIsOffscreen(&isOffscreen);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isOffscreen));

        return;
    }
    else if (sPropertyName == "currentIsPassword")
    {
        BOOL isPassword = NULL;

        pAutomationElement->get_CurrentIsPassword(&isPassword);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isPassword));

        return;
    }
    else if (sPropertyName == "currentIsRequiredForForm")
    {
        BOOL isRequiredForForm = NULL;

        pAutomationElement->get_CurrentIsRequiredForForm(&isRequiredForForm);

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isRequiredForForm));

        return;
    }
    else if (sPropertyName == "currentItemStatus")
    {
        BSTR itemStatus = NULL;

        pAutomationElement->get_CurrentItemStatus(&itemStatus);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(itemStatus)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentItemType")
    {
        BSTR itemType = NULL;

        pAutomationElement->get_CurrentItemType(&itemType);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(itemType)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentLabeledBy")
    {
        IUIAutomationElement *element;

        pAutomationElement->get_CurrentLabeledBy(&element);

        auto elementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, element);

        info.GetReturnValue()
            .Set(elementWrapper);

        return;
    }
    else if (sPropertyName == "currentLocalizedControlType")
    {
        BSTR localizedControlType = NULL;

        pAutomationElement->get_CurrentLocalizedControlType(&localizedControlType);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(localizedControlType)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "currentNativeWindowHandle")
    {
        UIA_HWND nativeWindowHandle;

        pAutomationElement->get_CurrentNativeWindowHandle(&nativeWindowHandle);

        info.GetReturnValue().Set(v8::External::New(isolate, nativeWindowHandle));

        return;
    }
    else if (sPropertyName == "currentOrientation")
    {
        OrientationType orientationType;

        pAutomationElement->get_CurrentOrientation(&orientationType);

        info.GetReturnValue().Set(v8::Int32::New(isolate, orientationType));

        return;
    }
    else if (sPropertyName == "currentProcessId")
    {
        int processId;

        pAutomationElement->get_CurrentProcessId(&processId);

        info.GetReturnValue().Set(v8::Int32::New(isolate, processId));

        return;
    }
    else if (sPropertyName == "currentProviderDescription")
    {
        BSTR providerDescription = NULL;

        pAutomationElement->get_CurrentProviderDescription(&providerDescription);

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(providerDescription)).ToLocalChecked());

        return;
    }
    else
    {
        throw std::exception("Not Implemented. ");
    }
}

void IUIAutomationElementWrapper::GetCachedProperty(v8::Local<v8::String> property, const v8::PropertyCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto pAutomationElementRaw = info.Holder()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElement = static_cast<IUIAutomationElement *>(pAutomationElementRaw);

    Nan::Utf8String utf8PropertyName(property);
    std::string sPropertyName(*utf8PropertyName);

    if (sPropertyName == "cachedName")
    {
        BSTR name = NULL;

        pAutomationElement->get_CachedName(&name);

        if (!name)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(name)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedAcceleratorKey")
    {
        BSTR acceloratorKey = NULL;

        pAutomationElement->get_CachedAcceleratorKey(&acceloratorKey);

        if (!acceloratorKey)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(acceloratorKey)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedAccessKey")
    {
        BSTR accessKey = NULL;

        pAutomationElement->get_CachedAccessKey(&accessKey);

        if (!accessKey)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(accessKey)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedAriaProperties")
    {
        BSTR ariaProperties = NULL;

        pAutomationElement->get_CachedAriaProperties(&ariaProperties);

        if (!ariaProperties)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(ariaProperties)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedAriaRole")
    {
        BSTR ariaRole = NULL;

        pAutomationElement->get_CachedAriaRole(&ariaRole);

        if (!ariaRole)
        {
            info.GetReturnValue()
                .SetNull();

            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(ariaRole)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedAutomationId")
    {
        BSTR automationId = NULL;

        pAutomationElement->get_CachedAutomationId(&automationId);

        if (!automationId)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(automationId)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedBoundingRectangle")
    {
        RECT boundingRectangle;

        auto hResult = pAutomationElement->get_CachedBoundingRectangle(&boundingRectangle);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();

            return;
        }

        auto boundingRectangleWrapper = RectWrapper::NewInstance(isolate, &boundingRectangle);

        info.GetReturnValue()
            .Set(boundingRectangleWrapper);

        return;
    }
    else if (sPropertyName == "cachedClassName")
    {
        BSTR className = NULL;

        pAutomationElement->get_CachedClassName(&className);

        if (!className)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(className)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedControllerFor")
    {
        IUIAutomationElementArray *controllerFor;
        auto hResult = pAutomationElement->get_CachedControllerFor(&controllerFor);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        auto controllerForWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, controllerFor);

        info.GetReturnValue()
            .Set(controllerForWrapper);

        return;
    }
    else if (sPropertyName == "cachedControlType")
    {
        CONTROLTYPEID controlTypeId = NULL;

        auto hResult = pAutomationElement->get_CachedControlType(&controlTypeId);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue().Set(v8::Int32::New(isolate, controlTypeId));

        return;
    }
    else if (sPropertyName == "cachedCulture")
    {
        int culture;

        auto hResult = pAutomationElement->get_CachedCulture(&culture);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Int32::New(isolate, culture));

        return;
    }
    else if (sPropertyName == "cachedDescribedBy")
    {
        IUIAutomationElementArray *describedBy;

        auto hResult = pAutomationElement->get_CachedDescribedBy(&describedBy);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        auto describedByWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, describedBy);

        info.GetReturnValue()
            .Set(describedByWrapper);

        return;
    }
    else if (sPropertyName == "cachedFlowsTo")
    {
        IUIAutomationElementArray *flowsTo;

        auto hResult = pAutomationElement->get_CachedFlowsTo(&flowsTo);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        auto flowsToWrapper = IUIAutomationElementArrayWrapper::NewInstance(isolate, flowsTo);

        info.GetReturnValue()
            .Set(flowsToWrapper);

        return;
    }
    else if (sPropertyName == "cachedFrameworkId")
    {
        BSTR frameworkId = NULL;

        pAutomationElement->get_CachedFrameworkId(&frameworkId);

        if (!frameworkId)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(frameworkId)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedHasKeyboardFocus")
    {
        BOOL hasKeyboardFocus = NULL;
        auto hResult = pAutomationElement->get_CachedHasKeyboardFocus(&hasKeyboardFocus);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, hasKeyboardFocus));

        return;
    }
    else if (sPropertyName == "cachedHelpText")
    {
        BSTR helpText = NULL;

        pAutomationElement->get_CachedHelpText(&helpText);

        if (!helpText)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(helpText)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedIsContentElement")
    {
        BOOL isContentElement = NULL;

        auto hResult = pAutomationElement->get_CachedIsContentElement(&isContentElement);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isContentElement));

        return;
    }
    else if (sPropertyName == "cachedIsControlElement")
    {
        BOOL isControlElement = NULL;

        auto hResult = pAutomationElement->get_CachedIsControlElement(&isControlElement);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isControlElement));

        return;
    }
    else if (sPropertyName == "cachedIsDataValidForForm")
    {
        BOOL isDataValidForForm = NULL;

        auto hResult = pAutomationElement->get_CachedIsDataValidForForm(&isDataValidForForm);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isDataValidForForm));

        return;
    }
    else if (sPropertyName == "cachedIsEnabled")
    {
        BOOL isEnabled = NULL;

        auto hResult = pAutomationElement->get_CachedIsEnabled(&isEnabled);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isEnabled));

        return;
    }
    else if (sPropertyName == "cachedIsKeyboardFocusable")
    {
        BOOL isKeyboardFocusable = NULL;

        auto hResult = pAutomationElement->get_CachedIsKeyboardFocusable(&isKeyboardFocusable);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isKeyboardFocusable));

        return;
    }
    else if (sPropertyName == "cachedIsOffscreen")
    {
        BOOL isOffscreen = NULL;

        auto hResult = pAutomationElement->get_CachedIsOffscreen(&isOffscreen);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isOffscreen));

        return;
    }
    else if (sPropertyName == "cachedIsPassword")
    {
        BOOL isPassword = NULL;

        auto hResult = pAutomationElement->get_CachedIsPassword(&isPassword);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isPassword));

        return;
    }
    else if (sPropertyName == "cachedIsRequiredForForm")
    {
        BOOL isRequiredForForm = NULL;

        auto hResult = pAutomationElement->get_CachedIsRequiredForForm(&isRequiredForForm);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::Boolean::New(isolate, isRequiredForForm));

        return;
    }
    else if (sPropertyName == "cachedItemStatus")
    {
        BSTR itemStatus = NULL;

        pAutomationElement->get_CachedItemStatus(&itemStatus);

        if (!itemStatus)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(itemStatus)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedItemType")
    {
        BSTR itemType = NULL;

        pAutomationElement->get_CachedItemType(&itemType);

        if (!itemType)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(itemType)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedLabeledBy")
    {
        IUIAutomationElement *element;

        pAutomationElement->get_CachedLabeledBy(&element);

        auto elementWrapper = IUIAutomationElementWrapper::NewInstance(isolate, element);

        info.GetReturnValue()
            .Set(elementWrapper);

        return;
    }
    else if (sPropertyName == "cachedLocalizedControlType")
    {
        BSTR localizedControlType = NULL;

        pAutomationElement->get_CachedLocalizedControlType(&localizedControlType);

        if (!localizedControlType)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue()
            .Set(v8::String::NewFromUtf8(isolate, _com_util::ConvertBSTRToString(localizedControlType)).ToLocalChecked());

        return;
    }
    else if (sPropertyName == "cachedNativeWindowHandle")
    {
        UIA_HWND nativeWindowHandle;

        auto hResult = pAutomationElement->get_CachedNativeWindowHandle(&nativeWindowHandle);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue().Set(v8::External::New(isolate, nativeWindowHandle));

        return;
    }
    else if (sPropertyName == "cachedOrientation")
    {
        OrientationType orientationType;

        auto hResult = pAutomationElement->get_CachedOrientation(&orientationType);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue().Set(v8::Int32::New(isolate, orientationType));

        return;
    }
    else if (sPropertyName == "cachedProcessId")
    {
        int processId;

        auto hResult = pAutomationElement->get_CachedProcessId(&processId);

        if (FAILED(hResult))
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

        info.GetReturnValue().Set(v8::Int32::New(isolate, processId));

        return;
    }
    else if (sPropertyName == "cachedProviderDescription")
    {
        BSTR providerDescription = NULL;

        pAutomationElement->get_CachedProviderDescription(&providerDescription);

        if (!providerDescription)
        {
            info.GetReturnValue()
                .SetNull();
            return;
        }

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

    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentName").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentAcceleratorKey").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentAccessKey").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentAriaProperties").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentAriaRole").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentAutomationId").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentBoundingRectangle").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentClassName").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentControllerFor").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentControlType").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentCulture").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentDescribedBy").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentFlowsTo").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentFrameworkId").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentHasKeyboardFocus").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentHelpText").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsContentElement").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsControlElement").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsDataValidForForm").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsEnabled").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsKeyboardFocusable").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsOffscreen").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsPassword").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentIsRequiredForForm").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentItemStatus").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentItemType").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentLabeledBy").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentLocalizedControlType").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentNativeWindowHandle").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentOrientation").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentProcessId").ToLocalChecked(), GetCurrentProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "currentProviderDescription").ToLocalChecked(), GetCurrentProperty);

    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedName").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedAcceleratorKey").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedAccessKey").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedAriaProperties").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedAriaRole").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedAutomationId").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedBoundingRectangle").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedClassName").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedControllerFor").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedControlType").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedCulture").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedDescribedBy").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedFlowsTo").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedFrameworkId").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedHasKeyboardFocus").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedHelpText").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsContentElement").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsControlElement").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsDataValidForForm").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsEnabled").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsKeyboardFocusable").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsOffscreen").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsPassword").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedIsRequiredForForm").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedItemStatus").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedItemType").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedLabeledBy").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedLocalizedControlType").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedNativeWindowHandle").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedOrientation").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedProcessId").ToLocalChecked(), GetCachedProperty);
    instanceTemplate->SetAccessor(v8::String::NewFromUtf8(isolate, "cachedProviderDescription").ToLocalChecked(), GetCachedProperty);

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

    instance->SetInternalField(0, v8::External::New(isolate, pElement));

    return instance;
}

void IUIAutomationElementWrapper::FindFirst(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
    auto isolate = info.GetIsolate();

    auto context = isolate->GetCurrentContext();

    auto pAutomationElementRaw = info.This()->GetInternalField(0).As<v8::External>()->Value();
    auto pAutomationElement = static_cast<IUIAutomationElement *>(pAutomationElementRaw);

    auto treeScopeRaw = info[0].As<v8::Int32>()->Value();
    auto treeScope = static_cast<TreeScope>(treeScopeRaw);

    auto pConditionWrapperRaw = info[1].As<v8::Object>()->GetInternalField(0).As<v8::External>()->Value();
    auto pConditionWrapper = static_cast<IUIAutomationCondition *>(pConditionWrapperRaw);

    IUIAutomationElement *pFoundElement = NULL;
    HRESULT hr = pAutomationElement->FindFirst(treeScope, pConditionWrapper, &pFoundElement);

    auto foundElement = IUIAutomationElementWrapper::NewInstance(isolate, pFoundElement);

    info.GetReturnValue().Set(foundElement);
}
