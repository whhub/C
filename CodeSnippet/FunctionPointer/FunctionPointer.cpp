// FunctionPointer.cpp : Defines the entry point for the console application.


#include <iostream>
using namespace std;

typedef void (*NotifyResult)(bool bResult);

void Publish(bool bResult)
{
	cout << "Result : " << bResult << endl;
}

void GT(int a, int b, NotifyResult notifier)
{
	notifier(a>b);
}


int main()
{
	GT(3, 2, Publish);

	cout << "press any key to continue ." << endl;
	cin.get();

	return 0;
}

