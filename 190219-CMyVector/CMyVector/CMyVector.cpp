// CMyVector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyVector.h"

using ::guyver2::CMyVector;

int main()
{
	CMyVector a;
	a.MyPush_back(1);
	a.printArray();

	a.MyPush_back(2);
	a.printArray();

	a.MyPush_back(5);
	a.printArray();

	a.deleteIndex(2);
	a.printArray();

	a.MyPop_back();
	a.printArray();

	CMyVector b(a);

	b.insertNumber(3, 1);
	b.printArray();
	
	b.MyPush_back(5);
	b.printArray();

	CMyVector c;
	c = a + b;
	c.printArray();

	c.MyPop_back();

	c.printArray();

	printf("Capacity: %d\n", c.MyCapacity());

	c.MyShrink();

	printf("Capacity: %d\n", c.MyCapacity());
	c.printArray();


    return 0;
}