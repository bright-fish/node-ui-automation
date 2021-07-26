const { IUIAutomation } = require('./build/Release/automation');

const automation = new IUIAutomation();

const desktop = automation.getRootElement();

console.log(desktop);

// const propertyCondition = automation.createPropertyCondition();
// const andCondition = automation.createAndCondition();

// const controlViewWalker = automation.get_ControlViewWalker();

// const component = desktop.findFirst(UIA_NamePropertyId, propertyCondition);

