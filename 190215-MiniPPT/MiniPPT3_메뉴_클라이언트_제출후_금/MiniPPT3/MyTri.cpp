#include "stdafx.h"
#include "MyTri.h"


CMyTri::CMyTri(PPT_H pParam)
	:CMyShape(pParam)
{
}


CMyTri::~CMyTri()
{
}


int CMyTri::Draw(CDC *pDC)
{
	POINT arPt[3] =
	{
		{ (int)m_Shape.firstPointX,(int)m_Shape.secondPointY },
		{ (int)(m_Shape.firstPointX + (int)m_Shape.secondPointX) / 2, (int)m_Shape.firstPointY },
		{ (int)m_Shape.secondPointX,(int)m_Shape.secondPointY }
	};

	CBrush NewBrush(RGB(m_red, m_green, m_blue));
	CBrush* pOldBrush = nullptr;
	pOldBrush = (CBrush*)pDC->SelectObject(&NewBrush);

	pDC->Polygon(arPt, 3);
	pDC->SelectObject(pOldBrush);

	return 0;
}
