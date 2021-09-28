{
  "targets": [
    {
      "target_name": "Automation",
      "cflags!": [ "-fno-exceptions" ],
      "cflags_cc!": [ "-fno-exceptions" ],
      "xcode_settings": { "GCC_ENABLE_CPP_EXCEPTIONS": "YES",
        "CLANG_CXX_LIBRARY": "libc++",
        "MACOSX_DEPLOYMENT_TARGET": "10.7",
      },
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
            "wrappers/IUIAutomationEventHandlerWrapper.cc",
            "utilities/GenericAutomationEventHandler.cc"
      ],
      "include_dirs": ["<!(node -p \"require('node-addon-api').include_dir\")"],
      "libraries" : [
        "uiautomationcore.lib"
      ]
    }
  ]
}