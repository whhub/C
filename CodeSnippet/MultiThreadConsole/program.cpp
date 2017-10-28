#include <iostream>

#include <boost/thread/thread.hpp>

#include "mutex.h"

using namespace std;

void thread_work()
{
	cout << "Hello thread" << endl;
}


struct Count
{
	Count(int id) : id(id) {}

	void operator()()
	{
		for (int i=0; i<10; i++)
		{
			boost::mutex::scoped_lock lock(io_mutex);

			cout << id << ": " << i << endl;
		}
	}

	int id;
};


void counting(int id)
{
	for (int i=0; i<5; ++i)
	{
		boost::mutex::scoped_lock lock(io_mutex);
		cout << id << ":" << i << endl;
	}
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
	//TestMultiThread();

	cout << "Press Any key to exit" << endl;
	cin.get();
	return 0;
}
