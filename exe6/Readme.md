# AutoCAD ObjectARX Application - List Objects
 
## Overview
 
This ObjectARX application defines a function called `listObjects` that retrieves and displays the class names of all objects in the current space of the AutoCAD drawing. The class names are printed to the AutoCAD Text Window.
 
## Functionality
 
The `listObjects` function performs the following tasks:
 
1. Gets the current AutoCAD database.
2. Retrieves the current space object (usually Model Space or Paper Space).
3. Iterates through each object in the current space.
4. For each object, it gets the entity and displays its class name.
5. Closes each entity after retrieving and displaying its class name.
6. Closes the current space object.
7. Deletes the block iterator object from memory.
8. Displays the AutoCAD Text Window.
 
## Usage
 
1. **Build and Load:**
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the project and load the resulting DLL in AutoCAD.
 
2. **Run the Command:**
   - In AutoCAD, enter the custom command associated with the `listObjects` function (e.g., "LISTOBJECTS").
 
3. **View Results:**
   - The function will print the class names of all objects in the current space to the AutoCAD Text Window.

