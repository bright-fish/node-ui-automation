export declare interface AutomationCacheRequest {
    addPattern(patternId: PatternIds): void;
    addProperty(propertyId: PropertyIds): void;
    clone(): AutomationCacheRequest;

    automationElementMode: ElementModes;
    treeFilter: AutomationCondition;
    treeScope: TreeScopes;
}

export declare interface AutomationCondition {
    // todo: toString would be nice to see what is included in the automation condition if possible.  
}

export declare interface AutomationElementArray {
    getElement(index: number): AutomationElement;
}

export declare interface Point {
    x: number;
    y: number;
}

export declare type Variant = string | number | null;

export declare interface IAnnotationProvider {
    annotationTypeId: string;
    annotationTypeName: string;
    author: string;
    dateTime: string;
    target: AutomationElement;
}

export declare enum DockPositions {
    Top = 0,
    Left = 1,
    Bottom = 2,
    Right = 3,
    Fill = 4,
    None = 5
}

export declare interface IDockProvider {
    dockPosition: DockPositions;

    setDockPosition(dockPosition: DockPositions): void;
}

export declare interface IDragProvider {
    dropEffects: string[];
    dropEffect: string;
    isGrabbed: boolean;
    getGrabbedItems(): IRawElementProviderSimple[];
}

export declare interface IDropTargetProvider {
    dropTargetEffect: string;
    dropTargetEffects: string[];
}

export declare enum ExpandCollapseStates {
    Collapsed = 0,
    Expanded = 1,
    PartiallyExpanded = 2,
    LeafNode = 3
}

export declare interface IExpandCollapseProvider {
    collapse(): void;
    expand(): void;
    expandCollapseState: ExpandCollapseStates
}

export declare interface IGridItemProvider {
    column: number;
    columnSpan: number;
    containingGrid: IRawElementProviderSimple;
    row: number;
    rowSpan: number;
}

export declare interface IGridProvider {
    columnCount: number;
    rowCount: number;
    getItem(row: number, column: number): IRawElementProviderSimple;
}

export declare interface IInvokeProvider {
    invoke(): void;
}

export declare interface IItemContainerProvider {
    findItemByProperty(startAfter: IRawElementProviderSimple, propertyId: PropertyIds, value: Variant): IRawElementProviderSimple;
}
export declare interface IDispatch {

}

// skipping
// export declare interface IAccessible {
//     accChild: IDispatch;
//     accChildCount: number;
//     accDefaultAction: string;
//     accDescription: string;
//     accFocus;
//     accHelp;
//     accHelpTopic;
//     accKeyboardShortcut;
//     accName;
//     accParent;
//     accRole;
//     accSelection;
//     accState;
//     accValue;
// }

export declare interface SelectionFlags {
    None: 0,
    TakeFocus: 0x1,
    AddSelection: 0x2,
    RemoveSelection: 0x4,
    TakeSelection: 0x8,
    ExtendSelection: 0x10
}

export declare interface ILegacyIAccessibleProvider {
    childId: number;
    defaultAction: string;
    description: string;
    help: string;
    keyboardShortcut: string;
    name: string;
    role: number;
    state: number;
    value: string;
    // skipping: getAccessible(): IAccessible;
    doDefaultAction(): void;
    getSelection(): IRawElementProviderSimple[];
    select(flag: SelectionFlags): void;
    setValue(value: string): void;
}

export declare interface IMultipleViewProvider {
    currentView: number;
    getSupportedViews(): number[];
    getViewName(viewId: number): string;
    setCurrentView(viewId: number): void;
}

// skipping: due to complexity
// export declare interface IObjectModelProvider {
// todo:  getUnderlyingObjectModel();
// this function requires that we return an IUnknown pointer and casting that doesnt really make sense.  
// one thought would be to return the underlying pointer as a node buffer.  This would allow someone to get the memory out of it if neccessary.  
// }

// skipping
// export declare interface IProxyProviderWinEventHandler  {

// }

// skipping
// export declare interface IProxyProviderWinEventSink   {

// }


export declare interface IRangeValueProvider {
    isReadOnly: boolean;
    largeChange: number;
    maximum: number;
    minimum: number;
    smallChange: number;
    value: string;
    setValue(value: number);
}

// skipping
// export declare interface IRawElementProviderAdviseEvents  {

// }


export declare interface IRawElementProviderFragment {

}


export declare interface IRawElementProviderFragmentRoot {

}


export declare interface IRawElementProviderHostingAccessibles {

}


export declare interface IRawElementProviderHwndOverride {

}

export declare enum ProviderOptions {
    ClientSideProvider = 0x1,
    ServerSideProvider = 0x2,
    NonClientAreaProvider = 0x4,
    OverrideProvider = 0x8,
    ProviderOwnsSetFocus = 0x10,
    UseComThreading = 0x20,
    RefuseNonClientSupport = 0x40,
    HasNativeIAccessible = 0x80,
    UseClientCoordinates = 0x100
}

export declare interface IRawElementProviderSimple {
    hostRawElementProvider: IRawElementProviderSimple;
    providerOptions: ProviderOptions;

