// Exercise5.h : main header file for the Exercise5 DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif


#include "resource.h"		// main symbols
#include <Windows.h>
#include<arxHeaders.h>
#include <dbents.h>

// CExercise5App
// See Exercise5.cpp for the implementation of this class
//

class CExercise5App : public CWinApp
{
public:
	CExercise5App();

// Overrides
public:
	virtual BOOL InitInstance();
	static void addLayer();
	DECLARE_MESSAGE_MAP()
};
