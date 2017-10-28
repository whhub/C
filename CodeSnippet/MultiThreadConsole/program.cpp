#include <iostream>

#include <boost/thread/thread.hpp>

#include "Count.h"
#include "counting.h"

using namespace std;

void thread_work()
{
	cout << "Hello thread" << endl;
}








void TestMultiThread()
{
	boost::thread thrd(thread_work);
	boost::thread thrd1(Count(1));
	boost::thread thrd2(Count(2));
	boost::thread thrd3(boost::bind(&counting, 3));
	boost::thread thrd4(boost::bind(&counting, 4));

	thrd.join();
	thrd1.join();
	thrd2.join();
	thrd3.join();
	thrd4.join();
}

int main()
{
	TestMultiThread();

	cout << "Press Any key to exit" << endl;
	cin.get();
	return 0;
}


//ref: http://www.cppblog.com/shaker/archive/2011/11/30/33583.html
