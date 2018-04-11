#pragma once

class CThread
{
private:
	HANDLE m_hID;
	HANDLE m_hIOCP;
	DWORD m_dwHandleID;
	BYTE m_bType;

private:
	CThread(const CThread&);
	CThread& operator=(const CThread&);

public:
	CThread();
	~CThread();
	void Setup(HANDLE hID,HANDLE hIOCP,DWORD dwHandleID);
	void Stop();
	bool Resume();
	void Terminate();
	void SetType(BYTE bType);
	HANDLE GetHandle() const { return m_hID; }
};

typedef vector<CThread *> VECTORTHREAD;
class CThreadMgr
{
private:
	VECTORTHREAD m_listThread;

private:
	CThreadMgr(const CThreadMgr&);
	CThreadMgr& operator=(const CThreadMgr&);

public:
	CThreadMgr();
	~CThreadMgr();
	void Clear();
	CThread* CreateThreadClass(HANDLE hID,HANDLE hIOCP,DWORD dwHandleID);
	void Add(CThread *pThread);
	void Remove(CThread *pThread);
	void RemoveAllThread();
	bool ResumeAllThread();
};
