export declare interface AutomationCacheRequest {
    addPattern(patternId: AutomationPatterns): void;
    addProperty(propertyId: AutomationProperties): void;
    clone(): AutomationCacheRequest;

    automationElementMode: AutomationElementModes;
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
    Top,
    Left,
    Bottom,
    Right,
    Fill,
    None
}

export declare interface IDockProvider {
    dockPosition: DockPositions;

    setDockPosition(dockPosition: DockPositions): void;
}

export declare interface IDragProvider {
    dropEffects: string[];
    dropEffect: string;
    isGrabbed: boolean;
    getGrabbedItems: IRawElementProviderSimple[];
}

export declare interface IDropTargetProvider {
    dropTargetEffect: string;
    dropTargetEffects: string[];
}

export declare enum ExpandCollapseState {
    // todo: enum pass
    Collapsed,
    Expanded,
    PartiallyExpanded,
    LeafNode
}

export declare interface IExpandCollapseProvider {
    collapse(): void;
    expand(): void;
    expandCollapseState: ExpandCollapseState
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
    findItemByProperty(startAfter: IRawElementProviderSimple, propertyId: AutomationProperties, value: Variant): IRawElementProviderSimple;
}

export declare interface IAccessible {

}

export declare interface SelectionFlags {
    None: 0,
    TakeFocus: 0x1,
    AddSelection: 0x2,
    RemoveSelection: 0x4,
    TakeSelection: 0x8,
    ExtendSelection: 0x10
}

export declare interface ILegacyIAccessibleProvider {
    doDefaultAction(): void;
    childId: number;
    defaultAction: string;
    description: string;
    help: string;
    keyboardShortcut: string;
    name: string;
    role: number;
    state: number;
    value: string;
    getAccessible(): IAccessible;
    getSelection(): IRawElementProviderSimple[];
    select(flag: SelectionFlags);
    setValue(value: string): void;
}

export declare interface IMultipleViewProvider {
    currentView: number;
    getSupportedViews(): number[];
    getViewName(viewId: number): string;
    setCurrentView(viewId: number): void;
}

export declare interface IObjectModelProvider {
    // todo:  getUnderlyingObjectModel();
    // this function requires that we return an IUnknown pointer and casting that doesnt really make sense.  
    // one thought would be to return the underlying pointer as a node buffer.  This would allow someone to get the memory out of it if neccessary.  

}

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

