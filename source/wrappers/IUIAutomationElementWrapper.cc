#include "Wrappers.h"
#include "../AutomationAddon.h"
#include "../utilities/Functions.h"
#include "../patterns/Patterns.h"
#include "../utilities/ComAutoPointer.h"
#include "../utilities/AutoSafeArray.h"

Napi::FunctionReference *IUIAutomationElementWrapper::Initialize(Napi::Env env)
{
    auto classDefinition = {
        InstanceMethod<&IUIAutomationElementWrapper::BuildUpdatedCache>("buildUpdatedCache"),
        InstanceMethod<&IUIAutomationElementWrapper::FindAll>("findAll"),
        InstanceMethod<&IUIAutomationElementWrapper::FindAllBuildCache>("findAllBuildCache"),
        InstanceMethod<&IUIAutomationElementWrapper::FindFirst>("findFirst"),
        InstanceMethod<&IUIAutomationElementWrapper::FindFirstBuildCache>("findFirstBuildCache"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCachedChildren>("getCachedChildren"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCachedParent>("getCachedParent"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCachedPattern>("getCachedPattern"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCachedPropertyValue>("getCachedPropertyValue"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCachedPropertyValueEx>("getCachedPropertyValueEx"),
        InstanceMethod<&IUIAutomationElementWrapper::GetClickablePoint>("getClickablePoint"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCurrentPattern>("getCurrentPattern"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCurrentPropertyValue>("getCurrentPropertyValue"),
        InstanceMethod<&IUIAutomationElementWrapper::GetCurrentPropertyValueEx>("getCurrentPropertyValueEx"),
        InstanceMethod<&IUIAutomationElementWrapper::GetRuntimeId>("getRuntimeId"),

        InstanceMethod<&IUIAutomationElementWrapper::SetFocus>("setFocus"),

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

    Napi::FunctionReference *functionReference = new Napi::FunctionReference();

    *functionReference = Napi::Persistent(function);

    return functionReference;
}

Napi::Value IUIAutomationElementWrapper::New(Napi::Env env, ComAutoPointer<IUIAutomationElement> pElement)
{
    if (pElement == NULL)
    {
        return env.Null();
    }

    auto automationAddon = env.GetInstanceData<AutomationAddon>();

    return automationAddon->IUIAutomationElementWrapperConstructor->New({Napi::External<IUIAutomationElement>::New(env, pElement)});
}

IUIAutomationElementWrapper::IUIAutomationElementWrapper(const Napi::CallbackInfo &info) : Napi::ObjectWrap<IUIAutomationElementWrapper>(info)
{
    if (info.Length() != 1)
    {
        throw Napi::TypeError::New(info.Env(), "IUIAutomationElement constructor is missing parameters.");
    }

    m_pElement = info[0].As<Napi::External<IUIAutomationElement>>().Data();
}

IUIAutomationElementWrapper::~IUIAutomationElementWrapper()
{
    m_pElement.Release();
}

Napi::Value IUIAutomationElementWrapper::BuildUpdatedCache(const Napi::CallbackInfo &info)
{
    auto cacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[0].ToObject());

    ComAutoPointer<IUIAutomationElement> pElement = NULL;
    auto hResult = m_pElement->BuildUpdatedCache(cacheRequestWrapper->m_pCacheRequest, &pElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pElement);
}

Napi::Value IUIAutomationElementWrapper::FindAll(const Napi::CallbackInfo &info)
{
    auto treeScope = static_cast<TreeScope>(info[0].ToNumber().Int32Value());

    auto pConditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[1].ToObject());

    ComAutoPointer<IUIAutomationElementArray> pFoundElements = NULL;
    HRESULT hResult = m_pElement->FindAll(treeScope, pConditionWrapper->m_pCondition, &pFoundElements);

    HandleResult(info, hResult);

    int iLength = 0;
    hResult = pFoundElements->get_Length(&iLength);

    HandleResult(info, hResult);

    Napi::Array output = Napi::Array::New(info.Env());

    for (int i = 0; i < iLength; i++)
    {
        ComAutoPointer<IUIAutomationElement> pAutomationElement = NULL;

        hResult = pFoundElements->GetElement(i, &pAutomationElement);

        HandleResult(info, hResult);

        auto elementWrapper = IUIAutomationElementWrapper::New(info.Env(), pAutomationElement);

        output.Set(i, elementWrapper);
    }

    return output;
}

Napi::Value IUIAutomationElementWrapper::FindAllBuildCache(const Napi::CallbackInfo &info)
{
    auto treeScope = static_cast<TreeScope>(info[0].ToNumber().Int32Value());

    auto pConditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[1].ToObject());

    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[2].ToObject());

    ComAutoPointer<IUIAutomationElementArray> pFoundElements;
    HRESULT hResult = m_pElement->FindAllBuildCache(treeScope, pConditionWrapper->m_pCondition, pCacheRequestWrapper->m_pCacheRequest, &pFoundElements);

    HandleResult(info, hResult);

    int iLength = 0;
    hResult = pFoundElements->get_Length(&iLength);

    HandleResult(info, hResult);

    Napi::Array output = Napi::Array::New(info.Env());

    for (int i = 0; i < iLength; i++)
    {
        ComAutoPointer<IUIAutomationElement> pAutomationElement = NULL;

        hResult = pFoundElements->GetElement(i, &pAutomationElement);

        HandleResult(info, hResult);

        auto elementWrapper = IUIAutomationElementWrapper::New(info.Env(), pAutomationElement);

        output.Set(i, elementWrapper);
    }

    return output;
}

Napi::Value IUIAutomationElementWrapper::FindFirst(const Napi::CallbackInfo &info)
{
    auto treeScope = static_cast<TreeScope>(info[0].ToNumber().Int32Value());

    auto pConditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[1].ToObject());

    ComAutoPointer<IUIAutomationElement> pFoundElement = NULL;
    HRESULT hResult = m_pElement->FindFirst(treeScope, pConditionWrapper->m_pCondition, &pFoundElement);

    HandleResult(info, hResult);

    auto foundElementWrapper = IUIAutomationElementWrapper::New(info.Env(), pFoundElement);

    return foundElementWrapper;
}

Napi::Value IUIAutomationElementWrapper::FindFirstBuildCache(const Napi::CallbackInfo &info)
{
    auto treeScope = static_cast<TreeScope>(info[0].ToNumber().Uint32Value());

    auto pConditionWrapper = Napi::ObjectWrap<IUIAutomationConditionWrapper>::Unwrap(info[1].ToObject());

    auto pCacheRequestWrapper = Napi::ObjectWrap<IUIAutomationCacheRequestWrapper>::Unwrap(info[2].ToObject());

    ComAutoPointer<IUIAutomationElement> pFoundElement = NULL;
    HRESULT hResult = m_pElement->FindFirstBuildCache(treeScope, pConditionWrapper->m_pCondition, pCacheRequestWrapper->m_pCacheRequest, &pFoundElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pFoundElement);
}

Napi::Value IUIAutomationElementWrapper::GetCachedChildren(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElementArray> pElementArray = NULL;
    HRESULT hResult = m_pElement->GetCachedChildren(&pElementArray);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), pElementArray);
}

Napi::Value IUIAutomationElementWrapper::GetCachedPattern(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUnknown> pProvider = NULL;

    auto patternId = static_cast<PATTERNID>(info[0].ToNumber().Int32Value());

    auto hResult = m_pElement->GetCachedPattern(patternId, &pProvider);

    HandleResult(info, hResult);

    return GetPatternProviderByPatternId(info, pProvider, patternId);
}

Napi::Value IUIAutomationElementWrapper::GetCachedParent(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElement> pElement = NULL;
    HRESULT hResult = m_pElement->GetCachedParent(&pElement);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), pElement);
}

