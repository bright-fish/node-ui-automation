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

export declare type Variant = string | number | boolean | null;

export declare interface IAnnotationPattern {
    cachedAnnotationTypeId: string;
    cachedAnnotationTypeName: string;
    cachedAuthor: string;
    cachedDateTime: string;
    cachedTarget: AutomationElement;

    currentAnnotationTypeId: string;
    currentAnnotationTypeName: string;
    currentAuthor: string;
    currentDateTime: string;
    currentTarget: AutomationElement;
}

export declare enum DockPositions {
    Top = 0,
    Left = 1,
    Bottom = 2,
    Right = 3,
    Fill = 4,
    None = 5
}

export declare interface IDockPattern {
    cachedDockPosition: DockPositions;
    currentDockPosition: DockPositions;

    setDockPosition(dockPosition: DockPositions): void;
}

export declare interface IDragPattern {
    cachedDropEffects: string[];
    cachedDropEffect: string;
    cachedIsGrabbed: boolean;

    currentDropEffects: string[];
    currentDropEffect: string;
    currentIsGrabbed: boolean;

    getCachedGrabbedItems(): AutomationElement[];
    getCurrentGrabbedItems(): AutomationElement[];
}

export declare interface IDropTargetPattern {
    cachedDropTargetEffect: string;
    cachedDropTargetEffects: string[];

    currentDropTargetEffect: string;
    currentDropTargetEffects: string[];
}

export declare enum ExpandCollapseStates {
    Collapsed = 0,
    Expanded = 1,
    PartiallyExpanded = 2,
    LeafNode = 3
}

export declare interface IExpandCollapsePattern {
    collapse(): void;
    expand(): void;
    cachedExpandCollapseState: ExpandCollapseStates;
    currentExpandCollapseState: ExpandCollapseStates;
}

export declare interface IGridItemPattern {
    cachedColumn: number;
    cachedColumnSpan: number;
    cachedContainingGrid: AutomationElement;
    cachedRow: number;
    cachedRowSpan: number;

    currentColumn: number;
    currentColumnSpan: number;
    currentContainingGrid: AutomationElement;
    currentRow: number;
    currentRowSpan: number;
}

export declare interface IGridPattern {
    cachedColumnCount: number;
    cachedRowCount: number;
    currentColumnCount: number;
    currentRowCount: number;

    getItem(row: number, column: number): AutomationElement;
}

export declare interface IInvokePattern {
    invoke(): void;
}

export declare interface IItemContainerPattern {
    findItemByProperty(startAfter: AutomationElement, propertyId: PropertyIds, value: Variant): AutomationElement;
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

export declare interface ILegacyIAccessiblePattern {
    cachedChildId: number;
    cachedDefaultAction: string;
    cachedDescription: string;
    cachedHelp: string;
    cachedKeyboardShortcut: string;
    cachedName: string;
    cachedRole: number;
    cachedState: number;
    cachedValue: string;

    currentChildId: number;
    currentDefaultAction: string;
    currentDescription: string;
    currentHelp: string;
    currentKeyboardShortcut: string;
    currentName: string;
    currentRole: number;
    currentState: number;
    currentValue: string;

    // skipping: getAccessible(): IAccessible;
    doDefaultAction(): void;
    getCachedSelection(): AutomationElement[];
    getCurrentSelection(): AutomationElement[];
    select(flag: SelectionFlags): void;
    setValue(value: string): void;
}

export declare interface IMultipleViewPattern {
    cachedCurrentView: number;
    currentCurrentView: number;

    getCachedSupportedViews(): number[];
    getCurrentSupportedViews(): number[];
    getViewName(viewId: number): string;
    setCurrentView(viewId: number): void;
}

// skipping: due to complexity
// export declare interface IObjectModelPattern {
// todo:  getUnderlyingObjectModel();
// hard to do dynamic reflective property scanning on a model in c++.  
// }

// skipping
// export declare interface IProxyPatternWinEventHandler  {

// }

// skipping
// export declare interface IProxyPatternWinEventSink   {

// }


export declare interface IRangeValuePattern {
    cachedIsReadOnly: boolean;
    cachedLargeChange: number;
    cachedMaximum: number;
    cachedMinimum: number;
    cachedSmallChange: number;
    cachedValue: string;

    currentIsReadOnly: boolean;
    currentLargeChange: number;
    currentMaximum: number;
    currentMinimum: number;
    currentSmallChange: number;
    currentValue: string;

