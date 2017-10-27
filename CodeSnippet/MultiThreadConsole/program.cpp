#include <iostream>

#include <boost/thread/thread.hpp>

using namespace std;

void thread_work()
{
	cout << "Hello thread" << endl;
}

boost::mutex io_mutex;

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

int main()
{
	boost::thread thrd(thread_work);
	boost::thread thrd1(Count(1));
	boost::thread thrd2(Count(2));

	thrd.join();
	thrd1.join();
	thrd2.join();

	cout << "Press Any key to exit" << endl;
	cin.get();
	return 0;
}
