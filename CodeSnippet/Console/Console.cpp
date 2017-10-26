// Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Host.h"
#include "Client.h"


void TestCallBack()
{
	auto host = new Host();

	auto client = new Client();
	client->SetCallBack(boost::bind(&Host::CallBack, host, _1));

	client->Call();
}

int _tmain(int argc, _TCHAR* argv[])
{
	TestCallBack();



	return 0;
}

