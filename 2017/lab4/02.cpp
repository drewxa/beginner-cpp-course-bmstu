#include <iostream>
#include <cstring>


template<class T>
void print(T * a, size_t sz)
{
	for (size_t i = 0; i < sz; ++i)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void sort(T * arr, size_t sz)
{
	for (size_t i = 0; i < sz; ++i)
	{
		for (size_t j = i; j < sz; ++j)
		{
			if (arr[i] > arr[j])
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}

// специализация
template<>
void sort<char *>(char ** arr, size_t sz)
{
	for (size_t i = 0; i < sz; ++i)
	{
		for (size_t j = i; j < sz; ++j)
		{
			if (strcmp(arr[j], arr[i]) < 0)
			{
				std::swap(arr[i], arr[j]);
			}
		}
	}
}

int main()
{
	float v1[] = {1.2f, 14.1f, 1.1f, 1.f};
	print(v1, 4);
	sort(v1, 4);
	print(v1, 4);


	int v2[] = {1, -14, 12, 2};
	print(v2, 4);
	sort(v2, 4);
	print(v2, 4);


	char * v3[] = {"A", "C", "B", "D"};
	print(v3, 4);
	sort(v3, 4);
	print(v3, 4);
}