#pragma once
#include "MyShape.h"
class CMyPie :
	public CMyShape
{
public:
	CMyPie(PPT_H pParam);
	 ~CMyPie();

	 int Draw(CDC *pDC);
};

