#include "stdafx.h"
#include "MyLine.h"


CMyLine::CMyLine(PPT_H pParam)
	:CMyShape(pParam)
{
}


CMyLine::~CMyLine()
{
}


int CMyLine::Draw(CDC* pDC)
{
	CPen SelectedPen;
	SelectedPen.CreatePen(PS_SOLID, m_witdh, RGB(m_red, m_green, m_blue));

	CPen* pOldtmp = nullptr;
	pOldtmp = (CPen*)pDC->SelectObject(&SelectedPen);
	pDC->MoveTo(m_Shape.firstPointX, m_Shape.firstPointY);
	pDC->LineTo(m_Shape.secondPointX, m_Shape.secondPointY);
	pDC->SelectObject(pOldtmp);

	return 0;
}
