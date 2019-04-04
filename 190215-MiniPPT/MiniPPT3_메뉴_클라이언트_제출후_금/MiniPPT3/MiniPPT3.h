
// MiniPPT3.h : main header file for the MiniPPT3 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "ChatView.h"
#include "logView.h"
#include "PPTView.h"
#include "ConnectSocket.h"



// CMiniPPT3App:
// See MiniPPT3.cpp for the implementation of this class
//

class CMiniPPT3App : public CWinApp
{
public:
	CMiniPPT3App();

//Attributes
public:
	CChatView* m_pChatView = nullptr;
	CLogView* m_pLogView = nullptr;
	CPPTView* m_pPPTView = nullptr;

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
public:

	CConnectSocket m_Socket;
};

extern CMiniPPT3App theApp;
