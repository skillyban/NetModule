#pragma once


class CBaseObject;
//#include "Msg.h"
class CMsg;

#define MAX_SENDBUF_SIZE	768//4096
#define BUFMEMORY_SIZE	32768//48K

class COverlappedEx : public OVERLAPPED
{
public:
	COverlappedEx();
	virtual ~COverlappedEx();

	virtual void OnIoCompleted();
	virtual void ReUse(CBaseObject* pObject,SOCKET sock);

	void ClearOverlappedStruct();
	void SetObject(CBaseObject* pObject);
	CBaseObject* GetObject();
	void SetDelFlag();
	bool CheckDelFlag();

	void SetOverlappedType(bool bRecvFlag);
	bool GetOverlappedType();
private:
	COverlappedEx(const COverlappedEx&);
	COverlappedEx& operator=(const COverlappedEx&);

private:
	CBaseObject* m_pObject;
	bool m_flagDel;
	bool m_flagRecv;
};

class CRecvOverlappedEx : public COverlappedEx
{
public:
	CRecvOverlappedEx(CBaseObject* pObject);
	virtual ~CRecvOverlappedEx();

	virtual void OnIoCompleted();
	virtual void ReUse(CBaseObject* pObject,SOCKET sock);

};

class CSendOverlappedEx : public COverlappedEx
{
public:
	CSendOverlappedEx(CBaseObject* pObject,SOCKET sock,BYTE bSocketType=0);
	virtual ~CSendOverlappedEx();

	virtual void OnIoCompleted();
	virtual void ReUse(CBaseObject* pObject,SOCKET sock);
	
	bool MoveQueToSend();
	bool StoreQue(const CMsg& msg);

	bool SetUsingFlag(bool flagUsing);
	bool CheckUsingFlag();

	void Flush();
	void Send(const CMsg& msg);
//	void CloseSocket();
	void OnCloseSocket();
	void ClearSendBuffer();
	void ClearQueueBuffer();
	void Lock();
	void UnLock();
	void LockQueue();
	void UnLockQueue();

	char* GetMemory(WORD wSize);
	DWORD GetSendData() const;

private:
	CRITICAL_SECTION m_cs;
	CRITICAL_SECTION m_csQueue;
	SOCKET m_sock;

	bool m_flagUsing;

	WSABUF* m_pbufSend;
	WSABUF* m_pbufQueue;
	DWORD m_dwNumBufSend;
	DWORD m_dwNumBufQueue;
	
	WORD m_wBufferSize;
	DWORD m_dwMemorySize;
	
	char* m_pBuf;
	int	m_nUseCnt;

	DWORD m_dwSendData;
};

