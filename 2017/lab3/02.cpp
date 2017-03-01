#include <iostream>
#include <exception>


struct TDummy
{
	TDummy()
	{
		std::cout << "TDummy" << std::endl;
	}
	~TDummy()
	{
		std::cout << "~TDummy" << std::endl;
	}
	void Print() const throw()
	{
		std::cout << "Print " << std::endl;
	}
};

void someFunc()
{
	throw std::runtime_error("some error");
}

int main()
{
	try
	{
		TDummy d;
		someFunc();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		TDummy * d = new TDummy();
		someFunc();

		// memory leak!!!
		delete d;
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	system("pause");
}