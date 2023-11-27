// Exercise8.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Exercise8.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

//Function to change a color of entity in AutoCAD
void CExercise8App::changeColor()
{
    ads_name sset, ename;
    // Prompt the user for objects to modify
    if (acedSSGet(NULL, NULL, NULL, NULL, sset) == RTNORM)
    {
        int lSSCnt = 0;
        acedSSLength(sset, &lSSCnt);
        // Display the number of objects selected
        acutPrintf(_T("\nObjects selected: %i"), lSSCnt);
        TCHAR kWord[30] = _T("");
        TCHAR kDef[30] = _T("Red");
        // Prompt the user for a keyword/option
        acedInitGet(0, _T("1 2 3 Red Yellow Green Bylayer"));
        int retVal = acedGetKword(
            _T("\nEnter a color [Red/Yellow/Green/Bylayer] <Red>: "),
            kWord);
        // User entered a keyword or pressed enter
        if (retVal == RTNORM || retVal == RTNONE)
        {
            // Set the value that should be current
            // if the user presses Enter
            if (retVal == RTNONE)
            {
                wcscpy_s(kWord, kDef);
            }
            // Loop through all the objects
            for (int loopCnt = 0; loopCnt < lSSCnt; loopCnt++)
            {
                // Get the next object from the selection set
                acedSSName(sset, loopCnt, ename);
                // Get the object id for the object
                // from the selection set
                AcDbObjectId objId;
                acdbGetObjectId(objId, ename);
                // Open the object for write
                AcDbEntity* pEnt;
                acdbOpenObject(pEnt, objId, AcDb::kForWrite);
                // Change the object's color based on
                // the keyword entered
                AcCmColor color;
                color.setColorIndex(AcCmEntityColor::kByACI);
                // Determine which color to assign to the object
                if (_tcscmp(kWord, _T("1")) == 0 || _tcscmp(kWord, _T("Red")) == 0)
                {
                    color.setColorIndex(1);
                }
                else if (_tcscmp(kWord, _T("2")) == 0 || _tcscmp(kWord, _T("Yellow")) == 0)
                {
                    color.setColorIndex(2);
                }
                else if (_tcscmp(kWord, _T("3")) == 0 || _tcscmp(kWord, _T("Green")) == 0)
                {
                    color.setColorIndex(3);
                }
                else if (_tcscmp(kWord, _T("Bylayer")) == 0)
                {
                    color.setColorIndex(AcCmEntityColor::kByLayer);
                }
                // Set the color for the object and then close it
                pEnt->setColor(color);
                pEnt->close();
            }
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
        acedRegCmds->addCommand(L"AUCommands", _T("ChangeColor"), _T("ChangeColor"), ACRX_CMD_MODAL, &CExercise8App::changeColor);
        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\n Command Unloaded"));
        break;
    }
    return AcRx::kRetOK;
}
// CExercise8App

BEGIN_MESSAGE_MAP(CExercise8App, CWinApp)
END_MESSAGE_MAP()


// CExercise8App construction

CExercise8App::CExercise8App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CExercise8App object

CExercise8App theApp;


// CExercise8App initialization

BOOL CExercise8App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}
