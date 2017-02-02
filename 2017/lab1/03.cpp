#include <iostream>
#include <string>


struct TPoint
{
	int X;
	int Y;
};

void printPoint(const TPoint & p)
{
	std::cout << "X = " << p.X << ", Y = " << p.Y << std::endl;
}

void changePoint(TPoint & p)
{
	p.X += 100;
	p.Y *= 4;
}

void printMessage(std::string const& message)
{
	std::cout << message << std::endl;
	// compile error
	// message = "some other message";
}

int main()
{
	TPoint myPoint;
	myPoint.X = 100;
	myPoint.Y = 100;
	printPoint(myPoint);

	TPoint & ref = myPoint;
	printMessage("print ref");
	printPoint(ref);
	printMessage("print myPoint");
	printPoint(myPoint);


	printMessage("changing");
	ref.Y = 2000;
	myPoint.X = 2000;
	printMessage("print ref");
	printPoint(ref);
	printMessage("print myPoint");
	printPoint(myPoint);

	printMessage("--------------------------------");

	TPoint point;
	
	printMessage("enter X");
	std::cin >> point.X;

	printMessage("enter Y");
	std::cin >> point.Y;


	printPoint(point);
	changePoint(point);
	printPoint(point);


	system("pause");
}