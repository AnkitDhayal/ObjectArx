// Exercise12.h : main header file for the Exercise12 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise12App
// See Exercise12.cpp for the implementation of this class
//

class CExercise12App : public CWinApp
{
public:
	CExercise12App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void userInformation();
	DECLARE_MESSAGE_MAP()
};
