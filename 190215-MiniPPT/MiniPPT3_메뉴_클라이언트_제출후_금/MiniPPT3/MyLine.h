#pragma once
#include "MyShape.h"
class CMyLine :
	public CMyShape
{
public:
	CMyLine(PPT_H pParam);
	~CMyLine();

	int Draw(CDC *pDC);
};

