#pragma once

class CSession;
class CDataPool;
class CThread;
class CThreadMgr;

class IDBConnection;

class CServerModule
{
public:
	CServerModule();
	virtual ~CServerModule();
	virtual DWORD OnStart();
	virtual void OnStop();
	virtual DWORD OnPause();
	virtual DWORD OnContinue();
protected: 

	virtual DWORD ControlThread() = 0;
	virtual DWORD ClientThread() = 0;
	virtual DWORD CheckerThread() = 0;

	virtual DWORD InitializeIOCP();
	virtual DWORD InitializeThreads();
	virtual bool ResumeThreads();
	virtual DWORD LoadConfigurations();
	virtual DWORD GetRegistryInfo();
	virtual DWORD InitializeData();
	virtual void ReleaseData();

	virtual void OnComKeyAccept(CSession *pSession);
	virtual void OnComKeyClient(CSession *pSession,DWORD dwIoSize,IDBConnection* pDB,IDBConnection* pLogDB);
	virtual DWORD OnReceive(CSession *pSession,IDBConnection* pDB,IDBConnection* pLogDB) = 0;
	virtual void OnOpenSession(CSession *pSession);
	virtual void OnCloseSession(CSession* pSession, IDBConnection* pDB, IDBConnection* pLogDB);

	virtual IDBConnection *CreateDBConnection() = 0;

	DWORD InitListenSock(DWORD dwPort);
	CSession* CreateNewSession();
	BOOL WaitForNewConnection();
	BOOL DispatchSession(CSession* pSession,DWORD dwIoSize,IDBConnection* pDB,IDBConnection* pLogDB);
	BOOL WaitForMessage(CSession* pSession);

	void SetServiceName(LPCTSTR szServiceName);
	DWORD OpenServerDatabase();
	void CloseServerDatabase();
	LPCTSTR GetLocalIP();

public:
	void CloseSession(CSession* pSession);

	const char *GetDBServerName()
	{
		return m_s_DBServerName.c_str();
	}
	const char *GetDBServerDriver()
	{
		return m_s_DBServerDriver.c_str();
	}

	const char *GetDBServerServer()
	{
		return m_s_DBServerServer.c_str();
	}
	const char *GetDBServerDatabase()
	{
		return m_s_DBServerDatabase.c_str();
	}
	const char *GetDBServerUser()
	{
		return m_s_DBServerUser.c_str();
	}
	const char *GetDBServerPassword()
	{
		return m_s_DBServerPassword.c_str();
	}

	const char *GetDBServerLogServer()
	{
		return m_s_DBServerLogServer.c_str();
	}
	const char *GetDBServerLogDatabase()
	{
		return m_s_DBServerLogDatabase.c_str();
	}
	const char *GetDBServerLogUser()
	{
		return m_s_DBServerLogUser.c_str();
	}
	const char *GetDBServerLogPassword()
	{
		return m_s_DBServerLogPassword.c_str();
	}

private:
	static DWORD WINAPI _ControlThread( LPVOID lpParam);
	static DWORD WINAPI _ClientThread( LPVOID lpParam);
	static DWORD WINAPI _CheckerThread( LPVOID lpParam);

private:
	CServerModule(const CServerModule&);
	CServerModule& operator=(const CServerModule&);

protected:

	char	m_szServerName[SERVERNAME_LENGTH+1];
	char	m_szLocalAddr[IP_ADDRESS_LENGTH+1];
	char	m_szDomainName[MAX_DOMAIN_NAME_LENGTH+1];
	int		m_iLocalPort;

	string m_s_ServiceName;

	string m_s_DBServerName;
	string m_s_DBServerDriver;

	string m_s_DBServerServer;
	string m_s_DBServerDatabase;
	string m_s_DBServerUser;
	string m_s_DBServerPassword;

	string m_s_DBServerLogServer;
	string m_s_DBServerLogDatabase;
	string m_s_DBServerLogUser;
	string m_s_DBServerLogPassword;

	int m_iNumWorkerThread;
	int	m_iNumClient;

	HANDLE m_hIOCPControl;
	HANDLE m_hIOCPClient;
	HANDLE m_hIOCPChecker;

	CThreadMgr* m_pThreadMgr;
	IDBConnection* m_pDb;
	IDBConnection* m_pLogDb;

	SOCKET m_sockListen;
	CSession* m_pAccept;

	BOOL	m_bFull;
	CRITICAL_SECTION m_csFull;

public:
	CDataPool* m_pSessionDataPool;

};