    setValue(value: number);
}

// skipping
// export declare interface IRawElementPatternAdviseEvents  {

// }


// todo: Possibly remove. 
// export declare enum ProviderOptions {
//     ClientSideProvider = 0x1,
//     ServerSideProvider = 0x2,
//     NonClientAreaProvider = 0x4,
//     OverrideProvider = 0x8,
//     ProviderOwnsSetFocus = 0x10,
//     UseComThreading = 0x20,
//     RefuseNonClientSupport = 0x40,
//     HasNativeIAccessible = 0x80,
//     UseClientCoordinates = 0x100
// }


export declare interface AutomationMetadataIdentifiers {

}


export declare interface IScrollItemPattern {
    scrollIntoView(): void;
}

export declare enum ScrollAmounts {
    LargeDecrement = 0,
    SmallDecrement = 1,
    NoAmount = 2,
    LargeIncrement = 3,
    SmallIncrement = 4
}

export declare interface IScrollPattern {
    cachedHorizontallyScrollable: boolean;
    cachedHorizontalScrollPercent: number;
    cachedHorizontalViewSize: number;
    cachedVerticallyScrollable: boolean;
    cachedVerticalScrollPercent: number;
    cachedVerticalViewSize: number;

    currentHorizontallyScrollable: boolean;
    currentHorizontalScrollPercent: number;
    currentHorizontalViewSize: number;
    currentVerticallyScrollable: boolean;
    currentVerticalScrollPercent: number;
    currentVerticalViewSize: number;

    scroll(horizontalAmount: ScrollAmounts, verticalAmount: ScrollAmounts): void;
    setScrollPercent(horizontalPercent: number, verticalPercent: number): void;
}

export declare interface ISelectionItemPattern {
    cachedIsSelected: boolean;
    cachedSelectionContainer: AutomationElement;
    currentIsSelected: boolean;
    currentSelectionContainer: AutomationElement;

    addToSelection(): void;
    removeFromSelection(): void;
    select(): void;
}

export declare interface ISelectionPattern {
    cachedCanSelectMultiple: boolean;
    cachedIsSelectionRequired: boolean;

    currentCanSelectMultiple: boolean;
    currentIsSelectionRequired: boolean;

    getCachedSelection(): AutomationElement[];
    getCurrentSelection(): AutomationElement[];
}

export declare interface ISelectionPattern2 extends ISelectionPattern {
    cachedCurrentSelectedItem: AutomationElement;
    cachedFirstSelectedItem: AutomationElement;
    cachedItemCount: number;
    cachedLastSelectedItem: AutomationElement;

    currentCurrentSelectedItem: AutomationElement;
    currentFirstSelectedItem: AutomationElement;
    currentItemCount: number;
    currentLastSelectedItem: AutomationElement;

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

export declare interface ISpreadsheetItemPattern {
    cachedFormula: string;
    currentFormula: string;

    getCachedAnnotationObjects(): AutomationElement[];
    getCachedAnnotationTypes(): AnnotationTypeIds[];

    getCurrentAnnotationObjects(): AutomationElement[];
    getCurrentAnnotationTypes(): AnnotationTypeIds[];

}

export declare interface ISpreadsheetPattern {
    getItemByName(name: string): AutomationElement
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

export declare interface IStylesPattern {
    cachedExtendedProperties: string;
    cachedFillColor: number;
    cachedFillPatternColor: number;
    cachedFillPatternStyle: string;
    cachedShape: string;
    cachedStyleId: StyleIds;
    cachedStyleName: string;

    currentExtendedProperties: string;
    currentFillColor: number;
    currentFillPatternColor: number;
    currentFillPatternStyle: string;
    currentShape: string;
    currentStyleId: StyleIds;
    currentStyleName: string;
}

export declare enum SynchronizedInputTypes {
    KeyUp = 0x1,
    KeyDown = 0x2,
    LeftMouseUp = 0x4,
    LeftMouseDown = 0x8,
    RightMouseUp = 0x10,
    RightMouseDown = 0x20
}

export declare interface ISynchronizedInputPattern {
    cancel(): void;
    startListening(synchronizedInputType: SynchronizedInputTypes): void;
}

export declare interface ITableItemPattern {
    getCachedColumnHeaderItems(): AutomationElement[];
    getCachedRowHeaderItems(): AutomationElement[];

    getCurrentColumnHeaderItems(): AutomationElement[];
    getCurrentRowHeaderItems(): AutomationElement[];
}

export declare enum RowOrColumnMajor {
    RowMajor = 0,
    ColumnMajor = 1,
    Indeterminate = 2
}

export declare interface ITablePattern {
    cachedRowOrColumnMajor: RowOrColumnMajor;
    currentRowOrColumnMajor: RowOrColumnMajor;

    getCachedColumnHeaders(): AutomationElement[];
    getCachedRowHeaders(): AutomationElement[];

