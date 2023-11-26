## Project Overview
 
This project serves as a template for developing ObjectARX applications in the AutoCAD environment. It is set up as an MFC (Microsoft Foundation Classes) Dynamic Link-Library (DLL) with a DLL extension.
 
## Setup Instructions
 
1. **Create a New ObjectARX Project:**
   - Open Microsoft Visual Studio.
   - Create a new project as an MFC Dynamic Link-Library (DLL) with a DLL extension.
2. **Configure the Project for ObjectARX:**
   - Modify C++ and Linker properties to set up the project for ObjectARX development.
3. **Add Required Libraries:**
   - In the project's properties settings, link against ObjectARX libraries and any other dependencies needed for AutoCAD applications.
4. **Define acrxEntryPoint Function:**
   - Define the `acrxEntryPoint` function, serving as the entry point for the ObjectARX application.
   - Handle initialization and unloading messages, such as `AcRx::kInitAppMsg` and `AcRx::kUnloadAppMsg`.
5. **Implement Command for Message Display:**
   - Implement code to display the message "Hello in the world of AutoCAD" when the command "AddCommand" is entered in AutoCAD.
   - Define a custom command function (e.g., `addCommand`) and register it using `acedRegCmds->addCommand`.
 
## Usage
 
1. Build the project in Microsoft Visual Studio.
2. Load the resulting DLL in AutoCAD.
3. Enter the command "AddCommand" to see the message in the AutoCAD environment.

