Go through all the pattern wrappers and convert them from providers to patterns.  Ensure that all functions are wrapped.  
Go through the d.ts file correct all the providers and rename them accordingly.  Put all properties on the typings.  
Go through the compiled files in the gyp file and rename them all to make the project build.  

Ensure all the files are #included properly due to the rename.  
Make sure the constructor functions are all renamed in AutomationAddon.h and .cc file.  
Remove any of the unused utility classes that arent used by the patterns, for example IRawElementProviderSimpleWrapper.  

Remove this file once all these things are done.  
