const { IUIAutomation, IUIAutomationEventHandler, UIA_NamePropertyId, UIA_Window_WindowOpenedEventId, UIA_Invoke_InvokedEventId, TreeScope } = require('../build/Debug/Automation');

describe('IUIAutomation', () => {
    let automation = null;

    test('constructor', () => {
        automation = new IUIAutomation();
    });

    describe('createPropertyCondition', () => {
        test('returns', () => {
            const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

            expect(propertyCondition).not.toBeNull();
        });
    });

    describe('contentViewCondition', () => {
        test('returns', () => {
            expect(automation.contentViewCondition).not.toBeNull();
        });
    });

    describe('contentViewWalker', () => {
        test('returns', () => {
            expect(automation.contentViewWalker).not.toBeNull();
        });
    });

    describe('controlViewCondition', () => {
        test('returns', () => {
            expect(automation.controlViewCondition).not.toBeNull();
        });
    });

    describe('controlViewWalker', () => {
        test('returns', () => {
            expect(automation.controlViewWalker).not.toBeNull();
        });
    });

    describe('proxyFactoryMapping', () => {
        test('returns', () => {
            expect(automation.proxyFactoryMapping).not.toBeNull();
        });
    });

    describe('rawViewCondition', () => {
        test('returns', () => {
            expect(automation.rawViewCondition).not.toBeNull();
        });
    });

    describe('rawViewWalker', () => {
        test('returns', () => {
            expect(automation.rawViewWalker).not.toBeNull();
        });
    });

    describe('reservedMixedAttributeValue', () => {
        test('returns', () => {
            expect(automation.reservedMixedAttributeValue).not.toBeNull();
        });
    });

    describe('reservedNotSupportedValue', () => {
        test('returns', () => {
            expect(automation.reservedNotSupportedValue).not.toBeNull();
        });
    });

    fdescribe('addAutomationEventHandler', () => {
        test('returns', (done) => {
            automation = new IUIAutomation();
            // todo:  the constructor does not function according to plan.  
            // look at the constrcutor and see why its failing.  
            // its due to the clsid not being present for the library.  
            const eventHandler = new IUIAutomationEventHandler((sender, eventId) => {
                expect(sender).not.toBeNull();

                expect(eventId).not.toBeNull();

                done();
            });

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

            const winverElement = desktopElement.findFirst(TreeScope.TreeScope_Subtree, winverNamePropertyCondition);

            const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "Microsoft Software License Terms");

            const cacheRequest = automation.createCacheRequest();

            const termsLink = winverElement.findFirst(TreeScope.TreeScope_Subtree, propertyCondition);

            automation.addAutomationEventHandler(UIA_Window_WindowOpenedEventId, desktopElement, TreeScope.TreeScope_Subtree, cacheRequest, eventHandler);
        }, 300000);
    });

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
        test('returns', () => {
            const cacheRequest = automation.createCacheRequest();

            expect(cacheRequest).not.toBeNull();
        });
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
