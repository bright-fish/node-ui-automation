const { IUIAutomation, UIA_NamePropertyId, TreeScope } = require("./index");

const automation = new IUIAutomation();

const desktopElement = automation.getRootElement();

const propertyCondition = automation.createPropertyCondition(
  UIA_NamePropertyId,
  "About Windows"
);

const winverElement = desktopElement.findFirst(
  TreeScope.Subtree,
  propertyCondition
);

const controlViewWalker = automation.controlViewWalker;

const firstChildElement = controlViewWalker.getFirstChildElement(winverElement);

console.log(winverElement.cachedName);
console.log(winverElement.currentProcessId);
console.log(firstChildElement);
