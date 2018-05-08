#pragma once

#define SIXTYFOUR_K				32768 //64*1024
#define FOUR_K					4*1024

class CEventSession
{
public:
	CEventSession();
	virtual ~CEventSession();
	virtual void ReUse();
	void SetSocket(SOCKET sock) { m_hSocket = sock;}
	SOCKET GetSocket() { return m_hSocket;}
	void CloseSocket();
	bool SetSocketFlag();
	bool CheckSocketFlag();

	DWORD Connect2Svr(const char *lpszSvrAddr,DWORD dwPort,bool flagIp = true);
	bool WaitForMessage();
	void Dispatch(WORD wMsgSize);
	WORD CheckMessage();
	void IncreaseReadSize(DWORD dwIoSize);
	void DecreaseReadSize(DWORD dwIoSize);

	void Say(const CMsg& msg);

	void InitMsg();
	CMsg& GetMsg();

private:
	CEventSession(const CEventSession&);
	CEventSession& operator=(const CEventSession&);

protected:
	SOCKET m_hSocket;
	CMsg m_msg;
	LPBYTE m_pBuf;
	DWORD m_dwRead;
	bool m_flagSocket;
};
