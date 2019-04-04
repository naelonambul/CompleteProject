
// GDIView.cpp : implementation of the CGDIView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GDI.h"
#endif

#include "GDIDoc.h"
#include "GDIView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGDIView

IMPLEMENT_DYNCREATE(CGDIView, CView)

BEGIN_MESSAGE_MAP(CGDIView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CGDIView construction/destruction

CGDIView::CGDIView()
{
	// TODO: add construction code here
	Randomize();

	SetTitleFontSize(80);
	SetArrayFontSize(0);
	SetReturnFontSize(25);
}

CGDIView::~CGDIView()
{
}

BOOL CGDIView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGDIView drawing

void CGDIView::OnDraw(CDC* /*pDC*/)
{
	CGDIDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	TRACE("OnDraw\n");

	// TODO: add draw code for native data here
}


// CGDIView printing

BOOL CGDIView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGDIView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGDIView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CGDIView diagnostics

#ifdef _DEBUG
void CGDIView::AssertValid() const
{
	CView::AssertValid();
}

void CGDIView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGDIDoc* CGDIView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGDIDoc)));
	return (CGDIDoc*)m_pDocument;
}
#endif //_DEBUG


// CGDIView message handlers


int CGDIView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}

/***********************************************************************
@brief		Keep shape at something change
@details	Draw first time, and keep shape when receive 
@author		gayver2
@date		2018-12-27
@version	0.0.1
***********************************************************************/
void CGDIView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	
	mypDC = &dc;
	
	if(pOldBitmap == nullptr)
	{	
		bitmap.CreateCompatibleBitmap(mypDC, MAX_SCREEN_X, MAX_SCREEN_Y);		//Make bitmap at same size.
		memdc.CreateCompatibleDC(mypDC);										//Create buffer
		memdc2.CreateCompatibleDC(mypDC);
	}										
	
	pOldBitmap = memdc.SelectObject(&bitmap);

	memdc.FillSolidRect(0, 0, 
		MAX_SCREEN_X, MAX_SCREEN_Y, 
		RGB(255, 255, 255));													//Draw buffer background	

	memdc.SetBkColor(RGB(255, 255, 255));										//It is string
	
	pOldfnt = memdc.SelectObject(&Titlefnt);									//Change font

	strTitle = _T("Sort");
	memdc.TextOut(m_nTitlePosition, m_nTitlePosition - 10, strTitle);				//Title
	
	memdc.SelectObject(&Arrayfnt);												//Change font
	DrawChart(memdc);															//Include Array

	DrawEnterString(0, 0, 0, memdc);

	memdc2.SelectObject(&bitmap);

	memdc.BitBlt(0, 0, MAX_SCREEN_X, MAX_SCREEN_Y, &memdc2, 0, 0, SRCCOPY);

	dc.BitBlt(0, 0, MAX_SCREEN_X, MAX_SCREEN_Y,
		&memdc, 0, 0, SRCCOPY);

	memdc.SelectObject(pOldfnt);
	memdc.SelectObject(pOldBitmap);

	//OutputDebugString(_T("CGDIView::OnPaint()"));
}


void CGDIView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

#include "cstdio"

/***********************************************************************
@brief		Change stick position
@details	When the key push, change value. It depends on the previous value.  
@author		gayver2
@date		2018-12-27
@version	0.0.1
***********************************************************************/
void CGDIView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
		CClientDC dc(this);
		CDC &p = dc;

		if(nChar == VK_RETURN && m_nThread == 0) 
		{
			AfxBeginThread(MyThread01, NULL);
			//OutputDebugString(_T("AfxBeginThread\n"));
		}
		else if (nChar == VK_RETURN && m_nThread == 2)
		{
			m_nThread = 0;
			Randomize();
		}
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}

