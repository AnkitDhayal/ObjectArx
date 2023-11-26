// Exercise1.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>


//Function for entry point in AutoCAD
extern "C"
int acrxEntryPoint(AcRx::AppMsgCode Msg, void* pkt)
{
    switch (Msg) {
    case AcRx::kInitAppMsg:
        acrxUnlockApplication(pkt);
        acrxRegisterAppMDIAware(pkt);
        acutPrintf(L"\n Command Loaded");
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}
// CExercise1App

BEGIN_MESSAGE_MAP(CExercise1App, CWinApp)
END_MESSAGE_MAP()


// CExercise1App construction

CExercise1App::CExercise1App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise1App object

CExercise1App theApp;


// CExercise1App initialization

BOOL CExercise1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