Napi::Value IUIAutomationElementWrapper::GetCachedPropertyValue(const Napi::CallbackInfo &info)
{
    auto propertyId = static_cast<PROPERTYID>(info[0].ToNumber().Int32Value());

    VARIANT variant;
    HRESULT hResult = m_pElement->GetCachedPropertyValue(propertyId, &variant);

    HandleResult(info, hResult);

    return FromVariant(info.Env(), variant);
}

Napi::Value IUIAutomationElementWrapper::GetCachedPropertyValueEx(const Napi::CallbackInfo &info)
{
    auto propertyId = static_cast<PROPERTYID>(info[0].ToNumber().Int32Value());

    auto ignoreDefaultValue = info[1].ToBoolean().Value();

    VARIANT variant;
    HRESULT hResult = m_pElement->GetCachedPropertyValueEx(propertyId, ignoreDefaultValue, &variant);

    HandleResult(info, hResult);

    return FromVariant(info.Env(), variant);
}

Napi::Value IUIAutomationElementWrapper::GetClickablePoint(const Napi::CallbackInfo &info)
{
    POINT point;
    BOOL gotClickable;
    HRESULT hResult = m_pElement->GetClickablePoint(&point, &gotClickable);

    HandleResult(info, hResult);

    if (!gotClickable)
    {
        return info.Env().Null();
    }

    auto pointObject = Napi::Object::New(info.Env());

    pointObject.Set("x", point.x);
    pointObject.Set("y", point.y);

    return pointObject;
}

