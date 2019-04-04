// PPTView.cpp : implementation file
//

#include "stdafx.h"
#include "MiniPPT3.h"
#include "PPTView.h"
#include "PPTHeader.h"
#include "MyRect.h"
#include "MyTri.h"
#include "MyPie.h"
#include "MyLine.h"


// CPPTView

IMPLEMENT_DYNCREATE(CPPTView, CView)

CPPTView::CPPTView()
	: m_StartPoint(0, 0)
	, m_EndPoint(0, 0)
	, m_Rect(TRUE)
	, m_Triangle(FALSE)
	, m_Pie(FALSE)
	, m_Pen(FALSE)
	, m_Red(0)
	, m_Green(0)
	, m_Blue(0)
	, m_Black(1)
	, m_Line(10)
	, m_SelectMode(FALSE)
	, m_SelectPoint(0, 0)
	, m_Delete(FALSE)
	, myDefault(0, 0)
{

}

CPPTView::~CPPTView()
{
}

BEGIN_MESSAGE_MAP(CPPTView, CView)
	ON_COMMAND(ID_PROPERTIES_RECT, &CPPTView::OnPropertiesRect)
	ON_COMMAND(ID_PROPERTIES_TRIANGLE, &CPPTView::OnPropertiesTriangle)
	ON_COMMAND(ID_PROPERTIES_PIE, &CPPTView::OnPropertiesPie)
	ON_COMMAND(ID_PROPERTIES_PEN, &CPPTView::OnPropertiesPen)
	ON_COMMAND(ID_PROPERTIES_RED, &CPPTView::OnPropertiesRed)
	ON_COMMAND(ID_PROPERTIES_GREEN, &CPPTView::OnPropertiesGreen)
	ON_COMMAND(ID_PROPERTIES_BLUE, &CPPTView::OnPropertiesBlue)
	ON_COMMAND(ID_PROPERTIES_BLACK, &CPPTView::OnPropertiesBlack)
	ON_COMMAND(ID_PROPERTIES_LINE10, &CPPTView::OnPropertiesLine10)
	ON_COMMAND(ID_PROPERTIES_LINE20, &CPPTView::OnPropertiesLine20)
	ON_COMMAND(ID_PROPERTIES_LINE30, &CPPTView::OnPropertiesLine30)
	ON_COMMAND(ID_PROPERTIES_LINE40, &CPPTView::OnPropertiesLine40)
	ON_COMMAND(ID_PROPERTIES_SELECTMODE, &CPPTView::OnPropertiesSelectmode)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_RECT, &CPPTView::OnUpdatePropertiesRect)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_TRIANGLE, &CPPTView::OnUpdatePropertiesTriangle)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_PIE, &CPPTView::OnUpdatePropertiesPie)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_PEN, &CPPTView::OnUpdatePropertiesPen)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_RED, &CPPTView::OnUpdatePropertiesRed)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_GREEN, &CPPTView::OnUpdatePropertiesGreen)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_BLUE, &CPPTView::OnUpdatePropertiesBlue)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_BLACK, &CPPTView::OnUpdatePropertiesBlack)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_LINE10, &CPPTView::OnUpdatePropertiesLine10)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_LINE20, &CPPTView::OnUpdatePropertiesLine20)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_LINE30, &CPPTView::OnUpdatePropertiesLine30)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_LINE40, &CPPTView::OnUpdatePropertiesLine40)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_SELECTMODE, &CPPTView::OnUpdatePropertiesSelectmode)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_PROPERTIES_DELETE, &CPPTView::OnPropertiesDelete)
	ON_UPDATE_COMMAND_UI(ID_PROPERTIES_DELETE, &CPPTView::OnUpdatePropertiesDelete)
	ON_WM_RBUTTONUP()
	ON_WM_ERASEBKGND()
//	ON_WM_CREATE()
ON_WM_DESTROY()
END_MESSAGE_MAP()


// CPPTView drawing

void CPPTView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}


// CPPTView diagnostics

#ifdef _DEBUG
void CPPTView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPPTView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPPTView message handlers

