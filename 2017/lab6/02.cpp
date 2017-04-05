#include <iostream>

#include <string>
#include <vector>

// functional object
template <typename T>
struct common_less
{
	bool operator()(const T& a, const T& b)
	{
		return a < b;
	}
};

// functional object
struct custom_less
{
	bool operator()(int a, int b)
	{
		int x = (a*3) % 5;
		int y = (b*3) % 5;
		return x < y;
	}
};

// BinaryOp - custom compatator
template <typename T, typename IT, typename Cmp>
T get_max(IT beg, IT end, Cmp compatator)
{
	T max = *beg;
	for (IT it = beg; it != end; ++it)
	{
		if (compatator(max, *it))
			max = *it;
	}
	return max;
}

int main()
{
	std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7, 13};


	std::cout << get_max<int>(vec.begin(), vec.end(), common_less<int>{}) << std::endl;


	custom_less obj;
	std::cout << get_max<int>(vec.begin(), vec.end(), obj) << std::endl;
}