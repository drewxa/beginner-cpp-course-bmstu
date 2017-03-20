#include "TVector.h"
#include <iostream>

template<class T>
void printVector(const TVector<T>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
}

int main()
{
	{
		TVector<int> vec;
		for (int i = 0; i < 32; ++i)
			vec.push_back(i);

		printVector(vec);

		vec.insert(vec.begin() + 10, 1000);
		printVector(vec);

		vec.erase(vec.begin(), vec.begin() + 10);
		printVector(vec);

		vec.erase(vec.begin());
		printVector(vec);

		std::cout << vec.front() << std::endl;
		std::cout << vec.back() << std::endl;

		vec.pop_back();
		std::cout << vec.back() << std::endl;

		size_t oldSize = vec.size();
		vec.resize(44);
		printVector(vec);

		vec.resize(oldSize);
		printVector(vec);

		TVector<int> vec2;
		for (int i = 0; i < 2; ++i)
			vec2.push_back(i);

		vec2.swap(vec);
		printVector(vec2);
		printVector(vec);

		vec2 = vec;
		printVector(vec2);
		printVector(vec);

		try
		{
			TVector<int>::value_type item = vec2.at(1000000);
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}

		try
		{
			vec2.resize(UINT64_MAX);
		}
		catch (const std::exception & e)
		{
			std::cout << e.what();
		}
	}

	TVector<float> vec;
	for (int i = 0; i < 32; ++i)
		vec.push_back(static_cast<float>(i) / 100);

	system("pause");
}