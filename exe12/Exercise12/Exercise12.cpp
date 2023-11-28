// Exercise12.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise12.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

//Function for displying user information
void CExercise12App::userInformation()
{
	// Request the user's age
	int nAge = 0;
	acedGetInt(_T("\nEnter your age: "), &nAge);
	// Request the user's name
	TCHAR cName[30];
	acedGetString(NULL, _T("\nEnter your name: "), cName);
	// Specify the insertion point for the first single line text object
	ads_point pt;
	acedGetPoint(NULL, _T("\nSpecify insertion point: "), pt);
	// Convert the entered age from an Integer to a character array
	TCHAR cAge[33];
	_itot_s(nAge, cAge, 10);
	// Build the string for the first text object
	TCHAR cVal1[512];
	_tcscpy_s(cVal1, _T("Age: "));
	_tcscat_s(cVal1, cAge);
	// Build the string for the second text object
	TCHAR cVal2[512];
	_tcscpy_s(cVal2, _T("Name: "));
	_tcscat_s(cVal2, cName);
	// Get the current database
	AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
	// Get the current space object
	AcDbBlockTableRecord* pBlockTableRecord;
	Acad::ErrorStatus es = acdbOpenObject(pBlockTableRecord, pDb->currentSpaceId(), AcDb::kForWrite);
	if (es == Acad::eOk)
	{
		AcGePoint3d ptIns(pt[0], pt[1], pt[2]);
		// Create the first text object at a height of 3.5
		AcDbText* pText1 = new AcDbText(ptIns, cVal1);
		pText1->setHeight(3.5);
		// Define the insertion point for the second text object
		ptIns.y = ptIns.y - 5;
		// Create the second text object at a height of 3.5
		AcDbText* pText2 = new AcDbText(ptIns, cVal2);
		pText2->setHeight(3.5);
		// Create a new ObjectId for the new Text objects
		AcDbObjectId text1Id, text2Id;
		// Add the new Text objects to the current space
		pBlockTableRecord->appendAcDbEntity(text1Id, pText1);
		pBlockTableRecord->appendAcDbEntity(text2Id, pText2);
		// Close the current space block
		pBlockTableRecord->close();
		pText1->close();
		pText2->close();
	}
	else {
		acutPrintf(_T("\nERROR: Block could not be opened for write."));
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
        acedRegCmds->addCommand(L"AUCommands", _T("UserInformation"), _T("UserInformation"), ACRX_CMD_MODAL, &CExercise12App::userInformation);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// CExercise12App

BEGIN_MESSAGE_MAP(CExercise12App, CWinApp)
END_MESSAGE_MAP()


// CExercise12App construction

CExercise12App::CExercise12App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise12App object

CExercise12App theApp;


// CExercise12App initialization

BOOL CExercise12App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
