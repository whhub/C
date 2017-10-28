#pragma once

#include <iostream>
#include <boost/thread/mutex.hpp>
#include "mutex.h"

struct Count
{
	Count(int id) : id(id) {}

	void operator()()
	{
		for (int i=0; i<10; i++)
		{
			boost::mutex::scoped_lock lock(io_mutex);

			std::cout << id << ": " << i << std::endl;
		}
	}

	int id;
};
