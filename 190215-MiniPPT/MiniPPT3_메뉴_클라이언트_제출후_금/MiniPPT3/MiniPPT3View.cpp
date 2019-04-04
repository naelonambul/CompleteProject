
// MiniPPT3View.cpp : implementation of the CMiniPPT3View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MiniPPT3.h"
#endif

#include "MiniPPT3Doc.h"
#include "MiniPPT3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMiniPPT3View

IMPLEMENT_DYNCREATE(CMiniPPT3View, CView)

BEGIN_MESSAGE_MAP(CMiniPPT3View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMiniPPT3View construction/destruction

CMiniPPT3View::CMiniPPT3View()
{
	// TODO: add construction code here

}

CMiniPPT3View::~CMiniPPT3View()
{
}

BOOL CMiniPPT3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMiniPPT3View drawing

void CMiniPPT3View::OnDraw(CDC* /*pDC*/)
{
	CMiniPPT3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMiniPPT3View printing

BOOL CMiniPPT3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMiniPPT3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMiniPPT3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CMiniPPT3View diagnostics

#ifdef _DEBUG
void CMiniPPT3View::AssertValid() const
{
	CView::AssertValid();
}

void CMiniPPT3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMiniPPT3Doc* CMiniPPT3View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMiniPPT3Doc)));
	return (CMiniPPT3Doc*)m_pDocument;
}
#endif //_DEBUG


// CMiniPPT3View message handlers
