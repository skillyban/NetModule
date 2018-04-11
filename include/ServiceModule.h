#pragma once

class CServerModule;

void WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
void WINAPI ServiceHandler(DWORD dwControl);

class CServiceModule
{
public: 
	CServiceModule(LPCTSTR szServiceName = NULL);
	virtual ~CServiceModule();
	
	bool Install();
	void UnInstall();

	DWORD OnStart();
	void OnStop();
	DWORD OnPause();
	DWORD OnContinue();

	void Run();
	void UpdateServiceStatus(DWORD dwState);
	void SetSvrModule(CServerModule* pSvrModule);
	void SetServiceName(LPCTSTR szServiceName);
	LPCTSTR GetServiceName() { return (LPCTSTR)m_szServiceName;}
	CServerModule *GetServerModule()
	{
		return m_pSvrModule;
	}

private:
	CServiceModule(const CServiceModule&);
	CServiceModule& operator=(const CServiceModule&);

public:
	SERVICE_STATUS_HANDLE m_hService;
	SERVICE_STATUS m_Status;
private:
	char m_szServiceName[50];
	DWORD m_dwThreadID;
	CServerModule* m_pSvrModule;
};

