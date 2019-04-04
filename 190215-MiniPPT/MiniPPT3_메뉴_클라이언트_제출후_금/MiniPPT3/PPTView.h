#pragma once
#include "atltypes.h"
#include "PPTHeader.h"

#define SELECTMODE -1
#define ACTIVEMODE 0

// CPPTView view

class CPPTView : public CView
{
	DECLARE_DYNCREATE(CPPTView)

protected:
	CPPTView();           // protected constructor used by dynamic creation
	virtual ~CPPTView();

public:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

// Attributes
public:
	CPoint m_StartPoint;		// When you Click
	CPoint m_EndPoint;			// When you release 
	CPoint m_SelectPoint;		// When you Double Click
	CPoint myDefault;			// Default Point

	PPT_H tmp;
	CPtrList m_PptList;

	int m_Rect;					// Choose Rect Menu
	int m_Triangle;				// Choose Triangle Menu
	int m_Pie;					// Choose Pie Menu
	int m_Pen;					// Choose Pen Menu

	int m_Red;					// Choose Red Menu
	int m_Green;				// Choose Green Menu
	int m_Blue;					// Choose Blue Menu
	int m_Black;				// Choose Black Menu

	int m_Line;					// Choose and Change Pixel

	bool m_SelectMode;			// Choose Select Mode

	int m_Delete;				// Choose Delete

	CBitmap *pOldBitmap = nullptr;
	CBitmap bitmap;

	CDC *mypDC = nullptr;		// Only OnPaint
	CDC memdc;					// Double buffer

	CPen* pOldPen;
	CBrush* pOldBrush;

	CPen m_DummyPen;
	CBrush m_DummyBrush;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPropertiesRect();
	afx_msg void OnPropertiesTriangle();
	afx_msg void OnPropertiesPie();
	afx_msg void OnPropertiesPen();
	afx_msg void OnPropertiesRed();
	afx_msg void OnPropertiesGreen();
	afx_msg void OnPropertiesBlue();
	afx_msg void OnPropertiesBlack();
	afx_msg void OnPropertiesLine10();
	afx_msg void OnPropertiesLine20();
	afx_msg void OnPropertiesLine30();
	afx_msg void OnPropertiesLine40();
	afx_msg void OnPropertiesSelectmode();
	afx_msg void OnPropertiesDelete();

	afx_msg void OnUpdatePropertiesRect(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesTriangle(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesPie(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesPen(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesRed(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesGreen(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesBlue(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesBlack(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesLine10(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesLine20(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesLine30(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesLine40(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesSelectmode(CCmdUI *pCmdUI);
	afx_msg void OnUpdatePropertiesDelete(CCmdUI *pCmdUI);

	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);

	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	void DrawHeader(PPT_H nHeader, CDC *dc);
	void ReleaseList(CPtrList &m_pList);
};