/***********************************************************************
@brief		DrawArrow for progress
@details	m_R, m_G, m_B is RGB.
@author		gayver2
@date		2018-12-27
@version	0.0.1
***********************************************************************/
void CGDIView::DrawArrow(int nMutiply, int m_R, int m_G, int m_B, CClientDC &dc)
{

	CPen pen1(PS_SOLID, 3, RGB(m_R, m_G, m_B));
	CPen *pOldPen1 = dc.SelectObject(&pen1);

	dc.MoveTo(m_nDefaultX + (nMutiply - 1)* m_nBetweenDistance - 10, m_nArrowPosition + 10); //arrow
	dc.LineTo(m_nDefaultX + (nMutiply - 1) * m_nBetweenDistance, m_nArrowPosition);
	dc.LineTo(m_nDefaultX + (nMutiply - 1) * m_nBetweenDistance + 10, m_nArrowPosition + 10);

	dc.MoveTo(m_nDefaultX + (nMutiply - 1) * m_nBetweenDistance, m_nArrowPosition);			//vertival
	dc.LineTo(m_nDefaultX + (nMutiply - 1) * m_nBetweenDistance, m_nArrowPosition + 25);
	dc.LineTo(m_nDefaultX + nMutiply * m_nBetweenDistance, m_nArrowPosition + 25);			//horizontally
	dc.LineTo(m_nDefaultX + nMutiply * m_nBetweenDistance, m_nArrowPosition);

	dc.MoveTo(m_nDefaultX + nMutiply * m_nBetweenDistance - 10, m_nArrowPosition + 10);		//arrow
	dc.LineTo(m_nDefaultX + nMutiply * m_nBetweenDistance, m_nArrowPosition);
	dc.LineTo(m_nDefaultX + nMutiply * m_nBetweenDistance + 10, m_nArrowPosition + 10);

	dc.SelectObject(&pOldPen1);
}
/***********************************************************************
@brief		DrawGreybox for stick
@details	there are 2 box. One is white, another is gray.
@author		gayver2
@date		2018-12-27
@version	0.0.1
***********************************************************************/
void CGDIView::DrawBox(int j ,CClientDC &dc)
{
	dc.FillSolidRect(											//white
		m_nDefaultX + j * m_nBetweenDistance - 10, m_nTopPosition,
		m_nWidth, m_nBoxHeight - (m_nBoxRatio * m_nArray[j]),
		RGB(255, 255, 255));

	dc.FillSolidRect(											//gray
		m_nDefaultX + j * m_nBetweenDistance - 10, m_nBottomPosition - (m_nBoxRatio * m_nArray[j - 1]),
		m_nWidth, m_nBoxRatio * m_nArray[j - 1],
		RGB(192, 192, 192));

	dc.FillSolidRect(											//white
		m_nDefaultX + (j - 1) * m_nBetweenDistance - 10, m_nTopPosition,
		m_nWidth, m_nBoxHeight - (m_nBoxRatio * m_nArray[j]),
		RGB(255, 255, 255));

	dc.FillSolidRect(											//gray
		m_nDefaultX + (j - 1) * m_nBetweenDistance - 10, m_nBottomPosition - (m_nBoxRatio * m_nArray[j]),
		m_nWidth, m_nBoxRatio * m_nArray[j],
		RGB(192, 192, 192));
}

/***********************************************************************
@brief		DrawArray for switch
@details	There are two value. The value need to switch.
@author		gayver2
@date		2018-12-27
@version	0.0.1
***********************************************************************/
void CGDIView::DrawArrayValue(int j, CClientDC &dc)
{
	dc.SetBkColor(RGB(255, 255, 255));						//BackColor
	dc.SetTextColor(RGB(0, 0, 192));							//value

	CString strTmp;
	CString strTmp2;

	pOldfnt = dc.SelectObject(&Arrayfnt);

	strTmp.Format(_T("%d"), m_nArray[j]);
	strTmp2.Format(_T("%d"), m_nArray[j - 1]);
															//switch print
	dc.TextOut(m_nDefaultX + j		* m_nBetweenDistance, m_nValuePosition, strTmp);			
	dc.TextOut(m_nDefaultX + (j - 1)* m_nBetweenDistance, m_nValuePosition, strTmp2);

	dc.SelectObject(pOldfnt);
	dc.SetTextColor(RGB(0, 0, 0));
}
/***********************************************************************
@brief		Randomize array value
@details
@author		gayver2
@date		2019-01-03
@version	0.0.2
***********************************************************************/
inline void CGDIView::Randomize()
{
	srand((unsigned)time(NULL));

	int tmp = 0;
	BOOL Same[MYARRAYCOUNT] = { FALSE };

	for (int i = 0; i < MYARRAYCOUNT;)
	{
		tmp = rand() % MYARRAYCOUNT;

		if (Same[tmp] == FALSE)
		{
			Same[tmp] = TRUE;
			m_nArray[i] = tmp;

			++i;
		}
	}
}
/************************************************************************
@brief		DrawMainChart
@details
@author		gayver2
@date		2019 - 01 - 04
@version	0.0.2
************************************************************************/
void CGDIView::DrawChart(CDC &dc)
{
	for (int i = 0; i < MYARRAYCOUNT; ++i)
	{
		dc.FillSolidRect(										//white
			m_nDefaultX + i * m_nBetweenDistance - 10, m_nTopPosition,
			m_nWidth, m_nBoxHeight - (m_nBoxRatio * m_nArray[i]),
			RGB(255, 255, 255));

		dc.FillSolidRect(										//gray
			m_nDefaultX + i * m_nBetweenDistance - 10, m_nBottomPosition - (m_nBoxRatio * m_nArray[i]),
			m_nWidth, m_nBoxRatio * m_nArray[i],
			RGB(192, 192, 192));

		dc.SetBkColor(RGB(255, 255, 255));					//BackColor
		dc.SelectObject(&Arrayfnt);

		dc.SetTextColor(RGB(0, 0, 0));							//index
		strArray.Format(_T("%d"), i);
		dc.TextOut(m_nDefaultX + i * m_nBetweenDistance, m_nIndexPosition, strArray);

		dc.SetTextColor(RGB(0, 0, 192));						//value
		strArray.Format(_T("%d"), m_nArray[i]);
		dc.TextOut(m_nDefaultX + i * m_nBetweenDistance, m_nValuePosition, strArray);
	}
	dc.SetTextColor(RGB(0, 0, 0));
}

