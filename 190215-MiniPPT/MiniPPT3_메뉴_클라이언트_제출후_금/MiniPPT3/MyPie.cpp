#include "stdafx.h"
#include "MyPie.h"


CMyPie::CMyPie(PPT_H pParam)
	:CMyShape(pParam)
{
}


CMyPie::~CMyPie()
{
}


int CMyPie::Draw(CDC* pDC)
{
	CBrush NewBrush(RGB(m_red, m_green, m_blue));
	CBrush* pOldBrush = nullptr;
	pOldBrush = (CBrush*)pDC->SelectObject(&NewBrush);

	pDC->Ellipse(
		m_Shape.firstPointX, m_Shape.firstPointY,
		m_Shape.secondPointX, m_Shape.secondPointY);
	pDC->SelectObject(pOldBrush);

	return 0;
}
