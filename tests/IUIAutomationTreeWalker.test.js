const { Automation, PropertyIds, TreeScopes } = require('microsoft-ui-automation');
const { AboutWindowsApplication } = require('./Shared');

describe('IUIAutomationTreeWalker', () => {
    const aboutWindowsApplication = new AboutWindowsApplication();
    aboutWindowsApplication.open();

    const automation = new Automation();
    const desktopElement = automation.getRootElement();
    const propertyCondition = automation.createPropertyCondition(PropertyIds.NamePropertyId, "About Windows");
    const winverElement = desktopElement.findFirst(TreeScopes.Subtree, propertyCondition);

    afterAll(() => {
        aboutWindowsApplication.close();
    });

    test('rawViewWalker getter', () => {
        expect(automation.rawViewWalker).toBeDefined();
    });

    test('getFirstChildElement', () => {
        const firstChildElement = automation.rawViewWalker.getFirstChildElement(winverElement);

        expect(firstChildElement).not.toBeNull();
    });

    test('getFirstChildElementBuildCache', () => {
        const cacheRequest = automation.createCacheRequest();

        const firstChildElement = automation.rawViewWalker.getFirstChildElementBuildCache(winverElement, cacheRequest);

        expect(firstChildElement).not.toBeNull();
    });

    test('getLastChildElement', () => {
        const lastChildElement = automation.rawViewWalker.getLastChildElement(winverElement);

        expect(lastChildElement).not.toBeNull();
    });

    test('getLastChildElementBuildCache', () => {
        const cacheRequest = automation.createCacheRequest();

        const lastChildElement = automation.rawViewWalker.getLastChildElementBuildCache(winverElement, cacheRequest);

        expect(lastChildElement).not.toBeNull();
    });

    test('getNextSiblingElement', () => {
        const nextSiblingElement = automation.rawViewWalker.getNextSiblingElement(winverElement);

        expect(nextSiblingElement).not.toBeNull();
    });

    test('getNextSiblingElementBuildCache', () => {
        const cacheRequest = automation.createCacheRequest();

        const nextSiblingElement = automation.rawViewWalker.getNextSiblingElementBuildCache(winverElement, cacheRequest);

        expect(nextSiblingElement).not.toBeNull();
    });

    test('getParentElement', () => {
        const parentElement = automation.rawViewWalker.getParentElement(winverElement);

        expect(parentElement).not.toBeNull();
    });

    test('getParentElementBuildCache', () => {
        const cacheRequest = automation.createCacheRequest();

        const parentElement = automation.rawViewWalker.getParentElementBuildCache(winverElement, cacheRequest);

        expect(parentElement).not.toBeNull();
    });

    test('getPreviousSiblingElement', () => {
        const previousSiblingElement = automation.rawViewWalker.getPreviousSiblingElement(winverElement);

        expect(previousSiblingElement).not.toBeNull();
    });

    test('getPreviousSiblingElementBuildCache', () => {
        const cacheRequest = automation.createCacheRequest();

        const previousSiblingElement = automation.rawViewWalker.getFirstChildElementBuildCache(winverElement, cacheRequest);

        expect(previousSiblingElement).not.toBeNull();
    });

    test('normalizeElement', () => {
        const normalizedElement = automation.rawViewWalker.normalizeElement(winverElement);

        expect(normalizedElement).not.toBeNull();
    });

    test('normalizeElementBuildCache', () => {
        const cacheRequest = automation.createCacheRequest();

        const normalizedElement = automation.rawViewWalker.normalizeElementBuildCache(winverElement, cacheRequest);

        expect(normalizedElement).not.toBeNull();
    });
});