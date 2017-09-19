#include "Host.h"


Host::Host(void)
{
}


Host::~Host(void)
{
}

void Host::CallBack(const string &message)
{
	cout << "Host Received Message [" << message.c_str() << "]" << endl;
}
