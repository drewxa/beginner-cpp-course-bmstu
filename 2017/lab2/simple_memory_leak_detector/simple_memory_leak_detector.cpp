#include "simple_memory_leak_detector.h"
#include <iostream>

const size_t OVERHEAD_SIZE = 10000;
void * GLOBAL_ARRAY[OVERHEAD_SIZE];

void * operator new(std::size_t n) throw(std::bad_alloc)
{
    // TODO: implement
}

void operator delete(void * p) throw()
{
	// TODO: implement
}

bool memoryLeakExist()
{
	// TODO: implement
}