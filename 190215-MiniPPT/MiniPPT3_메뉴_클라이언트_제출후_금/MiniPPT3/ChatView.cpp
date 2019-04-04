// ChatView.cpp : implementation file
//

#include "stdafx.h"
#include "MiniPPT3.h"
#include "ChatView.h"


// CChatView

IMPLEMENT_DYNCREATE(CChatView, CView)

CChatView::CChatView()
{

}

CChatView::~CChatView()
{
}

BEGIN_MESSAGE_MAP(CChatView, CView)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()


// CChatView drawing

void CChatView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CChatView diagnostics

#ifdef _DEBUG
void CChatView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CChatView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CChatView message handlers

/***********************************************************************
@brief		Crate and Show window
@details	
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
int CChatView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	m_wndChatForm.Create(IDD_CHAT_FORM, this);
	m_wndChatForm.ShowWindow(SW_SHOW);

	return 0;
}

/***********************************************************************
@brief		EraseBkgnd Disable
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
BOOL CChatView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}
