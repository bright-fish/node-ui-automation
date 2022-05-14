# Node UI Automation 

## For use only on the Windows Operating System.  

This is a node api add-on that wraps the Microsoft UI Automation Library.  The majority of COM functionality is wrapped using napi.  There may be a few missing things like proxies, however the majority of the functionality is here.  

# Installation

`npm install @bright-fish/node-ui-automation`

# How to use

Open the winver "About Windows" application.  Below is an automation that clicks the ok button in the About Windows dialog.   

```javascript 
const { Automation, PropertyIds, TreeScopes, PatternIds } = require('@bright-fish/node-ui-automation');

const automation = new Automation();

const desktopElement = automation.getRootElement();

const aboutWindowsProperty = automation.createPropertyCondition(PropertyIds.NamePropertyId, 'About Windows');

const winverWindow = desktopElement.findFirst(TreeScopes.Subtree, aboutWindowsProperty);

const okProperty = automation.createPropertyCondition(PropertyIds.NamePropertyId, "OK");

const okButton = winverWindow.findFirst(TreeScopes.Subtree, okProperty);

const invokeProvider = okButton.getCurrentPattern(PatternIds.InvokePatternId);

invokeProvider.invoke();

```

# Documentation 

Most of the functionality is provided with similar names.  The typings shipped with the library can help identify whats available to use.  

Here is a link to the Microsoft documentation.  

https://docs.microsoft.com/en-us/windows/win32/winauto/entry-uiauto-win32
