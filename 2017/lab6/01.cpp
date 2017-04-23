//#include <iostream>
//
//#include <string>
//#include <vector>
//
//// functional object
//template <typename T>
//struct CommonAddition
//{
//	T operator()(const T& a, const T& b)
//	{
//		return a + b;
//	}
//};
//
//// functional object
//template <typename T>
//struct CommonXOR
//{
//	T operator()(const T& a, const T& b)
//	{
//		return a ^ b;
//	}
//};
//
//// BinaryOp - custom function
//template <typename IT, typename T, typename BinaryOp>
//T accumulate(IT beg, IT end, T init, BinaryOp op)
//{
//	for (IT it = beg; it != end; ++it)
//	{
//		init = op(init, *it);
//	}
//	return init;
//}
//
//int main()
//{
//	std::vector<int> vec = {0, 1, 2, 3, 4, 5, 6, 7};
//
//	
//	std::cout << accumulate(vec.begin(), vec.end(), 0, CommonAddition<int>{}) << std::endl;
//
//
//	CommonXOR<int> obj;
//	std::cout << accumulate(vec.begin(), vec.end(), 0, obj) << std::endl;
//}