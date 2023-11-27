# AutoCAD ObjectARX Application - Change Color
 
## Overview
 
This ObjectARX application defines a function called `changeColor` that allows the user to interactively change the color of selected objects in AutoCAD. The function prompts the user to select objects, enter a color keyword or numeric value, and iterates through the selected objects, changing their color based on the user's input.
 
## Functionality
 
The `changeColor` function performs the following steps:
 
1. **Prompt for Object Selection:**
   - Prompts the user to select objects in AutoCAD.
 
2. **Prompt for Color Selection:**
   - If objects are selected, it prompts the user to enter a color keyword/option, defaulting to "Red."
 
3. **Change Color of Selected Objects:**
   - Iterates through the selected objects and changes their color based on the user's input.
   - The user can specify colors using keywords ("Red," "Yellow," "Green") or numeric values (1, 2, 3).
   - If the user chooses "Bylayer," the object's color is set to be determined by the layer color.
 
4. **Close Selected Objects:**
   - Closes the selected objects after changing their colors.
 
## Usage
 
1. **Build and Load:**
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the project and load the resulting DLL in AutoCAD.
 
2. **Run the Command:**
   - In AutoCAD, enter the custom command associated with the `changeColor` function (e.g., "CHANGECOLOR").
 
3. **Select Objects:**
   - Use the AutoCAD selection tools to select objects in the drawing.
 
4. **Enter Color Option:**
   - Enter a color keyword or numeric value when prompted.
 
5. **View Results:**
   - The function will change the color of the selected objects based on the user's input.

