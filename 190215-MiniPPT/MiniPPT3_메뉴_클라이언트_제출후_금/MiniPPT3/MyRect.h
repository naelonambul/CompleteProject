#pragma once
#include "MyShape.h"
#include "PPTHeader.h"

class CMyRect :public CMyShape
{
public:
	CMyRect(PPT_H pParam);
	~CMyRect();


	int Draw(CDC *pDC);
};

