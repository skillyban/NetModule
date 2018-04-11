#pragma once

class IDBConnection
{
public:
	IDBConnection() {};
	virtual ~IDBConnection() {};

	virtual BOOL OpenEnvironment() = 0;
	virtual void CloseEnvironment() = 0;

	virtual BOOL Connect(LPCTSTR lpszDriver, LPCTSTR	lpszServer, LPCTSTR lpszDatabase, LPCTSTR lpszUserID, LPCTSTR lpszPasswd) = 0;

	virtual void Disconnect() = 0;

//	virtual SQLHSTMT GetTBLCommand( int nCmd) = 0;
	virtual SQLHSTMT GetSPCommand( int nCmd) = 0;

	virtual SQLHDBC GetHDBC() = 0;

};