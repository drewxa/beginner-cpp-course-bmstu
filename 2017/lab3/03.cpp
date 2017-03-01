#include <iostream>
#include <exception>


struct TDummy
{
	int Data = 0;
	TDummy(int data)
		: Data(data)
	{
		std::cout << "TDummy" << std::endl;
	}
	~TDummy()
	{
		std::cout << "~TDummy" << std::endl;
	}
	void Print() const throw()
	{
		std::cout << "Print " << Data << std::endl;
	}
};

// implement RAII
class TDummyScopedPtr
{
	TDummy * Ptr;
public:
	TDummyScopedPtr();
	TDummyScopedPtr(TDummy* ptr);
	~TDummyScopedPtr();

	TDummy* operator->();
	TDummy& operator*();

	void Reset(TDummy * newPtr);

	void swap(TDummyScopedPtr& rhs) throw();

	TDummyScopedPtr& operator=(const TDummyScopedPtr&) = delete;
	TDummyScopedPtr(const TDummyScopedPtr&) = delete;
};



int main()
{
	try
	{
		TDummyScopedPtr ptrTwo;
		TDummy * raw = new TDummy(2);
		ptrTwo.Reset(raw);

		TDummyScopedPtr ptr(new TDummy(1));

		ptr.swap(ptrTwo);

		ptr->Print();
		(*ptrTwo).Print();

		throw std::runtime_error("some error");

		// free memory leak! YEP!
	}
	catch (const std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
}