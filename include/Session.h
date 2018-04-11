#pragma once

class CRecvOverlappedEx;
class CSendOverlappedEx;
class CStatics;

#include "BaseObject.h"

class CSession : public CBaseObject
{
public:
	CSession();
	virtual ~CSession();

	virtual void ReUse();
//	virtual void SetIpAddr();

	void SetSocket(SOCKET sock);
	SOCKET GetSocket() const;
	void CloseSocket();
	bool SetSocketFlag();
	bool CheckSocketFlag();

	void InitOverlapped();
//	DWORD Connect2Svr(HANDLE hIOCPClient,DWORD dwCompKey,LPCTSTR lpszSvrAddr,DWORD dwPort);
	BOOL WaitForNewConnection(SOCKET sockListen);
	HANDLE CreateIOCPSession(HANDLE hClientIOCP,DWORD dwComKey);
	BOOL WaitForMessage();
	void Dispatch(const WORD wMsgSize);
	void Say(const CMsg& msg);
	WORD CheckMessage ();
	void IncreaseReadSize(const DWORD dwIoSize);
	void DecreaseReadSize(const DWORD dwMsgSize);

	void InitMsg();
	CMsg& GetMsg();
	bool SetUseFlag();
	bool CheckUseFlag();
	void RecordTick();
	DWORD GetCurrentTick() { return m_dwCurrentTick; }

	void StartStatics();
	void EndStatics();
	CStatics* GetStatics() { return m_pStatics;}
	void Lock();
	void UnLock();

	const char *GetPeerAddress();

private:
	CSession(const CSession&);
	CSession& operator=(const CSession&);

private:
	CSendOverlappedEx* m_povSend;
	CRecvOverlappedEx* m_povRecv;

	CMsg m_msg;
	LPBYTE m_pBuf;	// m_msg.m_buf 이다.
	DWORD m_dwRead;	// Read 사이즈

	DWORD m_dwCurrentTick;
	CRITICAL_SECTION m_cs;
	bool m_flagSocket;
	bool m_flagUse;

	CStatics *m_pStatics;
protected:
	SOCKET m_sock;
	SOCKADDR_IN m_addrClient;
};
