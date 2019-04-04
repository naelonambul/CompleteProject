// ChatForm.cpp : implementation file
//

#include "stdafx.h"
#include "MiniPPT3.h"
#include "ChatForm.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "ChatView.h"

// CChatForm dialog

IMPLEMENT_DYNAMIC(CChatForm, CDialog)

CChatForm::CChatForm(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_CHAT_FORM, pParent)
	, m_strMessage(_T(""))
{
}

CChatForm::~CChatForm()
{
}

void CChatForm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//List Box
	DDX_Control(pDX, IDC_LIST1, m_List);
	//Edit Box
	DDX_Text(pDX, IDC_EDIT1, m_strMessage);	
}


BEGIN_MESSAGE_MAP(CChatForm, CDialog)
	ON_WM_KEYDOWN()
	ON_BN_CLICKED(IDC_BUTTON1, &CChatForm::OnBnClickedButton1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CChatForm::OnLbnSelchangeList1)
	ON_EN_CHANGE(IDC_EDIT1, &CChatForm::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CChatForm message handlers


void CChatForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

/***********************************************************************
@brief		ESCAPE Key disable
@details	When the key push
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
BOOL CChatForm::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_ESCAPE)
			return FALSE;
	}
	return CDialog::PreTranslateMessage(pMsg);
}

/***********************************************************************
@brief		ChatMessage Send Button
@details	Use Edit box, List Box
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CChatForm::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	UpdateData();
	PPT_H tmp = { 0 };
	tmp.chatFlag = 1;
	tmp.strlen = m_strMessage.GetLength();

	if (tmp.strlen > 0)
	{
		//insert send code

		((CMiniPPT3App*)AfxGetApp())->m_Socket.Send(&tmp, sizeof(PPT_H));
		((CMiniPPT3App*)AfxGetApp())->m_Socket.Send((LPVOID)(LPCTSTR)m_strMessage,
			(tmp.strlen + 1) * sizeof(TCHAR));

		m_strMessage = _T("");
		UpdateData(FALSE);
	}
}


void CChatForm::OnLbnSelchangeList1()
{
	// TODO: Add your control notification handler code here
}


void CChatForm::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
