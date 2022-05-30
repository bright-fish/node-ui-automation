#include "Functions.h"
#include "../Shared.h"
#include "../patterns/Patterns.h"

void HandleResult(const Napi::CallbackInfo &info, HRESULT hResult)
{
    if (FAILED(hResult))
    {
        auto error = _com_error(hResult);

        throw Napi::Error::New(info.Env(), error.ErrorMessage());
    }
}

VARIANT ToVariant(Napi::Env env, Napi::Value local)
{
    VARIANT variant;

    if (local.IsUndefined())
    {
        variant.vt = VT_EMPTY;
    }
    else if (local.IsNull())
    {
        variant.vt = VT_EMPTY;
    }
    else if (local.IsNumber())
    {
        variant.vt = VT_I4;
        variant.intVal = local.ToNumber().Int32Value();
    }
    else if (local.IsString())
    {
        variant.vt = VT_BSTR;
        variant.bstrVal = _com_util::ConvertStringToBSTR(local.ToString().Utf8Value().c_str());
    }
    else if (local.IsBoolean())
    {
        variant.vt = VT_BOOL;
        variant.boolVal = local.ToBoolean();
    }
    else if (local.IsArray())
    {
        auto array = local.As<Napi::Array>();

        variant.vt = VT_ARRAY | VT_I4;
        variant.parray = SafeArrayCreateVector(VT_I4, 0, array.Length());

        for (long i = 0; i < array.Length(); i++)
        {
            auto element = array.Get(i);

            auto value = element.ToNumber().Int32Value();

            SafeArrayPutElement(variant.parray, &i, &value);
        }
    }
    else
    {
        throw Napi::Error::New(env, "Unsupported variant data type.");
    }

    return variant;
}

Napi::Value FromVariant(Napi::Env env, VARIANT variant)
{
    switch (variant.vt)
    {
    case VT_NULL:
        return env.Null();
    case VT_I4:
        return Napi::Number::New(env, variant.iVal);
    case VT_EMPTY:
        return env.Null();
    case VT_BSTR:
        return Napi::String::New(env, _com_util::ConvertBSTRToString(variant.bstrVal));
    default:
        throw std::domain_error("Unsupported variant type.");
    }
}

