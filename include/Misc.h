#pragma once

class CMisc
{
public:
	CMisc(void) {};
	~CMisc(void) {};
};

bool IsExistingFile(const TCHAR *szFilePath);
bool IsExistingDirectory(const TCHAR *szFilePath);
bool GetFileSize ( const TCHAR *szFilePath, unsigned long *lpSize );