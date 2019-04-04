// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "PPTServer.h"
#include "ClientSocket.h"
#include "ListenSocket.h"
#include "PPTHeader.h"


// CClientSocket

CClientSocket::CClientSocket(CListenSocket &sock)
	:m_Listen(sock)
{
}

CClientSocket::~CClientSocket()
{
}


// CClientSocket member functions


void CClientSocket::OnClose(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class

	CSocket::OnClose(nErrorCode);

	m_Listen.CloseClient(this);
}

/***********************************************************************
@brief		Modified OnRecive
@details	Echo chat, PPT Header
@author		gayver2
@date		2019-02-10
@version	0.0.1
***********************************************************************/
void CClientSocket::OnReceive(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	PPT_H tmp = { 0 };

	TCHAR szBuffer[1024] = { 0 };
	//한 클라이언트로부터 메시지를 수신하면
	int nRecv = Receive(&tmp, sizeof(tmp));

	int nCilentLength = sizeof(sockaddr_in);
	SOCKADDR_IN clientAddress;

	getpeername(this->m_hSocket, (sockaddr*)&clientAddress, &nCilentLength);
	CString strClientIP(inet_ntoa(clientAddress.sin_addr));
	int nLength = sizeof(strClientIP);

	TCHAR* myIP = (TCHAR*)(LPCTSTR)strClientIP;

	memcpy_s(tmp.sourceip, 16 * sizeof(TCHAR), myIP, 16 * sizeof(TCHAR));


	if (tmp.chatFlag == (UCHAR)1)
	{
		int nRecv2 = Receive(szBuffer, tmp.strlen * sizeof(TCHAR));
		m_Listen.SendMessageAll((TCHAR*)&tmp, nRecv);
		m_Listen.SendMessageAll(szBuffer, nRecv2);
	}
	else
	{
		//new, delete, modify
		m_Listen.SendMessageAll((TCHAR*)&tmp, nRecv);
	}
	CSocket::OnReceive(nErrorCode);
}