Napi::Value IUIAutomationElementWrapper::GetCurrentPropertyValue(const Napi::CallbackInfo &info)
{
    auto propertyId = static_cast<PROPERTYID>(info[0].ToNumber().Uint32Value());

    VARIANT variant;
    HRESULT hResult = m_pElement->GetCurrentPropertyValue(propertyId, &variant);

    HandleResult(info, hResult);

    return FromVariant(info.Env(), variant);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentPropertyValueEx(const Napi::CallbackInfo &info)
{
    auto propertyId = static_cast<PROPERTYID>(info[0].ToNumber().Uint32Value());

    auto ignoreDefaultValue = info[1].ToBoolean().Value();

    VARIANT variant;
    HRESULT hResult = m_pElement->GetCurrentPropertyValueEx(propertyId, ignoreDefaultValue, &variant);

    HandleResult(info, hResult);

    return FromVariant(info.Env(), variant);
}

Napi::Value IUIAutomationElementWrapper::GetRuntimeId(const Napi::CallbackInfo &info)
{
    AutoSafeArray<int32_t> pSafeArray;
    auto hResult = m_pElement->GetRuntimeId(&pSafeArray.m_psa);

    HandleResult(info, hResult);

    auto array = Napi::Array::New(info.Env());

    for (unsigned long i = 0; i < pSafeArray.GetCount(); i++)
    {
        auto number = Napi::Number::New(info.Env(), pSafeArray.GetAt(i));

        array.Set(i, number);
    }

    return array;
}

void IUIAutomationElementWrapper::SetFocus(const Napi::CallbackInfo &info)
{
    HRESULT hResult = m_pElement->SetFocus();

    HandleResult(info, hResult);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentName(const Napi::CallbackInfo &info)
{
    BSTR name = NULL;

    auto hResult = m_pElement->get_CurrentName(&name);

    HandleResult(info, hResult);

    if (!name)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(name));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAcceleratorKey(const Napi::CallbackInfo &info)
{
    BSTR acceloratorKey = NULL;

    auto hResult = m_pElement->get_CurrentAcceleratorKey(&acceloratorKey);

    HandleResult(info, hResult);

    if (!acceloratorKey)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(acceloratorKey));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAccessKey(const Napi::CallbackInfo &info)
{
    BSTR accessKey = NULL;

    auto hResult = m_pElement->get_CurrentAccessKey(&accessKey);

    HandleResult(info, hResult);

    if (!accessKey)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(accessKey));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAriaProperties(const Napi::CallbackInfo &info)
{
    BSTR ariaProperties = NULL;

    auto hResult = m_pElement->get_CurrentAriaProperties(&ariaProperties);

    HandleResult(info, hResult);

    if (!ariaProperties)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaProperties));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAriaRole(const Napi::CallbackInfo &info)
{
    BSTR ariaRole = NULL;

    auto hResult = m_pElement->get_CurrentAriaRole(&ariaRole);

    HandleResult(info, hResult);

    if (!ariaRole)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaRole));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentAutomationId(const Napi::CallbackInfo &info)
{
    BSTR automationId = NULL;

    auto hResult = m_pElement->get_CurrentAutomationId(&automationId);

    HandleResult(info, hResult);

    if (!automationId)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(automationId));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentBoundingRectangle(const Napi::CallbackInfo &info)
{
    RECT boundingRectangle;

    auto hResult = m_pElement->get_CurrentBoundingRectangle(&boundingRectangle);

    HandleResult(info, hResult);

    auto output = Napi::Object::New(info.Env());

    output.Set("top", boundingRectangle.top);
    output.Set("right", boundingRectangle.right);
    output.Set("bottom", boundingRectangle.bottom);
    output.Set("left", boundingRectangle.left);

    return output;
}

