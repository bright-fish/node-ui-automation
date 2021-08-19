const { IUIAutomation, UIA_NamePropertyId, TreeScope } = require('./build/Debug/automation');

const automation = new IUIAutomation();

const desktopElement = automation.getRootElement();

const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

const winverElement = desktopElement.findFirst(TreeScope.TreeScope_Subtree, propertyCondition);

const controlViewWalker = automation.controlViewWalker;

const firstChildElement = controlViewWalker.getFirstChildElement(winverElement);

console.log(winverElement.cachedName);
console.log(winverElement.currentProcessId);