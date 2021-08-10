{
  "targets": [
    {
      "target_name": "Automation",
      "sources": [ 
            "IUIAutomationElementWrapper.cc" ,
            "IUIAutomationWrapper.cc", 
            "binding.cc",
            "UIA_PropertyIdsWrapper.cc",
            "TreeScopeWrapper.cc",
            "IUIAutomationConditionWrapper.cc",
            "RectWrapper.cc",
            "IUIAutomationElementArrayWrapper.cc"
      ],
      "include_dirs" : [ "<!(node -e \"require('nan')\")" ],
      "libraries" : [
        "uiautomationcore.lib"
      ]
    }
  ]
}