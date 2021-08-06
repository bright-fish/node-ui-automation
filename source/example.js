const { IUIAutomation, UIA_NamePropertyId, TreeScope } = require('./build/Debug/automation');

const automation = new IUIAutomation();

const desktopElement = automation.getRootElement();

const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

const component = desktopElement.findFirst(TreeScope.TreeScope_Subtree, propertyCondition);

// const controlViewWalker = automation.get_ControlViewWalker();


console.log(component.name);
