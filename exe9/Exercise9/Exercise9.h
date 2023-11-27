// Exercise9.h : main header file for the Exercise9 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise9App
// See Exercise9.cpp for the implementation of this class
//

class CExercise9App : public CWinApp
{
public:
	CExercise9App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void AddLine();
	DECLARE_MESSAGE_MAP()
};
