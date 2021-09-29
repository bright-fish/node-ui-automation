const { IUIAutomation, PropertyIDs, TreeScope } = require("./index");

const automation = new IUIAutomation();

const desktopElement = automation.getRootElement();

const propertyCondition = automation.createPropertyCondition(
  PropertyIDs.UIA_NamePropertyId,
  "About Windows"
);

const winverElement = desktopElement.findFirst(
  TreeScope.TreeScope_Subtree,
  propertyCondition
);

if (!winverElement) {
  console.error("Unable to find element");
  process.exit(1);
}

const controlViewWalker = automation.controlViewWalker;
const firstChildElement = controlViewWalker.getFirstChildElement(winverElement);

console.log(winverElement.cachedName);
console.log(winverElement.currentProcessId);
console.log(firstChildElement);
