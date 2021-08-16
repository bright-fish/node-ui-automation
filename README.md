# node-microsoft-ui-automation

npm install

npm run configure

npm run build


For the early versions I want to stick to main stream behavior.  

https://docs.microsoft.com/en-us/windows/win32/winauto/uiauto-howto-topics-for-uiautomation-clients


## todo:

* Create wrapper for CachedRequest.  

* Implement functions in IUIAutomationElementWrapper.  
    * pAutomationElementWrapper->m_pAutomationElement->FindAll();
    * pAutomationElementWrapper->m_pAutomationElement->GetCurrentPattern();
    * pAutomationElementWrapper->m_pAutomationElement->GetCurrentPatternAs();
    * pAutomationElementWrapper->m_pAutomationElement->GetCurrentPropertyValue();
    * pAutomationElementWrapper->m_pAutomationElement->GetCurrentPropertyValueEx();
    * pAutomationElementWrapper->m_pAutomationElement->GetClickablePoint();
    * pAutomationElementWrapper->m_pAutomationElement->GetRuntimeId();
    * pAutomationElementWrapper->m_pAutomationElement->SetFocus();
* Implement functions in IUIAutomation class.  
    * Content Walker.
    * Raw Walker.
    * Control Walker.  

* Create enumerations for all the various enumeration types.  
    * EventIds
    * ttributeIds
    * ControlTypeIds
    * AnnotationTypes
    * StyleIds
    * LandmarkTypeIds
* Implement indexer on IUIAutomationElementArrayWrapper.  
* Maybe separate the folder structure.  
* Put in the typescript typings.  
* (optional) Figure out how to switch out the versions
* Create unit tests verifying functionality.  
* Unit testing for worker threads. 
* Verify object lifetime is correct


