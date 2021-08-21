{
  "targets": [
    {
      "target_name": "Automation",
      "sources": [ 
            "binding.cc",
            "UIA_EventIdsWrapper.cc",
            "UIA_PropertyIdsWrapper.cc",
            "TreeScopeWrapper.cc",
            "RectWrapper.cc",
            "IUnknownWrapper.cc",
            "IUIAutomationElementWrapper.cc" ,
            "IUIAutomationWrapper.cc", 
            "IUIAutomationConditionWrapper.cc",
            "IUIAutomationElementArrayWrapper.cc",
            "IUIAutomationTreeWalkerWrapper.cc",
            "IUIAutomationCacheRequestWrapper.cc", 
            "IUIAutomationProxyFactoryMappingWrapper.cc",
      ],
      "include_dirs" : [ "<!(node -e \"require('nan')\")" ],
      "libraries" : [
        "uiautomationcore.lib"
      ]
    }
  ]
}