// todo: figure out values
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
    hostElementProvider: IRawElementProviderSimple;
    providerOptions: ProviderOptions;

    // todo: this is missing, figure out if feasible.  
    // getPatternProvider(patternId: AutomationPatterns.CustomNavigationPatternId): IAnnotationProvider;    
    getPatternProvider(patternId: AutomationPatterns.AnnotationPatternId): IAnnotationProvider;
    getPatternProvider(patternId: AutomationPatterns.DockPatternId): IDockProvider;
    getPatternProvider(patternId: AutomationPatterns.DragPatternId): IDragProvider;
    getPatternProvider(patternId: AutomationPatterns.DropTargetPatternId): IDropTargetProvider;
    getPatternProvider(patternId: AutomationPatterns.ExpandCollapsePatternId): IExpandCollapseProvider;
    getPatternProvider(patternId: AutomationPatterns.GridItemPatternId): IGridItemProvider;
    getPatternProvider(patternId: AutomationPatterns.GridPatternId): IGridProvider;
    getPatternProvider(patternId: AutomationPatterns.InvokePatternId): IInvokeProvider;
    getPatternProvider(patternId: AutomationPatterns.ItemContainerPatternId): IItemContainerProvider;
    getPatternProvider(patternId: AutomationPatterns.LegacyIAccessiblePatternId): ILegacyIAccessibleProvider;
    getPatternProvider(patternId: AutomationPatterns.MultipleViewPatternId): IMultipleViewProvider;
    getPatternProvider(patternId: AutomationPatterns.ObjectModelPatternId): IObjectModelProvider; // todo: not implemented due to complexity.
    getPatternProvider(patternId: AutomationPatterns.RangeValuePatternId): IRangeValueProvider;
    getPatternProvider(patternId: AutomationPatterns.ScrollItemPatternId): IScrollItemProvider;
    getPatternProvider(patternId: AutomationPatterns.ScrollPatternId): IScrollProvider;
    getPatternProvider(patternId: AutomationPatterns.SelectionItemPatternId): ISelectionItemProvider;
    getPatternProvider(patternId: AutomationPatterns.SelectionPatternId): ISelectionProvider;
    getPatternProvider(patternId: AutomationPatterns.SelectionPattern2Id): ISelectionProvider2;
    getPatternProvider(patternId: AutomationPatterns.SpreadsheetItemPatternId): ISpreadsheetItemProvider;
    getPatternProvider(patternId: AutomationPatterns.SpreadsheetPatternId): ISpreadsheetProvider;
    getPatternProvider(patternId: AutomationPatterns.StylesPatternId): IStylesProvider;
    getPatternProvider(patternId: AutomationPatterns.SynchronizedInputPatternId): ISynchronizedInputProvider;
    getPatternProvider(patternId: AutomationPatterns.TableItemPatternId): ITableItemProvider;
    getPatternProvider(patternId: AutomationPatterns.TablePatternId): ITableProvider;
    getPatternProvider(patternId: AutomationPatterns.TextChildPatternId): ITextChildProvider;
    getPatternProvider(patternId: AutomationPatterns.TextEditPatternId): ITextEditProvider;
    getPatternProvider(patternId: AutomationPatterns.TextPatternId): ITextProvider;
    getPatternProvider(patternId: AutomationPatterns.TextPattern2Id): ITextProvider2;
    getPatternProvider(patternId: AutomationPatterns.TogglePatternId): IToggleProvider;
    getPatternProvider(patternId: AutomationPatterns.TransformPatternId): ITransformProvider;
    getPatternProvider(patternId: AutomationPatterns.TransformPattern2Id): ITransformProvider2;
    getPatternProvider(patternId: AutomationPatterns.ValuePatternId): IValueProvider;
    getPatternProvider(patternId: AutomationPatterns.VirtualizedItemPatternId): IVirtualizedItemProvider;
    getPatternProvider(patternId: AutomationPatterns.WindowPatternId): IWindowProvider;
    getPatternProvider(patternId: AutomationPatterns): unknown;

    getPropertyValue(propertyId: AutomationProperties): Variant;
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
    scroll(horizontalAmount: number, verticalAmount: number);
    setScrollPercent(horizontalPercent: number, verticalPercent: number);
}

export declare interface ISelectionItemProvider {
    addToSelection(): void;
    isSelected: boolean;
    selectionContainer: IRawElementProviderSimple;
    removeFromSelection(): void;
    select(): void;
}

export declare interface ISelectionProvider {
    canSelectMultiple: boolean;
    isSelectionRequired: boolean;
    getSelection(): IRawElementProviderSimple[];
}

export declare interface ISelectionProvider2 {
    currentSelectedItem: IRawElementProviderSimple;
    firstSelectedItem: IRawElementProviderSimple;
    itemCount: number;
    lastSelectedItem: IRawElementProviderSimple;
}

export declare interface AutomationAnnotationTypes {
    // todo: enum pass
}
export declare interface ISpreadsheetItemProvider {
    formula: string;
    getAnnotationObjects(): IRawElementProviderSimple[];
    getAnnotationTypes(): AutomationAnnotationTypes[];
}

export declare interface ISpreadsheetProvider {
    getItemByName(name: string): IRawElementProviderSimple
}

export declare interface AutomationStyles {
    // todo: enum pass
}

export declare interface IStylesProvider {
    extendedProperties: string;
    fillColor: number;
    fillPatternColor: number;
    fillPatternStyle: string;
    shape: string;
    styleId: AutomationStyles;
    styleName: string;
}


export declare interface AutomationSynchronizedInputTypes {
    // todo: enum pass
    KeyUp,
    KeyDown,
    LeftMouseUp,
    LeftMouseDown,
    RightMouseUp,
    RightMouseDown
}

export declare interface ISynchronizedInputProvider {
    cancel();
    startListening(synchronizedInputType: AutomationSynchronizedInputTypes);
}

