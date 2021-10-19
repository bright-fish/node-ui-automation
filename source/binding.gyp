{
  "targets": [
    {
      "target_name": "Automation",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "msvs_settings": {
        "VCCLCompilerTool": { "ExceptionHandling": 1 },
      },
      "sources": [ 
            "AutomationAddon.cc",
            "wrappers/UIA_EventIdsWrapper.cc",
            "wrappers/UIA_PropertyIdsWrapper.cc",
            "wrappers/TreeScopeWrapper.cc",
            "wrappers/RectWrapper.cc",
            "wrappers/IUnknownWrapper.cc",
            "wrappers/IUIAutomationElementWrapper.cc" ,
            "wrappers/IUIAutomationWrapper.cc", 
            "wrappers/IUIAutomationConditionWrapper.cc",
            "wrappers/IUIAutomationElementArrayWrapper.cc",
            "wrappers/IUIAutomationTreeWalkerWrapper.cc",
            "wrappers/IUIAutomationCacheRequestWrapper.cc", 
            "wrappers/IUIAutomationProxyFactoryMappingWrapper.cc",
            "wrappers/IUIAutomationFocusChangedEventHandlerWrapper.cc",
            "wrappers/IUIAutomationEventHandlerWrapper.cc",
            "wrappers/IUIAutomationPropertyChangedEventHandlerWrapper.cc",
            "wrappers/IUIAutomationStructureChangedEventHandlerWrapper.cc",

            "utilities/AutomationEventHandler.cc",
            "utilities/FocusChangedEventHandler.cc",
            "utilities/PropertyChangedEventHandler.cc",
            "utilities/StructureChangedEventHandler.cc"
      ],
      "include_dirs": ["<!(node -p \"require('node-addon-api').include_dir\")"],
      "libraries" : [
        "uiautomationcore.lib",
      ]
    }
  ]
}