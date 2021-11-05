const { IUIAutomation, TreeScope, UIA_NamePropertyId } = require('bindings')('Automation');

describe('IUIAutomationElement', () => {
    let winver = null;
    let automation = null;
    let desktopElement = null;
    let winverElement = null;

    test('getRootElement', () => {
        automation = new IUIAutomation();

        desktopElement = automation.getRootElement();
    });

    test('buildUpdatedCache', () => {
        let cacheRequest = automation.createCacheRequest();

        const updatedCacheElement = desktopElement.buildUpdatedCache(cacheRequest);

        expect(updatedCacheElement).toBeDefined();
    });

    test('findAll', () => {
        const winverNamePropertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

        const elements = desktopElement.findAll(TreeScope.TreeScope_Subtree, winverNamePropertyCondition);

        const winverElement = elements.getElement(0);

        expect(winverElement).toBeDefined();
    });


    test('findAllBuildCache', () => {
        const winverNamePropertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

        let cacheRequest = automation.createCacheRequest();

        const winverElement = desktopElement.findAllBuildCache(TreeScope.TreeScope_Subtree, winverNamePropertyCondition, cacheRequest);
    });

    test('findFirst', () => {
        const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

        winverElement = desktopElement.findFirst(TreeScope.TreeScope_Subtree, propertyCondition);

        expect(winverElement).not.toBeNull();
    });

    test('findFirstBuildCache', () => {
        const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

        const cacheRequest = automation.createCacheRequest();

        winverElement = desktopElement.findFirstBuildCache(TreeScope.TreeScope_Subtree, propertyCondition, cacheRequest);

        expect(winverElement).not.toBeNull();
    });

    test('getCachedChildren', () => {
        const cachedChildren = desktopElement.getCachedChildren();

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
        const value = winverElement.getCachedPropertyValue(UIA_NamePropertyId);

        expect(value).toBe('About Windows');
    });

    test('getCachedPropertyValueEx', () => { 
        const value = winverElement.getCachedPropertyValueEx(UIA_NamePropertyId, true);

        expect(value).toBe('About Windows');
    });

    test('getClickablePoint', () => { 
        const isClickable = winverElement.getClickablePoint({ x: 123, y: 123 });

        expect(isClickable).toBe(false);
    });

    // skipped
    test.todo('getCurrentPattern');
    // skipped
    test.todo('getCurrentPatternAs');

    test('getCurrentPropertyValue', () => { 
        // todo: here
        const value = winverElement.getCurrentPropertyValue(UIA_NamePropertyId);

        expect(value).toBe('About Windows');
    });

    test('getCurrentPropertyValueEx', () => { 
        const value = winverElement.getCurrentPropertyValueEx(UIA_NamePropertyId, true);

        expect(value).toBe('About Windows');
    });

    // skipped
    test.todo('getRuntimeId');

    test('setFocus', () => { 
        winverElement.setFocus();
    });
});