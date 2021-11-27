const {
    AnnotationTypeIds,
    AttributeIds,
    ControlTypeIds,
    DockPositions,
    ElementModes,
    EventIds,
    ExpandCollapseStates,
    OrientationTypes,
    PatternIds,
    PropertyIds,
    ProviderOptions,
    RowOrColumnMajor,
    StyleIds,
    SupportedTextSelections,
    SynchronizedInputTypes,
    TextPatternRangeEndpoints,
    TextUnits,
    ToggleStates,
    TreeScopes,
    WindowInteractionStates,
    WindowVisualStates,
    ZoomUnits
} = require('microsoft-ui-automation');

describe('Enumerations', () => {
    test('all', () => {
        expect(AnnotationTypeIds).toBeDefined();
        expect(AttributeIds).toBeDefined();
        expect(ControlTypeIds).toBeDefined();
        expect(DockPositions).toBeDefined();
        expect(ElementModes).toBeDefined();
        expect(EventIds).toBeDefined();
        expect(ExpandCollapseStates).toBeDefined();
        expect(OrientationTypes).toBeDefined();
        expect(PatternIds).toBeDefined();
        expect(PropertyIds).toBeDefined();
        expect(ProviderOptions).toBeDefined();
        expect(RowOrColumnMajor).toBeDefined();
        expect(StyleIds).toBeDefined();
        expect(SupportedTextSelections).toBeDefined();
        expect(SynchronizedInputTypes).toBeDefined();
        expect(TextPatternRangeEndpoints).toBeDefined();
        expect(TextUnits).toBeDefined();
        expect(ToggleStates).toBeDefined();
        expect(TreeScopes).toBeDefined();
        expect(WindowInteractionStates).toBeDefined();
        expect(WindowVisualStates).toBeDefined();
        expect(ZoomUnits).toBeDefined();
    });
});