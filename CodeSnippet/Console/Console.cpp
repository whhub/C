// Console.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Host.h"


int _tmain(int argc, _TCHAR* argv[])
{
	auto host = new Host();
	host->CallBack();
	return 0;
}

