#pragma once

#include "DBInterface.h"

extern LPCTSTR g_szSPCmd[];

#define MAX_CMD_LENGTH		1024
#define MAX_COL_NUM			256
#define MAX_CMD_NUM			256

#define SQLOK(rc)			SQL_SUCCEEDED(rc)
#define SQLFAIL(rc)			!SQLOK(rc)
//#define SQLFAIL(n)	(n != SQL_SUCCESS && n != SQL_SUCCESS_WITH_INFO && n != SQL_NO_DATA)

#define DBPARAMIO_INPUT		0x01
#define DBPARAMIO_OUTPUT	0x02
#define DBPARAMIO_INOUT		0x03

#define TYPE_BYTE			0x00
#define TYPE_CHAR			0x01
#define TYPE_USHORT			0x02
#define TYPE_SHORT			0x03
#define TYPE_ULONG			0x04
#define TYPE_LONG			0x05
#define TYPE_FLOAT			0x06
#define TYPE_STRING			0x07
#define TYPE_TIME			0x08

#define BEGIN_PARAM_MAP()								\
	virtual void _BindParameter ()						\
	{													\
		if (m_hstmt == SQL_NULL_HANDLE)					\
			return;										\
		m_wParamCount = 1;

#define END_PARAM_MAP()									\
	}

#define BEGIN_COL_MAP()								\
	virtual void _GetData ()							\
	{													\
		if (m_hstmt == SQL_NULL_HANDLE)					\
			return;										\

#define END_COL_MAP()									\
	}


#define COLUMN_ENTRY(n,v)								\
		GetData (n,v);

#define COLUMN_ENTRY_STRING(n,v,s)						\
		GetData (n,v,s);

#define PARAM_ENTRY(n,v)								\
		BindParam (n,v);

#define PARAM_ENTRY_STRING(n,v,s)						\
		BindParam (n,v,s);



#define DEFINE_COMMAND(a)								\
	virtual void _SetCommand ()	{ m_nCmd = a; }

// global function

#define TABLE	0
#define SP		1

// revision of GetErrorString(CString& strError) of (CSPBase & CTBLBase)
BOOL _SetDBError( SQLRETURN rc, SQLHSTMT hstmt, int nType, int nCommand, BOOL bFatal = FALSE);

class CDBConnection : public IDBConnection
{
protected:
	SQLHSTMT	m_hstmtSP[MAX_CMD_NUM];
	SQLHDBC		m_hdbc;
	SQLHENV	    m_henv;

	int			m_nNumSPCmd;

	BOOL        m_bInit;

public:
	CDBConnection();
	virtual ~CDBConnection();

	virtual BOOL OpenEnvironment();
	virtual void CloseEnvironment();

	virtual BOOL Connect(LPCTSTR lpszDriver, LPCTSTR	lpszServer, LPCTSTR lpszDatabase, LPCTSTR lpszUserID, LPCTSTR lpszPasswd);

	virtual void Disconnect();

	SQLHSTMT GetSPCommand( int nCmd);

	// allocate & prepare statement for Stored procedure & tablular command
	BOOL AllocStmt(int nType,int nCmdID); // be sure to be inline.

	BOOL BeginTrans();
	void EndTrans( BOOL bCommit);

	SQLHDBC GetHDBC() { return m_hdbc; }

private:
	CDBConnection(const CDBConnection&);
	CDBConnection& operator=(const CDBConnection&);
};

class CSPBase
{
protected:
	DWORD		m_dwDataLen[MAX_COL_NUM];

	WORD		m_wParamCount;
	int			m_nCmd;
	SQLHSTMT	m_hstmt;

	SQLCHAR		m_szErrMsg[1024];

	SQLSMALLINT GetInOutType (BYTE bInOut);
	void BindParam (BYTE bInOut, BYTE& bValue);
	void BindParam (BYTE bInOut, USHORT& usValue);
	void BindParam (BYTE bInOut, SHORT& sValue);
	void BindParam (BYTE bInOut, ULONG& ulValue);
	void BindParam (BYTE bInOut, __int64& ddwValue);
	void BindParam (BYTE bInOut, LONG& lValue);
	void BindParam (BYTE bInOut, INT& nValue);
	void BindParam (BYTE bInOut, float& rValue);
	void BindParam (BYTE bInOut, double& rValue);
	void BindParam (BYTE bInOut, ULONGLONG& ullValue);
	void BindParam (BYTE bInOut, char szValue[], int nSize);
	void BindParam (BYTE bInOut, BYTE szValue[], int nSize);
	void BindParam (BYTE bInOut, wchar_t szValue[], int nSize);
	void BindParam (BYTE bInOut, DBTIMESTAMP& tmValue);

	void GetData (WORD wCol, BYTE& bValue);
	void GetData (WORD wCol, USHORT& usValue);
	void GetData (WORD wCol, SHORT& sValue);
	void GetData (WORD wCol, ULONG& ulValue);
	void GetData (WORD wCol, LONG& lValue);
	void GetData (WORD wCol, INT& nValue);
	void GetData (WORD wCol, float& rValue);
	void GetData (WORD wCol, double& rValue);
	void GetData (WORD wCol, char szValue[], int nSize);
	void GetData (WORD wCol, BYTE szValue[], int nSize);
	void GetData (WORD wCol, wchar_t szValue[], int nSize);
	void GetData (WORD wCol, DBTIMESTAMP& tmValue);
	void GetData (WORD wCol, __int64& rValue);
	void GetData (WORD wCol, ULONGLONG& ullValue);

	virtual void _BindParameter () {};
	virtual void _BindColumn () {};
	virtual void _GetData () {};
	virtual void _SetCommand() { m_nCmd = -1; };

private:
	CSPBase(const CSPBase&);
	CSPBase& operator=(const CSPBase&);

public:

	CSPBase();
	virtual ~CSPBase();

	BOOL Open( IDBConnection* pDB );
	BOOL SetDBError( SQLRETURN rc)
	{
//		return FALSE;
		return _SetDBError( rc, m_hstmt, SP, m_nCmd);
	};

	void Cleanup(void);
	BOOL Fetch();
	BOOL GetMoreResult();
	BOOL IsFieldNull( WORD wCol);
	int GetRowCount();
};

