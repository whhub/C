#pragma once

#ifdef BUILD_CALLBACKCLIENT_LIB
#define CallBackClient_Export __declspec (dllexport)
#else //!defined(MCSF_BUILD_FILMING_DB_LIB)
#define CallBackClient_Export __declspec (dllimport)
#endif

#include <boost/bind.hpp>   
#include <boost/function.hpp>  

using namespace std;

typedef boost::function<void(const string&)> Action;

class CallBackClient_Export Client
{
public:
	Client(void);
	~Client(void);
	void Call();
	void SetCallBack(Action action);
private:
	Action _action;
};

