#ifndef __BOOLEAN_FUNCTION_INCLUDED__
#define __BOOLEAN_FUNCTION_INCLUDED__

#include <string>
#include <vector>

class boolean_function
{
public:
	using value_type = bool;
	using size_type = size_t;
	using reference = value_type&;
	using const_reference = const value_type&;

	using iterator = typename std::vector<value_type>::iterator;
	using const_iterator = typename std::vector<value_type>::const_iterator;
	
public:

	// возвращает функцию которая равна xn с размерностью dimension
	// пример 1
	// n = 0
	// dimension = 3
	// вернется функция "01010101"
	// пример 2
	// n = 1
	// dimension = 4
	// вернется функция "0011001100110011"
	static boolean_function var(size_t n, size_t dimension);
	
	// тождественный ноль "от dimension переменных"
	static boolean_function zero(size_t dimension);
	
	// тождественная единица "от dimension переменных"
	static boolean_function one(size_t dimension);
	
	static boolean_function from_anf(std::vector<value_type> v);
	
	boolean_function();
	
	// задает фунцию тождественного нуля от n переменных
	boolean_function(size_t n);
	
	// задает фунцию от n переменных. значение равно value
	// пример
	// пусть value = 14, т.е. 0...00001110 в двоичной системе
	// а n = 3
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(unsigned long long value, size_type n);
	
	// пусть table = "01110000"
	// тогда АНФ boolean_function будет равна x + y + xy + zx + zy + zyx
	boolean_function(const std::string& table);
	
	// пусть table = {true, false, false, true};
	// тогда АНФ boolean_function будет равна x + y + 1
	boolean_function(const std::vector<value_type>& table);
	
	boolean_function(const boolean_function& table);

	boolean_function& operator=(const boolean_function& rhs);

	// сложение по модулю 2
	// если разное количество переменных - исключение
	boolean_function& operator += (const boolean_function& rhs);

	// конъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator *= (const boolean_function& rhs);

	// дизъюнкция
	// если разное количество переменных - исключение
	boolean_function& operator |= (const boolean_function& rhs);

	// побитовое отрицание
	boolean_function operator ~ ();

	// true если функции равны
	//  иначе false
	bool operator == (const boolean_function&) const;
	
	// true если одна функция сравнима и больше или равна rhs
	// false если сравнима и меньше rhs
	// logic_error если фунции не сравнимы
	bool operator >= (const boolean_function& rhs) const;

	reference operator[](size_type ind);
	const_reference operator[](size_type ind) const;

	reference at(size_type ind);
	const_reference at(size_type ind) const;

	iterator begin();
	iterator end();

	const_iterator cbegin() const;
	const_iterator cend() const;

	// длина столбца функции
	size_type size() const throw();

	// количество переменных
	size_type dimension() const throw();

	// возвращает значение функции
	// пусть boolean_function задает функцию f(x, y, z)
	// тогда функция вернет f(vars[0], vars[1], vars[2])
	bool operator()(const std::vector<bool>& vars) const;


	// T(x1, x2, ..., xN) - текущая функция
	// operator вернет новую функцию, которая равна композиции G = T(fs[0], fs[1], ..., fs[N-1])
	boolean_function operator()(const std::vector<boolean_function>& fs) const;
	
	bool is_monotone() const;
	bool is_symmetric() const;
	bool is_linear() const;
	bool is_T1() const;
	bool is_T0() const;
	bool is_balanced() const; //равновесная ли

	bool is_functionally_complete_system() const;
	
	// Возвращает АНФ функции
	std::vector<value_type> anf() const;
};

// пусть boolean_function представляет из себя функцию "01110000"
// тогда get_polynom вернет строку "x0 + x1 + x0x1 + x0x2 + x1x2 + x0x1x2"
std::string get_polynom(const boolean_function&) const;

boolean_function opeartor + (const boolean_function& a, const boolean_function& b);

boolean_function opeartor * (const boolean_function& a, const boolean_function& b);

boolean_function opeartor | (const boolean_function& a, const boolean_function& b);


#endif // __BOOLEAN_FUNCTION_INCLUDED__
