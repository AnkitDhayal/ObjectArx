# User Information Drawing Tool
 
## Overview
 
This simple drawing tool collects user information and creates text objects to display the entered name and age in AutoCAD. The user is prompted to provide their age and name, specify a location in the drawing, and the tool constructs and adds text objects accordingly.
 
## Usage
 
1. **Run the Application:**
   - Load the ObjectARX project in Microsoft Visual Studio.
   - Build and load the resulting DLL in AutoCAD.
 
2. **Enter Command:**
   - In AutoCAD, enter the custom command (e.g. "UserInformation") to activate the tool.
 
3. **Provide User Information:**
   - The tool will prompt you to enter your age and name.
 
4. **Specify Drawing Location:**
   - Follow the prompts to specify where in the drawing you want to place the information.
 
5. **View Text Objects:**
   - The tool will construct two text strings, one showing the age and the other showing the name.
   - Two text objects with a height of 3.5 units will be added to the drawing at the specified location.

