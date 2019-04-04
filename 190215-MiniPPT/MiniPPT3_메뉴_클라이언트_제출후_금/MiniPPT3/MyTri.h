#pragma once
#include "MyShape.h"
class CMyTri :
	public CMyShape
{
public:
	CMyTri(PPT_H pParam);
	~CMyTri();

	int Draw(CDC *pDC);
};

