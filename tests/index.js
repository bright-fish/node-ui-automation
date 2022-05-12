const { Automation, PropertyIds, TreeScopes, PatternIds, AutomationStructureChangedEventHandler } = require('microsoft-ui-automation');

const automation = new Automation();

const desktopElement = automation.getRootElement();

const aboutWindowsProperty = automation.createPropertyCondition(PropertyIds.NamePropertyId, 'About Windows');

const winverWindow = desktopElement.findFirst(TreeScopes.Subtree, aboutWindowsProperty);

const eventHandler = new AutomationStructureChangedEventHandler((element) => { 
    console.log('here two');
});

automation.addStructureChangedEventHandler(winverWindow, TreeScopes.Subtree, null, eventHandler);

const linkProperty = automation.createPropertyCondition(PropertyIds.NamePropertyId, "Microsoft Software License Terms");

const linkElement = winverWindow.findFirst(TreeScopes.Subtree, linkProperty);

const invokeProvider = linkElement.getCurrentPattern(PatternIds.InvokePatternId);

invokeProvider.invoke();


// listening to structure changes.
// listening to focus events.
 

// invoke providers. 
// range value 
// value provider
// virtualized item provider.





console.log('here')


