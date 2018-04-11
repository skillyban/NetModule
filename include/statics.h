#pragma once

class CHandlerStatics
{
public:
	CHandlerStatics();
	CHandlerStatics(WORD wProtocolID);
	~CHandlerStatics();

	void Clear();
	WORD GetProtocolID();
	void UsingNow();
	DWORD GetCount();
	DWORD GetDiffTick();
private:
	WORD m_wProtocolID;

	DWORD m_dwCount;
	DWORD m_dwLastTick;
	DWORD m_dwCurTick;
};

typedef map<WORD,CHandlerStatics*> MAPHANDLER;

class CStatics
{
public:
	CStatics();
	~CStatics();

	void Clear();
	CHandlerStatics* AddHandler(WORD wProtocolID);
	CHandlerStatics* FindHandler(WORD wProtocolID);
	void HandlerUsingNow(WORD wProtocolID,DWORD dwSize,bool fInPutFlag = true);
	void SetType(BYTE bType) { m_bType = bType;}
	BYTE GetType() { return m_bType;}
	void GetInOutPutData(DWORD &dwInPutData,DWORD &dwOutPutData);
private:
	MAPHANDLER m_mapHandler;
	BYTE	m_bType;
	DWORD	m_dwInPutSize;
	DWORD	m_dwOutPutSize;
	DWORD	m_dwPreInPutSize;
	DWORD	m_dwPreOutPutSize;
};
