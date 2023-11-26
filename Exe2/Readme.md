# AutoCAD ObjectARX Application - Load and Unload in AutoCAD
 
## Overview
 
This AutoCAD ObjectARX application is for loading and unloading of a ObjectARX dll file in AutoCAD.
## Integration Steps
 
### 1. Build Debug Version:
 
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the debug version of the project.
 
### 2. Load ObjectARX File:
 
   - In AutoCAD, use the "APPLOAD" command in the AutoCAD command line.
   - Browse and load the compiled ObjectARX DLL (debug version) into AutoCAD.
 
### 3. Unload Feature:
 
   - After using the custom command, unload the feature by following these steps:
     - Click on the "Unload" command in the Appload window.
     - Alternatively, use the "NETUNLOAD" command in the AutoCAD command line.
 
## Usage
 
1. **Build Debug Version:**
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the debug version of the project.
 
2. **Load ObjectARX File:**
   - In AutoCAD, enter the "APPLOAD" command in the AutoCAD command line.
   - Browse and load the compiled ObjectARX DLL (debug version) into AutoCAD.
 
3. **Run Custom Command:**
   - In AutoCAD, enter the custom command "AddCommand" in the AutoCAD command line.
   - The command will print the message "Welcome in the World of AutoCAD."
 
4. **Unload Feature:**
   - After using the custom command, unload the feature using the "Unload" command in the Appload window or the "NETUNLOAD" command in the AutoCAD command line.

