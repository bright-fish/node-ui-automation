const { IUIAutomation, TreeScope } = require('../build/Debug/automation');


describe('IUIAutomationElement', () => {
    let automation = null;
    let desktopElement = null;

    beforeAll(() => {
        // start up winver
    });

    afterAll(() => {
        // stop winver
    });

    test('getRootElement', () => {
        automation = new IUIAutomation();

        desktopElement = automation.getRootElement();
    });

    test.todo('buildUpdatedCache');
    test.todo('findAll');
    test.todo('findAllBuildCache');
    test.todo('findFirst');
    test.todo('findFirstBuildCache');
    test.todo('getCachedChildren');
    test.todo('getCachedParent');
    test.todo('getCachedPattern');
    test.todo('getCachedPatternAs');
    test.todo('getCachedPropertyValue');
    test.todo('getCachedPropertyValueEx');
    test.todo('getClickablePoint');
    test.todo('getCurrentPattern');
    test.todo('getCurrentPatternAs');
    test.todo('getCurrentPropertyValue');
    test.todo('getCurrentPropertyValueEx');
    test.todo('getRuntimeId');
    test.todo('setFocus');
});