#include <iostream>

template <size_t N>
void print()
{
	std::cout << "print '.' " << N << " times" << std::endl;
	for (size_t i = 0; i < N; ++i)
	{
		std::cout << '.';
	}
	std::cout << std::endl;
}

template<size_t N>
size_t fact()
{
	return fact<N - 1>() * N;
}

template<>
size_t fact<1>()
{
	return 1;
}


int main()
{
	print<10>();
	print<1>();
	print<8>();

	std::cout << "6! = " << fact<6>() << std::endl;
	std::cout << "3! = " << fact<3>() << std::endl;
	std::cout << "4! = " << fact<4>() << std::endl;
}