    // todo: this is missing, figure out if feasible.  
    // getPatternProvider(patternId: AutomationPatterns.CustomNavigationPatternId): IAnnotationProvider;    
    getPatternProvider(patternId: PatternIds.AnnotationPatternId): IAnnotationProvider;
    getPatternProvider(patternId: PatternIds.DockPatternId): IDockProvider;
    getPatternProvider(patternId: PatternIds.DragPatternId): IDragProvider;
    getPatternProvider(patternId: PatternIds.DropTargetPatternId): IDropTargetProvider;
    getPatternProvider(patternId: PatternIds.ExpandCollapsePatternId): IExpandCollapseProvider;
    getPatternProvider(patternId: PatternIds.GridItemPatternId): IGridItemProvider;
    getPatternProvider(patternId: PatternIds.GridPatternId): IGridProvider;
    getPatternProvider(patternId: PatternIds.InvokePatternId): IInvokeProvider;
    getPatternProvider(patternId: PatternIds.ItemContainerPatternId): IItemContainerProvider;
    getPatternProvider(patternId: PatternIds.LegacyIAccessiblePatternId): ILegacyIAccessibleProvider;
    getPatternProvider(patternId: PatternIds.MultipleViewPatternId): IMultipleViewProvider;
    // todo: getPatternProvider(patternId: AutomationPatterns.ObjectModelPatternId): IObjectModelProvider; // not implemented due to complexity.
    getPatternProvider(patternId: PatternIds.RangeValuePatternId): IRangeValueProvider;
    getPatternProvider(patternId: PatternIds.ScrollItemPatternId): IScrollItemProvider;
    getPatternProvider(patternId: PatternIds.ScrollPatternId): IScrollProvider;
    getPatternProvider(patternId: PatternIds.SelectionItemPatternId): ISelectionItemProvider;
    getPatternProvider(patternId: PatternIds.SelectionPatternId): ISelectionProvider;
    getPatternProvider(patternId: PatternIds.SelectionPattern2Id): ISelectionProvider2;
    getPatternProvider(patternId: PatternIds.SpreadsheetItemPatternId): ISpreadsheetItemProvider;
    getPatternProvider(patternId: PatternIds.SpreadsheetPatternId): ISpreadsheetProvider;
    getPatternProvider(patternId: PatternIds.StylesPatternId): IStylesProvider;
    getPatternProvider(patternId: PatternIds.SynchronizedInputPatternId): ISynchronizedInputProvider;
    getPatternProvider(patternId: PatternIds.TableItemPatternId): ITableItemProvider;
    getPatternProvider(patternId: PatternIds.TablePatternId): ITableProvider;
    getPatternProvider(patternId: PatternIds.TextChildPatternId): ITextChildProvider;
    getPatternProvider(patternId: PatternIds.TextEditPatternId): ITextEditProvider;
    getPatternProvider(patternId: PatternIds.TextPatternId): ITextProvider;
    getPatternProvider(patternId: PatternIds.TextPattern2Id): ITextProvider2;
    getPatternProvider(patternId: PatternIds.TogglePatternId): IToggleProvider;
    getPatternProvider(patternId: PatternIds.TransformPatternId): ITransformProvider;
    getPatternProvider(patternId: PatternIds.TransformPattern2Id): ITransformProvider2;
    getPatternProvider(patternId: PatternIds.ValuePatternId): IValueProvider;
    getPatternProvider(patternId: PatternIds.VirtualizedItemPatternId): IVirtualizedItemProvider;
    getPatternProvider(patternId: PatternIds.WindowPatternId): IWindowProvider;
    getPatternProvider(patternId: PatternIds): unknown;

    getPropertyValue(propertyId: PropertyIds): Variant;
}

export declare interface IRawElementProviderSimple2 extends IRawElementProviderSimple {
    showContextMenu(): void;
}

export declare interface AutomationMetadataIdentifiers {

}

export declare interface IRawElementProviderSimple3 extends IRawElementProviderSimple2 {
    getMetadataValue(targetId: number, metadataId: AutomationMetadataIdentifiers): Variant;
}



// skipping
// export declare interface IRawElementProviderWindowlessSite {

// }


export declare interface IScrollItemProvider {
    scrollIntoView(): void;
}

export declare interface IScrollProvider {
    horizontallyScrollable: boolean;
    horizontalScrollPercent: number;
    horizontalViewSize: number;
    verticallyScrollable: boolean;
    verticalScrollPercent: number;
    verticalViewSize: number;
    scroll(horizontalAmount: number, verticalAmount: number): void;
    setScrollPercent(horizontalPercent: number, verticalPercent: number): void;
}

export declare interface ISelectionItemProvider {
    isSelected: boolean;
    selectionContainer: IRawElementProviderSimple;

    addToSelection(): void;
    removeFromSelection(): void;
    select(): void;
}

export declare interface ISelectionProvider {
    canSelectMultiple: boolean;
    isSelectionRequired: boolean;
    getSelection(): IRawElementProviderSimple[];
}

export declare interface ISelectionProvider2 extends ISelectionProvider {
    currentSelectedItem: IRawElementProviderSimple;
    firstSelectedItem: IRawElementProviderSimple;
    itemCount: number;
    lastSelectedItem: IRawElementProviderSimple;
}

export declare enum AnnotationTypeIds {
    Unknown = 60000,
    SpellingError = 60001,
    GrammarError = 60002,
    Comment = 60003,
    FormulaError = 60004,
    TrackChanges = 60005,
    Header = 60006,
    Footer = 60007,
    Highlighted = 60008,
    Endnote = 60009,
    Footnote = 60010,
    InsertionChange = 60011,
    DeletionChange = 60012,
    MoveChange = 60013,
    FormatChange = 60014,
    UnsyncedChange = 60015,
    EditingLockedChange = 60016,
    ExternalChange = 60017,
    ConflictingChange = 60018,
    Author = 60019,
    AdvancedProofingIssue = 60020,
    DataValidationError = 60021,
    CircularReferenceError = 60022,
    Mathematics = 60023,
    Sensitive = 60024
}

export declare interface ISpreadsheetItemProvider {
    formula: string;
    getAnnotationObjects(): IRawElementProviderSimple[];
    getAnnotationTypes(): AnnotationTypeIds[];
}

export declare interface ISpreadsheetProvider {
    getItemByName(name: string): IRawElementProviderSimple
}

export declare enum StyleIds {
    Custom = 70000,
    Heading1 = 70001,
    Heading2 = 70002,
    Heading3 = 70003,
    Heading4 = 70004,
    Heading5 = 70005,
    Heading6 = 70006,
    Heading7 = 70007,
    Heading8 = 70008,
    Heading9 = 70009,
    Title = 70010,
    Subtitle = 70011,
    Normal = 70012,
    Emphasis = 70013,
    Quote = 70014,
    BulletedList = 70015,
    NumberedList = 70016
}

