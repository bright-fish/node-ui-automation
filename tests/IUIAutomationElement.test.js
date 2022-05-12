const { AutomationStructureChangedEventHandler, ExpandCollapseStates, ScrollAmounts, SupportedTextSelections, WindowVisualStates, WindowInteractionStates } = require('microsoft-ui-automation');
const { Automation, TreeScopes, PropertyIds, ElementModes, PatternIds, DockPositions, ControlTypeIds, ToggleStates } = require('microsoft-ui-automation');
const { AboutWindowsApplication, TestApplication } = require('./Shared');

describe('IUIAutomationElement', () => {
    beforeAll(() => {
        this.automation = new Automation();
        this.aboutWindowsApplication = new AboutWindowsApplication();

        this.aboutWindowsApplication.open();

        this.desktopElement = this.automation.getRootElement();

        const winverNamePropertyCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "About Windows");
        this.winverElement = this.desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);
    });

    afterAll(() => {
        this.aboutWindowsApplication.close();
    })

    test('buildUpdatedCache', () => {
        console.log(this.test);

        let cacheRequest = this.automation.createCacheRequest();

        const updatedCacheElement = this.desktopElement.buildUpdatedCache(cacheRequest);

        expect(updatedCacheElement).toBeDefined();
    });

    test('findAll', () => {
        const elements = this.desktopElement.findAll(TreeScopes.Subtree, winverNamePropertyCondition);

        const winverElement = elements.getElement(0);

        expect(winverElement).toBeDefined();
    });


    test('findAllBuildCache', () => {
        const winverNamePropertyCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "About Windows");

        let cacheRequest = this.automation.createCacheRequest();

        const winverElement = this.desktopElement.findAllBuildCache(TreeScopes.Subtree, winverNamePropertyCondition, cacheRequest);

        expect(winverElement).toBeDefined();
    });

    test('findFirst', () => {
        const propertyCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "About Windows");

        const winverElement = this.desktopElement.findFirst(TreeScopes.Subtree, propertyCondition);

        expect(winverElement).not.toBeNull();
    });

    test('findFirstBuildCache', () => {
        const propertyCondition = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "About Windows");

        const cacheRequest = this.automation.createCacheRequest();

        const winverElement = this.desktopElement.findFirstBuildCache(TreeScopes.Subtree, propertyCondition, cacheRequest);

        expect(winverElement).not.toBeNull();
    });

    test('getCachedChildren', () => {
        const cachedChildren = this.desktopElement.getCachedChildren();

        expect(cachedChildren).toBeDefined();
    });

    test('getCachedParent', () => {
        const cachedParent = winverElement.getCachedParent();

        expect(cachedParent).toBeDefined();
    });

    // skipped: required inheritance and use of IUnknown.  
    test.todo('getCachedPattern');
    // skipped: requires inheritance and use of IUnknown.  
    test.todo('getCachedPatternAs');

    test('getCachedPropertyValue', () => {
        let cacheRequest = this.automation.createCacheRequest();

        cacheRequest.automationElementMode = ElementModes.None;

        cacheRequest.treeFilter = this.automation.rawViewCondition;

        cacheRequest.addProperty(PropertyIds.NamePropertyId);

        winverCachedElement = winverElement.buildUpdatedCache(cacheRequest);

        const value = winverCachedElement.getCachedPropertyValue(PropertyIds.NamePropertyId);

        expect(value).toBe('About Windows');
    });

    test('getCachedPropertyValueEx', () => {
        let cacheRequest = this.automation.createCacheRequest();

        cacheRequest.automationElementMode = ElementModes.None;

        cacheRequest.treeFilter = this.automation.rawViewCondition;
        cacheRequest.addProperty(PropertyIds.NamePropertyId);

        winverCachedElement = winverElement.buildUpdatedCache(cacheRequest);

        const value = winverCachedElement.getCachedPropertyValueEx(PropertyIds.NamePropertyId, true);

        expect(value).toBe('About Windows');
    });

    test('getClickablePoint', () => {
        const isClickable = winverElement.getClickablePoint({ x: 123, y: 123 });

        expect(isClickable).toBe(false);
    });

    describe.only('getCurrentPattern', () => {
        beforeAll(async () => {
            this.testApplication = new TestApplication(this.automation);
            await this.testApplication.open();

            let testApplicationWindowCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "TestApplication");
            this.testApplicationWindow = this.desktopElement.findFirst(TreeScopes.Children, testApplicationWindowCondition);
        });

        afterAll(() => {
            this.testApplication.close();
        });

        test.todo('AnnotationPattern');

        test.todo('DockPattern');
        
        // test.only('DockPattern', () => {
        //     const dockPattern = this.testApplicationWindow.getCurrentPattern(PatternIds.DockPatternId);

        //     // dockPattern.currentDockPosition
        //     dockPattern.setDockPosition(DockPositions.Bottom);
        //     dockPattern.setDockPosition(DockPositions.Top);

        // });

        test.todo('DragPattern');

        test.todo('DropTargetPattern');

        test('ExpandCollapsePattern', () => {
            this.testApplication.navigateToTree();

            const universeTreeItem = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "Universe");
            const universeTreeItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, universeTreeItem);

            const expandCollapsePattern = universeTreeItemElement.getCurrentPattern(PatternIds.ExpandCollapsePatternId);

            expect(expandCollapsePattern.currentExpandCollapseState).toBe(ExpandCollapseStates.Collapsed);

            expandCollapsePattern.expand();

            expect(expandCollapsePattern.currentExpandCollapseState).toBe(ExpandCollapseStates.Expanded);

            expandCollapsePattern.collapse();

            expect(expandCollapsePattern.currentExpandCollapseState).toBe(ExpandCollapseStates.Collapsed);
        });

        test('GridItemPattern', () => {
            this.testApplication.navigateToListView();

            const listViewCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListViewSubItem-0");
            const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

            const gridItemPattern = listViewElement.getCurrentPattern(PatternIds.GridItemPatternId);

            expect(gridItemPattern.currentColumn).toBe(0);
            expect(gridItemPattern.currentColumnSpan).toBe(1);
            expect(gridItemPattern.currentContainingGrid).toBeDefined();
            expect(gridItemPattern.currentRow).toBe(0);
            expect(gridItemPattern.currentRowSpan).toBe(1);
        });

        test('GridPattern', () => {
            this.testApplication.navigateToListView();

            const listViewCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListView");

            const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

            let gridPattern = listViewElement.getCurrentPattern(PatternIds.GridPatternId);

            const firstElement = gridPattern.getItem(1, 0);

            expect(firstElement).toBeDefined();
            expect(gridPattern.currentColumnCount).toBe(1);
            expect(gridPattern.currentRowCount).toBe(9);
        });

        test('InvokePattern', () => {
            this.testApplication.navigateToButton();

            const buttonCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "Button");
            const buttonElement = this.testApplicationWindow.findFirst(TreeScopes.Subtree, buttonCondition);

            const invokePattern = buttonElement.getCurrentPattern(PatternIds.InvokePatternId);

            invokePattern.invoke();

            // todo: assert that it has been invoked.  
        });

        test.todo('ItemContainerPattern');

        test.todo('LegacyIAccessiblePattern');

        test('MultipleViewPattern', () => {
            this.testApplication.navigateToListView();

            const listViewCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListView");

            const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

            let multipleViewPattern = listViewElement.getCurrentPattern(PatternIds.MultipleViewPatternId);

            const currentSupportedViews = multipleViewPattern.getCurrentSupportedViews();

            expect(currentSupportedViews).toBeDefined();
            expect(currentSupportedViews.length).toBe(1);

            expect(multipleViewPattern.currentCurrentView).toBe(1);
            expect(multipleViewPattern.getViewName(1)).toBe('Details');

            // todo: thhis fails for the specific control in the test application.  
            // one thing to do would be find a way to manipulate the view dynamcially.  
            // multipleViewPattern.setCurrentView(1);

            // expect(multipleViewPattern.currentCurrentView).toBe(1);
        });

        test.todo('ObjectModelPattern');


        test.skip('RangeValuePattern', async () => {

        });

        test('ScrollItemPattern', async () => {
            this.testApplication.navigateToListView();

            const jupiterTreeItem = this.automation.createPropertyCondition(PropertyIds.NamePropertyId, "Jupiter");
            const jupiterTreeItemElement = this.testApplicationWindow.findFirst(TreeScopes.Subtree, jupiterTreeItem);

            let scrollItemPattern = jupiterTreeItemElement.getCurrentPattern(PatternIds.ScrollItemPatternId);

            scrollItemPattern.scrollIntoView();

            const listViewCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListView");

            const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

            let scrollPattern = listViewElement.getCurrentPattern(PatternIds.ScrollPatternId);

            scrollPattern.setScrollPercent(0, 0);
        });

        test('ScrollPattern', async () => {
            this.testApplication.navigateToListView();

            const listViewCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListView");

            const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

            let scrollPattern = listViewElement.getCurrentPattern(PatternIds.ScrollPatternId);

            expect(scrollPattern.currentHorizontalScrollPercent).toBe(0);
            expect(scrollPattern.currentHorizontalViewSize).toBe(100);
            expect(scrollPattern.currentHorizontallyScrollable).toBe(false);
            expect(scrollPattern.currentVerticalViewSize).toBeCloseTo(44.444);
            expect(scrollPattern.currentVerticalScrollPercent).toBe(0);

            expect(scrollPattern.currentVerticallyScrollable).toBe(true);

            scrollPattern.scroll(ScrollAmounts.NoAmount, ScrollAmounts.LargeIncrement);

            expect(scrollPattern.currentVerticalScrollPercent).toBe(80);

            scrollPattern.setScrollPercent(0, 40);

            expect(scrollPattern.currentVerticalScrollPercent).toBe(40);

            scrollPattern.setScrollPercent(0, 0);
        });

        test('SelectionPattern', async () => {
            this.testApplication.navigateToListView();

            const listViewCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListView");
            const listViewElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewCondition);

            let selectionPattern = listViewElement.getCurrentPattern(PatternIds.SelectionPatternId);

            expect(selectionPattern.currentCanSelectMultiple).toBe(true);
            expect(selectionPattern.currentIsSelectionRequired).toBe(false);

            let selection = selectionPattern.getCurrentSelection();

            expect(selection.length).toBe(0);

            const listViewItemCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListViewItem-0");
            const listViewItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewItemCondition);

            const selectionItemPattern = listViewItemElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

            selectionItemPattern.select();

            selection = selectionPattern.getCurrentSelection();

            expect(selection.length).toBe(1);
        });

        test('SelectionItemPattern', async () => {
            this.testApplication.navigateToListView();

            const listViewItemCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "ListViewItem-0");
            const listViewItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, listViewItemCondition);

            const selectionItemPattern = listViewItemElement.getCurrentPattern(PatternIds.SelectionItemPatternId);

            expect(selectionItemPattern.currentIsSelected).toBe(false);

            selectionItemPattern.select();

            expect(selectionItemPattern.currentIsSelected).toBe(true);

            selectionItemPattern.removeFromSelection();

            expect(selectionItemPattern.currentIsSelected).toBe(false);

            selectionItemPattern.addToSelection();

            expect(selectionItemPattern.currentIsSelected).toBe(true);

            selectionItemPattern.removeFromSelection();

            expect(selectionItemPattern.currentIsSelected).toBe(false);
        });

        test.todo('SpreadsheetItemPattern');

        test.todo('SpreadsheetPattern');

        test.todo('StylesPattern');

        test.todo('SynchronizedInputPattern');

        test('TablePattern', async () => {
            this.testApplication.navigateToDataView();
        });

        test('TableItemPattern', async () => {
            this.testApplication.navigateToDataView();
        });

        // todo: need to come back and test this pattern.
        test('TextChildPattern', async () => {
            this.testApplication.navigateToRichTextBox();

            const richTextBoxItemCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "RichTextBox");
            const richTextBoxItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, richTextBoxItemCondition);

            const textChildPattern = richTextBoxItemElement.getCurrentPattern(PatternIds.TextChildPatternId);

            // expect(textChildPattern.textContainer).toBeDefined();
            // expect(textChildPattern.textRange).toBeDefined();

            // const text = textChildPattern.textRange.getText(1024);

            // expect(text).toBe();
        });

        // todo: My assumptions about this pattern were wrong.  I need to read this article before proceeding to test.  
        // https://docs.microsoft.com/en-us/windows/win32/winauto/textedit-control-pattern
        test.skip('TextEditPattern', async () => {
            this.testApplication.navigateToRichTextBox();

            const richTextBoxItemCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "RichTextBox");
            let richTextBoxItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, richTextBoxItemCondition);

            // const valuePattern = richTextBoxItemElement.getCurrentPattern(PatternIds.ValuePatternId);

            // valuePattern.setValue('I am a string.');

            // richTextBoxItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, richTextBoxItemCondition);

            const textEditPattern = richTextBoxItemElement.getCurrentPattern(PatternIds.TextEditPatternId);


            // expect(textEditPattern.documentRange).toBeDefined();
            expect(textEditPattern.getActiveComposition()).toBeDefined();
            expect(textEditPattern.getConversionTarget()).toBeDefined();
            // expect(textEditPattern.getSelection()).toBeDefined();
            // expect(textEditPattern.getVisibleRanges()).toBeDefined();
            // expect(textEditPattern.supportedTextSelection).toBe(SupportedTextSelections.None);
        });

        test('TextPattern', async () => {
            this.testApplication.navigateToRichTextBox();

            const richTextBoxItemCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "RichTextBox");
            const richTextBoxItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, richTextBoxItemCondition);

            const textChildPattern = richTextBoxItemElement.getCurrentPattern(PatternIds.TextPatternId);

            expect(textChildPattern.documentRange).toBeDefined();
            expect(textChildPattern.getSelection()).toBeDefined();
            expect(textChildPattern.getVisibleRanges()).toBeDefined();
            // todo: Need to place an image in the RichTextBox for this to work. 
            // expect(textChildPattern.rangeFromChild()).toBeDefined();

            const boundingRectangle = richTextBoxItemElement.currentBoundingRectangle;

            const centerPoint = { x: 0, y: 0 };

            centerPoint.x = boundingRectangle.left + (boundingRectangle.right - boundingRectangle.left) / 2;
            centerPoint.y = boundingRectangle.top + (boundingRectangle.bottom - boundingRectangle.top) / 2;

            const range = textChildPattern.rangeFromPoint(centerPoint);

            expect(range).toBeDefined();
        });

        test('TogglePattern', async () => {
            this.testApplication.navigateToCheckBox();

            const checkBoxItemCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "CheckBox");
            const checkBoxItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, checkBoxItemCondition);

            const togglePattern = checkBoxItemElement.getCurrentPattern(PatternIds.TogglePatternId);

            expect(togglePattern.currentToggleState).toBe(ToggleStates.Off);

            togglePattern.toggle();

            expect(togglePattern.currentToggleState).toBe(ToggleStates.On);
        });

        test('TransformPattern', async () => {
            const transformPattern = this.testApplicationWindow.getCurrentPattern(PatternIds.TransformPatternId);

            expect(transformPattern.currentCanMove).toBe(true);
            if (transformPattern.currentCanMove) {
                transformPattern.move(0, 0);
            }

            expect(transformPattern.currentCanResize).toBe(true);
            if (transformPattern.currentCanResize) {
                transformPattern.resize(800, 600);
            }

            expect(transformPattern.currentCanRotate).toBe(false);
            if (transformPattern.currentCanRotate) {
                transformPattern.rotate(90);
            }
        });

        test('ValuePattern', async () => {
            this.testApplication.navigateToText();

            const textBoxItemCondition = this.automation.createPropertyCondition(PropertyIds.AutomationIdPropertyId, "TextBox");
            const textBoxItemElement = this.testApplicationWindow.findFirst(TreeScopes.Descendants, textBoxItemCondition);

            const valuePattern = textBoxItemElement.getCurrentPattern(PatternIds.ValuePatternId);

            expect(valuePattern.currentIsReadOnly).toBe(false);

            expect(valuePattern.currentValue).toBe('Text Box Value');

            const value = 'Test';

            valuePattern.setValue(value);

            expect(valuePattern.currentValue).toBe(value);
        });

        test('VirtualizedItemPattern', async () => {
            this.testApplication.navigateToListView();

            // todo: need to create a virtualized item list.  
        });

        test.only('WindowPattern', async () => {
            const windowPattern = this.testApplicationWindow.getCurrentPattern(PatternIds.WindowPatternId);

            expect(windowPattern.currentCanMaximize).toBe(true);
            expect(windowPattern.currentCanMinimize).toBe(true);
            expect(windowPattern.currentIsModal).toBe(false);
            expect(windowPattern.currentIsTopmost).toBe(false);
            expect(windowPattern.currentWindowInteractionState).toBe(WindowInteractionStates.ReadyForUserInteraction);
            expect(windowPattern.currentWindowVisualState).toBe(WindowVisualStates.Normal);

            windowPattern.setWindowVisualState(WindowVisualStates.Minimized);

            expect(windowPattern.currentWindowVisualState).toBe(WindowVisualStates.Minimized);

            windowPattern.setWindowVisualState(WindowVisualStates.Normal);

            expect(windowPattern.currentWindowVisualState).toBe(WindowVisualStates.Normal);

            // todo: is not impelemnted
            // const isInputIdle = windowPattern.waitForInputIdle(0);

            // expect(isInputIdle).toBe(true);
        });
    });

    // skipped: javascript has no support for generics or templating.  
    test.todo('getCurrentPatternAs');

    test('getCurrentPropertyValue', () => {
        const value = winverElement.getCurrentPropertyValue(PropertyIds.NamePropertyId);

        expect(value).toBe('About Windows');
    });

    test('getCurrentPropertyValueEx', () => {
        const value = winverElement.getCurrentPropertyValueEx(PropertyIds.NamePropertyId, true);

        expect(value).toBe('About Windows');
    });

    // skipped
    test.todo('getRuntimeId');

    test('setFocus', () => {
        winverElement.setFocus();
    });
});