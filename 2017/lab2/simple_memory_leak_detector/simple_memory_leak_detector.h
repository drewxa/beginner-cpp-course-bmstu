#pragma once
#include <exception>

void * operator new(std::size_t n) throw(std::bad_alloc);

void operator delete(void * p) throw();

bool memoryLeakExist();