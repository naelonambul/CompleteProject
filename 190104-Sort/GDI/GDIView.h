
// GDIView.h : interface of the CGDIView class
//

#pragma once
#define MYARRAYCOUNT 400
#define MAX_SCREEN_X 3840
#define MAX_SCREEN_Y 1920
#define SLEEP_TIME 1

class CGDIView : public CView
{
protected: // create from serialization only
	CGDIView();
	DECLARE_DYNCREATE(CGDIView)

// Attributes
public:
	CGDIDoc* GetDocument() const;
		
	int m_nDefaultX = 100;											//Default x

	int m_nTopPosition = 200;										//Chart downposition 
	int m_nBottomPosition = 600;									//Chart topposition

	int m_nTitlePosition = 60;										//Title			position
	int m_nIndexPosition = m_nBottomPosition + 50;					//Indexstring	position
	int m_nValuePosition = m_nBottomPosition + 100;					//valuestring	position
	int m_nArrowPosition = m_nBottomPosition + 150;					//Arrow			position
	int m_nArrowplusX = 5;

	int m_nWidth = 5;
	int m_nBetweenDistance = 3;

	int m_nBoxRatio		= 1 ;	//Box ratio
	int m_nBoxHeight	= (m_nBottomPosition - m_nTopPosition);			//Box height

	int m_nArray[MYARRAYCOUNT]	= { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};		//Array value
	int m_nArrayMaxValue		= 100;									//Max	value

	int m_nThread = 0;													//Thread number

	CDC memdc, memdc2;														//Double buffer
	CDC *mypDC			= nullptr;										//Only OnPaint
	
	CBitmap *pOldBitmap = nullptr;
	CBitmap bitmap;
	
	CFont* pOldfnt		= nullptr;

	CString strTitle;	CFont Titlefnt;		LOGFONT Titlelf = { 0 };	//Choose font
	CString strArray;	CFont Arrayfnt;		LOGFONT Arraylf = { 0 };
	CString strReturn;	CFont Returnfnt;	LOGFONT Returnlf = { 0 };

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CGDIView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	
	void DrawArrow(int nMutiply, int m_R, int m_G, int m_B, CClientDC &dc);		//DrawArrow(j, RGB, dc)
	void DrawBox(int j, CClientDC &dc);											//DrawStick(j, dc)
	void DrawArrayValue(int nIndex, CClientDC &dc);								//DrawArray(index, dc)
	void DrawChart(CDC &dc);
	void DrawEnterString(int m_nR, int m_nG, int m_nB, CDC &dc);

	void SetTitleFontSize(int size);
	void SetArrayFontSize(int size);
	void SetReturnFontSize(int size);
	
	inline void Randomize();													//Radomize value
	inline void SwapValue(int nIndex)											//Value switch
	{
		int tmp = m_nArray[nIndex];
		m_nArray[nIndex] = m_nArray[nIndex - 1];
		m_nArray[nIndex -1] = tmp;
	}
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

static UINT MyThread01(LPVOID pParam);


#ifndef _DEBUG  // debug version in GDIView.cpp
inline CGDIDoc* CGDIView::GetDocument() const
   { return reinterpret_cast<CGDIDoc*>(m_pDocument); }
#endif

