# AutoCAD ObjectARX Application - Add Layer
 
## Overview
 
This ObjectARX application defines a function called `addLayer` that ensures the existence of a layer named "OBJ" within the current AutoCAD drawing. If the "OBJ" layer does not already exist, the function creates it with specified properties.
 
## Functionality
 
The `addLayer` function performs the following steps:
 
1. **Check for Existing Layer:**

   - Checks the Layer Table for the presence of a layer named "OBJ."
 
2. **Create a New Layer if Not Found:**

   - If the layer is not found, the function proceeds to:

     - Open the Layer Table for write access.

     - Create a new AcDbLayerTableRecord representing the "OBJ" layer.

     - Set the layer's name to "OBJ" and its color to cyan.

     - Add the new layer to the Layer Table.

     - Close both the Layer Table and the created layer record to release resources.
 
## Usage
 
1. **Build and Load:**

   - Open the ObjectARX project in Microsoft Visual Studio.

   - Build the project and load the resulting DLL in AutoCAD.
 
2. **Run the Command:**

   - In AutoCAD, enter the custom command associated with the `addLayer` function (e.g., "ADDLAYER").
 
3. **View Results:**

   - The function will ensure the existence of a layer named "OBJ" in the drawing, creating it with specified properties if needed.