Napi::Value IUIAutomationElementWrapper::GetCurrentClassName(const Napi::CallbackInfo &info)
{
    BSTR className = NULL;

    auto hResult = m_pElement->get_CurrentClassName(&className);

    HandleResult(info, hResult);

    if (!className)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(className));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentControllerFor(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *controllerFor;
    auto hResult = m_pElement->get_CurrentControllerFor(&controllerFor);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), controllerFor);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentControlType(const Napi::CallbackInfo &info)
{
    CONTROLTYPEID controlTypeId = NULL;

    auto hResult = m_pElement->get_CurrentControlType(&controlTypeId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), controlTypeId);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentCulture(const Napi::CallbackInfo &info)
{
    int culture;

    auto hResult = m_pElement->get_CurrentCulture(&culture);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), culture);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentDescribedBy(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *describedBy;

    auto hResult = m_pElement->get_CurrentDescribedBy(&describedBy);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), describedBy);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentFlowsTo(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *flowsTo;

    auto hResult = m_pElement->get_CurrentFlowsTo(&flowsTo);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), flowsTo);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentFrameworkId(const Napi::CallbackInfo &info)
{
    BSTR frameworkId = NULL;

    auto hResult = m_pElement->get_CurrentFrameworkId(&frameworkId);

    HandleResult(info, hResult);

    if (!frameworkId)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(frameworkId));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentHasKeyboardFocus(const Napi::CallbackInfo &info)
{
    BOOL hasKeyboardFocus = NULL;
    auto hResult = m_pElement->get_CurrentHasKeyboardFocus(&hasKeyboardFocus);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), hasKeyboardFocus);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentHelpText(const Napi::CallbackInfo &info)
{
    BSTR helpText = NULL;

    auto hResult = m_pElement->get_CurrentHelpText(&helpText);

    HandleResult(info, hResult);

    if (!helpText)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(helpText));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsContentElement(const Napi::CallbackInfo &info)
{
    BOOL isContentElement = NULL;

    auto hResult = m_pElement->get_CurrentIsContentElement(&isContentElement);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isContentElement);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsControlElement(const Napi::CallbackInfo &info)
{
    BOOL isControlElement = NULL;

    auto hResult = m_pElement->get_CurrentIsControlElement(&isControlElement);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isControlElement);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsDataValidForForm(const Napi::CallbackInfo &info)
{
    BOOL isDataValidForForm = NULL;

    auto hResult = m_pElement->get_CurrentIsDataValidForForm(&isDataValidForForm);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isDataValidForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsEnabled(const Napi::CallbackInfo &info)
{
    BOOL isEnabled = NULL;

    auto hResult = m_pElement->get_CurrentIsEnabled(&isEnabled);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isEnabled);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsKeyboardFocusable(const Napi::CallbackInfo &info)
{
    BOOL isKeyboardFocusable = NULL;

    auto hResult = m_pElement->get_CurrentIsKeyboardFocusable(&isKeyboardFocusable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isKeyboardFocusable);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsOffscreen(const Napi::CallbackInfo &info)
{
    BOOL isOffscreen = NULL;

    auto hResult = m_pElement->get_CurrentIsOffscreen(&isOffscreen);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isOffscreen);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsPassword(const Napi::CallbackInfo &info)
{
    BOOL isPassword = NULL;

    auto hResult = m_pElement->get_CurrentIsPassword(&isPassword);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isPassword);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentIsRequiredForForm(const Napi::CallbackInfo &info)
{
    BOOL isRequiredForForm = NULL;

    auto hResult = m_pElement->get_CurrentIsRequiredForForm(&isRequiredForForm);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isRequiredForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentItemStatus(const Napi::CallbackInfo &info)
{
    BSTR itemStatus = NULL;

    auto hResult = m_pElement->get_CurrentItemStatus(&itemStatus);

    HandleResult(info, hResult);

    if (!itemStatus)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemStatus));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentItemType(const Napi::CallbackInfo &info)
{
    BSTR itemType = NULL;

    auto hResult = m_pElement->get_CurrentItemType(&itemType);

    HandleResult(info, hResult);

    if (!itemType)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemType));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentLabeledBy(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElement> element = NULL;

    auto hResult = m_pElement->get_CurrentLabeledBy(&element);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), element);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentLocalizedControlType(const Napi::CallbackInfo &info)
{
    BSTR localizedControlType = NULL;

    auto hResult = m_pElement->get_CurrentLocalizedControlType(&localizedControlType);

    HandleResult(info, hResult);

    if (!localizedControlType)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(localizedControlType));
}

