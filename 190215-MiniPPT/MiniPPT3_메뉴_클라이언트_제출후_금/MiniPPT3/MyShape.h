#pragma once
#include "PPTHeader.h"

// CMyShape command target

class CMyShape : public CObject
{
public:
	CMyShape(PPT_H &pParam);
	virtual ~CMyShape();

	PPT_H m_Shape;

	int m_red = 0;
	int m_blue = 0;
	int m_green = 0;

	int m_witdh = 0;


	operator PPT_H()	{ return m_Shape; }
	virtual int Draw(CDC *pDC)  = 0;
	BOOL PtInShape(unsigned int xParam, unsigned int yParam);
};


