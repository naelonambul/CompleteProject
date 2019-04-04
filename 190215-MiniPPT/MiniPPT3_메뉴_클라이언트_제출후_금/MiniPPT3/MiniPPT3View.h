
// MiniPPT3View.h : interface of the CMiniPPT3View class
//

#pragma once

class CMiniPPT3View : public CView
{
protected: // create from serialization only
	CMiniPPT3View();
	DECLARE_DYNCREATE(CMiniPPT3View)

// Attributes
public:
	CMiniPPT3Doc* GetDocument() const;

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
	virtual ~CMiniPPT3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
};





#ifndef _DEBUG  // debug version in MiniPPT3View.cpp
inline CMiniPPT3Doc* CMiniPPT3View::GetDocument() const
   { return reinterpret_cast<CMiniPPT3Doc*>(m_pDocument); }
#endif

