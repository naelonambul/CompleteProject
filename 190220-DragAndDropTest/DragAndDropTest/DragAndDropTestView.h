
// DragAndDropTestView.h : interface of the CDragAndDropTestView class
//

#pragma once
#include "FormDrag.h"

class CDragAndDropTestView : public CView
{
protected: // create from serialization only
	CDragAndDropTestView();
	DECLARE_DYNCREATE(CDragAndDropTestView)

// Attributes
public:
	CDragAndDropTestDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDragAndDropTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

public:
	CFormDrag m_wndDrag;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDropFiles(HDROP hDropInfo);
};

#ifndef _DEBUG  // debug version in DragAndDropTestView.cpp
inline CDragAndDropTestDoc* CDragAndDropTestView::GetDocument() const
   { return reinterpret_cast<CDragAndDropTestDoc*>(m_pDocument); }
#endif

