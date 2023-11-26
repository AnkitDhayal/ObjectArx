// Exercise2.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

//Function to display a massage in AutoCAD
void CExercise2App::addCommand()
{
    acutPrintf(_T("Welcome into the world of AutoCAD"));
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
        acedRegCmds->addCommand(L"AUCommands", _T("AddCommand"), _T("AddCommand"), ACRX_CMD_MODAL, &CExercise2App::addCommand);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// CExercise2App

BEGIN_MESSAGE_MAP(CExercise2App, CWinApp)
END_MESSAGE_MAP()


// CExercise2App construction

CExercise2App::CExercise2App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise2App object

CExercise2App theApp;


// CExercise2App initialization

BOOL CExercise2App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