/***********************************************************************
@brief		Shape Handler
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnPropertiesRect()
{
	// TODO: Add your command handler code here
	m_Rect = TRUE;	m_Triangle = FALSE;
					m_Pie = FALSE;	
					m_Pen = FALSE;
}


void CPPTView::OnPropertiesTriangle()
{
	// TODO: Add your command handler code here
	m_Triangle = TRUE;	m_Rect = FALSE;
						m_Pie = FALSE;
						m_Pen = FALSE;
}


void CPPTView::OnPropertiesPie()
{
	// TODO: Add your command handler code here
	m_Pie = TRUE;	m_Rect = FALSE;
					m_Triangle = FALSE;
					m_Pen = FALSE;
}


void CPPTView::OnPropertiesPen()
{
	// TODO: Add your command handler code here
	m_Pen = TRUE;	m_Rect = FALSE;
					m_Triangle = FALSE;
					m_Pie = FALSE;
}

/***********************************************************************
@brief		Color Handler
@details	value 1 or 0
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnPropertiesRed()
{
	// TODO: Add your command handler code here
	m_Red = 1;	m_Green = 0;	m_Blue = 0;
	m_Black = 0;
}


void CPPTView::OnPropertiesGreen()
{
	// TODO: Add your command handler code here
	m_Red = 0;	m_Green = 1;	m_Blue = 0;
	m_Black = 0;
}


void CPPTView::OnPropertiesBlue()
{
	// TODO: Add your command handler code here
	m_Red = 0;	m_Green = 0;	m_Blue = 1;
	m_Black = 0;
}


void CPPTView::OnPropertiesBlack()
{
	// TODO: Add your command handler code here
	m_Red = 0;	m_Green = 0;	m_Blue = 0;
	m_Black = 1; 
}

/***********************************************************************
@brief		Line Width Handler
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnPropertiesLine10()
{
	// TODO: Add your command handler code here
	m_Line = 10;
}


void CPPTView::OnPropertiesLine20()
{
	// TODO: Add your command handler code here
	m_Line = 20;
}


void CPPTView::OnPropertiesLine30()
{
	// TODO: Add your command handler code here
	m_Line = 30;
}


void CPPTView::OnPropertiesLine40()
{
	// TODO: Add your command handler code here
	m_Line = 40;
}

/***********************************************************************
@brief		!!! Slect mode Handler
@details	didn't work
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnPropertiesSelectmode()
{
	// TODO: Add your command handler code here
	m_SelectMode = TRUE;
}
/***********************************************************************
@brief		!!! Delete mode Handler
@details	didn't work
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnPropertiesDelete()
{
	// TODO: Add your command handler code here
	
	//SEND
	PPT_H tmp = { 0 };
	tmp.pptFlag = (UCHAR)1;
	tmp.pptDelete = (UCHAR)1;
	tmp.pptModify = (UCHAR)0;

	tmp.thirdPointX = m_SelectPoint.x;
	tmp.thirdPointY = m_SelectPoint.y;

	tmp.firstPointX = myDefault.x;
	tmp.firstPointY = myDefault.y;

	tmp.secondPointX = myDefault.x;
	tmp.secondPointY = myDefault.y;

	((CMiniPPT3App*)AfxGetApp())->m_Socket.Send(&tmp, sizeof(PPT_H));

	//Menu Reset
	m_Delete = TRUE; 
	m_SelectMode = FALSE;

	m_Rect = TRUE; m_Triangle = FALSE;
	m_Pie = FALSE; m_Pen = FALSE;

	m_Red = 0; m_Green = 0; m_Blue = 0; 
	m_Black = 1;

	m_Line = 10;
}


/***********************************************************************
@brief		Update Menu handler
@details	
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnUpdatePropertiesRect(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Rect == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesTriangle(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Triangle == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesPie(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Pie == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesPen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Pen == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesRed(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Red == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesGreen(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Green == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesBlue(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Blue == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesBlack(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Black == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesLine10(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Line == 10)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesLine20(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Line == 20)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesLine30(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Line == 30)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesLine40(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_Line == 40)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}


void CPPTView::OnUpdatePropertiesSelectmode(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_SelectMode == TRUE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}

void CPPTView::OnUpdatePropertiesDelete(CCmdUI *pCmdUI)
{
	// TODO: Add your command update UI handler code here
	if (m_SelectMode == FALSE)
		pCmdUI->Enable(false);
	else
		pCmdUI->Enable(true);
}

/***********************************************************************
@brief		Mouse Left Button Down
@details	for StartPoint
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(m_StartPoint != point)
		m_StartPoint = point;

	CView::OnLButtonDown(nFlags, point);
}

/***********************************************************************
@brief		Mouse Left Button Up
@details	for EndPoint
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_EndPoint != point)
		m_EndPoint = point;

	CView::OnLButtonUp(nFlags, point);
}
/***********************************************************************
@brief		Mouse Double Click
@details	for Select, Delete to Header - thirdPoint
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if(m_SelectPoint != point)
	m_SelectPoint = point;

	m_SelectMode = TRUE;

	CView::OnLButtonDblClk(nFlags, point);
}
/***********************************************************************
@brief		Mouse Right Button Up
@details	for Send
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	//End of One step
	//send
	PPT_H tmp = { 0 };
	tmp.pptFlag = (UCHAR)1;
	if(m_StartPoint != myDefault && m_EndPoint != myDefault)
	{ 
		if (m_SelectPoint != m_StartPoint && 
			m_StartPoint != m_EndPoint &&
			myDefault != m_SelectPoint)
		{
			tmp.pptModify = (UCHAR)1;
			tmp.thirdPointX = m_SelectPoint.x;
			tmp.thirdPointY = m_SelectPoint.y;

			tmp.firstPointX = m_StartPoint.x;	//Already Entered value
			tmp.firstPointY = m_StartPoint.y;

			tmp.secondPointX = m_EndPoint.x;
			tmp.secondPointY = m_EndPoint.y;
		}
		else if (m_StartPoint != myDefault && m_EndPoint != myDefault)
		{
			tmp.pptNew = (UCHAR)1;

			tmp.firstPointX = m_StartPoint.x;
			tmp.firstPointY = m_StartPoint.y;

			tmp.secondPointX = m_EndPoint.x;
			tmp.secondPointY = m_EndPoint.y;
		}

		tmp.blkColor = (UCHAR)m_Black;
		tmp.bluColor = (UCHAR)m_Blue;
		tmp.redColor = (UCHAR)m_Red;
		tmp.grnColor = (UCHAR)m_Green;

		tmp.penMenu = (UCHAR)m_Pen;
		tmp.pieMenu = (UCHAR)m_Pie;
		tmp.triMenu = (UCHAR)m_Triangle;
		tmp.recMenu = (UCHAR)m_Rect;

		switch (m_Line)
		{
		case 40: tmp.line40 = (UCHAR)1; break;
		case 30: tmp.line30 = (UCHAR)1; break;
		case 20: tmp.line20 = (UCHAR)1; break;
		case 10: tmp.line10 = (UCHAR)1; break;
		default: tmp.line10 = (UCHAR)1; break;
		}

		((CMiniPPT3App*)AfxGetApp())->m_Socket.Send(&tmp, sizeof(PPT_H));

		//make all default
		m_SelectMode = FALSE;
		m_SelectPoint = myDefault;

		m_StartPoint = myDefault;
		m_EndPoint = myDefault;
	}

	CView::OnRButtonUp(nFlags, point);
}
/***********************************************************************
@brief		Draw Paint
@details	for View
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	mypDC = &dc;
	if (pOldBitmap == nullptr)
	{
		bitmap.CreateCompatibleBitmap(mypDC, 1000, 700);		//Make bitmap at same size.
		memdc.CreateCompatibleDC(mypDC);	
	}
			
	pOldPen = memdc.SelectObject(&m_DummyPen);
	pOldBrush = memdc.SelectObject(&m_DummyBrush);
	pOldBitmap = memdc.SelectObject(&bitmap);

	//BackGround White
	memdc.FillSolidRect(0, 0,
		1000, 700,
		RGB(255, 255, 255));

	POSITION pos = m_PptList.GetHeadPosition();
	while( pos != NULL)
	{
		CMyShape *pShape = (CMyShape*)m_PptList.GetNext(pos);
		pShape->Draw(&memdc);
	}

	dc.BitBlt(0, 0, 1000, 700,
		&memdc, 0, 0, SRCCOPY);

	memdc.SelectObject(pOldPen);
	memdc.SelectObject(pOldBrush);
	memdc.SelectObject(pOldBitmap);
}
/***********************************************************************
@brief		EraseBkgnd Disable
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
BOOL CPPTView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default

	return TRUE;
	//return CView::OnEraseBkgnd(pDC);
}

/***********************************************************************
@brief		Draw One Header
@details	for PPTView
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CPPTView::DrawHeader(PPT_H nHeader, CDC* dc)
{

	unsigned char* cHeader;
	cHeader = reinterpret_cast<unsigned char*>(&nHeader);

	switch(cHeader[1] & 0xf0)	//shape
	{
		case 0x80:	
		{
			CMyRect Shapetmp(nHeader);
			Shapetmp.Draw(dc);
			break;		//rect
		}
		case 0x40:
		{	
			CMyTri Shapetmp(nHeader);
			Shapetmp.Draw(dc);
			break;		//tri
		}
		case 0x20:	
		{
			CMyPie Shapetmp(nHeader);
			Shapetmp.Draw(dc);
			break;		//pie
		}
		case 0x10:  
		{	
			CMyLine Shapetmp(nHeader);
			Shapetmp.Draw(dc);
			break;		//Line
		}
	}
}
/***********************************************************************
@brief		Free to your Shape
@details	
@author		gayver2
@date		2019-02-14
@version	0.0.4
***********************************************************************/
void CPPTView::ReleaseList(CPtrList &m_pList)
{
	POSITION pos = m_pList.GetHeadPosition();
	while (pos != NULL)
	{
		CMyShape *pShape = (CMyShape*)m_pList.GetNext(pos);
		delete pShape;
	}
}
/***********************************************************************
@brief		The point of release
@details
@author		gayver2
@date		2019-02-14
@version	0.0.4
***********************************************************************/
void CPPTView::OnDestroy()
{
	CView::OnDestroy();
	ReleaseList(m_PptList);
	// TODO: Add your message handler code here
}
