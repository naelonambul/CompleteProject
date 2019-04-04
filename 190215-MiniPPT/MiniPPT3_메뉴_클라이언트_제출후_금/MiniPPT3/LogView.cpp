// LogView.cpp : implementation file
//

#include "stdafx.h"
#include "MiniPPT3.h"
#include "LogView.h"


// CLogView

IMPLEMENT_DYNCREATE(CLogView, CView)

CLogView::CLogView()
{

}

CLogView::~CLogView()
{
}

BEGIN_MESSAGE_MAP(CLogView, CView)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CLogView drawing

void CLogView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CLogView diagnostics

#ifdef _DEBUG
void CLogView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CLogView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLogView message handlers

/***********************************************************************
@brief		Crate and Show window
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
int CLogView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_wndLogForm.Create(IDD_LOG_FORM, this);
	m_wndLogForm.ShowWindow(SW_SHOW);

	return 0;
}

/***********************************************************************
@brief		EraseBkgnd Disable
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
BOOL CLogView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}
