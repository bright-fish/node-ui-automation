const {
    IUIAutomation,
    IUIAutomationEventHandler,
    IUIAutomationFocusChangedEventHandler,
    IUIAutomationPropertyChangedEventHandler,
    UIA_NamePropertyId,
    UIA_Window_WindowOpenedEventId,
    UIA_HasKeyboardFocusPropertyId,
    UIA_ToggleToggleStatePropertyId,
    TreeScope
} = require('bindings')('Automation');

describe('IUIAutomation', () => {
    let automation = null;

    test('constructor', () => {
        automation = new IUIAutomation();
    });

    beforeEach(() => {
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

    // todo: removeAutomationEventHandler
    xdescribe('add/removeAutomationEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(2);

            const eventHandler = new IUIAutomationEventHandler((sender, eventId) => {
                expect(sender).not.toBeNull();

                expect(eventId).not.toBeNull();

                console.log(sender.currentName);

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

    // todo: removeFocusChangedEventHandler
    xdescribe('add/removeFocusChangedEventHandler', () => {
        test('returns', done => {
            expect.assertions(1);

            const focusChangedEventHandler = new IUIAutomationFocusChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                done();
            });

            // const cacheRequest = automation.createCacheRequest();

            automation.addFocusChangedEventHandler(null, focusChangedEventHandler);

        }, 300000);
    });

    // todo: broken, come back and fix a different day.  
    xdescribe('add/removePropertyChangedEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(1);

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

            const winverElement = desktopElement.findFirst(TreeScope.TreeScope_Subtree, winverNamePropertyCondition);

            const propertyChangedEventHandler = new IUIAutomationPropertyChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                done();
            });

            automation.addPropertyChangedEventHandler(desktopElement, TreeScope.TreeScope_Subtree, null, propertyChangedEventHandler, [UIA_ToggleToggleStatePropertyId]);
        }, 300000);
    });

    // todo: skipping
    describe('addPropertyChangedEventHandlerNativeArray', () => {
        test.todo('returns');
    });

    describe('addStructureChangedEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(1);

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

            const winverElement = desktopElement.findFirst(TreeScope.TreeScope_Subtree, winverNamePropertyCondition);

            const structureChangedEventHandler = new IUIAutomationStructureChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                done();
            });

            automation.addStructureChangedEventHandler(desktopElement, TreeScope.TreeScope_Subtree, null, structureChangedEventHandler, [UIA_ToggleToggleStatePropertyId]);

        }, 300000);
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

    // skipping
    describe('createAndConditionFromArray', () => {
        test.todo('returns');
    });

    // skipping
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

    // todo: skipping
    describe('createOrConditionFromArray', () => {
        test.todo('returns');
    });

    // todo: skipping
    describe('createOrConditionFromNativeArray', () => {
        test.todo('returns');
    });

    describe('createPropertyCondition', () => {
        test.todo('returns');
    });

    describe('createPropertyConditionEx', () => {
        test.todo('returns');
    });

    // skipping
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

    // todo: skipping
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
