#include <iostream>

// как было в С
float fMax(float a, float b)
{
	return (a > b) ? a : b;
}

int iMax(int a, int b)
{
	return (a > b) ? a : b;
}

char cMax(char a, char b)
{
	return (a > b) ? a : b;
}

double dMax(double a, double b)
{
	return (a > b) ? a : b;
}

// в С++ НЕ НАДО ТАК
#define MAX(x, y) ((x) > (y)) ? (x) : (y)


// реальность С++
template<typename T>
T max(T a, T b)
{
	return (a > b) ? a : b;
}

int main()
{
	// пример С
	float f = fMax(1.0f, 2.0f);
	int i = iMax(1, 2);
	char c = fMax('A', 'B');

	
	// реальность С++
	float f2 = max<float>(1.0f, 2.0f);
	int i2 = max<int>(1, 2);
	char c2 = max<char>('A', 'B');


	// а попробуем без указания типа
	float f3 = max(1.0f, 2.0f);
	int i3 = max(1, 2);
	char c3 = max('A', 'B');
	// упс...
	// float f4 = max(1.0f, 2);
}