export declare interface ITableItemProvider {
    getColumnHeaderItems(): IRawElementProviderSimple[];
    getRowHeaderItems(): IRawElementProviderSimple[];
}

export declare enum AutomationRowOrColumnMajor {
    // todo: enum pass
    RowMajor,
    ColumnMajor,
    Indeterminate
}

export declare interface ITableProvider {
    rowOrColumnMajor: AutomationRowOrColumnMajor;
    getColumnHeaders(): IRawElementProviderSimple[];
    getRowHeaders(): IRawElementProviderSimple[];
}

export declare interface ITextChildProvider {
    textContainer: IRawElementProviderSimple;
    textRange: ITextRangeProvider;
}

export declare interface ITextEditProvider {
    getActiveComposition(): ITextRangeProvider;
    getC
    onversionTarget(): ITextRangeProvider;
}
export declare enum AutomationSupportedTextSelections {
    // todo: enum pass
    None,
    Single,
    Multiple
}

export declare interface ITextProvider {
    documentRange: ITextRangeProvider
    supportedTextSelection: AutomationSupportedTextSelections;
    getSelection(): ITextRangeProvider[];
    getVisibleRanges(): ITextRangeProvider[];
    rangeFromChild(childElement: IRawElementProviderSimple): ITextRangeProvider;
    rangeFromPoint(point: Point): ITextRangeProvider;
}



export declare interface ITextProvider2 extends ITextProvider {
    getCaretRange(): { isActive: boolean, value: ITextRangeProvider };
    rangeFromAnnotation(annotationElement: IRawElementProviderSimple): ITextRangeProvider;
}

export declare enum AutomationTextPatternRangeEndpoint {
    // todo: enum pass
    Start,
    End
}

export declare enum TextUnits {
    // todo: enum pass
    Character,
    Format,
    Word,
    Line,
    Paragraph,
    Page,
    Document
}

export declare enum AutomationAttributes {
    // todo: enum pass
}


export declare interface ITextRangeProvider {
    addToSelection(): void;
    clone(): ITextRangeProvider;
    compare(range: ITextRangeProvider): boolean;
    compareEndpoints(endpoint: AutomationTextPatternRangeEndpoint, targeRange: ITextRangeProvider, targetEndpoint: AutomationTextPatternRangeEndpoint): number;
    expandToEnclosingUnit(textUnit: TextUnits);
    findAttribute(attributeId: AutomationAttributes, value: Variant, backward: boolean): ITextRangeProvider;
    findText(text: string, backward: boolean, ignoreCase: boolean): ITextRangeProvider;
    getAttributeValue(attributeId: AutomationAttributes): Variant;
    getBoundingRectangles(): Rect[]; //todo: read documentation and validate all 3 special cases.  
    getChildren(): IRawElementProviderSimple[];
    getEnclosingElement(): IRawElementProviderSimple;
    getText(maxLength: number): string;
    move(textUnit: TextUnits, count: number): number;
    moveEndpointByRange(endpoint: AutomationTextPatternRangeEndpoint, targetRange: ITextRangeProvider, targetEndpoint: AutomationTextPatternRangeEndpoint): void;
    moveEndpointByUnit(endpoint: AutomationTextPatternRangeEndpoint, textUnit: TextUnits, count: number): number;
    removeFromSelection(): void;
    scrollIntoView(alignTop: boolean): void;
    select(): void;
}

export declare interface ITextRangeProvider2 extends ITextRangeProvider {
    showContextMenu(): void;
}

export declare enum ToggleStates {
    // todo: enum pass

    Off,
    On,
    Indeterminate
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
    NoAmount,
    LargeDecrement,
    SmallDecrement,
    LargeIncrement,
    SmallIncrement
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
    // todo: enum pass
    Running,
    Closing,
    ReadyForUserInteraction,
    BlockedByModalWindow,
    NotResponding
}

