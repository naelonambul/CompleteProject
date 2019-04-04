
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MiniPPT3.h"

#include "MainFrm.h"
#include "PPTView.h"
#include "ChatView.h"
#include "LogView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}
/***********************************************************************
@brief		Fix Resolution
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.style &= ~(WS_THICKFRAME | WS_MAXIMIZEBOX);
	cs.cx = 1200;
	cs.cy = 700;

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers


/***********************************************************************
@brief		Split Window, and Save
@details
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: Add your specialized code here and/or call the base class
	//1. Divide MiniPPT3View
	if (!m_wndSplitHor.CreateStatic(this, 1, 2))
		return FALSE;

	//2. Attach PPTView
	if (!m_wndSplitHor.CreateView(0, 0,
		RUNTIME_CLASS(CPPTView), CSize(900, 200), pContext))
		return FALSE;

	//3.Divide another MiniPPT3View
	if (!m_wndSplitVer.CreateStatic(&m_wndSplitHor, 2, 1,
		WS_CHILD | WS_VISIBLE,
		m_wndSplitHor.IdFromRowCol(0, 1)))
		return FALSE;

	//4. Attach LogView to top
	if (!m_wndSplitVer.CreateView(0, 0,
		RUNTIME_CLASS(CLogView), CSize(300, 200), pContext))
		return FALSE;

	//5. Attach ChatView to bottom
	if (!m_wndSplitVer.CreateView(1, 0,
		RUNTIME_CLASS(CChatView), CSize(300, 500), pContext))
		return FALSE;

	//X. Save View for approch
	theApp.m_pLogView = (CLogView*)m_wndSplitVer.GetPane(0, 0);
	theApp.m_pChatView = (CChatView*)m_wndSplitVer.GetPane(1, 0);
	theApp.m_pPPTView = (CPPTView*)m_wndSplitHor.GetPane(0, 0);

	//6. Focus on PPTView
	SetActiveView((CView*)m_wndSplitHor.GetPane(0, 0));

	return TRUE;
	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}
