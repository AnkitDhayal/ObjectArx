// Exercise5.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise5.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

//Creating non-graphical object(layer) in autocad
void CExercise5App::addLayer()
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




extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
    switch (Msg) {
    case AcRx::kInitAppMsg:
        acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        // below line for registering new command
        acedRegCmds->addCommand(L"AUCommands", _T("AddLayer"), _T("AddLayer"), ACRX_CMD_MODAL, &CExercise5App::addLayer);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// CExercise5App

BEGIN_MESSAGE_MAP(CExercise5App, CWinApp)
END_MESSAGE_MAP()


// CExercise5App construction

CExercise5App::CExercise5App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise5App object

CExercise5App theApp;


// CExercise5App initialization

BOOL CExercise5App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