export declare enum WindowVisualStates {
    // todo: enum pass
    Normal,
    Maximized,
    Minimized
}
export declare interface IWindowProvider {
    close(): void;
    canMaximize: boolean;
    canMinimize: boolean;
    isModal: boolean;
    isTopmost: boolean;
    windowInteractionState: WindowInteractionStates;
    windowVisualState: WindowVisualStates;
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
    getCachedPropertyValue(propertyId: AutomationProperties): Variant;
    getCachedPropertyValueEx(propertyId: AutomationProperties, ignoreDefaultValue: boolean): Variant;
    getClickablePoint(point: Point): boolean;

    // todo: this is missing, figure out if feasible.  
    // getCurrentPattern(patternId: AutomationPatterns.CustomNavigationPatternId): IAnnotationProvider;    
    getCurrentPattern(patternId: AutomationPatterns.AnnotationPatternId): IAnnotationProvider;
    getCurrentPattern(patternId: AutomationPatterns.DockPatternId): IDockProvider;
    getCurrentPattern(patternId: AutomationPatterns.DragPatternId): IDragProvider;
    getCurrentPattern(patternId: AutomationPatterns.DropTargetPatternId): IDropTargetProvider;
    getCurrentPattern(patternId: AutomationPatterns.ExpandCollapsePatternId): IExpandCollapseProvider;
    getCurrentPattern(patternId: AutomationPatterns.GridItemPatternId): IGridItemProvider;
    getCurrentPattern(patternId: AutomationPatterns.GridPatternId): IGridProvider;
    getCurrentPattern(patternId: AutomationPatterns.InvokePatternId): IInvokeProvider;
    getCurrentPattern(patternId: AutomationPatterns.ItemContainerPatternId): IItemContainerProvider;
    getCurrentPattern(patternId: AutomationPatterns.LegacyIAccessiblePatternId): ILegacyIAccessibleProvider;
    getCurrentPattern(patternId: AutomationPatterns.MultipleViewPatternId): IMultipleViewProvider;
    getCurrentPattern(patternId: AutomationPatterns.ObjectModelPatternId): IObjectModelProvider; // todo: not implemented due to complexity.
    getCurrentPattern(patternId: AutomationPatterns.RangeValuePatternId): IRangeValueProvider;
    getCurrentPattern(patternId: AutomationPatterns.ScrollItemPatternId): IScrollItemProvider;
    getCurrentPattern(patternId: AutomationPatterns.ScrollPatternId): IScrollProvider;
    getCurrentPattern(patternId: AutomationPatterns.SelectionItemPatternId): ISelectionItemProvider;
    getCurrentPattern(patternId: AutomationPatterns.SelectionPatternId): ISelectionProvider;
    getCurrentPattern(patternId: AutomationPatterns.SelectionPattern2Id): ISelectionProvider2;
    getCurrentPattern(patternId: AutomationPatterns.SpreadsheetItemPatternId): ISpreadsheetItemProvider;
    getCurrentPattern(patternId: AutomationPatterns.SpreadsheetPatternId): ISpreadsheetProvider;
    getCurrentPattern(patternId: AutomationPatterns.StylesPatternId): IStylesProvider;
    getCurrentPattern(patternId: AutomationPatterns.SynchronizedInputPatternId): ISynchronizedInputProvider;
    getCurrentPattern(patternId: AutomationPatterns.TableItemPatternId): ITableItemProvider;
    getCurrentPattern(patternId: AutomationPatterns.TablePatternId): ITableProvider;
    getCurrentPattern(patternId: AutomationPatterns.TextChildPatternId): ITextChildProvider;
    getCurrentPattern(patternId: AutomationPatterns.TextEditPatternId): ITextEditProvider;
    getCurrentPattern(patternId: AutomationPatterns.TextPatternId): ITextProvider;
    getCurrentPattern(patternId: AutomationPatterns.TextPattern2Id): ITextProvider2;
    getCurrentPattern(patternId: AutomationPatterns.TogglePatternId): IToggleProvider;
    getCurrentPattern(patternId: AutomationPatterns.TransformPatternId): ITransformProvider;
    getCurrentPattern(patternId: AutomationPatterns.TransformPattern2Id): ITransformProvider2;
    getCurrentPattern(patternId: AutomationPatterns.ValuePatternId): IValueProvider;
    getCurrentPattern(patternId: AutomationPatterns.VirtualizedItemPatternId): IVirtualizedItemProvider;
    getCurrentPattern(patternId: AutomationPatterns.WindowPatternId): IWindowProvider;
    getCurrentPattern(patternId: AutomationPatterns): unknown;

