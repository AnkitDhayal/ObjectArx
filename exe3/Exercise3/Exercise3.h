// Exercise3.h : main header file for the Exercise3 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif


#include "resource.h"		// main symbols


// CExercise3App
// See Exercise3.cpp for the implementation of this class

class CExercise3App : public CWinApp
{
public:
	CExercise3App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void addCommand();
	DECLARE_MESSAGE_MAP()
};
