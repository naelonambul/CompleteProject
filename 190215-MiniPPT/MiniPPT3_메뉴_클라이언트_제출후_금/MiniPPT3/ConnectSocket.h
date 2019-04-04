#pragma once

// CConnectSocket command target

class CConnectSocket : public CSocket
{
public:
	CConnectSocket();
	virtual ~CConnectSocket();
	virtual void OnReceive(int nErrorCode);
};