    getCurrentColumnHeaders(): AutomationElement[];
    getCurrentRowHeaders(): AutomationElement[];
}

export declare interface ITextChildPattern {
    textContainer: AutomationElement;
    textRange: ITextRange;
}

export declare interface ITextEditPattern extends ITextPattern {

    getActiveComposition(): ITextRange;
    getConversionTarget(): ITextRange;
}

export declare enum SupportedTextSelections {
    None = 0,
    Single = 1,
    Multiple = 2
}

export declare interface ITextPattern {
    get documentRange(): ITextRange;
    supportedTextSelection: SupportedTextSelections;

    getSelection(): ITextRange[];
    getVisibleRanges(): ITextRange[];
    rangeFromChild(childElement: AutomationElement): ITextRange;
    rangeFromPoint(point: Point): ITextRange;
}

export declare interface CaretRange {
    isActive: boolean;
    value: ITextRange;
}

export declare interface ITextPattern2 extends ITextPattern {
    getCaretRange(): CaretRange;
    rangeFromAnnotation(annotationElement: AutomationElement): ITextRange;
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


export declare interface ITextRange {
    addToSelection(): void;
    clone(): ITextRange;
    compare(range: ITextRange): boolean;
    compareEndpoints(endpoint: TextPatternRangeEndpoints, targeRange: ITextRange, targetEndpoint: TextPatternRangeEndpoints): number;
    expandToEnclosingUnit(textUnit: TextUnits): void;
    findAttribute(attributeId: AttributeIds, value: Variant, backward: boolean): ITextRange;
    findText(text: string, backward: boolean, ignoreCase: boolean): ITextRange;
    getAttributeValue(attributeId: AttributeIds): Variant;
    getBoundingRectangles(): Rect[]; //todo: read documentation and validate all 3 special cases.  
    getChildren(): AutomationElement[];
    getEnclosingElement(): AutomationElement;
    getText(maxLength: number): string;
    move(textUnit: TextUnits, count: number): number;
    moveEndpointByRange(endpoint: TextPatternRangeEndpoints, targetRange: ITextRange, targetEndpoint: TextPatternRangeEndpoints): number;
    moveEndpointByUnit(endpoint: TextPatternRangeEndpoints, textUnit: TextUnits, count: number): number;
    removeFromSelection(): void;
    scrollIntoView(alignTop: boolean): void;
    select(): void;
}

// skipping for now
// export declare interface ITextRange2 extends ITextRange {
//     showContextMenu(): void;
// }

export declare enum ToggleStates {
    Off = 0,
    On = 1,
    Indeterminate = 2
}


export declare interface ITogglePattern {
    cachedToggleState: ToggleStates;
    currentToggleState: ToggleStates;

    toggle(): void;
}

export declare interface ITransformPattern {
    cachedCanMove: boolean;
    cachedCanResize: boolean;
    cachedCanRotate: boolean;

    currentCanMove: boolean;
    currentCanResize: boolean;
    currentCanRotate: boolean;

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

export declare interface ITransformPattern2 extends ITransformPattern {
    cachedCanZoom: boolean;
    cachedZoomLevel: number;
    cachedZoomMaximum: number;
    cachedZoomMinimum: number;

    currentCanZoom: boolean;
    currentZoomLevel: number;
    currentZoomMaximum: number;
    currentZoomMinimum: number;

    zoom(zoom: number);
    zoomByUnit(zoomUnit: ZoomUnits)
}

export declare interface IValuePattern {
    cachedIsReadOnly: boolean;
    cachedValue: string;

    currentIsReadOnly: boolean;
    currentValue: string;

    setValue(value: string): void;
}

export declare interface IVirtualizedItemPattern {
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

export declare interface IWindowPattern {
    cachedCanMaximize: boolean;
    cachedCanMinimize: boolean;
    cachedIsModal: boolean;
    cachedIsTopmost: boolean;
    cachedWindowInteractionState: WindowInteractionStates;
    cachedWindowVisualState: WindowVisualStates;

    currentCanMaximize: boolean;
    currentCanMinimize: boolean;
    currentIsModal: boolean;
    currentIsTopmost: boolean;
    currentWindowInteractionState: WindowInteractionStates;
    currentWindowVisualState: WindowVisualStates;

