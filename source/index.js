// @ts-check
const Automation = require("bindings")("Automation");

module.exports = {
  ...Automation,
  TreeScope: {
    None: Automation.TreeScope.TreeScope_None,
    Element: Automation.TreeScope.TreeScope_Element,
    Children: Automation.TreeScope.TreeScope_Children,
    Descendants: Automation.TreeScope.TreeScope_Descendants,
    Parent: Automation.TreeScope.TreeScope_Parent,
    Ancestors: Automation.TreeScope.TreeScope_Ancestors,
    Subtree: Automation.TreeScope.TreeScope_Subtree,
  },
};