Napi::Value IUIAutomationElementWrapper::GetCurrentNativeWindowHandle(const Napi::CallbackInfo &info)
{
    UIA_HWND nativeWindowHandle;

    auto hResult = m_pElement->get_CurrentNativeWindowHandle(&nativeWindowHandle);

    HandleResult(info, hResult);

    throw E_NOTIMPL;
    // return Napi::External<UIA_HWND>::New(info.Env(), nativeWindowHandle);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentOrientation(const Napi::CallbackInfo &info)
{
    OrientationType orientationType;

    auto hResult = m_pElement->get_CurrentOrientation(&orientationType);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), orientationType);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentPattern(const Napi::CallbackInfo &info)
{
    IUnknown *pProvider;

    auto patternId = info[0].ToNumber().Int64Value();

    auto hResult = m_pElement->GetCurrentPattern(patternId, &pProvider);

    HandleResult(info, hResult);

    return GetPatternProviderByPatternId(info, pProvider, patternId);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentProcessId(const Napi::CallbackInfo &info)
{
    int processId;

    auto hResult = m_pElement->get_CurrentProcessId(&processId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), processId);
}

Napi::Value IUIAutomationElementWrapper::GetCurrentProviderDescription(const Napi::CallbackInfo &info)
{
    BSTR providerDescription = NULL;

    auto hResult = m_pElement->get_CurrentProviderDescription(&providerDescription);

    HandleResult(info, hResult);

    if (!providerDescription)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(providerDescription));
}

