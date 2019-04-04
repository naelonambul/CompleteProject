#include "stdafx.h"
#include "MyRect.h"


CMyRect::CMyRect(PPT_H pParam)
	:CMyShape(pParam)
{
}


CMyRect::~CMyRect()
{
}


int CMyRect::Draw(CDC* pDC)
{
	CBrush NewBrush(RGB(m_red, m_green, m_blue));
	CBrush* pOldBrush = nullptr;
	pOldBrush = pDC->SelectObject(&NewBrush);

	pDC->Rectangle(m_Shape.firstPointX, m_Shape.firstPointY,
		m_Shape.secondPointX, m_Shape.secondPointY);
	pDC->SelectObject(pOldBrush);
	return 0;
}
