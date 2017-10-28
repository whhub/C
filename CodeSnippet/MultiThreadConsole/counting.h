#pragma once
#include <iostream>
#include <boost/thread/mutex.hpp>
#include "mutex.h"

void counting(int id)
{
	for (int i=0; i<5; ++i)
	{
		boost::mutex::scoped_lock lock(io_mutex);
		std::cout << id << ":" << i << std::endl;
	}
}
