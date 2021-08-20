const { IUIAutomation, UIA_NamePropertyId, TreeScope, PropertyIDs } = require('./index');

const automation = new IUIAutomation();

const desktopElement = automation.getRootElement();

const propertyCondition = automation.createPropertyCondition(PropertyIDs.Name, 'About Windows');

const winverElement = desktopElement.findFirst(TreeScope.Subtree, propertyCondition);

const controlViewWalker = automation.controlViewWalker;

const firstChildElement = controlViewWalker.getFirstChildElement(winverElement);

console.log(winverElement.cachedName);
console.log(winverElement.currentProcessId);
console.log(firstChildElement);