/************************************************************************
@brief		Set Title Font & Size
@details
@author		gayver2
@date		2019 - 01 - 04
@version	0.0.2
************************************************************************/
void CGDIView::SetTitleFontSize(int size = 80)
{
	wsprintf(Titlelf.lfFaceName, _T("%s"), _T("Tahoma"));
	Titlelf.lfHeight = size;							//fix Font size

	Titlefnt.CreateFontIndirect(&Titlelf);
}

/************************************************************************
@brief		Set Array Font & Size
@details
@author		gayver2
@date		2019 - 01 - 04
@version	0.0.2
************************************************************************/
void CGDIView::SetArrayFontSize(int size)
{
	wsprintf(Arraylf.lfFaceName, _T("%s"), _T("Arial"));
	Arraylf.lfHeight = size;							//fix Font size

	Arrayfnt.CreateFontIndirect(&Arraylf);
}
/************************************************************************
@brief		Set Array Font & Size
@details
@author		gayver2
@date		2019 - 01 - 04
@version	0.0.2
************************************************************************/
void CGDIView::SetReturnFontSize(int size)
{
	wsprintf(Returnlf.lfFaceName, _T("%s"), _T("Consolas"));
	Returnlf.lfHeight = size;							//fix Font size

	Returnfnt.CreateFontIndirect(&Returnlf);
}
/************************************************************************
@brief		Draw Enter String
@details
@author		gayver2
@date		2019 - 01 - 04
@version	0.0.2
************************************************************************/
void CGDIView::DrawEnterString(int m_nR, int m_nG, int m_nB, CDC &dc)
{
	dc.SelectObject(&Returnfnt);
	dc.SetTextColor(RGB(m_nR, m_nG, m_nB));
	strReturn = _T("Press");
	dc.TextOut(20, 730, strReturn);
	strReturn = _T("Enter");
	dc.TextOut(20, 750, strReturn);
	dc.SetTextColor(RGB(0, 0, 0));

	dc.SelectObject(&pOldfnt);
}
#include "MainFrm.h"

CCriticalSection g_cs;

/************************************************************************
@brief		Worker Thread.
@details	call draw function from pView.
@author		gayver2
@date		2019 - 01 - 04
@version	0.0.2
************************************************************************/
UINT MyThread01(LPVOID pParam)
{	
	CGDIView *pView = (CGDIView *)((CFrameWnd *)theApp.m_pMainWnd)->GetActiveView();
	CMainFrame *pMain = (CMainFrame *)theApp.m_pMainWnd;
	
	g_cs.Lock();										//Lock
	pView->m_nThread = 1;								//Already guaranteed from CPU
	CClientDC dc(pView);
	g_cs.Unlock();										//UnLock

	dc.SetBkColor(RGB(255, 255, 255));
	
	pView->DrawEnterString(255, 255, 255, dc);
	
	int m_myI = 0;
	int m_myJ = m_myI + 1;

	for (int i = m_myI; i < MYARRAYCOUNT; ++i)
	{
		for (int j = m_myJ; j < MYARRAYCOUNT; ++j)
		{	
			if (j == 1)												//Remove last compared																
			{
				pView->DrawArrow(MYARRAYCOUNT -1, 255, 255, 255, dc);//Remove Last Index
			}
		
			pView->DrawArrow(j - 1, 255, 255, 255, dc);				//Remove resent result

			if ( pView->m_nArray[j] < pView->m_nArray[j - 1] )		//Compare value	
			{
				pView->DrawBox(j, dc);
				
				g_cs.Lock();										//Lock
				pView->SwapValue(j);
				g_cs.Unlock();										//UnLock

				pView->DrawArrayValue(j, dc);
			}

			pView->DrawArrow(j, 192, 0, 0, dc);
			//Sleep(SLEEP_TIME);									//Give a moment
		}
	}
		
	pView->DrawEnterString(0, 0, 0, dc);							//Navigate next step
	pView->m_nThread = 2;											//Release VK_Return key
	return 0;
}


BOOL CGDIView::OnEraseBkgnd(CDC* pDC)
{
	return true;

	//return CView::OnEraseBkgnd(pDC);
}
