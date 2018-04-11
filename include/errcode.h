#pragma once

#define ERR_LOADCONFIG_OPENREGKEY				0x01010000
#define ERR_LOADCONFIG_READSERVERID				0x01010001
#define ERR_LOADCONFIG_READSERVERADDR			0x01010002
#define ERR_LOADCONFIG_READSERVERPORT			0x01010003
#define ERR_LOADCONFIG_READMSGSVRADDR			0x01010004
#define ERR_LOADCONFIG_READDBPASSWD				0x01010005
#define ERR_LOADCONFIG_READSECTIONID			0x01010006
#define ERR_LOADCONFIG_READFILEPATH				0x01010007
#define ERR_LOADCONFIG_READLOCALADDR			0x01010008
#define ERR_LOADCONFIG_READNUMWORKERTHREAD		0x01010009
#define ERR_LOADCONFIG_READLOGINSERVERADDR		0x0101000A
#define ERR_LOADCONFIG_READLOGINSERVERPORT		0x0101000B
#define ERR_LOADCONFIG_READGAMESERVERNAME		0x0101000C
#define ERR_LOADCONFIG_READGAMESERVERADDR		0x0101000D
#define ERR_LOADCONFIG_READGAMESERVERPORT		0x0101000E
#define ERR_LOADCONFIG_READDBSERVERNAME			0x0101000F
#define ERR_LOADCONFIG_READDBSERVERUSER			0x01010010
#define ERR_LOADCONFIG_READDBSERVERPASSWORD		0x01010011
#define ERR_LOADCONFIG_READDBSERVERDRIVER		0x01010012
#define ERR_LOADCONFIG_READDBSERVERSERVER		0x01010013
#define ERR_LOADCONFIG_READDBSERVERDATABASE		0x01010014
#define ERR_LOADCONFIG_READNUMCLIENT			0x01010015
#define ERR_LOADCONFIG_READCHATSERVERNAME		0x01010016
#define ERR_LOADCONFIG_READCHATSERVERADDR		0x01010017
#define ERR_LOADCONFIG_READCHATSERVERPORT		0x01010018
#define ERR_LOADCONFIG_READGAMESERVERCHANNEL	0x01010019

#define ERR_INITNET_CREATELISTENSOCKET			0x01020000
#define ERR_INITNET_LISTENSOCKETBIND			0x01020001
#define ERR_INITNET_SOCKETLISTEN				0x01020002
#define ERR_INITNET_WINSOCKINITIALIZE			0x01020003
#define ERR_INITNET_CREATEUDPSOCKET				0x01020004
#define ERR_INITNET_BINDUDPSOCKET				0x01020005

#define ERR_INITTHREAD_CREATEIOCPCONTROL		0x01030000
#define ERR_INITTHREAD_CREATEIOCPCLIENT			0x01030001
#define ERR_INITTHREAD_CREATEIOCPCHECKER		0x01030002
#define ERR_INITTHREAD_CREATEIOCPNPC			0x01030003
#define ERR_INITTHREAD_CREATECLIENTTHREAD		0x01030004
#define ERR_INITTHREAD_CREATECONTROLTHREAD		0x01030005
#define ERR_INITTHREAD_CREATECHECKERTHREAD		0x01030006
#define ERR_INITTHREAD_CREATENPCTHREAD			0x01030007
#define ERR_INITTHREAD_TLSALLOC		            0x01030008

#define ERR_INITTHREAD_CREATEUSERTHREAD			0x01030009


#define ERR_START_RESUMETHREAD					0x01040000
#define ERR_START_WAITFORCONNECT				0x01040001
#define ERR_START_ATTACHLISTENSOCKET			0x01040002
#define ERR_START_INITBATTLESVR					0x01040003
#define ERR_START_INITMKSVR						0x01040004
#define ERR_START_INITECONOMICSVR				0x01040005
#define ERR_START_CREATESEMAPHORE				0x01040006
#define ERR_START_CREATEEVENT					0x01040007

