#pragma once

class CBaseObject
{
public:
	CBaseObject();
	virtual ~CBaseObject();
	virtual void ReUse();
};

typedef vector<CBaseObject *> VECTOROBJECT;
typedef list<CBaseObject *> LISTOBJECT;
typedef deque<CBaseObject *> QUEOBJECT;
typedef map<BYTE,CBaseObject *> MAPOBJECT;

