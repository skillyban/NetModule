#pragma once

#define MSG_DEFAULT_SIZE	65534// 3584
#define MSG_HEADER_SIZE		6
#define MSG_INVALID_MSG		65535

class CMsg  
{
protected:
	BYTE	m_buf[MSG_DEFAULT_SIZE];
	LPBYTE	m_pHead;	
	LPBYTE	m_pData;	
	WORD	m_nRdOff;
	WORD	m_nWrOff;
//	BYTE	m_BackBuf[512];

public:
	void ReadData (LPVOID pData, int n);
	void WriteData (const LPVOID pData, int n);

	CMsg();
	CMsg(const CMsg& msg);
	CMsg(const LPVOID pBuf);

	CMsg& ID( WORD id );
	WORD  ID() const;

	CMsg&	SubID( WORD id );
	WORD	SubID() const;

	LPVOID GetBuf () const;
//	void SetBuf (LPVOID pBuf);
	WORD GetSize () const;
	BOOL IsReadAll () const;
	void Copy (const LPVOID pBuf);
	void Clear ();

	void ReadDataString (LPVOID pData, int n);
	void WriteDataString (const LPVOID pData, int n);

	void ReadData2 (LPVOID pData);
	void ReadDataUnicode (const LPVOID pData);
	void WriteData2 (const LPVOID pData, int n);
	void WriteDataUnicode (const LPVOID pData, int n);

// Archive Operators
	CMsg&		operator<<( const char		arg );
	CMsg&		operator<<( const short		arg );
	CMsg&		operator<<( const int		arg );
	CMsg&		operator<<( const BYTE		arg );
	CMsg&		operator<<( const WORD		arg );
	CMsg&		operator<<( const DWORD		arg );
	CMsg&		operator<<( const unsigned int		arg );
	CMsg&		operator<<( const char *arg );
	CMsg&		operator<<( const CMsg *arg );
	CMsg&		operator<<( const double	arg );
	CMsg&		operator<<( const float	arg );
	CMsg&		operator<<( const ULONGLONG	arg );
	CMsg&		operator<<( const wchar_t *arg );
	CMsg&		operator<<( const __int64	arg );

	CMsg&		operator>>( char&		arg );	
	CMsg&		operator>>( short&		arg );	
	CMsg&		operator>>( int&		arg );	
	CMsg&		operator>>( BYTE&		arg );
	CMsg&		operator>>( WORD&		arg );	
	CMsg&		operator>>( DWORD&		arg );
	CMsg&		operator>>( unsigned int&		arg );
//	CMsg&		operator>>( CString&	arg );	
	CMsg&		operator>>( char*		arg );
	CMsg&		operator=( const CMsg&		msg );	
	CMsg&		operator>>( double&		arg );
	CMsg&		operator>>( float&		arg );
	CMsg&		operator>>( ULONGLONG&	arg );
	CMsg&		operator>>( wchar_t*	arg );
	CMsg&		operator>>( __int64&	arg );
};

