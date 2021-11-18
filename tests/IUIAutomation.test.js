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
    let automation = new Automation();

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

                automation.removeAutomationEventHandler(eventHandler);

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

    xdescribe('add/removeFocusChangedEventHandler', () => {
        test('returns', done => {
            expect.assertions(1);

            const focusChangedEventHandler = new AutomationFocusChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                automation.removeFocusChangedEventHandler(focusChangedEventHandler);

                done();
            });

            automation.addFocusChangedEventHandler(null, focusChangedEventHandler);
        }, 300000);
    });

    // todo: figure out a way to test this.  
    xdescribe('add/removePropertyChangedEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(1);

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");

            const winverElement = desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);

            const propertyChangedEventHandler = new AutomationPropertyChangedEventHandler((sender) => {
                expect(sender).toBeDefined();

                automation.removePropertyChangedEventHandler(focusChangedEventHandler);

                done();
            });

            automation.addPropertyChangedEventHandler(desktopElement, TreeScopes.Subtree, null, propertyChangedEventHandler, [UIA_ToggleToggleStatePropertyId]);
        }, 300000);
    });

    // skipping
    describe('addPropertyChangedEventHandlerNativeArray', () => {
        test.todo('returns');
    });

    // todo: figure out way to test this.
    xdescribe('addStructureChangedEventHandler', () => {
        test('returns', (done) => {
            expect.assertions(1);

            const desktopElement = automation.getRootElement();

            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "tests");

            const winverElement = desktopElement.findFirst(TreeScopes.Subtree, winverNamePropertyCondition);

            const structureChangedEventHandler = new AutomationStructureChangedEventHandler((sender) => {
                expect(sender).not.toBeNull();

                automation.removeStructureChangedEventHandler(focusChangedEventHandler);

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
            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");
            const winverAutomationIdPropertyCondition = automation.createPropertyCondition(AutomationProperties.AutomationIdPropertyId, '13095');

            const andCondition = automation.createAndCondition(winverNamePropertyCondition, winverAutomationIdPropertyCondition);

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
            const winverNamePropertyCondition = automation.createPropertyCondition(AutomationProperties.NamePropertyId, "About Windows");
            const winverAutomationIdPropertyCondition = automation.createPropertyCondition(AutomationProperties.AutomationIdPropertyId, '13095');

            const orCondition = automation.createOrCondition(winverNamePropertyCondition, winverAutomationIdPropertyCondition);

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

    // skipping: implementation is possible.  just being lazy. 
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

    // skipping: HWND conversion doesnt seem too important with the scope of this project at the moment.  
    describe('elementFromHandle', () => {
        test.todo('returns');
    });

    // skipping: see above.  
    describe('elementFromHandleBuildCache', () => {
        test.todo('returns');
    });

    // skipping: not sure of use case.    
    describe('elementFromIAccessible', () => {
        test.todo('returns');
    });

    // skipping: not sure of use case.  
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
            const patternName = automation.getPatternProgrammaticName(AutomationPatterns.DragPatternId);

            expect(patternName).toBe('DragPattern');
        });
    });

    describe('getPropertyProgrammaticName', () => {
        test('returns', () => {
            const propertyName = automation.getPropertyProgrammaticName(AutomationProperties.NamePropertyId);

            expect(propertyName).toBe('Name');
        });
    });

    describe('getRootElement', () => {
        test('returns', () => {
            const desktopElement = automation.getRootElement();

            expect(desktopElement).toBeDefined();
        });
    });

    describe('getRootElementBuildCache', () => {
        test('returns', () => {
            const cacheRequest = automation.createCacheRequest();

            const desktopElement = automation.getRootElementBuildCache(cacheRequest);

            expect(desktopElement).toBeDefined();
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
            automation.removeAllEventHandlers();
        });
    });

    // skipping: test included in above
    describe('removeAutomationEventHandler', () => {
        test.todo('returns');
    });

    // skipping: test included in above
    describe('removeFocusChangedEventHandler', () => {
        test.todo('returns');
    });

    // skipping: test included in above
    describe('removePropertyChangedEventHandler', () => {
        test.todo('returns');
    });
    
    // skipping: test included in above
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
