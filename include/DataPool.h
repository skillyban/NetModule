#pragma once

class CBaseObject;

class CDataPool
{
public:
	CDataPool();
	virtual ~CDataPool();

	virtual void CreateDataPool(CBaseObject* pObject);
	virtual CBaseObject* GetNewObject();
	virtual void SetActiveObject(CBaseObject* pObject);
	virtual void CloseObject(CBaseObject* pObject);

	void ResetDataPool();
	
	void GetListReadyObject(VECTOROBJECT &listObject);
	void GetListAliveObject(VECTOROBJECT &listObject);

	DWORD PoolObjectCount();
	DWORD ReadyObjectCount();
	DWORD AliveObjectCount();
	DWORD DeadObjectCount();

	void SetReUseSize(WORD wSize);
	WORD GetReUseSize();
	void SetReadyFlag();
	void Lock();
	void UnLock();

	CBaseObject *GetObject(size_t i)
	{
		if(m_listAliveObject.empty())
			return NULL;

		if(i>=m_listAliveObject.size())
		{
			return NULL;
		}
		return m_listAliveObject[i];
	}

private:
	CDataPool(const CDataPool&);
	CDataPool& operator=(const CDataPool&);

private:
	CRITICAL_SECTION m_cs;
	QUEOBJECT m_listPoolObject;
	VECTOROBJECT m_listReadyObject;
	VECTOROBJECT m_listAliveObject;
	QUEOBJECT m_listDeadObject;
	WORD m_wReUseSize;
	bool m_flagReady;
};