export declare interface IStylesProvider {
    extendedProperties: string;
    fillColor: number;
    fillPatternColor: number;
    fillPatternStyle: string;
    shape: string;
    styleId: StyleIds;
    styleName: string;
}

export declare enum SynchronizedInputTypes {
    KeyUp = 0x1,
    KeyDown = 0x2,
    LeftMouseUp = 0x4,
    LeftMouseDown = 0x8,
    RightMouseUp = 0x10,
    RightMouseDown = 0x20
}

export declare interface ISynchronizedInputProvider {
    cancel(): void;
    startListening(synchronizedInputType: SynchronizedInputTypes): void;
}

export declare interface ITableItemProvider {
    getColumnHeaderItems(): IRawElementProviderSimple[];
    getRowHeaderItems(): IRawElementProviderSimple[];
}

export declare enum RowOrColumnMajor {
    RowMajor = 0,
    ColumnMajor = 1,
    Indeterminate = 2
}

export declare interface ITableProvider {
    rowOrColumnMajor: RowOrColumnMajor;
    getColumnHeaders(): IRawElementProviderSimple[];
    getRowHeaders(): IRawElementProviderSimple[];
}

export declare interface ITextChildProvider {
    textContainer: IRawElementProviderSimple;
    textRange: ITextRangeProvider;
}

export declare interface ITextEditProvider {
    getActiveComposition(): ITextRangeProvider;
    getConversionTarget(): ITextRangeProvider;
}

export declare enum SupportedTextSelections {
    None = 0,
    Single = 1,
    Multiple = 2
}

export declare interface ITextProvider {
    documentRange: ITextRangeProvider
    supportedTextSelection: SupportedTextSelections;
    getSelection(): ITextRangeProvider[];
    getVisibleRanges(): ITextRangeProvider[];
    rangeFromChild(childElement: IRawElementProviderSimple): ITextRangeProvider;
    rangeFromPoint(point: Point): ITextRangeProvider;
}

export declare interface CaretRange {
    isActive: boolean;
    value: ITextRangeProvider;
}

export declare interface ITextProvider2 extends ITextProvider {
    getCaretRange(): CaretRange;
    rangeFromAnnotation(annotationElement: IRawElementProviderSimple): ITextRangeProvider;
}

export declare enum TextPatternRangeEndpoints {
    Start = 0,
    End = 1
}

export declare enum TextUnits {
    Character = 0,
    Format = 1,
    Word = 2,
    Line = 3,
    Paragraph = 4,
    Page = 5,
    Document = 6
}

export declare enum AttributeIds {
    AnimationStyleAttributeId = 40000,
    BackgroundColorAttributeId = 40001,
    BulletStyleAttributeId = 40002,
    CapStyleAttributeId = 40003,
    CultureAttributeId = 40004,
    FontNameAttributeId = 40005,
    FontSizeAttributeId = 40006,
    FontWeightAttributeId = 40007,
    ForegroundColorAttributeId = 40008,
    HorizontalTextAlignmentAttributeId = 40009,
    IndentationFirstLineAttributeId = 40010,
    IndentationLeadingAttributeId = 40011,
    IndentationTrailingAttributeId = 40012,
    IsHiddenAttributeId = 40013,
    IsItalicAttributeId = 40014,
    IsReadOnlyAttributeId = 40015,
    IsSubscriptAttributeId = 40016,
    IsSuperscriptAttributeId = 40017,
    MarginBottomAttributeId = 40018,
    MarginLeadingAttributeId = 40019,
    MarginTopAttributeId = 40020,
    MarginTrailingAttributeId = 40021,
    OutlineStylesAttributeId = 40022,
    OverlineColorAttributeId = 40023,
    OverlineStyleAttributeId = 40024,
    StrikethroughColorAttributeId = 40025,
    StrikethroughStyleAttributeId = 40026,
    TabsAttributeId = 40027,
    TextFlowDirectionsAttributeId = 40028,
    UnderlineColorAttributeId = 40029,
    UnderlineStyleAttributeId = 40030,
    AnnotationTypesAttributeId = 40031,
    AnnotationObjectsAttributeId = 40032,
    StyleNameAttributeId = 40033,
    StyleIdAttributeId = 40034,
    LinkAttributeId = 40035,
    IsActiveAttributeId = 40036,
    SelectionActiveEndAttributeId = 40037,
    CaretPositionAttributeId = 40038,
    CaretBidiModeAttributeId = 40039,
    LineSpacingAttributeId = 40040,
    BeforeParagraphSpacingAttributeId = 40041,
    AfterParagraphSpacingAttributeId = 40042,
    SayAsInterpretAsAttributeId = 40043
}


export declare interface ITextRangeProvider {
    addToSelection(): void;
    clone(): ITextRangeProvider;
    compare(range: ITextRangeProvider): boolean;
    compareEndpoints(endpoint: TextPatternRangeEndpoints, targeRange: ITextRangeProvider, targetEndpoint: TextPatternRangeEndpoints): number;
    expandToEnclosingUnit(textUnit: TextUnits): void;
    findAttribute(attributeId: AttributeIds, value: Variant, backward: boolean): ITextRangeProvider;
    findText(text: string, backward: boolean, ignoreCase: boolean): ITextRangeProvider;
    getAttributeValue(attributeId: AttributeIds): Variant;
    getBoundingRectangles(): Rect[]; //todo: read documentation and validate all 3 special cases.  
    getChildren(): IRawElementProviderSimple[];
    getEnclosingElement(): IRawElementProviderSimple;
    getText(maxLength: number): string;
    move(textUnit: TextUnits, count: number): number;
    moveEndpointByRange(endpoint: TextPatternRangeEndpoints, targetRange: ITextRangeProvider, targetEndpoint: TextPatternRangeEndpoints): number;
    moveEndpointByUnit(endpoint: TextPatternRangeEndpoints, textUnit: TextUnits, count: number): number;
    removeFromSelection(): void;
    scrollIntoView(alignTop: boolean): void;
    select(): void;
}

