const { IUIAutomation, UIA_NamePropertyId } = require('../build/Debug/automation');

describe('IUIAutomation', () => {
    let automation = null;

    test('new IUIAutomation()', () => {
        automation = new IUIAutomation();
    });

    describe('createPropertyCondition', () => {
        test('returns', () => {
            const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

            expect(propertyCondition).not.toBeNull();
        });
    });

    describe('contentViewCondition', () => {
        test.todo('returns');
    });

    describe('contentViewWalker', () => {
        test('returns', () => {
            expect(automation.contentViewWalker).not.toBeNull();
        });
    });

    describe('controlViewCondition', () => {
        test.todo('returns');
    });

    describe('controlViewWalker', () => {
        test('returns', () => {
            expect(automation.controlViewWalker).not.toBeNull();
        });
    });

    describe('proxyFactoryMapping', () => {
        test.todo('returns');
    });

    describe('rawViewCondition', () => {
        test.todo('returns');
    });

    describe('rawViewWalker', () => {
        test('returns', () => {
            expect(automation.rawViewWalker).not.toBeNull();
        });
    });

    describe('reservedMixedAttributeValue', () => {
        test.todo('returns');
    });

    describe('reservedNotSupportedValue', () => {
        test.todo('returns');
    });

    describe('addAutomationEventHandler', () => {
        test.todo('returns');
    })

    describe('addFocusChangedEventHandler', () => {
        test.todo('returns');
    });

    describe('addPropertyChangedEventHandler', () => {
        test.todo('returns');
    });

    describe('addPropertyChangedEventHandlerNativeArray', () => {
        test.todo('returns');
    });

    describe('addStructureChangedEventHandler', () => {
        test.todo('returns');
    });

    describe('checkNotSupported', () => {
        test.todo('returns');
    });

    describe('compareElements', () => {
        test.todo('returns');
    });

    describe('compareRuntimeIds', () => {
        test.todo('returns');
    });

    describe('createAndCondition', () => {
        test.todo('returns');
    });

    describe('createAndConditionFromArray', () => {
        test.todo('returns');
    });

    describe('createAndConditionFromNativeArray', () => {
        test.todo('returns');
    });

    describe('createCacheRequest', () => {
        test.todo('returns');
    });

    describe('createFalseCondition', () => {
        test.todo('returns');
    });

    describe('createNotCondition', () => {
        test.todo('returns');
    });

    describe('createOrCondition', () => {
        test.todo('returns');
    });

    describe('createOrConditionFromArray', () => {
        test.todo('returns');
    });

    describe('createOrConditionFromNativeArray', () => {
        test.todo('returns');
    });

    describe('createPropertyCondition', () => {
        test.todo('returns');
    });

    describe('createPropertyConditionEx', () => {
        test.todo('returns');
    });

    describe('createProxyFactoryEntry', () => {
        test.todo('returns');
    });

    describe('createTreeWalker', () => {
        test.todo('returns');
    });

    describe('createTrueCondition', () => {
        test.todo('returns');
    });

    describe('elementFromHandle', () => {
        test.todo('returns');
    });

    describe('elementFromHandleBuildCache', () => {
        test.todo('returns');
    });

    describe('elementFromIAccessible', () => {
        test.todo('returns');
    });

    describe('elementFromIAccessibleBuildCache', () => {
        test.todo('returns');
    });

    describe('elementFromPoint', () => {
        test.todo('returns');
    });

    describe('elementFromPointBuildCache', () => {
        test.todo('returns');
    });

    describe('getFocusedElement', () => {
        test.todo('returns');
    });

    describe('getFocusedElementBuildCache', () => {
        test.todo('returns');
    });

    describe('getPatternProgrammaticName', () => {
        test.todo('returns');
    });

    describe('getPropertyProgrammaticName', () => {
        test.todo('returns');
    });

    describe('getRootElement', () => {
        test('returns', () => {
            const desktopElement = automation.getRootElement();

            expect(desktopElement).not.toBeNull();
        });
    });

    describe('getRootElementBuildCache', () => {
        test.todo('returns');
    });

    describe('intSafeArrayToNativeArray', () => {
        test.todo('returns');
    });

    describe('pollForPotentialSupportedPatterns', () => {
        test.todo('returns');
    });

    describe('pollForPotentialSupportedProperties', () => {
        test.todo('returns');
    });

    describe('rectToVariant', () => {
        test.todo('returns');
    });

    describe('removeAllEventHandlers', () => {
        test.todo('returns');
    });

    describe('removeAutomationEventHandler', () => {
        test.todo('returns');
    });

    describe('removeFocusChangedEventHandler', () => {
        test.todo('returns');
    });

    describe('removePropertyChangedEventHandler', () => {
        test.todo('returns');
    });

    describe('removeStructureChangedEventHandler', () => {
        test.todo('returns');
    });

    describe('safeArrayToRectNativeArray', () => {
        test.todo('returns');
    });

    describe('variantToRect', () => {
        test.todo('returns');
    });
});