Napi::Value IUIAutomationElementWrapper::GetCachedName(const Napi::CallbackInfo &info)
{
    BSTR name = NULL;

    auto hResult = m_pElement->get_CachedName(&name);

    HandleResult(info, hResult);

    if (!name)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(name));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAcceleratorKey(const Napi::CallbackInfo &info)
{
    BSTR acceleratorKey = NULL;

    auto hResult = m_pElement->get_CachedAcceleratorKey(&acceleratorKey);

    HandleResult(info, hResult);

    if (!acceleratorKey)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(acceleratorKey));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAccessKey(const Napi::CallbackInfo &info)
{
    BSTR accessKey = NULL;

    auto hResult = m_pElement->get_CachedAccessKey(&accessKey);

    HandleResult(info, hResult);

    if (!accessKey)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(accessKey));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAriaProperties(const Napi::CallbackInfo &info)
{
    BSTR ariaProperties = NULL;

    auto hResult = m_pElement->get_CachedAriaProperties(&ariaProperties);

    HandleResult(info, hResult);

    if (!ariaProperties)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaProperties));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAriaRole(const Napi::CallbackInfo &info)
{
    BSTR ariaRole = NULL;

    auto hResult = m_pElement->get_CachedAriaRole(&ariaRole);

    HandleResult(info, hResult);

    if (!ariaRole)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(ariaRole));
}

Napi::Value IUIAutomationElementWrapper::GetCachedAutomationId(const Napi::CallbackInfo &info)
{
    BSTR automationId = NULL;

    auto hResult = m_pElement->get_CachedAutomationId(&automationId);

    HandleResult(info, hResult);

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

    HandleResult(info, hResult);

    auto output = Napi::Object::New(info.Env());

    output.Set("top", boundingRectangle.top);
    output.Set("right", boundingRectangle.right);
    output.Set("bottom", boundingRectangle.bottom);
    output.Set("left", boundingRectangle.left);

    return output;
}

Napi::Value IUIAutomationElementWrapper::GetCachedClassName(const Napi::CallbackInfo &info)
{
    BSTR className = NULL;

    auto hResult = m_pElement->get_CachedClassName(&className);

    HandleResult(info, hResult);

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

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), controllerFor);
}

Napi::Value IUIAutomationElementWrapper::GetCachedControlType(const Napi::CallbackInfo &info)
{
    CONTROLTYPEID controlTypeId = NULL;

    auto hResult = m_pElement->get_CachedControlType(&controlTypeId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), controlTypeId);
}

Napi::Value IUIAutomationElementWrapper::GetCachedCulture(const Napi::CallbackInfo &info)
{
    int culture;

    auto hResult = m_pElement->get_CachedCulture(&culture);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), culture);
}

Napi::Value IUIAutomationElementWrapper::GetCachedDescribedBy(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *describedBy;

    auto hResult = m_pElement->get_CachedDescribedBy(&describedBy);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), describedBy);
}

Napi::Value IUIAutomationElementWrapper::GetCachedFlowsTo(const Napi::CallbackInfo &info)
{
    IUIAutomationElementArray *flowsTo;

    auto hResult = m_pElement->get_CachedFlowsTo(&flowsTo);

    HandleResult(info, hResult);

    return IUIAutomationElementArrayWrapper::New(info.Env(), flowsTo);
}

Napi::Value IUIAutomationElementWrapper::GetCachedFrameworkId(const Napi::CallbackInfo &info)
{
    BSTR frameworkId = NULL;

    auto hResult = m_pElement->get_CachedFrameworkId(&frameworkId);

    HandleResult(info, hResult);

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

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), hasKeyboardFocus);
}

