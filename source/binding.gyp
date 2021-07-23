{
  "targets": [
    {
      "target_name": "microsoft-ui-automation",
      "sources": [ 
            "binding.cc",
            "IUIAutomationWrapper.cc", 
            "IUIAutomationElementWrapper.cc" 
        ],
      "include_dirs" : [ "<!(node -e \"require('nan')\")" ]
    }
  ]
}