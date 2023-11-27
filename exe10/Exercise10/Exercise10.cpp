// Exercise10.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise10.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

void CExercise10App::addLine()
{
    // Get the current database 
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    // Open the Block Table for read-only
    AcDbBlockTable* pBlockTable;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    // Get the Model Space block
    AcDbBlockTableRecord* pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE,
        pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();
    // Define the points that will be used to define the Line object
    AcGePoint3d startPt(7.0, 3.0, 0.0);
    AcGePoint3d endPt(11.0, 3.0, 0.0);
    // Create the new Line object in memory
    AcDbLine* pLine = new AcDbLine(startPt, endPt);
    // Add the new Line object to Model space
    pBlockTableRecord->appendAcDbEntity(pLine);
    // Close the Model space block
    pBlockTableRecord->close();
    // Close the new line object
    pLine->close();
}

//Custom command
void CExercise10App::addCommand() {
    acutPrintf(_T("\n Hello in the World of AutoCAD"));
}

//Creating non-graphical object in autocad
void CExercise10App::addLayer()
{
    // Open the Layer table for read
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbLayerTable* pLayerTable;
    pDb->getLayerTable(pLayerTable, AcDb::kForRead);
    // Check to see if the layer exists
    if (pLayerTable->has(_T("OBJ")) == false)
    {
        // Open the Layer table for write
        pLayerTable->upgradeOpen();
        // Create the new layer and assign it the name 'OBJ'
        AcDbLayerTableRecord* pLayerTableRecord = new AcDbLayerTableRecord();
        pLayerTableRecord->setName(_T("OBJ"));
        // Set the color of the layer to cyan
        AcCmColor color;
        color.setColorIndex(4);
        pLayerTableRecord->setColor(color);
        // Add the new layer to the Layer table
        pLayerTable->add(pLayerTableRecord);
        // Close the Layer table and record
        pLayerTable->close();
        pLayerTableRecord->close();
    }
}

//To iterate through all the objects in model space
void CExercise10App::listObjects()
{
    // Get the current database
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();

    // Get the current space object
    AcDbBlockTableRecord* pBlockTableRecord;
    Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord, pDb->currentSpaceId(), AcDb::kForRead);

    // Create a new block iterator that will be used to
    // step through each object in the current space
    AcDbBlockTableRecordIterator* pItr;
    pBlockTableRecord->newIterator(pItr);

    // Create a variable AcDbEntity type which is a generic
    // object to represent a Line, Circle, Arc, among other objects
    AcDbEntity* pEnt;

    // Step through each object in the current space
    for (pItr->start(); !pItr->done(); pItr->step())
    {
        // Get the entity and open it for read
        pItr->getEntity(pEnt, AcDb::kForRead);
        // Display the class name for the entity before
        // closing the object
        acutPrintf(_T("\nClass name: %s"), pEnt->isA()->name());
        pEnt->close();
    }

    // Close the current space object
    pBlockTableRecord->close();

    // Remove the block iterator object from memory
    delete pItr;

    // Display the AutoCAD Text Window
    acedTextScr();
}


extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
    switch (Msg) {
    case AcRx::kInitAppMsg:
        acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        //below line for registering new command
        acedRegCmds->addCommand(L"MyGroup", _T("MYCOMMAND"), _T("MYCOMMAND"), ACRX_CMD_MODAL, &CExercise10App::addCommand);

        //Command for making graphical object
        acedRegCmds->addCommand(L"AUCommands", _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CExercise10App::addLine);

        //Command for making non-graphical object(layer)
        acedRegCmds->addCommand(_T("AUCommands"), _T("MakeLayer"), _T("MakeLayer"), ACRX_CMD_MODAL, &CExercise10App::addLayer);

        //Command for getting all the objects in model space
        acedRegCmds->addCommand(_T("AUCommands"), _T("ListObjects"), _T("ListObjects"), ACRX_CMD_MODAL, &CExercise10App::listObjects);

        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// CExercise10App

BEGIN_MESSAGE_MAP(CExercise10App, CWinApp)
END_MESSAGE_MAP()


// CExercise10App construction

CExercise10App::CExercise10App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise10App object

CExercise10App theApp;


// CExercise10App initialization

BOOL CExercise10App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