/*
#define ERR_MSGSVR_SOCKETCREATE					0x01050001
#define ERR_MSGSVR_CONNECTFAIL					0x01050002
#define ERR_MSGSVR_CREATEIOCPCONTROL			0x01050003
#define ERR_MSGSVR_WAITMESSAGE					0x01050004
#define ERR_MSGSVR_CREATELOCATORSOCKET			0x01050005
#define ERR_MSGSVR_CONNECTLOCATOR				0x01050006
#define ERR_MSGSVR_CREATELOCALSOCKET			0x01050007
#define ERR_MSGSVR_BINDLOCALSOCKET				0x01050008
#define ERR_MSGSVR_BINDLOCATORSOCKET			0x01050009
#define ERR_MSGSVR_SENDIDENT					0x0105000A
#define ERR_MSGSVR_ATTACHLOCATORSOCKET			0x0105000B
#define ERR_MSGSVR_ATTACHLOCALSOCKET			0x0105000C
#define ERR_MSGSVR_RECVMESSAGE					0x0105000D
#define ERR_MSGSVR_RECVLOCATORMSG				0x0105000E
#define ERR_MSGSVR_IOSIZENULL					0x0105000F
#define ERR_MSGSVR_OVERLAPPEDNULL				0x01050010
#define ERR_MSGSVR_PROCESSMSG					0x01050011
#define ERR_MSGSVR_INVALIDLOCATORMSG			0x01050012
#define ERR_MSGSVR_PROCESSLOCATORMSG			0x01050013
#define ERR_MSGSVR_NOTINITIALIZE				0x01050014
#define ERR_MSGSVR_ATTACHLISTENSOCKET			0x01050015
#define ERR_MSGSVR_WAITFORNEWSVRCONNECTION		0x01050016
#define ERR_MSGSVR_WAITFORSERVERMESSAGE			0x01050017
#define ERR_MSGSVR_INVALIDSERVERSESSION			0x01050018
#define ERR_MSGSVR_INVALIDMSG					0x01050019
#define ERR_MSGSVR_ACCEPTNEWSVR					0x0105001A
#define ERR_MSGSVR_LISTENSOCKBIND				0x0105001B
#define ERR_MSGSVR_LISTEN						0x0105001C
#define ERR_MAPSVR_CREATELOCALSOCKET			0x0105001D
#define ERR_MAPSVR_CONNECTLOCATOR				0x0105001E
#define ERR_MAPSVR_ATTACHLOCALSOCKET			0x0105001F
*/
/*
#define ERR_CREATCOM_MANAGEOBJECT				0x01060001

#define ERR_INITMAP_INVALIDMAPITEM				0x01070001
#define ERR_INITMAP_OPENMAPFILEFAIL				0x01070002
#define ERR_INITMAP_INVALIDDIVNUM				0x01070003
#define ERR_INITMAP_INVALIDSECTION				0x01070004
#define ERR_INITMAP_LOADHEIGHTINFOFAIL			0x01070005
#define ERR_INITMAP_LOADPORTAL					0x01070006
#define ERR_INITMAP_LOADLAYER					0x01070007
*/
/*
#define ERR_INITMC_CREATEMCLEAF					0x01080001
#define ERR_INITMC_SETOPTMC						0x01080002
#define ERR_INITMC_BINDMCLEAF					0x01080003
#define ERR_INITMC_CREATEMCROOT					0x01080004
#define ERR_INITMC_CREATEIOCPCONTROL			0x01080005
#define ERR_INITMC_WAITMESSAGE					0x01080006
#define ERR_INITMC_CONNECTROOT					0x01080007
*/

#define ERR_OPENDB_ALLOCENVIRONMENTHANDLE		0x02010001
#define ERR_OPENDB_PREPARE						0x02010002
#define ERR_OPENDB_CONNECT						0x02010003
#define ERR_OPENDB_CLEAR						0x02010004

#define ERR_CLIENT_INVALIDPARAM					0x03010000
#define ERR_CLIENT_NOTCERTIFIED					0x03010001
#define ERR_CLIENT_INVALIDATTRIBUTE				0x03010002
#define ERR_CLIENT_INVALIDVERSION				0x03010003
#define ERR_CLIENT_SPEEDHACK					0x03010004

#define ERR_CLIENT_INVALIDMSG					0x04010000
#define ERR_CLIENT_NOTADMINISTRATOR				0x04010001
#define ERR_CLIENT_INVALIDDATASIZE				0x04010002
#define ERR_CLIENT_INVALIDDATA					0x04010003


#define ERR_SYSTEM_NOTPREPARED                  0x05010000