// skipping for now
// export declare interface ITextRangeProvider2 extends ITextRangeProvider {
//     showContextMenu(): void;
// }

export declare enum ToggleStates {
    Off = 0,
    On = 1,
    Indeterminate = 2
}


export declare interface IToggleProvider {
    toggleState: ToggleStates;
    toggle(): void;
}

export declare interface ITransformProvider {
    canMove: boolean;
    canResize: boolean;
    canRotate: boolean;
    move(x: number, y: number);
    resize(width: number, height: number);
    rotate(degrees: number);
}

export declare enum ZoomUnits {
    NoAmount = 0,
    LargeDecrement = 1,
    SmallDecrement = 2,
    LargeIncrement = 3,
    SmallIncrement = 4
}

export declare interface ITransformProvider2 extends ITransformProvider {
    canZoom: boolean;
    zoomLevel: number;
    zoomMaximum: number;
    zoomMinimum: number;
    zoom(zoom: number);
    zoomByUnit(zoomUnit: ZoomUnits)
}

export declare interface IValueProvider {
    isReadOnly: boolean;
    value: string;
    setValue(value: string): void;
}

export declare interface IVirtualizedItemProvider {
    realize(): void;
}

export declare enum WindowInteractionStates {
    Running = 0,
    Closing = 1,
    ReadyForUserInteraction = 2,
    BlockedByModalWindow = 3,
    NotResponding = 4
}

export declare enum WindowVisualStates {
    Normal = 0,
    Maximized = 1,
    Minimized = 2
}

export declare interface IWindowProvider {
    canMaximize: boolean;
    canMinimize: boolean;
    isModal: boolean;
    isTopmost: boolean;
    windowInteractionState: WindowInteractionStates;
    windowVisualState: WindowVisualStates;

    close(): void;
    setVisualState(state: WindowVisualStates): void;
    waitForInputIdle(milliseconds: number): boolean;
}


export declare interface AutomationElement {
    buildUpdatedCache(cacheRequest: AutomationCacheRequest): AutomationElement;
    findAll(treeScope: TreeScopes, condition: AutomationCondition): AutomationElementArray;
    findAllBuildCache(treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, condition: AutomationCondition): AutomationElementArray;
    findFirst(treeScope: TreeScopes, condition: AutomationCondition): AutomationElement;
    findFirstBuildCache(treeScope: TreeScopes, condition: AutomationCondition, cacheRequest: AutomationCacheRequest): AutomationElement;
    getCachedChildren(): AutomationElementArray;
    getCachedParent(): AutomationElement;
    getCachedPropertyValue(propertyId: PropertyIds): Variant;
    getCachedPropertyValueEx(propertyId: PropertyIds, ignoreDefaultValue: boolean): Variant;
    getClickablePoint(point: Point): boolean;

    // todo: this is missing, figure out if feasible.  
    // getCurrentPattern(patternId: AutomationPatterns.CustomNavigationPatternId): IAnnotationProvider;    
    getCurrentPattern(patternId: PatternIds.AnnotationPatternId): IAnnotationProvider;
    getCurrentPattern(patternId: PatternIds.DockPatternId): IDockProvider;
    getCurrentPattern(patternId: PatternIds.DragPatternId): IDragProvider;
    getCurrentPattern(patternId: PatternIds.DropTargetPatternId): IDropTargetProvider;
    getCurrentPattern(patternId: PatternIds.ExpandCollapsePatternId): IExpandCollapseProvider;
    getCurrentPattern(patternId: PatternIds.GridItemPatternId): IGridItemProvider;
    getCurrentPattern(patternId: PatternIds.GridPatternId): IGridProvider;
    getCurrentPattern(patternId: PatternIds.InvokePatternId): IInvokeProvider;
    getCurrentPattern(patternId: PatternIds.ItemContainerPatternId): IItemContainerProvider;
    getCurrentPattern(patternId: PatternIds.LegacyIAccessiblePatternId): ILegacyIAccessibleProvider;
    getCurrentPattern(patternId: PatternIds.MultipleViewPatternId): IMultipleViewProvider;
    // getCurrentPattern(patternId: AutomationPatterns.ObjectModelPatternId): IObjectModelProvider; // todo: not implemented due to complexity.
    getCurrentPattern(patternId: PatternIds.RangeValuePatternId): IRangeValueProvider;
    getCurrentPattern(patternId: PatternIds.ScrollItemPatternId): IScrollItemProvider;
    getCurrentPattern(patternId: PatternIds.ScrollPatternId): IScrollProvider;
    getCurrentPattern(patternId: PatternIds.SelectionItemPatternId): ISelectionItemProvider;
    getCurrentPattern(patternId: PatternIds.SelectionPatternId): ISelectionProvider;
    getCurrentPattern(patternId: PatternIds.SelectionPattern2Id): ISelectionProvider2;
    getCurrentPattern(patternId: PatternIds.SpreadsheetItemPatternId): ISpreadsheetItemProvider;
    getCurrentPattern(patternId: PatternIds.SpreadsheetPatternId): ISpreadsheetProvider;
    getCurrentPattern(patternId: PatternIds.StylesPatternId): IStylesProvider;
    getCurrentPattern(patternId: PatternIds.SynchronizedInputPatternId): ISynchronizedInputProvider;
    getCurrentPattern(patternId: PatternIds.TableItemPatternId): ITableItemProvider;
    getCurrentPattern(patternId: PatternIds.TablePatternId): ITableProvider;
    getCurrentPattern(patternId: PatternIds.TextChildPatternId): ITextChildProvider;
    getCurrentPattern(patternId: PatternIds.TextEditPatternId): ITextEditProvider;
    getCurrentPattern(patternId: PatternIds.TextPatternId): ITextProvider;
    getCurrentPattern(patternId: PatternIds.TextPattern2Id): ITextProvider2;
    getCurrentPattern(patternId: PatternIds.TogglePatternId): IToggleProvider;
    getCurrentPattern(patternId: PatternIds.TransformPatternId): ITransformProvider;
    getCurrentPattern(patternId: PatternIds.TransformPattern2Id): ITransformProvider2;
    getCurrentPattern(patternId: PatternIds.ValuePatternId): IValueProvider;
    getCurrentPattern(patternId: PatternIds.VirtualizedItemPatternId): IVirtualizedItemProvider;
    getCurrentPattern(patternId: PatternIds.WindowPatternId): IWindowProvider;
    getCurrentPattern(patternId: PatternIds): unknown;

