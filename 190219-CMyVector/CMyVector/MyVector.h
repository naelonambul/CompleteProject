#pragma once

namespace guyver2{

class CMyVector
{
public:
	CMyVector();						//default
	CMyVector(const CMyVector &pParam);	//copy
	CMyVector(CMyVector &&pParam);		//move

	~CMyVector();

	double *m_pdData = nullptr;

	int m_nLastIndex = 0;			//Count of value
	int m_nSize = 10;			//Size of mem

private:
	double m_dVal = NULL;

public:
	int insertNumber(int nIndex, double dValue); 
	
	int findValue(double dValue);
	double MyAt(int nIndex)	const 
	{
		if (nIndex < m_nLastIndex)		return m_pdData[nIndex];
		return -1;
	}

	int deleteValue(double dValue);
	int deleteIndex(int nIndex);

	int MyPush_back(double dValue);
	int MyPop_back();

	int MyShrink();
	void printArray();

	double Myfront()	const	{	return m_pdData[0];			}
	double Myback()		const	{	return m_pdData[m_nLastIndex];	}

	int MySize()		const {	return m_nLastIndex;		}
	int MyCapacity()	const {	return m_nSize;			}
	
	bool MyEmpty()	const { return (m_nLastIndex == 0); }



	double operator[](int nIndex) const	{	return m_pdData[nIndex];	}

	double& operator[](int nIndex)	{	return m_pdData[nIndex];	}

	CMyVector operator+(const CMyVector &pParam)	{
		CMyVector Movetmp(pParam);

		memcpy_s(Movetmp.m_pdData, sizeof(double)*m_nLastIndex,
			m_pdData, sizeof(double)*m_nLastIndex);
		memcpy_s(Movetmp.m_pdData + m_nLastIndex, sizeof(double)*pParam.m_nLastIndex,
			pParam.m_pdData, sizeof(double)*pParam.m_nLastIndex);

		Movetmp.m_nLastIndex = m_nLastIndex + pParam.m_nLastIndex;
		Movetmp.m_nSize = Movetmp.m_nLastIndex + 1;

		return Movetmp;
	}

	CMyVector& operator=(CMyVector &&pParam)	{
		m_pdData = pParam.m_pdData;

		m_nSize = pParam.m_nSize;
		m_nLastIndex = pParam.m_nLastIndex;

		pParam.m_pdData = nullptr;

		return *this;
	}
private:
	void ExtendLength();
	void CreateArray();
	void Release();
};

} //guyver2