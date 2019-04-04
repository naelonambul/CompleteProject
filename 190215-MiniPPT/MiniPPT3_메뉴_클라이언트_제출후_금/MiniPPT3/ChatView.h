#pragma once
#include "ChatForm.h"

// CChatView view

class CChatView : public CView
{
	DECLARE_DYNCREATE(CChatView)

protected:
	CChatView();           // protected constructor used by dynamic creation
	virtual ~CChatView();

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
	CChatForm m_wndChatForm;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};


