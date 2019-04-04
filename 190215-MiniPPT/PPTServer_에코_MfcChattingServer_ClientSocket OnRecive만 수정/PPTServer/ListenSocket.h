#pragma once

// CListenSocket command target

class CListenSocket : public CAsyncSocket
{
public:
	CListenSocket();
	virtual ~CListenSocket();

	CPtrList m_listClient;
	virtual void OnAccept(int nErrorCode);
	void CloseClient(CSocket* pClient);
	void SendMessageAll(TCHAR* pszMessage, int nSize);
	void CloseAll();
};