    close(): void;
    setWindowVisualState(state: WindowVisualStates): void;
    waitForInputIdle(milliseconds: number): boolean;
}


export declare interface AutomationElement {
    buildUpdatedCache(cacheRequest: AutomationCacheRequest): AutomationElement;
    findAll(treeScope: TreeScopes, condition: AutomationCondition): AutomationElement[];
    findAllBuildCache(treeScope: TreeScopes, condition: AutomationCondition, cacheRequest: AutomationCacheRequest): AutomationElement[];
    findFirst(treeScope: TreeScopes, condition: AutomationCondition): AutomationElement;
    findFirstBuildCache(treeScope: TreeScopes, condition: AutomationCondition, cacheRequest: AutomationCacheRequest): AutomationElement;
    getCachedChildren(): AutomationElementArray;
    getCachedParent(): AutomationElement;

    // todo: this is missing, figure out if feasible.  
    // getCurrentPattern(patternId: PatternIds.CustomNavigationPatternId): ICustomNavigationPattern;    
    getCachedPattern(patternId: PatternIds.AnnotationPatternId): IAnnotationPattern;
    getCachedPattern(patternId: PatternIds.DockPatternId): IDockPattern;
    getCachedPattern(patternId: PatternIds.DragPatternId): IDragPattern;
    getCachedPattern(patternId: PatternIds.DropTargetPatternId): IDropTargetPattern;
    getCachedPattern(patternId: PatternIds.ExpandCollapsePatternId): IExpandCollapsePattern;
    getCachedPattern(patternId: PatternIds.GridItemPatternId): IGridItemPattern;
    getCachedPattern(patternId: PatternIds.GridPatternId): IGridPattern;
    getCachedPattern(patternId: PatternIds.InvokePatternId): IInvokePattern;
    getCachedPattern(patternId: PatternIds.ItemContainerPatternId): IItemContainerPattern;
    getCachedPattern(patternId: PatternIds.LegacyIAccessiblePatternId): ILegacyIAccessiblePattern;
    getCachedPattern(patternId: PatternIds.MultipleViewPatternId): IMultipleViewPattern;
    // CachedentPattern(patternId: AutomationPatterns.ObjectModelPatternId): IObjectModelPattern; // todo: not implemented due to complexity.
    getCachedPattern(patternId: PatternIds.RangeValuePatternId): IRangeValuePattern;
    getCachedPattern(patternId: PatternIds.ScrollItemPatternId): IScrollItemPattern;
    getCachedPattern(patternId: PatternIds.ScrollPatternId): IScrollPattern;
    getCachedPattern(patternId: PatternIds.SelectionItemPatternId): ISelectionItemPattern;
    getCachedPattern(patternId: PatternIds.SelectionPatternId): ISelectionPattern;
    getCachedPattern(patternId: PatternIds.SelectionPattern2Id): ISelectionPattern2;
    getCachedPattern(patternId: PatternIds.SpreadsheetItemPatternId): ISpreadsheetItemPattern;
    getCachedPattern(patternId: PatternIds.SpreadsheetPatternId): ISpreadsheetPattern;
    getCachedPattern(patternId: PatternIds.StylesPatternId): IStylesPattern;
    getCachedPattern(patternId: PatternIds.SynchronizedInputPatternId): ISynchronizedInputPattern;
    getCachedPattern(patternId: PatternIds.TableItemPatternId): ITableItemPattern;
    getCachedPattern(patternId: PatternIds.TablePatternId): ITablePattern;
    getCachedPattern(patternId: PatternIds.TextChildPatternId): ITextChildPattern;
    getCachedPattern(patternId: PatternIds.TextEditPatternId): ITextEditPattern;
    getCachedPattern(patternId: PatternIds.TextPatternId): ITextPattern;
    getCachedPattern(patternId: PatternIds.TextPattern2Id): ITextPattern2;
    getCachedPattern(patternId: PatternIds.TogglePatternId): ITogglePattern;
    getCachedPattern(patternId: PatternIds.TransformPatternId): ITransformPattern;
    getCachedPattern(patternId: PatternIds.TransformPattern2Id): ITransformPattern2;
    getCachedPattern(patternId: PatternIds.ValuePatternId): IValuePattern;
    getCachedPattern(patternId: PatternIds.VirtualizedItemPatternId): IVirtualizedItemPattern;
    getCachedPattern(patternId: PatternIds.WindowPatternId): IWindowPattern;
    getCachedPattern(patternId: PatternIds): unknown;

    getCachedPropertyValue(propertyId: PropertyIds): Variant;
    getCachedPropertyValueEx(propertyId: PropertyIds, ignoreDefaultValue: boolean): Variant;
    getClickablePoint(): Point | null;

