#pragma once

#define IP_ADDRESS_LENGTH			15
#define SERVERNAME_LENGTH			50
#define MAX_DOMAIN_NAME_LENGTH		512

#define MAX_NUM_THREAD				128
#define MIN_NUM_THREAD				4
#define THREAD_PER_PROCESSOR		2

#define COMPKEY_ACCEPT				11
#define COMPKEY_CLOSE				12
#define COMPKEY_STOP				13
#define COMPKEY_CLIENT				14
#define COMPKEY_LOGOUT				15
#define COMPKEY_EVENTTIME			16
#define COMPKEY_TIMER				17

#define Random(Num) (int)(((long)rand() * (Num)) / (RAND_MAX + 1))
#define Randomize(Num) srand((unsigned)time(NULL) + (Num))

#define SIXTYFOUR_K				32768 //64*1024
#define FOUR_K					4*1024

void LogEvent(BOOL fError, LPCTSTR pFormat, ...);