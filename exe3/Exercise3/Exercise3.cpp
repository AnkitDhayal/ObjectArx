// Exercise3.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

//Function to a display a massage in AutoCAD
void CExercise3App::addCommand()
{
    acutPrintf(_T("\n Hello in the World of AutoCAD"));
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
        acedRegCmds->addCommand(L"AUCommands", _T("AddCommand"), _T("AddCommand"), ACRX_CMD_MODAL, &CExercise3App::addCommand);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// CExercise3App

BEGIN_MESSAGE_MAP(CExercise3App, CWinApp)
END_MESSAGE_MAP()


// CExercise3App construction

CExercise3App::CExercise3App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise3App object

CExercise3App theApp;


// CExercise3App initialization

BOOL CExercise3App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