    getCurrentPropertyValue(propertyId: PropertyIds): Variant;
    getCurrentPropertyValueEx(propertyId: PropertyIds, ignoreDefaultValues: boolean): Variant;
    setFocus(): void;

    currentName: string;
    currentAcceleratorKey: string;
    currentAccessKey: string;
    currentAriaProperties: string;
    currentAriaRole: string;
    currentAutomationId: string;
    currentBoundingRectangle: Rect;
    currentClassName: string;
    currentControllerFor: AutomationElement;
    currentControlType: ControlTypeIds;
    currentCulture: number;
    currentDescribedBy: AutomationElementArray;
    currentFlowsTo: AutomationElement;
    currentFrameworkId: string;
    currentHasKeyboardFocus: boolean;
    currentHelpText: string;
    currentIsContentElement: boolean;
    currentIsControlElement: boolean;
    currentIsDataValidForForm: boolean;
    currentIsEnabled: boolean;
    currentIsKeyboardFocusable: boolean;
    currentIsOffscreen: boolean;
    currentIsPassword: boolean;
    currentIsRequiredForForm: boolean;
    currentItemStatus: string;
    currentItemType: string;
    currentLabeledBy: AutomationElement;
    currentLocalizedControlType: string;
    currentNativeWindowHandle: unknown;
    currentOrientation: OrientationTypes;
    currentProcessId: number;
    currentProviderDescription: string;

    cachedName: string;
    cachedAcceleratorKey: string;
    cachedAccessKey: string;
    cachedAriaProperties: string;
    cachedAriaRole: string;
    cachedAutomationId: string;
    cachedBoundingRectangle: Rect;
    cachedClassName: string;
    cachedControllerFor: AutomationElement;
    cachedControlType: ControlTypeIds;
    cachedCulture: number;
    cachedDescribedBy: AutomationElementArray;
    cachedFlowsTo: AutomationElement;
    cachedFrameworkId: string;
    cachedHasKeyboardFocus: boolean;
    cachedHelpText: string;
    cachedIsContentElement: boolean;
    cachedIsControlElement: boolean;
    cachedIsDataValidForForm: boolean;
    cachedIsEnabled: boolean;
    cachedIsKeyboardFocusable: boolean;
    cachedIsOffscreen: boolean;
    cachedIsPassword: boolean;
    cachedIsRequiredForForm: boolean;
    cachedItemStatus: string;
    cachedItemType: string;
    cachedLabeledBy: AutomationElement;
    cachedLocalizedControlType: string;
    cachedNativeWindowHandle: unknown;
    cachedOrientation: OrientationTypes;
    cachedProcessId: number;
    cachedProviderDescription: string;
}

export declare class AutomationEventHandler {
    constructor(callback: (sender: AutomationElement, eventId: EventIds) => void);
}

export declare class AutomationFocusChangedEventHandler {
    constructor(callback: (sender: AutomationElement) => void);
}

export declare class AutomationPropertyChangedEventHandler {
    constructor(callback: (sender: AutomationElement, propertyId: PropertyIds) => void);
}

export declare class AutomationStructureChangedEventHandler {
    constructor(callback: (sender: AutomationElement) => void);
}

// skipping
export declare interface AutomationProxyFactorMapping {
    // todo:
}

export declare interface AutomationTreeWalker {
    getFirstChildElement(element: AutomationElement): AutomationElement
    getFirstChildElementBuildCache(element: AutomationElement, cacheRequest: AutomationCacheRequest): AutomationElement
    getLastChildElement(element: AutomationElement): AutomationElement;
    getLastChildElementBuildCache(element: AutomationElement, cacheRequest: AutomationCacheRequest): AutomationElement;
    getNextSiblingElement(element: AutomationElement): AutomationElement;
    getNextSiblingElementBuildCache(element: AutomationElement, cacheRequest: AutomationCacheRequest): AutomationElement;
    getParentElement(element: AutomationElement): AutomationElement;
    getParentElementBuildCache(element: AutomationElement, cacheRequest: AutomationCacheRequest): AutomationElement;
    getPreviousSiblingElement(element: AutomationElement): AutomationElement;
    getPreviousSiblingElementBuildCache(element: AutomationElement, cacheRequest: AutomationCacheRequest): AutomationElement;
    normalizeElement(element: AutomationElement): AutomationElement;
    normalizeElementBuildCache(element: AutomationElement, cacheRequest: AutomationCacheRequest): AutomationElement;
}

export declare class Automation {
    constructor();

