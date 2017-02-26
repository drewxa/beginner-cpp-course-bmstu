#include "simple_memory_leak_detector.h"
#include <iostream>

void check()
{
	if (memoryLeakExist())
		std::cout << "memory leaks" << std::endl;
	else
		std::cout << "all right" << std::endl;
}

void case0()
{
	int * p = new int(1324);
	check(); // memory leaks
}

void case1()
{
	int * p = new int(1324);
	delete p;
	check(); // all right
}

void case2()
{
	int * p = new int(1324);
	int * p1 = p;
	delete p;
	delete p1; // some error: may be double free error or incorrect kind of delete
}

void case3()
{
	int * p = new int(1324);
	p = new int(1324);
	delete p;
	check(); // memory leaks
}

void case4()
{
	std::string * arr = new std::string[1000];
	delete[] arr;
	check(); // all right
}

void case5()
{
	std::string * arr = new std::string[1000];
	delete arr; // some error: may be double free error or incorrect kind of delete
}

void case6()
{
	// in this case application crash
	std::string * arr = new std::string("abc");
	delete[] arr;
}

int main()
{
	int i = 0;
	std::cout << "Enter a number from 0 to 6" << std::endl;
	std::cin >> i;
	switch (i)
	{
	case 0:
		case0();
		break;
	case 1:
		case1();
		break;
	case 2:
		case2();
		break;
	case 3:
		case3();
		break;
	case 4:
		case4();
		break;
	case 5:
		case5();
		break;
	case 6:
		case6();
		break;
	default:
		std::cout << "incorrect number" << std::endl;
		break;
	}
}