Napi::Value GetPatternProviderByPatternId(const Napi::CallbackInfo &info, IUnknown *pProvider, PATTERNID patternId)
{
    switch (patternId)
    {
    case UIA_AnnotationPatternId:
        return IUIAutomationAnnotationPatternWrapper::New(info.Env(), static_cast<IUIAutomationAnnotationPattern *>(pProvider));
    case UIA_DockPatternId:
        return IUIAutomationDockPatternWrapper::New(info.Env(), static_cast<IUIAutomationDockPattern *>(pProvider));
    case UIA_DragPatternId:
        return IUIAutomationDragPatternWrapper::New(info.Env(), static_cast<IUIAutomationDragPattern *>(pProvider));
    case UIA_DropTargetPatternId:
        return IUIAutomationDropTargetPatternWrapper::New(info.Env(), static_cast<IUIAutomationDropTargetPattern *>(pProvider));
    case UIA_ExpandCollapsePatternId:
        return IUIAutomationExpandCollapsePatternWrapper::New(info.Env(), static_cast<IUIAutomationExpandCollapsePattern *>(pProvider));
    case UIA_GridItemPatternId:
        return IUIAutomationGridItemPatternWrapper::New(info.Env(), static_cast<IUIAutomationGridItemPattern *>(pProvider));
    case UIA_GridPatternId:
        return IUIAutomationGridPatternWrapper::New(info.Env(), static_cast<IUIAutomationGridPattern *>(pProvider));
    case UIA_InvokePatternId:
        return IUIAutomationInvokePatternWrapper::New(info.Env(), static_cast<IUIAutomationInvokePattern *>(pProvider));
    case UIA_ItemContainerPatternId:
        return IUIAutomationItemContainerPatternWrapper::New(info.Env(), static_cast<IUIAutomationItemContainerPattern *>(pProvider));
    case UIA_LegacyIAccessiblePatternId:
        return IUIAutomationLegacyIAccessiblePatternWrapper::New(info.Env(), static_cast<IUIAutomationLegacyIAccessiblePattern *>(pProvider));
    case UIA_MultipleViewPatternId:
        return IUIAutomationMultipleViewPatternWrapper::New(info.Env(), static_cast<IUIAutomationMultipleViewPattern *>(pProvider));
    case UIA_ObjectModelPatternId:
        // skipping:  return IUIAutomationObjectModelPatternWrapper::New(info.Env(), static_cast<IUIAutomationObjectModelPattern *>(pProvider));
        throw Napi::Error::New(info.Env(), "Pattern not implemented.");
    case UIA_RangeValuePatternId:
        return IUIAutomationRangeValuePatternWrapper::New(info.Env(), static_cast<IUIAutomationRangeValuePattern *>(pProvider));
    case UIA_ScrollItemPatternId:
        return IUIAutomationScrollItemPatternWrapper::New(info.Env(), static_cast<IUIAutomationScrollItemPattern *>(pProvider));
    case UIA_ScrollPatternId:
        return IUIAutomationScrollPatternWrapper::New(info.Env(), static_cast<IUIAutomationScrollPattern *>(pProvider));
    case UIA_SelectionItemPatternId:
        return IUIAutomationSelectionItemPatternWrapper::New(info.Env(), static_cast<IUIAutomationSelectionItemPattern *>(pProvider));
    case UIA_SelectionPatternId:
        return IUIAutomationSelectionPatternWrapper::New(info.Env(), static_cast<IUIAutomationSelectionPattern *>(pProvider));
    case UIA_SelectionPattern2Id:
        return IUIAutomationSelectionPattern2Wrapper::New(info.Env(), static_cast<IUIAutomationSelectionPattern2 *>(pProvider));
    case UIA_SpreadsheetItemPatternId:
        return IUIAutomationSpreadsheetItemPatternWrapper::New(info.Env(), static_cast<IUIAutomationSpreadsheetItemPattern *>(pProvider));
    case UIA_SpreadsheetPatternId:
        return IUIAutomationSpreadsheetPatternWrapper::New(info.Env(), static_cast<IUIAutomationSpreadsheetPattern *>(pProvider));
    case UIA_StylesPatternId:
        return IUIAutomationStylesPatternWrapper::New(info.Env(), static_cast<IUIAutomationStylesPattern *>(pProvider));
    case UIA_SynchronizedInputPatternId:
        return IUIAutomationSynchronizedInputPatternWrapper::New(info.Env(), static_cast<IUIAutomationSynchronizedInputPattern *>(pProvider));
    case UIA_TableItemPatternId:
        return IUIAutomationTableItemPatternWrapper::New(info.Env(), static_cast<IUIAutomationTableItemPattern *>(pProvider));
    case UIA_TablePatternId:
        return IUIAutomationTablePatternWrapper::New(info.Env(), static_cast<IUIAutomationTablePattern *>(pProvider));
    case UIA_TextChildPatternId:
        return IUIAutomationTextChildPatternWrapper::New(info.Env(), static_cast<IUIAutomationTextChildPattern *>(pProvider));
    case UIA_TextEditPatternId:
        return IUIAutomationTextEditPatternWrapper::New(info.Env(), static_cast<IUIAutomationTextEditPattern *>(pProvider));
    case UIA_TextPatternId:
        return IUIAutomationTextPatternWrapper::New(info.Env(), static_cast<IUIAutomationTextPattern *>(pProvider));
    case UIA_TextPattern2Id:
        return IUIAutomationTextPattern2Wrapper::New(info.Env(), static_cast<IUIAutomationTextPattern2 *>(pProvider));
    case UIA_TogglePatternId:
        return IUIAutomationTogglePatternWrapper::New(info.Env(), static_cast<IUIAutomationTogglePattern *>(pProvider));
    case UIA_TransformPatternId:
        return IUIAutomationTransformPatternWrapper::New(info.Env(), static_cast<IUIAutomationTransformPattern *>(pProvider));
    case UIA_TransformPattern2Id:
        return IUIAutomationTransformPattern2Wrapper::New(info.Env(), static_cast<IUIAutomationTransformPattern2 *>(pProvider));
    case UIA_ValuePatternId:
        return IUIAutomationValuePatternWrapper::New(info.Env(), static_cast<IUIAutomationValuePattern *>(pProvider));
    case UIA_VirtualizedItemPatternId:
        return IUIAutomationVirtualizedItemPatternWrapper::New(info.Env(), static_cast<IUIAutomationVirtualizedItemPattern *>(pProvider));
    case UIA_WindowPatternId:
        return IUIAutomationWindowPatternWrapper::New(info.Env(), static_cast<IUIAutomationWindowPattern *>(pProvider));
    case UIA_CustomNavigationPatternId:
        // return IUIAutomationCustomNavigationPatternWrapper::New(info.Env(), static_cast<IUIAutomationCustomNavigationPattern *>(pProvider));
        throw Napi::Error::New(info.Env(), "Pattern not implemented.");
    default:
        throw Napi::Error::New(info.Env(), "Pattern not implemented.");
    }
}