
// DragAndDropTestView.cpp : implementation of the CDragAndDropTestView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DragAndDropTest.h"
#endif

#include "DragAndDropTestDoc.h"
#include "DragAndDropTestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDragAndDropTestView

IMPLEMENT_DYNCREATE(CDragAndDropTestView, CView)

BEGIN_MESSAGE_MAP(CDragAndDropTestView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CDragAndDropTestView construction/destruction

CDragAndDropTestView::CDragAndDropTestView()
{
	// TODO: add construction code here

}

CDragAndDropTestView::~CDragAndDropTestView()
{
}

BOOL CDragAndDropTestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDragAndDropTestView drawing

void CDragAndDropTestView::OnDraw(CDC* /*pDC*/)
{
	CDragAndDropTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDragAndDropTestView printing

BOOL CDragAndDropTestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDragAndDropTestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDragAndDropTestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDragAndDropTestView diagnostics

#ifdef _DEBUG
void CDragAndDropTestView::AssertValid() const
{
	CView::AssertValid();
}

void CDragAndDropTestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDragAndDropTestDoc* CDragAndDropTestView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDragAndDropTestDoc)));
	return (CDragAndDropTestDoc*)m_pDocument;
}
#endif //_DEBUG


// CDragAndDropTestView message handlers


int CDragAndDropTestView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	m_wndDrag.Create(IDD_FORM_DRAG, this);
	m_wndDrag.ShowWindow(SW_SHOW);

	return 0;
}


void CDragAndDropTestView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	m_wndDrag.MoveWindow(0, 0, cx, cy);

	// TODO: Add your message handler code here
}
