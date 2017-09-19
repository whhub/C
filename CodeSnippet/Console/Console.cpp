// Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Host.h"
#include "Client.h"


int _tmain(int argc, _TCHAR* argv[])
{
	auto host = new Host();
	host->CallBack();

	auto client = new Client();

	return 0;
}

