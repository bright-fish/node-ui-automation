const { Automation, AutomationStructureChangedEventHandler, TreeScopes, PropertyIds, PatternIds } = require('microsoft-ui-automation');






const automation = new Automation();


const desktopElement = automation.getRootElement();

const aboutWindows = automation.createPropertyCondition(PropertyIds.NamePropertyId, 'About Windows');
const winverElement = desktopElement.findFirst(TreeScopes.Descendants, aboutWindows);

const eventHandler = new AutomationStructureChangedEventHandler((element) => {
    console.log(element.currentName);
});

automation.addStructureChangedEventHandler(winverElement, TreeScopes.Subtree, null, eventHandler);


const isControl = automation.createPropertyCondition(PropertyIds.IsControlElementPropertyId, true);

const micorsoftTerms = automation.createPropertyCondition(PropertyIds.NamePropertyId, 'Microsoft Software License Terms');

const okButtonCondition = automation.createAndCondition(isControl, micorsoftTerms);

const okButton = winverElement.findFirst(TreeScopes.Descendants, okButtonCondition);


const invokePattern = okButton.getCurrentPattern(PatternIds.InvokePatternId);

invokePattern.invoke();




