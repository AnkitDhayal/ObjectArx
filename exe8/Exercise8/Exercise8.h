// Exercise8.h : main header file for the Exercise8 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise8App
// See Exercise8.cpp for the implementation of this class
//

class CExercise8App : public CWinApp
{
public:
	CExercise8App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void changeColor();
	DECLARE_MESSAGE_MAP()
};
