#include <iostream>

#include <boost/thread/thread.hpp>
#include <boost/thread/condition.hpp>

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

const int BUF_SIZE = 10;
const int ITERS = 100;

class buffer
{
public:
	typedef boost::mutex::scoped_lock scoped_lock;

	buffer() : _uP(0), _uC(0), _uFull(0) {}

	void put(int m)
	{
		scoped_lock lock(_mutex);

		if(BUF_SIZE == _uFull)
		{
			{
				scoped_lock io_lock(io_mutex);
				cout << "Buffer is full. Waiting..." << endl;
			}
			while (BUF_SIZE == _uFull)
			{
				_conditon.wait(lock);
			}
		}

		_buf[_uP] = m;
		_uP = (_uP+1) % BUF_SIZE;
		++ _uFull;
		_conditon.notify_one();
	}

	int get()
	{
		scoped_lock lock(_mutex);

		if(0==_uFull)
		{
			{
				scoped_lock io_lock(io_mutex);
				cout << "Buffer is empty. Waiting..." << endl;
			}
			while (0==_uFull)
			{
				_conditon.wait(lock);
			}
		}

		int i = _buf[_uC];
		_uC = (_uC+1) % BUF_SIZE;
		--_uFull;
		_conditon.notify_one();

		return i;	
	}

private:
	boost::mutex _mutex;
	boost::condition _conditon;
	unsigned int _uP, _uC, _uFull;
	int _buf[BUF_SIZE];
};


buffer buf;

void writer()
{
	for (int n=0; n<ITERS; ++n)
	{
		{
			boost::mutex::scoped_lock lock(io_mutex);
			cout << "sending: " << n << endl;
		}
		buf.put(n);
	}
}


void reader()
{
	for (int x=0; x<ITERS; ++x)
	{
		int n = buf.get();
		{
			boost::mutex::scoped_lock lock(io_mutex);
			cout << "received: " << n << endl;
		}
	}
}

void TestProducerAndConsumer()
{
	boost::thread thrd1(&reader);
	boost::thread thrd2(&writer);
	thrd1.join();
	thrd2.join();
}

int main()
{
	TestMultiThread();
	//TestProducerAndConsumer();

	cout << "Press Any key to exit" << endl;
	cin.get();
	return 0;
}


//ref: http://www.cppblog.com/shaker/archive/2011/11/30/33583.html
//ref: http://blog.csdn.net/iamnieo/article/details/2908621
