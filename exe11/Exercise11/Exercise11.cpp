// Exercise11.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise11.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>
#include "acedCmdNF.h"


void CExercise11App::commandAndSystemVariable()
{
    // Create a variable of the result buffer type
    struct resbuf rb, rb1;

    // Get the current value of the CIRCLERAD system variable
    acedGetVar(_T("CIRCLERAD"), &rb);
    acutPrintf(_T("\nCurrent CIRCLERAD: %.2f\n"), rb.resval);

    // Define the center point for the circle
    ads_point pt;
    pt[X] = 2.5; pt[Y] = 3.75; pt[Z] = 0.0;

    // Define the radius of the circle
    double rrad = 2.75;

    // Provide all values to the CIRCLE command
    if (acedCommandS(RTSTR, _T("._CIRCLE"), RTPOINT, pt, RTREAL, rrad, RTNONE) != RTNORM)
    {
        acutPrintf(_T("\nError: CIRCLE command failed."));
    }

    // Pause for the center point
    if (acedCommandS(RTSTR, _T("._CIRCLE"), RTSTR, PAUSE, RTREAL, rrad, RTNONE) != RTNORM)
    {
        acutPrintf(_T("\nError: CIRCLE command failed."));
    }

    // Set the value of CIRCLERAD to the previous value
    rb1.restype = RTREAL;
    rb1.resval.rreal = rb.resval.rreal;
    acedSetVar(_T("CIRCLERAD"), &rb1);
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
        acedRegCmds->addCommand(L"AUCommands", _T("AddLine"), _T("AddLine"), ACRX_CMD_MODAL, &CExercise11App::commandAndSystemVariable);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}

// CExercise11App

BEGIN_MESSAGE_MAP(CExercise11App, CWinApp)
END_MESSAGE_MAP()


// CExercise11App construction

CExercise11App::CExercise11App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise11App object

CExercise11App theApp;


// CExercise11App initialization

BOOL CExercise11App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
