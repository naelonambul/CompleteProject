#pragma once

// CClientSocket command target
class CListenSocket;


class CClientSocket : public CSocket
{
public:
	CClientSocket(CListenSocket &sock);
	virtual ~CClientSocket();

	CListenSocket &m_Listen;
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
};


