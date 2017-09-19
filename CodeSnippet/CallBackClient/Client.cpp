#include "Client.h"
#include <iostream>

using namespace std;

Client::Client(void)
{
}


Client::~Client(void)
{
}

void Client::Call()
{
	cout << "Call in Client" << endl;
	if(nullptr != _action)
	{
		cout << "Call Action as call back" << endl;
		_action("message");
	}
}

void Client::SetCallBack(Action action)
{
	_action = action;
}
