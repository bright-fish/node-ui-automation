#include "Functions.h"
#include "../Shared.h"
#include "../providers/Providers.h"

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
        variant = ATL::CComVariant(local.ToNumber().Int32Value());
    }
    else if (local.IsString())
    {
        variant = ATL::CComVariant(_com_util::ConvertStringToBSTR(local.ToString().Utf8Value().c_str()));
    }
    else if (local.IsBoolean())
    {
        variant = ATL::CComVariant(local.ToBoolean());
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
    case UIA_InvokePatternId:
        return IInvokeProviderWrapper::New(info.Env(), static_cast<IInvokeProvider *>(pProvider));
    case UIA_SelectionPatternId:
        // return ISelectionProviderWrapper::New(info.Env(), (ISelectionProvider *)pProvider);
    case UIA_ValuePatternId:
        // return IValueProviderWrapper::New(info.Env(), (IValueProvider *)pProvider);
    case UIA_RangeValuePatternId:
        // return IRangeValueProviderWrapper::New(info.Env(), (IRangeValueProvider *)pProvider);
    case UIA_ScrollPatternId:
        // return IScrollProviderWrapper::New(info.Env(), (IScrollProvider *)pProvider);
    case UIA_ExpandCollapsePatternId:
        // return IExpandCollapseProviderWrapper::New(info.Env(), (IExpandCollapseProvider *)pProvider);
    case UIA_GridPatternId:
        // return IGridProviderWrapper::New(info.Env(), (IGridProvider *)pProvider);
    case UIA_GridItemPatternId:
        // return IGridItemProviderWrapper::New(info.Env(), (IGridItemProvider *)pProvider);
    case UIA_MultipleViewPatternId:
        // return IMultipleViewProviderWrapper::New(info.Env(), (IMultipleViewProvider *)pProvider);
    case UIA_WindowPatternId:
        // return IWindowProviderWrapper::New(info.Env(), (IWindowProvider *)pProvider);
    case UIA_SelectionItemPatternId:
        // return ISelectionItemProviderWrapper::New(info.Env(), (ISelectionItemProvider *)pProvider);
    case UIA_DockPatternId:
        return IDockProviderWrapper::New(info.Env(), (IDockProvider *)pProvider);
    case UIA_TablePatternId:
        // return ITableProviderWrapper::New(info.Env(), (ITableProvider *)pProvider);
    case UIA_TableItemPatternId:
        // return ITableItemProviderWrapper::New(info.Env(), (ITableItemProvider *)pProvider);
    case UIA_TextPatternId:
        // return ITextProviderWrapper::New(info.Env(), (ITextProvider *)pProvider);
    case UIA_TogglePatternId:
        // return IToggleProviderWrapper::New(info.Env(), (IToggleProvider *)pProvider);
    case UIA_TransformPatternId:
        // return ITransformProviderWrapper::New(info.Env(), (ITransformProvider *)pProvider);
    case UIA_ScrollItemPatternId:
        // return IScrollItemProviderWrapper::New(info.Env(), (IScrollItemProvider *)pProvider);
    case UIA_LegacyIAccessiblePatternId:
        // return ILegacyIAccessibleProviderWrapper::New(info.Env(), (ILegacyIAccessibleProvider *)pProvider);
    case UIA_ItemContainerPatternId:
        // return IItemContainerProviderWrapper::New(info.Env(), (IItemContainerProvider *)pProvider);
    case UIA_VirtualizedItemPatternId:
        // return IVirtualizedItemProviderWrapper::New(info.Env(), (IVirtualizedItemProvider *)pProvider);
    case UIA_SynchronizedInputPatternId:
        // return ISynchronizedInputProviderWrapper::New(info.Env(), (ISynchronizedInputProvider *)pProvider);
    case UIA_ObjectModelPatternId:
        // return IObjectModelProviderWrapper::New(info.Env(), (IObjectModelProvider *)pProvider);
    case UIA_AnnotationPatternId:
        return IAnnotationProviderWrapper::New(info.Env(), (IAnnotationProvider *)pProvider);
    case UIA_TextPattern2Id:
        // return ITextProvider2Wrapper::New(info.Env(), (ITextProvider2 *)pProvider);
    case UIA_StylesPatternId:
        // return IStylesProviderWrapper::New(info.Env(), (IStylesProvider *)pProvider);
    case UIA_SpreadsheetPatternId:
        // return ISpreadsheetProviderWrapper::New(info.Env(), (ISpreadsheetProvider *)pProvider);
    case UIA_SpreadsheetItemPatternId:
        // return ISpreadsheetItemProviderWrapper::New(info.Env(), (ISpreadsheetItemProvider *)pProvider);
    case UIA_TransformPattern2Id:
        // return ITransformProvider2Wrapper::New(info.Env(), (ITransformProvider2 *)pProvider);
    case UIA_TextChildPatternId:
        // return ITextChildProviderWrapper::New(info.Env(), (ITextChildProvider *)pProvider);
    case UIA_DragPatternId:
        // return IDragProviderWrapper::New(info.Env(), (IDragProvider *)pProvider);
    case UIA_DropTargetPatternId:
        // return IDropTargetProviderWrapper::New(info.Env(), (IDropTargetProvider *)pProvider);
    case UIA_TextEditPatternId:
        // return ITextEditProviderWrapper::New(info.Env(), (ITextEditProvider *)pProvider);
    case UIA_CustomNavigationPatternId:
        // return ICustomNavigationProviderWrapper::New(info.Env(), (ICustomNavigationProvider *)pProvider);
    case UIA_SelectionPattern2Id:
        // return ISelectionProvider2Wrapper::New(info.Env(), (ISelectionProvider2 *)pProvider);
    default:
        throw Napi::Error::New(info.Env(), "Pattern not implemented.");
    }
}