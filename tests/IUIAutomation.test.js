const {
    Automation,
    AutomationEventHandler,
    AutomationFocusChangedEventHandler,
    AutomationPropertyChangedEventHandler,
    AutomationStructureChangedEventHandler,
    AutomationProperties,
    AutomationEvents,
    TreeScopes,
    AutomationPatterns
} = require('microsoft-ui-automation');

describe('IUIAutomation', () => {
    let automation = null;

    test('constructor', () => {
        automation = new Automation();
    });

    beforeEach(() => {
        automation = new Automation();
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

    xdescribe('add/removeAutomationEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(2);

            const eventHandler = new AutomationEventHandler((sender, eventId) => {
                expect(sender).not.toBeNull();

                expect(eventId).not.toBeNull();

                console.log(sender.currentName);

                // todo: automation.removeAutomationEventHandler(eventHandler);

                done();
            });

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            const winverElement = desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);

            const propertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "Microsoft Software License Terms");

            const cacheRequest = automation.createCacheRequest();

            const termsLink = winverElement.findFirst(TreeScopes.Subtree, propertyCondition);

            automation.addAutomationEventHandler(AutomationEvents.Window_WindowOpenedEventId, desktopElement, TreeScopes.Subtree, cacheRequest, eventHandler);
        }, 300000);
    });

    // todo: removeFocusChangedEventHandler
    xdescribe('add/removeFocusChangedEventHandler', () => {
        test('returns', done => {
            expect.assertions(1);

            const focusChangedEventHandler = new AutomationFocusChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                done();
            });

            // const cacheRequest = automation.createCacheRequest();

            automation.addFocusChangedEventHandler(null, focusChangedEventHandler);

            // automation.removeFocusChanedEventHandler()
        }, 300000);
    });

    // todo: broken, come back and fix a different day.  
    xdescribe('add/removePropertyChangedEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(1);

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            const winverElement = desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);

            const propertyChangedEventHandler = new AutomationPropertyChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                done();
            });

            automation.addPropertyChangedEventHandler(desktopElement, TreeScopes.Subtree, null, propertyChangedEventHandler, [UIA_ToggleToggleStatePropertyId]);
        }, 300000);
    });

    // skipping
    describe('addPropertyChangedEventHandlerNativeArray', () => {
        test.todo('returns');
    });

    // todo: fix it.
    xdescribe('addStructureChangedEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(1);

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "tests");

            const winverElement = desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);

            const structureChangedEventHandler = new AutomationStructureChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                done();
            });

            automation.addStructureChangedEventHandler(winverElement, TreeScopes.Subtree, null, structureChangedEventHandler);

        }, 300000);
    });

    // skipping  
    describe('checkNotSupported', () => {
        test.todo('returns');
    });

    describe('compareElements', () => {
        test('returns', () => {
            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            const winverElementOne = desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);

            const winverElementTwo = desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);

            const areEqual = automation.compareElements(winverElementOne, winverElementTwo);

            expect(areEqual).toBe(true);
        });
    });

    // skipping  
    describe('compareRuntimeIds', () => {
        test.todo('returns');
    });

    describe('createAndCondition', () => {
        test('returns', () => {
            const winverNamePropertyConditionOne = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");
            const winverNamePropertyConditionTwo = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            const andCondition = automation.createAndCondition(winverNamePropertyConditionOne, winverNamePropertyConditionTwo);

            expect(andCondition).toBeDefined();
        });
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
        test('returns', () => {
            const falseCondition = automation.createFalseCondition();

            expect(falseCondition).toBeDefined();
        });
    });

    describe('createNotCondition', () => {
        test('returns', () => {
            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            const notCondition = automation.createNotCondition(winverNamePropertyCondition);

            expect(notCondition).toBeDefined();
        });
    });

    describe('createOrCondition', () => {
        test('returns', () => {
            const winverNamePropertyConditionOne = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");
            const winverNamePropertyConditionTwo = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            // const winverAutomationIdPropertyCondition = automation.createPropertyCondition(AutomationProperties.AutomationIdPropertyId, 13095);

            const orCondition = automation.createOrCondition(winverNamePropertyConditionOne, winverNamePropertyConditionTwo);

            expect(orCondition).toBeDefined();
        });
    });

    // skipping
    describe('createOrConditionFromArray', () => {
        test.todo('returns');
    });

    // skipping
    describe('createOrConditionFromNativeArray', () => {
        test.todo('returns');
    });

    describe('createPropertyCondition', () => {
        test('returns', () => {
            const propertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            expect(propertyCondition).not.toBeNull();
        });
    });

    // todo: skipping just being lazy.  
    describe('createPropertyConditionEx', () => {
        test.todo('returns');
    });

    // skipping: out of scope of javascript project, really needs implementation in c++
    describe('createProxyFactoryEntry', () => {
        test.todo('returns');
    });

    describe('createTreeWalker', () => {
        test('returns', () => {
            const propertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            const treeWalker = automation.createTreeWalker(propertyCondition);

            expect(treeWalker).toBeDefined();
        });
    });

    describe('createTrueCondition', () => {
        test('returns', () => {
            const trueCondition = automation.createTrueCondition();

            expect(trueCondition).toBeDefined();
        });
    });

    // skipping: HWND conversion doesnt seem too important with the scope of this project.  
    describe('elementFromHandle', () => {
        test.todo('returns');
    });

    // skipping: see above.  
    describe('elementFromHandleBuildCache', () => {
        test.todo('returns');
    });

    // skipping: out of scope of javascript.  how do you interop with com from javascript?  
    describe('elementFromIAccessible', () => {
        test.todo('returns');
    });

    // skipping: out of scope.  
    describe('elementFromIAccessibleBuildCache', () => {
        test.todo('returns');
    });

    describe('elementFromPoint', () => {
        test('returns', () => {
            const element = automation.elementFromPoint({ x: 123, y: 123 });

            expect(element).toBeDefined();
        });
    });

    describe('elementFromPointBuildCache', () => {
        test('returns', () => {
            const cacheRequest = automation.createCacheRequest();

            const element = automation.elementFromPointBuildCache({ x: 123, y: 123 }, cacheRequest);

            expect(element).toBeDefined();
        });
    });

    describe('getFocusedElement', () => {
        test('returns', () => {
            const element = automation.getFocusedElement();

            expect(element).toBeDefined();
        });
    });

    describe('getFocusedElementBuildCache', () => {
        test('returns', () => {
            const cacheRequest = automation.createCacheRequest();

            const element = automation.getFocusedElementBuildCache(cacheRequest);

            expect(element).toBeDefined();
        });
    });

    describe('getPatternProgrammaticName', () => {
        test('returns', () => {
            // todo: need pattern names
            // const element = automation.getPatternProgrammaticName();
        });
    });

    describe('getPropertyProgrammaticName', () => {
        test('returns', () => {
            const propertyName = automation.getPatternProgrammaticName(AutomationPatterns.DragPatternId);

            expect(propertyName).toBe('DragPattern');
        });
    });

    describe('getRootElement', () => {
        test('returns', () => {
            const desktopElement = automation.getRootElement();

            expect(desktopElement).not.toBeNull();
        });
    });

    describe('getRootElementBuildCache', () => {
        test('returns', () => {
            const cacheRequest = automation.createCacheRequest();

            const desktopElement = automation.getRootElementBuildCache(cacheRequest);

            expect(desktopElement).not.toBeNull();
        });
    });

    // skipping
    describe('intSafeArrayToNativeArray', () => {
        test.todo('returns');
    });

    // skipping
    describe('pollForPotentialSupportedPatterns', () => {
        test.todo('returns');
    });

    // skipping
    describe('pollForPotentialSupportedProperties', () => {
        test.todo('returns');
    });

    // skipping
    describe('rectToVariant', () => {
        test.todo('returns');
    });

    describe('removeAllEventHandlers', () => {
        test('returns', () => {

        });
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

    // skipping
    describe('safeArrayToRectNativeArray', () => {
        test.todo('returns');
    });

    // skipping
    describe('variantToRect', () => {
        test.todo('returns');
    });
});
