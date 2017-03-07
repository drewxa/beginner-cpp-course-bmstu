#include "TNotCopyable.h"
#include <iostream>
#include <time.h>

void gen(int i)
{
	if(i < 100)
		throw std::runtime_error("error");
}

int main()
{
	try
	{
		TNotCopyable obj;
		obj.Allocate();

		std::cout << obj.Get() << std::endl;

		srand(time(NULL));
		gen(rand() % 100);
		
		obj.Deallocate();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what();
	}

}