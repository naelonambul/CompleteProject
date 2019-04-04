// LogForm.cpp : implementation file
//

#include "stdafx.h"
#include "MiniPPT3.h"
#include "LogForm.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "logView.h"

// CLogForm dialog

IMPLEMENT_DYNAMIC(CLogForm, CDialog)

CLogForm::CLogForm(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_LOG_FORM, pParent)
{
}

CLogForm::~CLogForm()
{
}

void CLogForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//ListBox
	DDX_Control(pDX, IDC_LIST2, m_ListLog);	
}


BEGIN_MESSAGE_MAP(CLogForm, CDialog)
	ON_LBN_SELCHANGE(IDC_LIST2, &CLogForm::OnLbnSelchangeList2)
END_MESSAGE_MAP()


// CLogForm message handlers

void CLogForm::OnLbnSelchangeList2()
{
	// TODO: Add your control notification handler code here
}

/***********************************************************************
@brief		ESCAPE and RETURN Key disable
@details	When the key push
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
BOOL CLogForm::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_ESCAPE 
			|| pMsg->wParam == VK_RETURN)
			return FALSE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}
