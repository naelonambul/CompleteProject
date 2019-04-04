#include "stdafx.h"
#include "MyVector.h"

namespace guyver2{

CMyVector::CMyVector()
{
	printf("default\n");
}

CMyVector::CMyVector(const CMyVector &pParam)
{
	m_pdData = new double[pParam.m_nSize + 1] {m_dVal};
	errno_t myError = memcpy_s(m_pdData, sizeof(double)*pParam.m_nSize,
	pParam.m_pdData, sizeof(double)*pParam.m_nSize);
	if (myError) printf("Memory Allocate Failed");

	m_nSize = pParam.m_nSize;
	m_nLastIndex = pParam.m_nLastIndex;

	printf("Copy\n");
}

CMyVector::CMyVector(CMyVector &&pParam)
{
	m_pdData = pParam.m_pdData;

	m_nSize = pParam.m_nSize;
	m_nLastIndex = pParam.m_nLastIndex;

	pParam.m_pdData = nullptr;
	pParam.m_nSize = 10;
	pParam.m_nLastIndex = 0;

	printf("Move\n");
}

CMyVector::~CMyVector()
{
	Release();
}

void CMyVector::ExtendLength()
{
	int nOldSize = m_nSize;
	m_nSize += m_nSize;

	double *tmp = new double[m_nSize] { m_dVal };
	
	
	errno_t myError = memcpy_s(tmp, sizeof(double)*m_nSize, m_pdData, sizeof(double)*nOldSize);
	if (myError)		printf("Extend Memory failed");

	delete[] m_pdData;

	m_pdData = tmp;
	tmp = nullptr;
}

void CMyVector::CreateArray()
{
	if(m_pdData == nullptr)
		m_pdData = new double[m_nSize] {m_dVal};
}

void CMyVector::Release()
{
	if (m_pdData != nullptr){	delete[] m_pdData; }
	
	m_pdData = nullptr;
}

int CMyVector::insertNumber(int nIndex, double dValue)
{
	if(nIndex > m_nLastIndex)
	{
		printf("Invalid Index\n");
		return -1;
	}

	m_pdData[nIndex] = dValue;
	return 1;
}

int CMyVector::MyShrink()
{
	int nOldSize = m_nSize;
	m_nSize = m_nLastIndex + 1;

	double *tmp = new double[m_nSize] { m_dVal };
	
	errno_t myError = memcpy_s(tmp, sizeof(double)*m_nSize, m_pdData, sizeof(double)*m_nSize);
	if(myError)		return -1;
	
	delete[] m_pdData;

	m_pdData = tmp;
	tmp = nullptr;

	return 1;
}

void CMyVector::printArray()
{
	for(int i = 0; i < m_nLastIndex; ++i)
		printf("%3.2f ", m_pdData[i]);

	printf("\n");
}

int CMyVector::deleteValue(double dValue)
{
	int nIndex = findValue(dValue);

	if (nIndex == -1)		return -1;
	
	for (int i = nIndex; i < m_nLastIndex - 1; ++i)
		m_pdData[nIndex] = m_pdData[nIndex + 1];

	m_pdData[m_nLastIndex] = NULL;
	--m_nLastIndex;
	printf("Delete Value\n");

	return 1;
}

int CMyVector::deleteIndex(int nIndex)
{
	if(nIndex > m_nLastIndex)	return -1;
	
	for(int i = nIndex; i < m_nLastIndex - 1; ++i)
		m_pdData[nIndex] = m_pdData[nIndex + 1];
	
	m_pdData[m_nLastIndex] = NULL;
	--m_nLastIndex;
	printf("Delete Index\n");

	return 1;
}

int CMyVector::findValue(double dValue)
{
	for (int i = 0; i < m_nLastIndex + 1; ++i)
		if (m_pdData[i] == dValue)
		{
			printf("Found Index : %d, Value : %3.1f\n", i, m_pdData[i]);
			return i;
		}

	return -1;
}

int CMyVector::MyPush_back(double dValue)
{
	if(m_nLastIndex == 0)
	{
		CreateArray();
		m_pdData[0] = dValue;
		++m_nLastIndex;
		printf("PushHead\n");
		return -1;
	}
	else if (m_nLastIndex == m_nSize - 1)
		ExtendLength();

	m_pdData[m_nLastIndex] = dValue;
	++m_nLastIndex;

	printf("PushBack\n");

	return 1;
}

int CMyVector::MyPop_back()
{
	if (m_nLastIndex == 0)		return -1;
	
	m_pdData[m_nLastIndex] = m_dVal;
	--m_nLastIndex;

	printf("PopBack\n");
	return 1;
}

} //guyver2