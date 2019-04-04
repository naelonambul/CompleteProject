// MyShape.cpp : implementation file
//

#include "stdafx.h"
#include "MiniPPT3.h"
#include "MyShape.h"


// CMyShape

CMyShape::CMyShape(PPT_H &pParam)
{
	m_Shape = pParam;
	if(pParam.redColor)		m_red = 255;
	if(pParam.bluColor)		m_blue = 255;
	if(pParam.grnColor)		m_green = 255;
	if (pParam.blkColor) 	{m_red = 0;	m_blue = 0;	m_green = 0;}

	if(pParam.line10)	m_witdh = 10;
	if(pParam.line20)	m_witdh = 20;
	if(pParam.line30)	m_witdh = 30;
	if(pParam.line40)	m_witdh = 40;
}

CMyShape::~CMyShape()
{
}


// CMyShape member functions


BOOL CMyShape::PtInShape(unsigned int xParam, unsigned int yParam)
{
	CRect rgnTmp(m_Shape.firstPointX, m_Shape.firstPointY
	,m_Shape.secondPointX, m_Shape.secondPointY);
	
	POINT tmp = {xParam, yParam};

	if(PtInRect(rgnTmp, tmp))
	return TRUE;

	return FALSE;
}