    // todo: this is missing, figure out if feasible.  
    // getCurrentPattern(patternId: PatternIds.CustomNavigationPatternId): ICustomNavigationPattern;    
    getCurrentPattern(patternId: PatternIds.AnnotationPatternId): IAnnotationPattern;
    getCurrentPattern(patternId: PatternIds.DockPatternId): IDockPattern;
    getCurrentPattern(patternId: PatternIds.DragPatternId): IDragPattern;
    getCurrentPattern(patternId: PatternIds.DropTargetPatternId): IDropTargetPattern;
    getCurrentPattern(patternId: PatternIds.ExpandCollapsePatternId): IExpandCollapsePattern;
    getCurrentPattern(patternId: PatternIds.GridItemPatternId): IGridItemPattern;
    getCurrentPattern(patternId: PatternIds.GridPatternId): IGridPattern;
    getCurrentPattern(patternId: PatternIds.InvokePatternId): IInvokePattern;
    getCurrentPattern(patternId: PatternIds.ItemContainerPatternId): IItemContainerPattern;
    getCurrentPattern(patternId: PatternIds.LegacyIAccessiblePatternId): ILegacyIAccessiblePattern;
    getCurrentPattern(patternId: PatternIds.MultipleViewPatternId): IMultipleViewPattern;
    // getCurrentPattern(patternId: AutomationPatterns.ObjectModelPatternId): IObjectModelPattern; // todo: not implemented due to complexity.
    getCurrentPattern(patternId: PatternIds.RangeValuePatternId): IRangeValuePattern;
    getCurrentPattern(patternId: PatternIds.ScrollItemPatternId): IScrollItemPattern;
    getCurrentPattern(patternId: PatternIds.ScrollPatternId): IScrollPattern;
    getCurrentPattern(patternId: PatternIds.SelectionItemPatternId): ISelectionItemPattern;
    getCurrentPattern(patternId: PatternIds.SelectionPatternId): ISelectionPattern;
    getCurrentPattern(patternId: PatternIds.SelectionPattern2Id): ISelectionPattern2;
    getCurrentPattern(patternId: PatternIds.SpreadsheetItemPatternId): ISpreadsheetItemPattern;
    getCurrentPattern(patternId: PatternIds.SpreadsheetPatternId): ISpreadsheetPattern;
    getCurrentPattern(patternId: PatternIds.StylesPatternId): IStylesPattern;
    getCurrentPattern(patternId: PatternIds.SynchronizedInputPatternId): ISynchronizedInputPattern;
    getCurrentPattern(patternId: PatternIds.TableItemPatternId): ITableItemPattern;
    getCurrentPattern(patternId: PatternIds.TablePatternId): ITablePattern;
    getCurrentPattern(patternId: PatternIds.TextChildPatternId): ITextChildPattern;
    getCurrentPattern(patternId: PatternIds.TextEditPatternId): ITextEditPattern;
    getCurrentPattern(patternId: PatternIds.TextPatternId): ITextPattern;
    getCurrentPattern(patternId: PatternIds.TextPattern2Id): ITextPattern2;
    getCurrentPattern(patternId: PatternIds.TogglePatternId): ITogglePattern;
    getCurrentPattern(patternId: PatternIds.TransformPatternId): ITransformPattern;
    getCurrentPattern(patternId: PatternIds.TransformPattern2Id): ITransformPattern2;
    getCurrentPattern(patternId: PatternIds.ValuePatternId): IValuePattern;
    getCurrentPattern(patternId: PatternIds.VirtualizedItemPatternId): IVirtualizedItemPattern;
    getCurrentPattern(patternId: PatternIds.WindowPatternId): IWindowPattern;
    getCurrentPattern(patternId: PatternIds): unknown;

    getCurrentPropertyValue(propertyId: PropertyIds): Variant;
    getCurrentPropertyValueEx(propertyId: PropertyIds, ignoreDefaultValues: boolean): Variant;
    getRuntimeId(): number[]
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
    addStructureChangedEventHandler(element: AutomationElement, treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, eventHandler: AutomationStructureChangedEventHandler): void;
    checkNotSupported(variant: Variant): boolean;
    compareElements(elementOne: AutomationElement, elementTwo: AutomationElement): boolean;
    createAndCondition(conditionOne: AutomationCondition, conditionTwo: AutomationCondition): AutomationCondition;
    createFalseCondition(): AutomationCondition;
    createNotCondition(condition: AutomationCondition): AutomationCondition;
    createOrCondition(conditionOne: AutomationCondition, conditionTwo: AutomationCondition): AutomationCondition;
    createPropertyCondition(propertyId: PropertyIds, value: Variant): AutomationCondition;
    createTreeWalker(condition: AutomationCondition): AutomationTreeWalker;
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
    removeStructureChangedEventHandler(element: AutomationElement, eventHandler: AutomationStructureChangedEventHandler): void;

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