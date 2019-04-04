#pragma once
#include "afxwin.h"
#include "PPTHeader.h"

// CChatForm dialog

class CChatView;	//forward declarations

class CChatForm : public CDialog
{
	DECLARE_DYNAMIC(CChatForm)

public:
	CChatForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~CChatForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT_FORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CListBox m_List;
	CString m_strMessage;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnEnChangeEdit1();
};
