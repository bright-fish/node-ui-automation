const { IUIAutomation, UIA_NamePropertyId, TreeScope } = require('./build/Release/automation');

const automation = new IUIAutomation();

const desktopElement = automation.getRootElement();

// todo: make createPropertyCondition functional. 
// todo: write wrapper for property condition.  
// todo: maek property condition an external possibly?  
// todo: have find first unwrap the property condition, and then use it in the function call.  
// todo: return the component
// todo: map all the properties of the component to a javascript object.  

const propertyCondition = automation.createPropertyCondition(UIA_NamePropertyId, "About Windows");

const component = desktopElement.findFirst(TreeScope.TreeScope_SubTree, propertyCondition);

// const controlViewWalker = automation.get_ControlViewWalker();


