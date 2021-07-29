{
  "targets": [
    {
      "target_name": "Automation",
      "sources": [ 
            "IUIAutomationElementWrapper.cc" ,
            "IUIAutomationWrapper.cc", 
            "binding.cc",
            "UIA_PropertyIdsWrapper.cc",
            "TreeScopeWrapper.cc"
      ],
      "include_dirs" : [ "<!(node -e \"require('nan')\")" ],
      "libraries" : [
        "uiautomationcore.lib"
      ]
    }
  ]
}