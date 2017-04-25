#include <iostream>
#include <exception>

#define assert(X) { \
	if(!(X)) {\
		std::cout << "see function:'" << __FUNCTION__ << "' line: " << __LINE__;\
		throw std::logic_error(#X); \
	}\
}

#define RUN_TEST(func, message) \
{ try {\
	func();\
	std::cout << #func << " " << message << std::endl;\
  } catch(std::exception& e) { \
	std::cout << #func << " failed. reason: " << e.what() << std::endl; \
  }\
}


#include "boolean_function.h"

void test_ctor0()
{
	try
	{
		boolean_function f("111");
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}

	try
	{
		boolean_function f({true, false, true});
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_ctor1()
{
	boolean_function f;
	assert(f.size() == 0);
	assert(f.dimension() == 0);

	try
	{
		f.at(0);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_ctor2()
{
	boolean_function f(3);
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 0);
		assert(true);
		f.at(8);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_ctor3()
{
	boolean_function f(14, 3);
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 0);
		assert(static_cast<int>(f.at(1)) == 1);
		assert(static_cast<int>(f.at(2)) == 1);
		assert(static_cast<int>(f.at(3)) == 1);
		assert(static_cast<int>(f.at(4)) == 0);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);
		assert(true);
		f.at(8);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_ctor_string()
{
	boolean_function f("01110000");
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 0);
		assert(static_cast<int>(f.at(1)) == 1);
		assert(static_cast<int>(f.at(2)) == 1);
		assert(static_cast<int>(f.at(3)) == 1);
		assert(static_cast<int>(f.at(4)) == 0);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);
		assert(true);
		f.at(8);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_ctor_vec()
{
	std::vector<boolean_function::value_type> vec = {true, false, true, true, false, false, false, false};
	boolean_function f(vec);
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 1);
		assert(static_cast<int>(f.at(1)) == 0);
		assert(static_cast<int>(f.at(2)) == 1);
		assert(static_cast<int>(f.at(3)) == 1);
		assert(static_cast<int>(f.at(4)) == 0);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);
		assert(true);
		f.at(8);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_ctor_copy()
{
	std::vector<boolean_function::value_type> vec = {true, false, true, true, false, false, false, false};
	boolean_function g(vec);

	assert(g == boolean_function({true, false, true, true, false, false, false, false}));

	boolean_function f(g);
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 1);
		assert(static_cast<int>(f.at(1)) == 0);
		assert(static_cast<int>(f.at(2)) == 1);
		assert(static_cast<int>(f.at(3)) == 1);
		assert(static_cast<int>(f.at(4)) == 0);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);
		assert(true);
		f.at(8);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_op_copy()
{
	boolean_function g(14, 3);
	boolean_function f;
	assert(f.size() == 0);
	assert(f.dimension() == 0);
	f = g;

	try
	{
		assert(static_cast<int>(f.at(0)) == 0);
		assert(static_cast<int>(f.at(1)) == 1);
		assert(static_cast<int>(f.at(2)) == 1);
		assert(static_cast<int>(f.at(3)) == 1);
		assert(static_cast<int>(f.at(4)) == 0);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_op_xor()
{
	boolean_function g(14, 3);
	boolean_function f(4, 3);

	assert(f.size() == 8);
	assert(f.dimension() == 3);
	f += g;
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 0);
		assert(static_cast<int>(f.at(1)) == 1);
		assert(static_cast<int>(f.at(2)) == 0);
		assert(static_cast<int>(f.at(3)) == 1);
		assert(static_cast<int>(f.at(4)) == 0);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);

		f += boolean_function(64, 5);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_op_and()
{
	boolean_function g(14, 3);
	boolean_function f(4, 3);

	assert(f.size() == 8);
	assert(f.dimension() == 3);
	f *= g;
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 0);
		assert(static_cast<int>(f.at(1)) == 0);
		assert(static_cast<int>(f.at(2)) == 1);
		assert(static_cast<int>(f.at(3)) == 0);
		assert(static_cast<int>(f.at(4)) == 0);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);

		f *= boolean_function(64, 5);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_op_or()
{
	boolean_function g(14, 3);
	boolean_function f(16, 3);

	assert(f.size() == 8);
	assert(f.dimension() == 3);
	f |= g;
	assert(f.size() == 8);
	assert(f.dimension() == 3);

	try
	{
		assert(static_cast<int>(f.at(0)) == 0);
		assert(static_cast<int>(f.at(1)) == 1);
		assert(static_cast<int>(f.at(2)) == 1);
		assert(static_cast<int>(f.at(3)) == 1);
		assert(static_cast<int>(f.at(4)) == 1);
		assert(static_cast<int>(f.at(5)) == 0);
		assert(static_cast<int>(f.at(6)) == 0);
		assert(static_cast<int>(f.at(7)) == 0);

		f |= boolean_function(64, 5);
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_op_not()
{
	boolean_function f(14, 3);

	assert(f.size() == 8);
	assert(f.dimension() == 3);
	~f;

	try
	{
		assert(static_cast<int>(f.at(0)) == 1);
		assert(static_cast<int>(f.at(1)) == 0);
		assert(static_cast<int>(f.at(2)) == 0);
		assert(static_cast<int>(f.at(3)) == 0);
		assert(static_cast<int>(f.at(4)) == 1);
		assert(static_cast<int>(f.at(5)) == 1);
		assert(static_cast<int>(f.at(6)) == 1);
		assert(static_cast<int>(f.at(7)) == 1);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_op_eq()
{
	boolean_function f(14, 3);

	assert(f == boolean_function(14, 3));
	assert(f == boolean_function("01110000"));
	assert(f != boolean_function(15, 3));
	assert(f != boolean_function("11110010"));
}

void test_op_more()
{
	boolean_function f(14, 3);

	assert(f >= boolean_function(14, 3));
	assert(!(f >= boolean_function("11110000")));
	assert((f >= boolean_function("00110000")));
	try
	{
		f >= boolean_function("00110110");
		assert(false);
	}
	catch (...)
	{
		assert(true);
	}
}

void test_it()
{
	boolean_function f(14, 3);
	
	boolean_function::iterator it = f.begin();

	assert(static_cast<int>(*it) == 0);
	++it;
	assert(static_cast<int>(*it) == 1);
	++it;
	assert(static_cast<int>(*it) == 1);
	++it;
	assert(static_cast<int>(*it) == 1);
	++it;
	assert(static_cast<int>(*it) == 0);
	++it;
	assert(static_cast<int>(*it) == 0);
	++it;
	assert(static_cast<int>(*it) == 0);
	++it;
	assert(static_cast<int>(*it) == 0);
}

void test_it_begin_end()
{
	boolean_function f(5);
	
	for (auto & v : f)
	{
		assert(static_cast<bool>(v) == false);
	}
}

void test_access()
{
	boolean_function f(14, 3);

	assert(static_cast<int>(f[0]) == 0);
	assert(static_cast<int>(f[1]) == 1);
	assert(static_cast<int>(f[2]) == 1);
	assert(static_cast<int>(f[3]) == 1);
	assert(static_cast<int>(f[4]) == 0);
	assert(static_cast<int>(f[5]) == 0);
	assert(static_cast<int>(f[6]) == 0);
	assert(static_cast<int>(f[7]) == 0);

	f[4] = true;
	assert(static_cast<int>(f[4]) == 1);

	f[1] = 0;
	assert(static_cast<int>(f[1]) == 0);

	f[1] = f[3];
	assert(static_cast<int>(f[1]) == 1);
}

void test_property()
{
	boolean_function f(14, 3);

	assert(!f.is_linear());
	assert(!f.is_monotone());
	assert(!f.is_T1());
	assert(f.is_T0());
	assert(!f.is_balanced());
	assert(!f.is_functionally_complete_system());
	assert(!f.is_symmetric());
	assert(f.weight() == 3);
}

void test_property1()
{
	boolean_function f("1000");

	assert(!f.is_linear());
	assert(!f.is_monotone());
	assert(!f.is_T1());
	assert(!f.is_T0());
	assert(!f.is_balanced());
	assert(f.is_functionally_complete_system());
	assert(!f.is_symmetric());
	assert(f.weight() == 1);
}

void test_property2()
{
	assert(boolean_function("0110").is_linear());
	assert(!boolean_function("0110").is_monotone());
	assert(!boolean_function("0110").is_T1());
	assert(boolean_function("0110").is_T0());
	assert(boolean_function("0110").is_balanced());
	assert(!boolean_function("0110").is_functionally_complete_system());
	assert(!boolean_function("0110").is_symmetric());
	assert(boolean_function("0110").weight() == 2);

	assert(boolean_function("0001").is_monotone());
}

void test_anf()
{
	std::vector<boolean_function::value_type> f = boolean_function("0100").anf();
	// 0*1 + 1*y + 0*x + 1*xy
	assert(static_cast<int>(f[0]) == 0); // 0*1
	assert(static_cast<int>(f[1]) == 1); // 1*y
	assert(static_cast<int>(f[2]) == 0); // 0*x
	assert(static_cast<int>(f[3]) == 1); // 1*xy
}

void test_from_anf()
{
	std::vector<boolean_function::value_type> anf = {false, true, false, true};

	assert(boolean_function::from_anf(anf) == boolean_function("0100")); 
}

void test_const()
{
	assert(boolean_function::one(3) == boolean_function("11111111"));
	assert(boolean_function::one(5) == boolean_function("1"));
	assert(boolean_function::one(3) == boolean_function("1111"));

	assert(boolean_function::zero(3) == boolean_function("00000000"));
	assert(boolean_function::zero(5) == boolean_function("0"));
	assert(boolean_function::zero(3) == boolean_function("0000"));

	assert(boolean_function::var(0, 2) == boolean_function("0101"));
	assert(boolean_function::var(0, 2) == boolean_function("01010101"));

	assert(boolean_function::var(1, 2) == boolean_function("0011"));
	assert(boolean_function::var(1, 2) == boolean_function("0011001100110011"));

	boolean_function xor = boolean_function::var(1, 2) + boolean_function::var(0, 2);
	assert(xor == boolean_function("0110"));
}

void test_calc()
{
	boolean_function g("00010111");
	assert(g({true, false, true}));
	assert(g({true, true, true}));
	assert(g({true, true, false}));
	assert(!g({false, true, false}));
	assert(!g({false, false, false}));
	assert(!g({false, false, true}));
}

void test_combo()
{
	boolean_function G("00010111");

	boolean_function x0 = boolean_function::var(0, 1);
	boolean_function x1 = boolean_function::var(1, 2);
	boolean_function y = boolean_function::var(2, 3);
	boolean_function z0 = boolean_function::var(3, 4);
	boolean_function z1 = boolean_function::var(4, 5);

	boolean_function XOR("0110");
	boolean_function AND("0001");

	// c(x0, x1, y, z0, z1) = G(x0+x1, y, z0*z1);
	boolean_function c = G({
		XOR({x0, x1}),
		y,
		AND({z0, z1})
	});

	std::vector<boolean_function::value_type> coef = c.anf();

	assert(!coef[0]);
	assert(!coef[1]);
	assert(!coef[2]);
	assert(coef[4 + 1]); // x0y
	assert(coef[4 + 2]); // x1y
	assert(coef[16 + 8 + 1]);  // z0z1x0
	assert(coef[16 + 8 + 2]); // z0z1x0
	assert(coef[16 + 8 + 4]);  // z0z1y
	assert(!coef[63]);
}

void test_combo2()
{
	boolean_function G("0100");

	boolean_function x = boolean_function::var(0, 1);
	boolean_function y = boolean_function::var(1, 2);

	boolean_function XOR("0110");

	// G(x0, x1) = x0 + x0x1
	// c(x, y) = G(x+y, x+y);
	boolean_function c = G({
		XOR({x, x}),
		XOR({y, y})
	});

	boolean_function test(c.anf());
	assert(test.weight() == 0);	
}

int main()
{
	RUN_TEST(test_ctor0, "successed");
	RUN_TEST(test_ctor1, "successed");
	RUN_TEST(test_ctor2, "successed");
	RUN_TEST(test_ctor3, "successed");
	RUN_TEST(test_from_anf, "successed");
	RUN_TEST(test_ctor_string, "successed");
	RUN_TEST(test_ctor_vec, "successed");
	RUN_TEST(test_ctor_copy, "successed");

	RUN_TEST(test_op_xor, "successed");
	RUN_TEST(test_op_and, "successed");
	RUN_TEST(test_op_or, "successed");
	RUN_TEST(test_op_not, "successed");

	RUN_TEST(test_op_eq, "successed");
	RUN_TEST(test_op_more, "successed");

	RUN_TEST(test_it, "successed");
	RUN_TEST(test_it_begin_end, "successed");
	RUN_TEST(test_access, "successed");

	RUN_TEST(test_property, "successed");
	RUN_TEST(test_property1, "successed");
	RUN_TEST(test_property2, "successed");

	RUN_TEST(test_anf, "successed");

	RUN_TEST(test_const, "successed");

	RUN_TEST(test_calc, "successed");
	RUN_TEST(test_combo, "successed");
	RUN_TEST(test_combo2, "successed");
}
