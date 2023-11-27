// Exercise11.h : main header file for the Exercise11 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif
#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise11App
// See Exercise11.cpp for the implementation of this class
//

class CExercise11App : public CWinApp
{
public:
	CExercise11App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void commandAndSystemVariable();
	DECLARE_MESSAGE_MAP()
};
