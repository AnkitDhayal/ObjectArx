# AutoCAD ObjectARX Application - Input Line
 
## Overview
 
This ObjectARX application defines a function called `inputLine` that allows the user to draw a line in AutoCAD by interactively inputting two points. The line is then added to the current space block of the drawing.
 
## Functionality
 
The `inputLine` function performs the following tasks:
 
1. Gets the current AutoCAD database.
2. Retrieves the current space block (usually Model Space or Paper Space).
3. Prompts the user to input the first point using `acedGetPoint`.
4. If the first point is successfully obtained, prompts the user for the second point.
5. If both points are successfully obtained, creates a new AcDbLine object using the specified points.
6. Appends the new Line object to the current space block.
7. Closes the current space block and the Line object.
 
## Usage
 
1. **Build and Load:**
   - Open the ObjectARX project in Microsoft Visual Studio.
   - Build the project and load the resulting DLL in AutoCAD.
 
2. **Run the Command:**
   - In AutoCAD, enter the custom command associated with the `inputLine` function (e.g., "DRAWLINE").
 
3. **Follow Prompts:**
   - The function will prompt you to input the first and second points interactively.
 
4. **View Result:**
   - A line will be created based on the input points and added to the current space block.

