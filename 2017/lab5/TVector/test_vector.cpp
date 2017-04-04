#include "TVector.h"
#include <iostream>

int main()
{
	TPsevdoVector<int> vec13(10);
	vec13.push_back(0);
	vec13.push_back(1);
	vec13.push_back(2);

	for (int e : vec13)
	{
		std::cout << e << std::endl;
	}

	auto it = vec13.begin();
	std::cout << *(it + 2) << std::endl;

	system("pause");
}
