const { Automation, TreeScopes, AutomationProperties, AutomationElementModes } = require('microsoft-ui-automation');

describe('IUIAutomationElement', () => {
    let winver = null;
    const automation = new Automation();
    let desktopElement = null;
    let winverElement = null;

    test('getRootElement', () => {
        desktopElement = automation.getRootElement();
    });

    test('buildUpdatedCache', () => {
        let cacheRequest = automation.createCacheRequest();

        const updatedCacheElement = desktopElement.buildUpdatedCache(cacheRequest);

        expect(updatedCacheElement).toBeDefined();
    });

    test('findAll', () => {
        const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

        const elements = desktopElement.findAll(TreeScopes.Subtree, winverNamePropertyCondition);

        const winverElement = elements.getElement(0);

        expect(winverElement).toBeDefined();
    });


    test('findAllBuildCache', () => {
        const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

        let cacheRequest = automation.createCacheRequest();

        const winverElement = desktopElement.findAllBuildCache(TreeScopes.Subtree, winverNamePropertyCondition, cacheRequest);

        expect(winverElement).toBeDefined();
    });

    test('findFirst', () => {
        const propertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

        winverElement = desktopElement.findFirst(TreeScopes.Subtree, propertyCondition);

        expect(winverElement).not.toBeNull();
    });

    test('findFirstBuildCache', () => {
        const propertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

        const cacheRequest = automation.createCacheRequest();

        winverElement = desktopElement.findFirstBuildCache(TreeScopes.Subtree, propertyCondition, cacheRequest);

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
        let cacheRequest = automation.createCacheRequest();

        cacheRequest.automationElementMode = AutomationElementModes.None;

        cacheRequest.treeFilter = automation.rawViewCondition;

        cacheRequest.addProperty(AutomationProperties.NamePropertyId);

        winverCachedElement = winverElement.buildUpdatedCache(cacheRequest);

        const value = winverCachedElement.getCachedPropertyValue(AutomationProperties.NamePropertyId);

        expect(value).toBe('About Windows');
    });

    test('getCachedPropertyValueEx', () => {
        let cacheRequest = automation.createCacheRequest();

        cacheRequest.automationElementMode = AutomationElementModes.None;

        cacheRequest.treeFilter = automation.rawViewCondition;

        cacheRequest.addProperty(AutomationProperties.NamePropertyId);

        winverCachedElement = winverElement.buildUpdatedCache(cacheRequest);

        const value = winverCachedElement.getCachedPropertyValueEx(AutomationProperties.NamePropertyId, true);

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
        const value = winverElement.getCurrentPropertyValue(AutomationProperties.NamePropertyId);

        expect(value).toBe('About Windows');
    });

    test('getCurrentPropertyValueEx', () => {
        const value = winverElement.getCurrentPropertyValueEx(AutomationProperties.NamePropertyId, true);

        expect(value).toBe('About Windows');
    });

    // skipped
    test.todo('getRuntimeId');

    test('setFocus', () => {
        winverElement.setFocus();
    });
});