// Exercise7.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise7.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

//Function for taking input from user
void CExercise7App::addLine()
{
    // Get the current space block
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbBlockTableRecord* pBlockTableRecord;
    Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord, pDb->currentSpaceId(), AcDb::kForWrite);

    // Create 2 variables of the old point data type
    ads_point pt1, pt2;

    // Prompt for the first point
    if (RTNORM == acedGetPoint(NULL, _T("\nSpecify first point of line: "), pt1))
    {
        AcGePoint3d startPt(pt1[0], pt1[1], pt1[2]);

        // Prompt for the second point
        if (RTNORM == acedGetPoint(pt1, _T("\nSpecify second point of line: "), pt2))
        {
            AcGePoint3d endPt(pt2[0], pt2[1], pt2[2]);

            // Create and append the new Line object
            AcDbLine* pLine = new AcDbLine(startPt, endPt);
            pBlockTableRecord->appendAcDbEntity(pLine);

            // Close the block table record and the Line object
            pBlockTableRecord->close();
            pLine->close();
        }
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
        acedRegCmds->addCommand(L"AUCommands", _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CExercise7App::addLine);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// CExercise7App

BEGIN_MESSAGE_MAP(CExercise7App, CWinApp)
END_MESSAGE_MAP()


// CExercise7App construction

CExercise7App::CExercise7App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise7App object

CExercise7App theApp;


// CExercise7App initialization

BOOL CExercise7App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
