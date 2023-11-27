// Exercise6.h : main header file for the Exercise6 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif


#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise6App
// See Exercise6.cpp for the implementation of this class
//

class CExercise6App : public CWinApp
{
public:
	CExercise6App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void listObjects();
	DECLARE_MESSAGE_MAP()
};
