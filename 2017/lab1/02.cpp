#include <iostream>
#include <string>

struct TPoint
{
	int X;
	int Y;
};

void initArray(int * intArray, int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; ++i)
	{
		intArray[i] = rand();
	}
}

void printArray(int * intArray, int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	std::cout << "let's learn keywords 'new', 'delete'" << std::endl;

	int * ptr = new int(100);
	std::cout << "address of number is " << ptr << std::endl;
	std::cout << "value of number is " << *ptr << std::endl;
	// if create an object, then delete this object
	delete ptr;


	int sizeOfArray = 0;
	std::cout << "enter size od array" << std::endl;
	std::cin >> sizeOfArray;
	int * intArray = new int[sizeOfArray];
	initArray(intArray, sizeOfArray);
	printArray(intArray, sizeOfArray);
	// if create an array, then delete this array
	delete[] intArray;


	TPoint * ptrToPoint = new TPoint();
	std::cout << "enter X" << std::endl;
	std::cin >> ptrToPoint->X;
	std::cout << "enter Y" << std::endl;
	std::cin >> ptrToPoint->Y;
	std::cout << "X = " << ptrToPoint->X << ", Y = " << ptrToPoint->Y << std::endl;
	// if create an object, then delete this object
	delete ptrToPoint;

	system("pause");
}