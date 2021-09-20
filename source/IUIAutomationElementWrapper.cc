#include "IUIAutomationElementWrapper.h"

#include "Library.h"
#include <comutil.h>
#include <stdio.h>

IUIAutomationElementWrapper::IUIAutomationElementWrapper(const Napi::CallbackInfo &info, IUIAutomationElement *pElement) : IUIAutomationElementWrapper(info)
{
    m_pElement = pElement;
}

IUIAutomationElementWrapper::IUIAutomationElementWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationElementWrapper>(info)
{
}

Napi::Value IUIAutomationElementWrapper::GetCurrentName(const Napi::CallbackInfo &info)
{
    BSTR name = NULL;

    m_pElement->get_CurrentName(&name);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(name));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAcceleratorKey(const Napi::CallbackInfo &info)
{
    BSTR acceloratorKey = NULL;

    m_pElement->get_CurrentAcceleratorKey(&acceloratorKey);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(acceloratorKey));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAccessKey(const Napi::CallbackInfo &info)
{
    BSTR accessKey = NULL;

    m_pElement->get_CurrentAccessKey(&accessKey);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(accessKey));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAriaProperties(const Napi::CallbackInfo &info)
{
    BSTR ariaProperties = NULL;

    m_pElement->get_CurrentAriaProperties(&ariaProperties);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaProperties));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAriaRole(const Napi::CallbackInfo &info)
{
    BSTR ariaRole = NULL;

    m_pElement->get_CurrentAriaRole(&ariaRole);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaRole));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAutomationId(const Napi::CallbackInfo &info)
{
    BSTR automationId = NULL;

    m_pElement->get_CurrentAutomationId(&automationId);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(automationId));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentBoundingRectangle(const Napi::CallbackInfo &info)
{
    RECT boundingRectangle;

    m_pElement->get_CurrentBoundingRectangle(&boundingRectangle);

    auto boundingRectangleWrapper = new RectWrapper(info, &boundingRectangle);

    return boundingRectangleWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCurrentClassName(const Napi::CallbackInfo &info)
{
    BSTR className = NULL;

    m_pElement->get_CurrentClassName(&className);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(className));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentControllerFor(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *controllerFor;
    m_pElement->get_CurrentControllerFor(&controllerFor);

    auto controllerForWrapper = new IUIAutomationElementArrayWrapper(info, controllerFor);

    return controllerForWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCurrentControlType(const Napi::CallbackInfo &info)
{
    CONTROLTYPEID controlTypeId = NULL;

    m_pElement->get_CurrentControlType(&controlTypeId);

    return Napi::Number::New(info.Env(), controlTypeId);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentCulture(const Napi::CallbackInfo &info)
{
    int culture;

    m_pElement->get_CurrentCulture(&culture);

    return Napi::Number::New(info.Env(), culture);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentDescribedBy(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *describedBy;

    m_pElement->get_CurrentDescribedBy(&describedBy);

    auto describedByWrapper = new IUIAutomationElementArrayWrapper(info, describedBy);

    return describedByWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCurrentFlowsTo(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *flowsTo;

    m_pElement->get_CurrentFlowsTo(&flowsTo);

    auto flowsToWrapper = new IUIAutomationElementArrayWrapper(info, flowsTo);

    return flowsToWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCurrentFrameworkId(const Napi::CallbackInfo &info)
{
    BSTR frameworkId = NULL;

    m_pElement->get_CurrentFrameworkId(&frameworkId);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(frameworkId));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentHasKeyboardFocus(const Napi::CallbackInfo &info)
{
    BOOL hasKeyboardFocus = NULL;
    m_pElement->get_CurrentHasKeyboardFocus(&hasKeyboardFocus);

    return Napi::Boolean::New(info.Env(), hasKeyboardFocus);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentHelpText(const Napi::CallbackInfo &info)
{
    BSTR helpText = NULL;

    m_pElement->get_CurrentHelpText(&helpText);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(helpText));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsContentElement(const Napi::CallbackInfo &info)
{
    BOOL isContentElement = NULL;

    m_pElement->get_CurrentIsContentElement(&isContentElement);

    return Napi::Boolean::New(info.Env(), isContentElement);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsControlElement(const Napi::CallbackInfo &info)
{
    BOOL isControlElement = NULL;

    m_pElement->get_CurrentIsControlElement(&isControlElement);

    return Napi::Boolean::New(info.Env(), isControlElement);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsDataValidForForm(const Napi::CallbackInfo &info)
{
    BOOL isDataValidForForm = NULL;

    m_pElement->get_CurrentIsDataValidForForm(&isDataValidForForm);

    return Napi::Boolean::New(info.Env(), isDataValidForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsEnabled(const Napi::CallbackInfo &info)
{
    BOOL isEnabled = NULL;

    m_pElement->get_CurrentIsEnabled(&isEnabled);

    return Napi::Boolean::New(info.Env(), isEnabled);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsKeyboardFocusable(const Napi::CallbackInfo &info)
{
    BOOL isKeyboardFocusable = NULL;

    m_pElement->get_CurrentIsKeyboardFocusable(&isKeyboardFocusable);

    return Napi::Boolean::New(info.Env(), isKeyboardFocusable);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsOffscreen(const Napi::CallbackInfo &info)
{
    BOOL isOffscreen = NULL;

    m_pElement->get_CurrentIsOffscreen(&isOffscreen);

    return Napi::Boolean::New(info.Env(), isOffscreen);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsPassword(const Napi::CallbackInfo &info)
{
    BOOL isPassword = NULL;

    m_pElement->get_CurrentIsPassword(&isPassword);

    return Napi::Boolean::New(info.Env(), isPassword);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsRequiredForForm(const Napi::CallbackInfo &info)
{
    BOOL isRequiredForForm = NULL;

    m_pElement->get_CurrentIsRequiredForForm(&isRequiredForForm);

    return Napi::Boolean::New(info.Env(), isRequiredForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentItemStatus(const Napi::CallbackInfo &info)
{
    BSTR itemStatus = NULL;

    m_pElement->get_CurrentItemStatus(&itemStatus);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemStatus));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentItemType(const Napi::CallbackInfo &info)
{
    BSTR itemType = NULL;

    m_pElement->get_CurrentItemType(&itemType);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemType));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentLabeledBy(const Napi::CallbackInfo &info)
{
    IUIAutomationElement *element;

    m_pElement->get_CurrentLabeledBy(&element);

    auto elementWrapper = new IUIAutomationElementWrapper(info, element);

    return elementWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCurrentLocalizedControlType(const Napi::CallbackInfo &info)
{
    BSTR localizedControlType = NULL;

    m_pElement->get_CurrentLocalizedControlType(&localizedControlType);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(localizedControlType));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentNativeWindowHandle(const Napi::CallbackInfo &info)
{
    UIA_HWND nativeWindowHandle;

    m_pElement->get_CurrentNativeWindowHandle(&nativeWindowHandle);

    throw E_NOTIMPL;
    // return Napi::External::New(info.Env(), nativeWindowHandle);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentOrientation(const Napi::CallbackInfo &info)
{
    OrientationType orientationType;

    m_pElement->get_CurrentOrientation(&orientationType);

    return Napi::Number::New(info.Env(), orientationType);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentProcessId(const Napi::CallbackInfo &info)
{
    int processId;

    m_pElement->get_CurrentProcessId(&processId);

    return Napi::Number::New(info.Env(), processId);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentProviderDescription(const Napi::CallbackInfo &info)
{
    BSTR providerDescription = NULL;

    m_pElement->get_CurrentProviderDescription(&providerDescription);

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(providerDescription));
}

Napi::Value IUIAutomationElementWrapper::GetCachedName(const Napi::CallbackInfo &info)
{
    BSTR name = NULL;

    m_pElement->get_CachedName(&name);

    if (!name)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(name));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAcceleratorKey(const Napi::CallbackInfo &info)
{
    BSTR acceloratorKey = NULL;

    m_pElement->get_CachedAcceleratorKey(&acceloratorKey);

    if (!acceloratorKey)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(acceloratorKey));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAccessKey(const Napi::CallbackInfo &info)
{
    BSTR accessKey = NULL;

    m_pElement->get_CachedAccessKey(&accessKey);

    if (!accessKey)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(accessKey));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAriaProperties(const Napi::CallbackInfo &info)
{
    BSTR ariaProperties = NULL;

    m_pElement->get_CachedAriaProperties(&ariaProperties);

    if (!ariaProperties)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaProperties));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAriaRole(const Napi::CallbackInfo &info)
{
    BSTR ariaRole = NULL;

    m_pElement->get_CachedAriaRole(&ariaRole);

    if (!ariaRole)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaRole));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAutomationId(const Napi::CallbackInfo &info)
{
    BSTR automationId = NULL;

    m_pElement->get_CachedAutomationId(&automationId);

    if (!automationId)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(automationId));
}

Napi::Value IUIAutomationElementWrapper::GetCachedBoundingRectangle(const Napi::CallbackInfo &info)
{
    RECT boundingRectangle;

    auto hResult = m_pElement->get_CachedBoundingRectangle(&boundingRectangle);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    auto boundingRectangleWrapper = new RectWrapper(info, &boundingRectangle);

    return boundingRectangleWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCachedClassName(const Napi::CallbackInfo &info)
{
    BSTR className = NULL;

    m_pElement->get_CachedClassName(&className);

    if (!className)
    {
        return info.Env()
            .Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(className));
}

Napi::Value IUIAutomationElementWrapper::GetCachedControllerFor(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *controllerFor;
    auto hResult = m_pElement->get_CachedControllerFor(&controllerFor);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    auto controllerForWrapper = new IUIAutomationElementArrayWrapper(info, controllerFor);

    return controllerForWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCachedControlType(const Napi::CallbackInfo &info)
{
    CONTROLTYPEID controlTypeId = NULL;

    auto hResult = m_pElement->get_CachedControlType(&controlTypeId);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    return Napi::Number::New(info.Env(), controlTypeId);
}

Napi::Value IUIAutomationElementWrapper::GetCachedCulture(const Napi::CallbackInfo &info)
{
    int culture;

    auto hResult = m_pElement->get_CachedCulture(&culture);

    if (FAILED(hResult))
    {
        info.Env()
            .Null();
    }

    return Napi::Number::New(info.Env(), culture);
}

Napi::Value IUIAutomationElementWrapper::GetCachedDescribedBy(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *describedBy;

    auto hResult = m_pElement->get_CachedDescribedBy(&describedBy);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    auto describedByWrapper = new IUIAutomationElementArrayWrapper(info, describedBy);

    return describedByWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCachedFlowsTo(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *flowsTo;

    auto hResult = m_pElement->get_CachedFlowsTo(&flowsTo);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    auto flowsToWrapper = new IUIAutomationElementArrayWrapper(info, flowsTo);

    return flowsToWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCachedFrameworkId(const Napi::CallbackInfo &info)
{
    BSTR frameworkId = NULL;

    m_pElement->get_CachedFrameworkId(&frameworkId);

    if (!frameworkId)
    {
        return info.Env()
            .Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(frameworkId));
}

Napi::Value IUIAutomationElementWrapper::GetCachedHasKeyboardFocus(const Napi::CallbackInfo &info)
{
    BOOL hasKeyboardFocus = NULL;
    auto hResult = m_pElement->get_CachedHasKeyboardFocus(&hasKeyboardFocus);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    return Napi::Boolean::New(info.Env(), hasKeyboardFocus);
}

Napi::Value IUIAutomationElementWrapper::GetCachedHelpText(const Napi::CallbackInfo &info)
{
    BSTR helpText = NULL;

    m_pElement->get_CachedHelpText(&helpText);

    if (!helpText)
    {
        return info.Env()
            .Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(helpText));
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsContentElement(const Napi::CallbackInfo &info)
{
    BOOL isContentElement = NULL;

    auto hResult = m_pElement->get_CachedIsContentElement(&isContentElement);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    return Napi::Boolean::New(info.Env(), isContentElement);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsControlElement(const Napi::CallbackInfo &info)
{
    BOOL isControlElement = NULL;

    auto hResult = m_pElement->get_CachedIsControlElement(&isControlElement);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }
    return Napi::Boolean::New(info.Env(), isControlElement);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsDataValidForForm(const Napi::CallbackInfo &info)
{
    BOOL isDataValidForForm = NULL;

    auto hResult = m_pElement->get_CachedIsDataValidForForm(&isDataValidForForm);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    return Napi::Boolean::New(info.Env(), isDataValidForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsEnabled(const Napi::CallbackInfo &info)
{
    BOOL isEnabled = NULL;

    auto hResult = m_pElement->get_CachedIsEnabled(&isEnabled);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    return Napi::Boolean::New(info.Env(), isEnabled);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsKeyboardFocusable(const Napi::CallbackInfo &info)
{
    BOOL isKeyboardFocusable = NULL;

    auto hResult = m_pElement->get_CachedIsKeyboardFocusable(&isKeyboardFocusable);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    return Napi::Boolean::New(info.Env(), isKeyboardFocusable);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsOffscreen(const Napi::CallbackInfo &info)
{
    BOOL isOffscreen = NULL;

    auto hResult = m_pElement->get_CachedIsOffscreen(&isOffscreen);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    return Napi::Boolean::New(info.Env(), isOffscreen);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsPassword(const Napi::CallbackInfo &info)
{
    BOOL isPassword = NULL;

    auto hResult = m_pElement->get_CachedIsPassword(&isPassword);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    return Napi::Boolean::New(info.Env(), isPassword);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsRequiredForForm(const Napi::CallbackInfo &info)
{
    BOOL isRequiredForForm = NULL;

    auto hResult = m_pElement->get_CachedIsRequiredForForm(&isRequiredForForm);

    if (FAILED(hResult))
    {
        return info.Env().Null();
    }

    return Napi::Boolean::New(info.Env(), isRequiredForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCachedItemStatus(const Napi::CallbackInfo &info)
{
    BSTR itemStatus = NULL;

    m_pElement->get_CachedItemStatus(&itemStatus);

    if (!itemStatus)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemStatus));
}

Napi::Value IUIAutomationElementWrapper::GetCachedItemType(const Napi::CallbackInfo &info)
{
    BSTR itemType = NULL;

    m_pElement->get_CachedItemType(&itemType);

    if (!itemType)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemType));
}

Napi::Value IUIAutomationElementWrapper::GetCachedLabeledBy(const Napi::CallbackInfo &info)
{
    IUIAutomationElement *element;

    m_pElement->get_CachedLabeledBy(&element);

    auto elementWrapper = new IUIAutomationElementWrapper(info, element);

    return elementWrapper->Value();
}

Napi::Value IUIAutomationElementWrapper::GetCachedLocalizedControlType(const Napi::CallbackInfo &info)
{
    BSTR localizedControlType = NULL;

    m_pElement->get_CachedLocalizedControlType(&localizedControlType);

    if (!localizedControlType)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(localizedControlType));
}

Napi::Value IUIAutomationElementWrapper::GetCachedNativeWindowHandle(const Napi::CallbackInfo &info)
{
    UIA_HWND nativeWindowHandle;

    auto hResult = m_pElement->get_CachedNativeWindowHandle(&nativeWindowHandle);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }
    throw E_NOTIMPL;

    // return Napi::External::New(info.Env(), nativeWindowHandle);
}

Napi::Value IUIAutomationElementWrapper::GetCachedOrientation(const Napi::CallbackInfo &info)
{
    OrientationType orientationType;

    auto hResult = m_pElement->get_CachedOrientation(&orientationType);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    return Napi::Number::New(info.Env(), orientationType);
}

Napi::Value IUIAutomationElementWrapper::GetCachedProcessId(const Napi::CallbackInfo &info)
{
    int processId;

    auto hResult = m_pElement->get_CachedProcessId(&processId);

    if (FAILED(hResult))
    {
        return info.Env()
            .Null();
    }

    return Napi::Number::New(info.Env(), processId);
}

Napi::Value IUIAutomationElementWrapper::GetCachedProviderDescription(const Napi::CallbackInfo &info)
{
    BSTR providerDescription = NULL;

    m_pElement->get_CachedProviderDescription(&providerDescription);

    if (!providerDescription)
    {
        return info.Env()
            .Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(providerDescription));
}

Napi::Object IUIAutomationElementWrapper::Init(Napi::Env env, Napi::Object exports)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationElementWrapper::FindFirst>("findFirst"),

        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentName>("currentName"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentAcceleratorKey>("currentAcceleratorKey"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentAccessKey>("currentAccessKey"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentAriaProperties>("currentAriaProperties"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentAriaRole>("currentAriaRole"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentAutomationId>("currentAutomationId"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentBoundingRectangle>("currentBoundingRectangle"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentClassName>("currentClassName"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentControllerFor>("currentControllerFor"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentControlType>("currentControlType"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentCulture>("currentCulture"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentDescribedBy>("currentDescribedBy"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentFlowsTo>("currentFlowsTo"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentFrameworkId>("currentFrameworkId"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentHasKeyboardFocus>("currentHasKeyboardFocus"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentHelpText>("currentHelpText"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsContentElement>("currentIsContentElement"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsControlElement>("currentIsControlElement"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsDataValidForForm>("currentIsDataValidForForm"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsEnabled>("currentIsEnabled"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsKeyboardFocusable>("currentIsKeyboardFocusable"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsOffscreen>("currentIsOffscreen"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsPassword>("currentIsPassword"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentIsRequiredForForm>("currentIsRequiredForForm"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentItemStatus>("currentItemStatus"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentItemType>("currentItemType"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentLabeledBy>("currentLabeledBy"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentLocalizedControlType>("currentLocalizedControlType"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentNativeWindowHandle>("currentNativeWindowHandle"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentOrientation>("currentOrientation"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentProcessId>("currentProcessId"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCurrentProviderDescription>("currentProviderDescription"),

        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedName>("cachedName"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedAcceleratorKey>("cachedAcceleratorKey"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedAccessKey>("cachedAccessKey"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedAriaProperties>("cachedAriaProperties"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedAriaRole>("cachedAriaRole"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedAutomationId>("cachedAutomationId"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedBoundingRectangle>("cachedBoundingRectangle"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedClassName>("cachedClassName"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedControllerFor>("cachedControllerFor"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedControlType>("cachedControlType"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedCulture>("cachedCulture"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedDescribedBy>("cachedDescribedBy"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedFlowsTo>("cachedFlowsTo"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedFrameworkId>("cachedFrameworkId"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedHasKeyboardFocus>("cachedHasKeyboardFocus"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedHelpText>("cachedHelpText"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsContentElement>("cachedIsContentElement"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsControlElement>("cachedIsControlElement"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsDataValidForForm>("cachedIsDataValidForForm"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsEnabled>("cachedIsEnabled"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsKeyboardFocusable>("cachedIsKeyboardFocusable"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsOffscreen>("cachedIsOffscreen"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsPassword>("cachedIsPassword"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedIsRequiredForForm>("cachedIsRequiredForForm"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedItemStatus>("cachedItemStatus"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedItemType>("cachedItemType"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedLabeledBy>("cachedLabeledBy"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedLocalizedControlType>("cachedLocalizedControlType"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedNativeWindowHandle>("cachedNativeWindowHandle"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedOrientation>("cachedOrientation"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedProcessId>("cachedProcessId"),
        InstanceAccessor<&IUIAutomationElementWrapper::GetCachedProviderDescription>("cachedProviderDescription"),
    };

    Napi::Function function = DefineClass(env, "IUIAutomationElement", classDefinition);

    Napi::FunctionReference *constructor = new Napi::FunctionReference();

    *constructor = Napi::Persistent(function);

    env.SetInstanceData<Napi::FunctionReference>(constructor);

    return exports;
}

Napi::Value IUIAutomationElementWrapper::FindFirst(const Napi::CallbackInfo &info)
{
    auto treeScope = static_cast<TreeScope>(info[0].ToNumber().Int32Value());

    auto pConditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[1].ToObject());

    IUIAutomationElement *pFoundElement = NULL;
    HRESULT hr = m_pElement->FindFirst(treeScope, pConditionWrapper->m_pCondition, &pFoundElement);

    auto foundElementWrapper = new IUIAutomationElementWrapper(info, pFoundElement);

    return foundElementWrapper->Value();
}