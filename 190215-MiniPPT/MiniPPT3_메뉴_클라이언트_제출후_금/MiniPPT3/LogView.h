#pragma once
#include "LogForm.h"

// CLogView view

class CLogView : public CView
{
	DECLARE_DYNCREATE(CLogView)

protected:
	CLogView();           // protected constructor used by dynamic creation
	virtual ~CLogView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	CLogForm m_wndLogForm;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