Napi::Value IUIAutomationElementWrapper::GetCachedHelpText(const Napi::CallbackInfo &info)
{
    BSTR helpText = NULL;

    auto hResult = m_pElement->get_CachedHelpText(&helpText);

    HandleResult(info, hResult);

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

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isContentElement);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsControlElement(const Napi::CallbackInfo &info)
{
    BOOL isControlElement = NULL;

    auto hResult = m_pElement->get_CachedIsControlElement(&isControlElement);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isControlElement);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsDataValidForForm(const Napi::CallbackInfo &info)
{
    BOOL isDataValidForForm = NULL;

    auto hResult = m_pElement->get_CachedIsDataValidForForm(&isDataValidForForm);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isDataValidForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsEnabled(const Napi::CallbackInfo &info)
{
    BOOL isEnabled = NULL;

    auto hResult = m_pElement->get_CachedIsEnabled(&isEnabled);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isEnabled);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsKeyboardFocusable(const Napi::CallbackInfo &info)
{
    BOOL isKeyboardFocusable = NULL;

    auto hResult = m_pElement->get_CachedIsKeyboardFocusable(&isKeyboardFocusable);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isKeyboardFocusable);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsOffscreen(const Napi::CallbackInfo &info)
{
    BOOL isOffscreen = NULL;

    auto hResult = m_pElement->get_CachedIsOffscreen(&isOffscreen);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isOffscreen);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsPassword(const Napi::CallbackInfo &info)
{
    BOOL isPassword = NULL;

    auto hResult = m_pElement->get_CachedIsPassword(&isPassword);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isPassword);
}

Napi::Value IUIAutomationElementWrapper::GetCachedIsRequiredForForm(const Napi::CallbackInfo &info)
{
    BOOL isRequiredForForm = NULL;

    auto hResult = m_pElement->get_CachedIsRequiredForForm(&isRequiredForForm);

    HandleResult(info, hResult);

    return Napi::Boolean::New(info.Env(), isRequiredForForm);
}

Napi::Value IUIAutomationElementWrapper::GetCachedItemStatus(const Napi::CallbackInfo &info)
{
    BSTR itemStatus = NULL;

    auto hResult = m_pElement->get_CachedItemStatus(&itemStatus);

    HandleResult(info, hResult);

    if (!itemStatus)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemStatus));
}

Napi::Value IUIAutomationElementWrapper::GetCachedItemType(const Napi::CallbackInfo &info)
{
    BSTR itemType = NULL;

    auto hResult = m_pElement->get_CachedItemType(&itemType);

    HandleResult(info, hResult);

    if (!itemType)
    {
        return info.Env().Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(itemType));
}

Napi::Value IUIAutomationElementWrapper::GetCachedLabeledBy(const Napi::CallbackInfo &info)
{
    ComAutoPointer<IUIAutomationElement> element = NULL;

    auto hResult = m_pElement->get_CachedLabeledBy(&element);

    HandleResult(info, hResult);

    return IUIAutomationElementWrapper::New(info.Env(), element);
}

Napi::Value IUIAutomationElementWrapper::GetCachedLocalizedControlType(const Napi::CallbackInfo &info)
{
    BSTR localizedControlType = NULL;

    auto hResult = m_pElement->get_CachedLocalizedControlType(&localizedControlType);

    HandleResult(info, hResult);

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

    HandleResult(info, hResult);

    return Napi::External<UIA_HWND>::New(info.Env(), &nativeWindowHandle);
}

Napi::Value IUIAutomationElementWrapper::GetCachedOrientation(const Napi::CallbackInfo &info)
{
    OrientationType orientationType;

    auto hResult = m_pElement->get_CachedOrientation(&orientationType);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), orientationType);
}

Napi::Value IUIAutomationElementWrapper::GetCachedProcessId(const Napi::CallbackInfo &info)
{
    int processId;

    auto hResult = m_pElement->get_CachedProcessId(&processId);

    HandleResult(info, hResult);

    return Napi::Number::New(info.Env(), processId);
}

Napi::Value IUIAutomationElementWrapper::GetCachedProviderDescription(const Napi::CallbackInfo &info)
{
    BSTR providerDescription = NULL;

    auto hResult = m_pElement->get_CachedProviderDescription(&providerDescription);

    HandleResult(info, hResult);

    if (!providerDescription)
    {
        return info.Env()
            .Null();
    }

    return Napi::String::New(info.Env(), _com_util::ConvertBSTRToString(providerDescription));
}
