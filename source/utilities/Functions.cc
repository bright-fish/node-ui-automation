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
    case UIA_AnnotationPatternId:
        return IAnnotationProviderWrapper::New(info.Env(), static_cast<IAnnotationProvider *>(pProvider));
    case UIA_DockPatternId:
        return IDockProviderWrapper::New(info.Env(), static_cast<IDockProvider *>(pProvider));
    case UIA_DragPatternId:
        return IDragProviderWrapper::New(info.Env(), static_cast<IDragProvider *>(pProvider));
    case UIA_DropTargetPatternId:
        return IDropTargetProviderWrapper::New(info.Env(), static_cast<IDropTargetProvider *>(pProvider));
    case UIA_ExpandCollapsePatternId:
        return IExpandCollapseProviderWrapper::New(info.Env(), static_cast<IExpandCollapseProvider *>(pProvider));
    case UIA_GridItemPatternId:
        return IGridItemProviderWrapper::New(info.Env(), static_cast<IGridItemProvider *>(pProvider));
    case UIA_GridPatternId:
        return IGridProviderWrapper::New(info.Env(), static_cast<IGridProvider *>(pProvider));
    case UIA_InvokePatternId:
        return IInvokeProviderWrapper::New(info.Env(), static_cast<IInvokeProvider *>(pProvider));
    case UIA_ItemContainerPatternId:
        // return IItemContainerProviderWrapper::New(info.Env(), static_cast<IItemContainerProvider *>(pProvider));
    case UIA_LegacyIAccessiblePatternId:
        // return ILegacyIAccessibleProviderWrapper::New(info.Env(), static_cast<ILegacyIAccessibleProvider *>(pProvider));
    case UIA_MultipleViewPatternId:
        // return IMultipleViewProviderWrapper::New(info.Env(), static_cast<IMultipleViewProvider *>(pProvider));
    case UIA_ObjectModelPatternId:
        // return IObjectModelProviderWrapper::New(info.Env(), static_cast<IObjectModelProvider *>(pProvider));
    case UIA_RangeValuePatternId:
        // return IRangeValueProviderWrapper::New(info.Env(), static_cast<IRangeValueProvider *>(pProvider));
    case UIA_ScrollItemPatternId:
        // return IScrollItemProviderWrapper::New(info.Env(), static_cast<IScrollItemProvider *>(pProvider));
    case UIA_ScrollPatternId:
        // return IScrollProviderWrapper::New(info.Env(), static_cast<IScrollProvider *>(pProvider));
    case UIA_SelectionItemPatternId:
        // return ISelectionItemProviderWrapper::New(info.Env(), static_cast<ISelectionItemProvider *>(pProvider));
    case UIA_SelectionPatternId:
        // return ISelectionProviderWrapper::New(info.Env(), static_cast<ISelectionProvider *>(pProvider));
    case UIA_SelectionPattern2Id:
        // return ISelectionProvider2Wrapper::New(info.Env(), (ISelectionProvider2 *)pProvider);
    case UIA_SpreadsheetItemPatternId:
        // return ISpreadsheetItemProviderWrapper::New(info.Env(), static_cast<ISpreadsheetItemProvider *>(pProvider));
    case UIA_SpreadsheetPatternId:
        // return ISpreadsheetProviderWrapper::New(info.Env(), static_cast<ISpreadsheetProvider *>(pProvider));
    case UIA_StylesPatternId:
        // return IStylesProviderWrapper::New(info.Env(), static_cast<IStylesProvider *>(pProvider));
    case UIA_SynchronizedInputPatternId:
        // return ISynchronizedInputProviderWrapper::New(info.Env(), static_cast<ISynchronizedInputProvider *>(pProvider));
    case UIA_TableItemPatternId:
        // return ITableItemProviderWrapper::New(info.Env(), static_cast<ITableItemProvider *>(pProvider));
    case UIA_TablePatternId:
        // return ITableProviderWrapper::New(info.Env(), static_cast<ITableProvider *>(pProvider));
    case UIA_TextChildPatternId:
        // return ITextChildProviderWrapper::New(info.Env(), static_cast<ITextChildProvider *>(pProvider));
    case UIA_TextEditPatternId:
        // return ITextEditProviderWrapper::New(info.Env(), static_cast<ITextEditProvider *>(pProvider));
    case UIA_TextPatternId:
        // return ITextProviderWrapper::New(info.Env(), static_cast<ITextProvider *>(pProvider));
    case UIA_TextPattern2Id:
        // return ITextProvider2Wrapper::New(info.Env(), (ITextProvider2 *)pProvider);
    case UIA_TogglePatternId:
        // return IToggleProviderWrapper::New(info.Env(), static_cast<IToggleProvider *>(pProvider));
    case UIA_TransformPatternId:
        // return ITransformProviderWrapper::New(info.Env(), static_cast<ITransformProvider *>(pProvider));
    case UIA_TransformPattern2Id:
        // return ITransformProvider2Wrapper::New(info.Env(), (ITransformProvider2 *)pProvider);
    case UIA_ValuePatternId:
        // return IValueProviderWrapper::New(info.Env(), static_cast<IValueProvider *>(pProvider));
    case UIA_VirtualizedItemPatternId:
        // return IVirtualizedItemProviderWrapper::New(info.Env(), static_cast<IVirtualizedItemProvider *>(pProvider));
    case UIA_WindowPatternId:
        // return IWindowProviderWrapper::New(info.Env(), static_cast<IWindowProvider *>(pProvider));
    case UIA_CustomNavigationPatternId:
        // return ICustomNavigationProviderWrapper::New(info.Env(), static_cast<ICustomNavigationProvider *>(pProvider));
    default:
        throw Napi::Error::New(info.Env(), "Pattern not implemented.");
    }
}