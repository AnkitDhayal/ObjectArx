// Exercise1.h : main header file for the Exercise1 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise1App
// See Exercise1.cpp for the implementation of this class
//

class CExercise1App : public CWinApp
{
public:
	CExercise1App();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
