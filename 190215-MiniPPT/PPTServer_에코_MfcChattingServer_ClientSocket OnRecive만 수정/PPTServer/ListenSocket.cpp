// ListenSocket.cpp : implementation file
//

#include "stdafx.h"
#include "PPTServer.h"
#include "ListenSocket.h"
#include "ClientSocket.h"
#include "PPTHeader.h"


// CListenSocket

CListenSocket::CListenSocket()
{
}

CListenSocket::~CListenSocket()
{
}


// CListenSocket member functions


void CListenSocket::OnAccept(int nErrorCode)
{
	// TODO: Add your specialized code here and/or call the base class
	CSocket *pNewClient = new CClientSocket(*this);
	if(Accept(*pNewClient))
		m_listClient.AddTail(pNewClient);
	else
	{
		delete pNewClient;
	}

	CAsyncSocket::OnAccept(nErrorCode);
}


void CListenSocket::CloseClient(CSocket* pClient)
{
	POSITION pos = m_listClient.Find(pClient);
	if(pos != NULL)
		m_listClient.RemoveAt(pos);

	pClient->ShutDown();
	pClient->Close();
	delete pClient;
}


void CListenSocket::SendMessageAll(TCHAR* pszMessage, int nSize)
{
	POSITION pos = m_listClient.GetHeadPosition();
	CSocket *pClient = NULL;

	while (pos != NULL)
	{
		pClient = (CSocket*) m_listClient.GetNext(pos);
		if(pClient != NULL)
			pClient->Send(pszMessage, nSize);
	}
}


void CListenSocket::CloseAll()
{
	ShutDown();
	Close();

	CSocket *pClient = NULL;
	POSITION pos = m_listClient.GetHeadPosition();
	while (pos != NULL)
	{
		pClient = (CSocket*)m_listClient.GetNext(pos);
		if (pClient != NULL)
		{
			pClient->ShutDown();
			pClient->Close();
			delete pClient;
		}
	}

	m_listClient.RemoveAll();
}
