// ConnectSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MiniPPT3.h"
#include "ConnectSocket.h"

#include "ChatView.h"
#include "logView.h"
#include "PPTView.h"
#include "PPTHeader.h"

#include "MyRect.h"
#include "MyTri.h"
#include "MyPie.h"
#include "MyLine.h"

// CConnectSocket

CConnectSocket::CConnectSocket()
{
}

CConnectSocket::~CConnectSocket()
{
}


// CConnectSocket member functions

/***********************************************************************
@brief		Receive 
@details	call InvalidateRect
@author		gayver2
@date		2019-02-10
@version	0.0.3
***********************************************************************/
void CConnectSocket::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	PPT_H receiveTmp = { 0 };
	
	TCHAR szBuffer[1024] = { 0 }; 

	//ListBox
	int nCount1 = ((CMiniPPT3App*)AfxGetApp())->m_pLogView->m_wndLogForm.m_ListLog.GetCount();
	int nCount2 = ((CMiniPPT3App*)AfxGetApp())->m_pChatView->m_wndChatForm.m_List.GetCount();

	
	Receive(&receiveTmp, sizeof(PPT_H));
	unsigned char* cHeader;
	cHeader = reinterpret_cast<unsigned char*>(&receiveTmp);

	//ip
	CString startIP = receiveTmp.sourceip;			

	//shape
	CMyShape* tmp = nullptr;

	if(receiveTmp.chatFlag == (UCHAR)1)		
	{ 
		Receive(szBuffer,  sizeof(szBuffer));

		//Log Edit Box
		((CMiniPPT3App*)AfxGetApp())->m_pLogView->m_wndLogForm.m_ListLog.InsertString(nCount1, startIP + _T("-CHAT"));
		((CMiniPPT3App*)AfxGetApp())->m_pLogView->m_wndLogForm.m_ListLog.SetCurSel(nCount1);		
		
		//Chat Edit Box
		CString szMessage = szBuffer;
		((CMiniPPT3App*)AfxGetApp())->m_pChatView->m_wndChatForm.m_List.InsertString(nCount2, szMessage + _T(" ") +startIP);
		((CMiniPPT3App*)AfxGetApp())->m_pChatView->m_wndChatForm.m_List.SetCurSel(nCount2);			
	}
	else if (receiveTmp.pptFlag == (UCHAR)1)	//**
	{
		//Log Edit Box
		((CMiniPPT3App*)AfxGetApp())->m_pLogView->m_wndLogForm.m_ListLog.InsertString(nCount1, startIP + _T("-PPT"));
		((CMiniPPT3App*)AfxGetApp())->m_pLogView->m_wndLogForm.m_ListLog.SetCurSel(nCount1);		
		
		memcpy_s(&((CPPTView*)theApp.m_pPPTView)->tmp, sizeof(PPT_H), &receiveTmp, sizeof(PPT_H));
	
		CMyShape* Shapetmp = nullptr;
		CMyShape* FoundShape = nullptr;

		switch (cHeader[1] & 0xf0)	//shape
		{
			case 0x80: Shapetmp = new CMyRect(receiveTmp);	break;			//rect
			case 0x40: Shapetmp = new CMyTri(receiveTmp);	break;			//tri
			case 0x20: Shapetmp = new CMyPie(receiveTmp);	break;			//pie
			case 0x10: Shapetmp = new CMyLine(receiveTmp);	break;			//Line
		}

		POSITION prevPos = NULL;
		POSITION pos = NULL;
		pos = ((CPPTView*)theApp.m_pPPTView)->m_PptList.GetTailPosition();
		BOOL PtIn = 0;

		switch (cHeader[0] & 0x0f)
		{
			case 0x08: //New
				((CPPTView*)theApp.m_pPPTView)->m_PptList.AddTail(Shapetmp); break;
			case 0x04: //Delete need to search
			
				while (pos != NULL)
				{
					prevPos = pos;
					FoundShape = (CMyShape*)((CPPTView*)theApp.m_pPPTView)->m_PptList.GetPrev(pos);
					if(FoundShape != NULL && 
						FoundShape->PtInShape(receiveTmp.thirdPointX, receiveTmp.thirdPointY) == TRUE)
					{
						((CPPTView*)theApp.m_pPPTView)->m_PptList.RemoveAt(prevPos);
						break;
					}
				}		break;
		
			case 0x02:	//Modify need to search
			
				while (pos != NULL)
				{
					prevPos = pos;
					FoundShape = (CMyShape*)((CPPTView*)theApp.m_pPPTView)->m_PptList.GetPrev(pos);
					if (FoundShape != NULL && FoundShape->PtInShape(receiveTmp.thirdPointX, receiveTmp.thirdPointY) != NULL)
					{
						((CPPTView*)theApp.m_pPPTView)->m_PptList.InsertAfter(prevPos, Shapetmp);
						((CPPTView*)theApp.m_pPPTView)->m_PptList.RemoveAt(prevPos);
						break;
					}
				}		break;
			
			case 0x01: break;	 //Option
		}
	}
		//Draw Function
		((CPPTView*)theApp.m_pPPTView)->InvalidateRect(NULL, FALSE);
	CSocket::OnReceive(nErrorCode);
}
