{
  "targets": [
    {
      "target_name": "Automation",
      "sources": [ 
            "IUIAutomationElementWrapper.cc" ,
            "IUIAutomationWrapper.cc", 
            "binding.cc",
      ],
      "include_dirs" : [ "<!(node -e \"require('nan')\")" ],
      "libraries" : [
        "uiautomationcore.lib"
      ]
    }
  ]
}