    createCacheRequest(): AutomationCacheRequest;
    addAutomationEventHandler(eventId: EventIds, element: AutomationElement, treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, eventHandler: AutomationEventHandler): void;
    addFocusChangedEventHandler(cacheRequest: AutomationCacheRequest, eventHandler: AutomationFocusChangedEventHandler): void;
    addPropertyChangedEventHandler(element: AutomationElement, treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, eventHandler: AutomationPropertyChangedEventHandler): void;
    addStructureChangedEventHandler(element: AutomationElement, treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, eventHandler: AutomationStructurechangedEventHandler): void;
    checkNotSupported(variant: Variant): boolean;
    compareElements(elementOne: AutomationElement, elementTwo: AutomationElement): boolean;
    createAndCondition(conditionOne: AutomationCondition, conditionTwo: AutomationCondition): AutomationCondition;
    createFalseCondition(): AutomationCondition;
    createNotCondition(condition: AutomationCondition): AutomationCondition;
    createOrCondition(conditionOne: AutomationCondition, conditionTwo: AutomationCondition): AutomationCondition;
    createPropertyCondition(propertyId: PropertyIds, value: Variant): AutomationCondition;
    createTreeWalker(condition: AutomationCondition);
    createTrueCondition(): AutomationCondition;
    elementFromPoint(point: Point): AutomationElement;
    elementFromPointBuildCache(point: Point, cacheRequest: AutomationCacheRequest): AutomationElement;
    getFocusedElement(): AutomationElement;
    getFocusedElementBuildCache(cacheRequest: AutomationCacheRequest): AutomationElement;
    getPatternProgrammaticName(patternId: PatternIds): string;
    getPropertyProgrammaticName(propertyId: PropertyIds): string;
    getRootElement(): AutomationElement;
    getRootElementBuildCache(cacheRequest: AutomationCacheRequest): AutomationElement;
    removeAllEventHandlers(): void;
    removeAutomationEventHandler(eventId: EventIds, element: AutomationElement, eventHandler: AutomationEventHandler): void;
    removeFocusChangedEventHandler(eventHandler: AutomationFocusChangedEventHandler): void;
    removePropertyChangedEventHandler(element: AutomationElement, eventHandler: AutomationPropertyChangedEventHandler): void;
    removeStructureChangedEventHandler(element: AutomationElement, eventHandler: AutomationStructurechangedEventHandler): void;

    rawViewWalker: AutomationTreeWalker;
    rawViewCondition: AutomationCondition;
    contentViewWalker: AutomationTreeWalker;
    contentViewCondition: AutomationCondition;
    controlViewWalker: AutomationTreeWalker;
    controlViewCondition: AutomationCondition;
    // skipping: proxyFactoryMapping: AutomationProxyFactorMapping;
}

export declare interface Rect {
    bottom: number;
    top: number;
    left: number;
    right: number;
}

export declare enum TreeScopes {
    None = 0,
    Element = 0x1,
    Children = 0x2,
    Descendants = 0x4,
    Parent = 0x8,
    Ancestors = 0x10,
    Subtree = Element | Children | Descendants
}

export declare enum EventIds {
    ToolTipOpenedEventId = 20000,
    ToolTipClosedEventId = 20001,
    StructureChangedEventId = 20002,
    MenuOpenedEventId = 20003,
    AutomationPropertyChangedEventId = 20004,
    AutomationFocusChangedEventId = 20005,
    AsyncContentLoadedEventId = 20006,
    MenuClosedEventId = 20007,
    LayoutInvalidatedEventId = 20008,
    Invoke_InvokedEventId = 20009,
    SelectionItem_ElementAddedToSelectionEventId = 20010,
    SelectionItem_ElementRemovedFromSelectionEventId = 20011,
    SelectionItem_ElementSelectedEventId = 20012,
    Selection_InvalidatedEventId = 20013,
    Text_TextSelectionChangedEventId = 20014,
    Text_TextChangedEventId = 20015,
    Window_WindowOpenedEventId = 20016,
    Window_WindowClosedEventId = 20017,
    MenuModeStartEventId = 20018,
    MenuModeEndEventId = 20019,
    InputReachedTargetEventId = 20020,
    InputReachedOtherElementEventId = 20021,
    InputDiscardedEventId = 20022,
    SystemAlertEventId = 20023,
    LiveRegionChangedEventId = 20024,
    HostedFragmentRootsInvalidatedEventId = 20025,
    Drag_DragStartEventId = 20026,
    Drag_DragCancelEventId = 20027,
    Drag_DragCompleteEventId = 20028,
    DropTarget_DragEnterEventId = 20029,
    DropTarget_DragLeaveEventId = 20030,
    DropTarget_DroppedEventId = 20031,
    TextEdit_TextChangedEventId = 20032,
    TextEdit_ConversionTargetChangedEventId = 20033,
    ChangesEventId = 20034,
    NotificationEventId = 20035,
    ActiveTextPositionChangedEventId = 20036,
}

