{
  "targets": [
    {
      "target_name": "Automation",
      "sources": [ 
            "binding.cc",
            "IUIAutomationElementWrapper.cc" ,
            "IUIAutomationWrapper.cc", 
            "UIA_PropertyIdsWrapper.cc",
            "TreeScopeWrapper.cc",
            "IUIAutomationConditionWrapper.cc",
            "RectWrapper.cc",
            "IUIAutomationElementArrayWrapper.cc",
            "IUIAutomationTreeWalkerWrapper.cc",
            "IUIAutomationCacheRequestWrapper.cc"
      ],
      "include_dirs" : [ "<!(node -e \"require('nan')\")" ],
      "libraries" : [
        "uiautomationcore.lib"
      ]
    }
  ]
}