    getCurrentPropertyValue(propertyId: AutomationProperties): Variant;
    getCurrentPropertyValueEx(propertyId: AutomationProperties, ignoreDefaultValues: boolean): Variant;
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
    currentControlType: ControlTypes;
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
    cachedControlType: ControlTypes;
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
    constructor(callback: (sender: AutomationElement, eventId: AutomationEvents) => void);
}

export declare class AutomationFocusChangedEventHandler {
    constructor(callback: (sender: AutomationElement) => void);
}

export declare class AutomationPropertyChangedEventHandler {
    constructor(callback: (sender: AutomationElement, propertyId: AutomationProperties) => void);
}

export declare class AutomationStructurechangedEventHandler {
    constructor(callback: (sender: AutomationElement) => void);
}

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
    addAutomationEventHandler(eventId: AutomationEvents, element: AutomationElement, treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, eventHandler: AutomationEventHandler): void;
    addFocusChangedEventHandler(cacheRequest: AutomationCacheRequest, eventHandler: AutomationFocusChangedEventHandler): void;
    addPropertyChangedEventHandler(element: AutomationElement, treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, eventHandler: AutomationPropertyChangedEventHandler): void;
    addStructureChangedEventHandler(element: AutomationElement, treeScope: TreeScopes, cacheRequest: AutomationCacheRequest, eventHandler: AutomationStructurechangedEventHandler): void;
    checkNotSupported(variant: Variant): boolean;
    compareElements(elementOne: AutomationElement, elementTwo: AutomationElement): boolean;
    createAndCondition(conditionOne: AutomationCondition, conditionTwo: AutomationCondition): AutomationCondition;
    createFalseCondition(): AutomationCondition;
    createNotCondition(condition: AutomationCondition): AutomationCondition;
    createOrCondition(conditionOne: AutomationCondition, conditionTwo: AutomationCondition): AutomationCondition;
    createPropertyCondition(propertyId: AutomationProperties, value: Variant): AutomationCondition;
    createTreeWalker(condition: AutomationCondition);
    createTrueCondition(): AutomationCondition;
    elementFromPoint(point: Point): AutomationElement;
    elementFromPointBuildCache(point: Point, cacheRequest: AutomationCacheRequest): AutomationElement;
    getFocusedElement(): AutomationElement;
    getFocusedElementBuildCache(cacheRequest: AutomationCacheRequest): AutomationElement;
    getPatternProgrammaticName(patternId: AutomationPatterns): string;
    getPropertyProgrammaticName(propertyId: AutomationProperties): string;
    getRootElement(): AutomationElement;
    getRootElementBuildCache(cacheRequest: AutomationCacheRequest): AutomationElement;
    removeAllEventHandlers(): void;
    removeAutomationEventHandler(eventId: AutomationEvents, element: AutomationElement, eventHandler: AutomationEventHandler): void;
    removeFocusChangedEventHandler(eventHandler: AutomationFocusChangedEventHandler): void;
    removePropertyChangedEventHandler(element: AutomationElement, eventHandler: AutomationPropertyChangedEventHandler): void;
    removeStructureChangedEventHandler(element: AutomationElement, eventHandler: AutomationStructurechangedEventHandler): void;

    rawViewWalker: AutomationTreeWalker;
    rawViewCondition: AutomationCondition;
    contentViewWalker: AutomationTreeWalker;
    contentViewCondition: AutomationCondition;
    controlViewWalker: AutomationTreeWalker;
    controlViewCondition: AutomationCondition;
    proxyFactoryMapping: AutomationProxyFactorMapping;
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

export declare enum AutomationEvents {
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

export declare enum AutomationProperties {
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

export declare enum AutomationPatterns {
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

export declare enum AutomationElementModes {
    None = 0,
    Full = None + 1
}

export declare enum ControlTypes {
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