export declare enum PropertyIds {
    RuntimeIdPropertyId = 30000,
    BoundingRectanglePropertyId = 30001,
    ProcessIdPropertyId = 30002,
    ControlTypePropertyId = 30003,
    LocalizedControlTypePropertyId = 30004,
    NamePropertyId = 30005,
    AcceleratorKeyPropertyId = 30006,
    AccessKeyPropertyId = 30007,
    HasKeyboardFocusPropertyId = 30008,
    IsKeyboardFocusablePropertyId = 30009,
    IsEnabledPropertyId = 30010,
    AutomationIdPropertyId = 30011,
    ClassNamePropertyId = 30012,
    HelpTextPropertyId = 30013,
    ClickablePointPropertyId = 30014,
    CulturePropertyId = 30015,
    IsControlElementPropertyId = 30016,
    IsContentElementPropertyId = 30017,
    LabeledByPropertyId = 30018,
    IsPasswordPropertyId = 30019,
    NativeWindowHandlePropertyId = 30020,
    ItemTypePropertyId = 30021,
    IsOffscreenPropertyId = 30022,
    OrientationPropertyId = 30023,
    FrameworkIdPropertyId = 30024,
    IsRequiredForFormPropertyId = 30025,
    ItemStatusPropertyId = 30026,
    IsDockPatternAvailablePropertyId = 30027,
    IsExpandCollapsePatternAvailablePropertyId = 30028,
    IsGridItemPatternAvailablePropertyId = 30029,
    IsGridPatternAvailablePropertyId = 30030,
    IsInvokePatternAvailablePropertyId = 30031,
    IsMultipleViewPatternAvailablePropertyId = 30032,
    IsRangeValuePatternAvailablePropertyId = 30033,
    IsScrollPatternAvailablePropertyId = 30034,
    IsScrollItemPatternAvailablePropertyId = 30035,
    IsSelectionItemPatternAvailablePropertyId = 30036,
    IsSelectionPatternAvailablePropertyId = 30037,
    IsTablePatternAvailablePropertyId = 30038,
    IsTableItemPatternAvailablePropertyId = 30039,
    IsTextPatternAvailablePropertyId = 30040,
    IsTogglePatternAvailablePropertyId = 30041,
    IsTransformPatternAvailablePropertyId = 30042,
    IsValuePatternAvailablePropertyId = 30043,
    IsWindowPatternAvailablePropertyId = 30044,
    ValueValuePropertyId = 30045,
    ValueIsReadOnlyPropertyId = 30046,
    RangeValueValuePropertyId = 30047,
    RangeValueIsReadOnlyPropertyId = 30048,
    RangeValueMinimumPropertyId = 30049,
    RangeValueMaximumPropertyId = 30050,
    RangeValueLargeChangePropertyId = 30051,
    RangeValueSmallChangePropertyId = 30052,
    ScrollHorizontalScrollPercentPropertyId = 30053,
    ScrollHorizontalViewSizePropertyId = 30054,
    ScrollVerticalScrollPercentPropertyId = 30055,
    ScrollVerticalViewSizePropertyId = 30056,
    ScrollHorizontallyScrollablePropertyId = 30057,
    ScrollVerticallyScrollablePropertyId = 30058,
    SelectionSelectionPropertyId = 30059,
    SelectionCanSelectMultiplePropertyId = 30060,
    SelectionIsSelectionRequiredPropertyId = 30061,
    GridRowCountPropertyId = 30062,
    GridColumnCountPropertyId = 30063,
    GridItemRowPropertyId = 30064,
    GridItemColumnPropertyId = 30065,
    GridItemRowSpanPropertyId = 30066,
    GridItemColumnSpanPropertyId = 30067,
    GridItemContainingGridPropertyId = 30068,
    DockDockPositionPropertyId = 30069,
    ExpandCollapseExpandCollapseStatePropertyId = 30070,
    MultipleViewCurrentViewPropertyId = 30071,
    MultipleViewSupportedViewsPropertyId = 30072,
    WindowCanMaximizePropertyId = 30073,
    WindowCanMinimizePropertyId = 30074,
    WindowWindowVisualStatePropertyId = 30075,
    WindowWindowInteractionStatePropertyId = 30076,
    WindowIsModalPropertyId = 30077,
    WindowIsTopmostPropertyId = 30078,
    SelectionItemIsSelectedPropertyId = 30079,
    SelectionItemSelectionContainerPropertyId = 30080,
    TableRowHeadersPropertyId = 30081,
    TableColumnHeadersPropertyId = 30082,
    TableRowOrColumnMajorPropertyId = 30083,
    TableItemRowHeaderItemsPropertyId = 30084,
    TableItemColumnHeaderItemsPropertyId = 30085,
    ToggleToggleStatePropertyId = 30086,
    TransformCanMovePropertyId = 30087,
    TransformCanResizePropertyId = 30088,
    TransformCanRotatePropertyId = 30089,
    IsLegacyIAccessiblePatternAvailablePropertyId = 30090,
    LegacyIAccessibleChildIdPropertyId = 30091,
    LegacyIAccessibleNamePropertyId = 30092,
    LegacyIAccessibleValuePropertyId = 30093,
    LegacyIAccessibleDescriptionPropertyId = 30094,
    LegacyIAccessibleRolePropertyId = 30095,
    LegacyIAccessibleStatePropertyId = 30096,
    LegacyIAccessibleHelpPropertyId = 30097,
    LegacyIAccessibleKeyboardShortcutPropertyId = 30098,
    LegacyIAccessibleSelectionPropertyId = 30099,
    LegacyIAccessibleDefaultActionPropertyId = 30100,
    AriaRolePropertyId = 30101,
    AriaPropertiesPropertyId = 30102,
    IsDataValidForFormPropertyId = 30103,
    ControllerForPropertyId = 30104,
    DescribedByPropertyId = 30105,
    FlowsToPropertyId = 30106,
    ProviderDescriptionPropertyId = 30107,
    IsItemContainerPatternAvailablePropertyId = 30108,
    IsVirtualizedItemPatternAvailablePropertyId = 30109,
    IsSynchronizedInputPatternAvailablePropertyId = 30110,
    OptimizeForVisualContentPropertyId = 30111,
    IsObjectModelPatternAvailablePropertyId = 30112,
    AnnotationAnnotationTypeIdPropertyId = 30113,
    AnnotationAnnotationTypeNamePropertyId = 30114,
    AnnotationAuthorPropertyId = 30115,
    AnnotationDateTimePropertyId = 30116,
    AnnotationTargetPropertyId = 30117,
    IsAnnotationPatternAvailablePropertyId = 30118,
    IsTextPattern2AvailablePropertyId = 30119,
    StylesStyleIdPropertyId = 30120,
    StylesStyleNamePropertyId = 30121,
    StylesFillColorPropertyId = 30122,
    StylesFillPatternStylePropertyId = 30123,
    StylesShapePropertyId = 30124,
    StylesFillPatternColorPropertyId = 30125,
    StylesExtendedPropertiesPropertyId = 30126,
    IsStylesPatternAvailablePropertyId = 30127,
    IsSpreadsheetPatternAvailablePropertyId = 30128,
    SpreadsheetItemFormulaPropertyId = 30129,
    SpreadsheetItemAnnotationObjectsPropertyId = 30130,
    SpreadsheetItemAnnotationTypesPropertyId = 30131,
    IsSpreadsheetItemPatternAvailablePropertyId = 30132,
    Transform2CanZoomPropertyId = 30133,
    IsTransformPattern2AvailablePropertyId = 30134,
    LiveSettingPropertyId = 30135,
    IsTextChildPatternAvailablePropertyId = 30136,
    IsDragPatternAvailablePropertyId = 30137,
    DragIsGrabbedPropertyId = 30138,
    DragDropEffectPropertyId = 30139,
    DragDropEffectsPropertyId = 30140,
    IsDropTargetPatternAvailablePropertyId = 30141,
    DropTargetDropTargetEffectPropertyId = 30142,
    DropTargetDropTargetEffectsPropertyId = 30143,
    DragGrabbedItemsPropertyId = 30144,
    Transform2ZoomLevelPropertyId = 30145,
    Transform2ZoomMinimumPropertyId = 30146,
    Transform2ZoomMaximumPropertyId = 30147,
    FlowsFromPropertyId = 30148,
    IsTextEditPatternAvailablePropertyId = 30149,
    IsPeripheralPropertyId = 30150,
    IsCustomNavigationPatternAvailablePropertyId = 30151,
    PositionInSetPropertyId = 30152,
    SizeOfSetPropertyId = 30153,
    LevelPropertyId = 30154,
    AnnotationTypesPropertyId = 30155,
    AnnotationObjectsPropertyId = 30156,
    LandmarkTypePropertyId = 30157,
    LocalizedLandmarkTypePropertyId = 30158,
    FullDescriptionPropertyId = 30159,
    FillColorPropertyId = 30160,
    OutlineColorPropertyId = 30161,
    FillTypePropertyId = 30162,
    VisualEffectsPropertyId = 30163,
    OutlineThicknessPropertyId = 30164,
    CenterPointPropertyId = 30165,
    RotationPropertyId = 30166,
    SizePropertyId = 30167,
    IsSelectionPattern2AvailablePropertyId = 30168,
    Selection2FirstSelectedItemPropertyId = 30169,
    Selection2LastSelectedItemPropertyId = 30170,
    Selection2CurrentSelectedItemPropertyId = 30171,
    Selection2ItemCountPropertyId = 30172,
    HeadingLevelPropertyId = 30173,
    IsDialogPropertyId = 30174
}

