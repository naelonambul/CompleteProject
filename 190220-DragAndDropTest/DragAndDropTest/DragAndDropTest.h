
// DragAndDropTest.h : main header file for the DragAndDropTest application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDragAndDropTestApp:
// See DragAndDropTest.cpp for the implementation of this class
//

class CDragAndDropTestApp : public CWinApp
{
public:
	CDragAndDropTestApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDragAndDropTestApp theApp;
