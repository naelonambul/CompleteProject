#pragma once
#include "afxwin.h"


// CLogForm dialog

class CLogView;	//forward declarations

class CLogForm : public CDialog
{
	DECLARE_DYNAMIC(CLogForm)

public:
	CLogForm(CWnd* pParent = NULL);   // standard constructor
	virtual ~CLogForm();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOG_FORM };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnSelchangeList2();
	CListBox m_ListLog;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
