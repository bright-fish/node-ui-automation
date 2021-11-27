#include "AnnotationTypeIdsWrapper.h"

Napi::Object AnnotationTypeIdsWrapper::New(Napi::Env env)
{
    auto annotationTypeIds = Napi::Object::New(env);

    annotationTypeIds.Set("Unknown", Napi::Number::New(env, AnnotationType_Unknown));
    annotationTypeIds.Set("SpellingError", Napi::Number::New(env, AnnotationType_SpellingError));
    annotationTypeIds.Set("GrammarError", Napi::Number::New(env, AnnotationType_GrammarError));
    annotationTypeIds.Set("Comment", Napi::Number::New(env, AnnotationType_Comment));
    annotationTypeIds.Set("FormulaError", Napi::Number::New(env, AnnotationType_FormulaError));
    annotationTypeIds.Set("TrackChanges", Napi::Number::New(env, AnnotationType_TrackChanges));
    annotationTypeIds.Set("Header", Napi::Number::New(env, AnnotationType_Header));
    annotationTypeIds.Set("Footer", Napi::Number::New(env, AnnotationType_Footer));
    annotationTypeIds.Set("Highlighted", Napi::Number::New(env, AnnotationType_Highlighted));
    annotationTypeIds.Set("Endnote", Napi::Number::New(env, AnnotationType_Endnote));
    annotationTypeIds.Set("Footnote", Napi::Number::New(env, AnnotationType_Footnote));
    annotationTypeIds.Set("InsertionChange", Napi::Number::New(env, AnnotationType_InsertionChange));
    annotationTypeIds.Set("DeletionChange", Napi::Number::New(env, AnnotationType_DeletionChange));
    annotationTypeIds.Set("MoveChange", Napi::Number::New(env, AnnotationType_MoveChange));
    annotationTypeIds.Set("FormatChange", Napi::Number::New(env, AnnotationType_FormatChange));
    annotationTypeIds.Set("UnsyncedChange", Napi::Number::New(env, AnnotationType_UnsyncedChange));
    annotationTypeIds.Set("EditingLockedChange", Napi::Number::New(env, AnnotationType_EditingLockedChange));
    annotationTypeIds.Set("ExternalChange", Napi::Number::New(env, AnnotationType_ExternalChange));
    annotationTypeIds.Set("ConflictingChange", Napi::Number::New(env, AnnotationType_ConflictingChange));
    annotationTypeIds.Set("Author", Napi::Number::New(env, AnnotationType_Author));
    annotationTypeIds.Set("AdvancedProofingIssue", Napi::Number::New(env, AnnotationType_AdvancedProofingIssue));
    annotationTypeIds.Set("DataValidationError", Napi::Number::New(env, AnnotationType_DataValidationError));
    annotationTypeIds.Set("CircularReferenceError", Napi::Number::New(env, AnnotationType_CircularReferenceError));
    annotationTypeIds.Set("Mathematics", Napi::Number::New(env, AnnotationType_Mathematics));
    annotationTypeIds.Set("Sensitive", Napi::Number::New(env, AnnotationType_Sensitive));

    return annotationTypeIds;
}
