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
            "IUIAutomationEventHandlerWrapper.cc"
      ],
      "include_dirs": ["<!(node -p \"require('node-addon-api').include_dir\")"],
      "libraries" : [
        "uiautomationcore.lib"
      ]
    }
  ]
}