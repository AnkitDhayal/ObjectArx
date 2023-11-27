# AutoCAD ObjectARX Application - Hello World
 
## Overview
 
This ObjectARX application defines a custom command, "AddCommand," that displays the message "Welcome in the world of AutoCAD" when the user enters the command in the AutoCAD command line.
 
## Initialization
 
1. **Unlock and Register as MDI Aware:**
   - The application is unlocked and registered as MDI (Multiple Document Interface) aware.
 
2. **Print Initialization Message:**
   - Prints a message to the AutoCAD command line, indicating that the application has been loaded.
 
3. **Register New Modal Command:**
   - Registers a new modal command named "AddCommand" in the "MyGroup" group.
   - Associates the command with the `AddCommand` function in the `CProject3App` class.
 
## Custom Command - MyCommand
 
The `addCommand` function defines the behavior of the custom command "AddCommand." When executed, it prints the message "Welcome in the World of AutoCAD" to the AutoCAD command line.
 
## Unload
 
1. **Print Unload Message:**
   - Prints a message to the AutoCAD command line, indicating that the application is being unloaded.
 
## Usage
 
1. **Build and Load:**
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the project and load the resulting DLL in AutoCAD.
 
2. **Run the Command:**
   - In AutoCAD, enter the custom command "AddCommand" in the AutoCAD command line.
 
3. **View Results:**
   - The command will print the message "Welcome in the World of AutoCAD" to the AutoCAD command line.