export declare enum PatternIds {
    InvokePatternId = 10000,
    SelectionPatternId = 10001,
    ValuePatternId = 10002,
    RangeValuePatternId = 10003,
    ScrollPatternId = 10004,
    ExpandCollapsePatternId = 10005,
    GridPatternId = 10006,
    GridItemPatternId = 10007,
    MultipleViewPatternId = 10008,
    WindowPatternId = 10009,
    SelectionItemPatternId = 10010,
    DockPatternId = 10011,
    TablePatternId = 10012,
    TableItemPatternId = 10013,
    TextPatternId = 10014,
    TogglePatternId = 10015,
    TransformPatternId = 10016,
    ScrollItemPatternId = 10017,
    LegacyIAccessiblePatternId = 10018,
    ItemContainerPatternId = 10019,
    VirtualizedItemPatternId = 10020,
    SynchronizedInputPatternId = 10021,
    ObjectModelPatternId = 10022,
    AnnotationPatternId = 10023,
    TextPattern2Id = 10024,
    StylesPatternId = 10025,
    SpreadsheetPatternId = 10026,
    SpreadsheetItemPatternId = 10027,
    TransformPattern2Id = 10028,
    TextChildPatternId = 10029,
    DragPatternId = 10030,
    DropTargetPatternId = 10031,
    TextEditPatternId = 10032,
    CustomNavigationPatternId = 10033,
    SelectionPattern2Id = 10034
}

export declare enum ElementModes {
    None = 0,
    Full = None + 1
}

export declare enum ControlTypeIds {
    ButtonControlTypeId = 50000,
    CalendarControlTypeId = 50001,
    CheckBoxControlTypeId = 50002,
    ComboBoxControlTypeId = 50003,
    EditControlTypeId = 50004,
    HyperlinkControlTypeId = 50005,
    ImageControlTypeId = 50006,
    ListItemControlTypeId = 50007,
    ListControlTypeId = 50008,
    MenuControlTypeId = 50009,
    MenuBarControlTypeId = 50010,
    MenuItemControlTypeId = 50011,
    ProgressBarControlTypeId = 50012,
    RadioButtonControlTypeId = 50013,
    ScrollBarControlTypeId = 50014,
    SliderControlTypeId = 50015,
    SpinnerControlTypeId = 50016,
    StatusBarControlTypeId = 50017,
    TabControlTypeId = 50018,
    TabItemControlTypeId = 50019,
    TextControlTypeId = 50020,
    ToolBarControlTypeId = 50021,
    ToolTipControlTypeId = 50022,
    TreeControlTypeId = 50023,
    TreeItemControlTypeId = 50024,
    CustomControlTypeId = 50025,
    GroupControlTypeId = 50026,
    ThumbControlTypeId = 50027,
    DataGridControlTypeId = 50028,
    DataItemControlTypeId = 50029,
    DocumentControlTypeId = 50030,
    SplitButtonControlTypeId = 50031,
    WindowControlTypeId = 50032,
    PaneControlTypeId = 50033,
    HeaderControlTypeId = 50034,
    HeaderItemControlTypeId = 50035,
    TableControlTypeId = 50036,
    TitleBarControlTypeId = 50037,
    SeparatorControlTypeId = 50038,
    SemanticZoomControlTypeId = 50039,
    AppBarControlTypeId = 50040,
}

export declare enum OrientationTypes {
    None = 0,
    Horizontal = 1,
    Vertical = 2
}