#pragma once

#ifdef BUILD_CALLBACKHOST_LIB
#define CallBackHost_Export __declspec (dllexport)
#else //!defined(MCSF_BUILD_FILMING_DB_LIB)
#define CallBackHost_Export __declspec (dllimport)
#endif

#include <iostream>
using namespace std;

class CallBackHost_Export Host
{
public:
	Host(void);
	~Host(void);
	void CallBack(const string & message);
};

