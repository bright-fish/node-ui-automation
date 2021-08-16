const { IUIAutomation, UIA_NamePropertyId, TreeScope } = require('../build/Debug/automation');


describe('IUIAutomationTreeWalker', () => {
    let automation = null;
    let rawViewWalker = null;

    test('create', () => {
        automation = new IUIAutomation();

        rawViewWalker = automation.rawViewWalker;
    });

    test('getFirstChildElement', () => {
        const desktopElement = automation.getRootElement();

        const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

        const winverComponent = desktopElement.findFirst(TreeScope.TreeScope_Subtree, propertyCondition);

        const firstChildElement = rawViewWalker.getFirstChildElement(winverComponent);

        expect(firstChildElement).not.toBeNull();
    });
    
    test.todo('getFirstChildElementBuildCache');
    test.todo('getLastChildElement');
    test.todo('getLastChildElementBuildCache');
    test.todo('getNextSiblingElement');
    test.todo('getNextSiblingElementBuildCache');
    test.todo('getParentElement');
    test.todo('getParentElementBuildCache');
    test.todo('getPreviousSiblingElement');
    test.todo('getPreviousSiblingElementBuildCache');
    test.todo('normalizeElement');
    test.todo('normalizeElementBuildCache');
});