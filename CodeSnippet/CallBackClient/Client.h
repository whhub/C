#pragma once

#ifdef BUILD_CALLBACKCLIENT_LIB
#define CallBackClient_Export __declspec (dllexport)
#else //!defined(MCSF_BUILD_FILMING_DB_LIB)
#define CallBackClient_Export __declspec (dllimport)
#endif

class CallBackClient_Export Client
{
public:
	Client(void);
	~Client(void);
	void Call();
};

