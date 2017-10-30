#pragma once

#include <iostream>
#include <boost/thread/mutex.hpp>
#include <boost/thread/tss.hpp>
#include "mutex.h"

boost::thread_specific_ptr<int> ptr;

struct Count
{
	Count(int id) : id(id) {}

	void operator()()
	{
		if(0 == ptr.get()) {ptr.reset(new int(0));}

		for (int i=0; i<10; i++)
		{
			(*ptr)++;

			boost::mutex::scoped_lock lock(io_mutex);

			std::cout << id << ": " << *ptr << std::endl;
		}
	}

	int id;
};
