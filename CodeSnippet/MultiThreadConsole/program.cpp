#include <iostream>

#include <boost/thread/thread.hpp>

using namespace std;

void thread_work()
{
	cout << "Hello thread" << endl;
}


int main()
{
	boost::thread thrd(thread_work);
	thrd.join();

	cout << "Press Any key to exit" << endl;
	cin.get();
	return 0;
}
