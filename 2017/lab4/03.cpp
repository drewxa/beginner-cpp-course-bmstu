#include <iostream>
#include <fstream>

struct A
{
	void Load()
	{
		std::cout << "Enter number" << std::endl;
		std::cin >> Data;
	}

	void Print() const
	{
		std::cout << Data << std::endl;
	}
private:
	int Data;
};

struct B
{
	void Load()
	{
		std::ifstream fl("text", std::ios::in);
		fl >> Data;
	}

	void Print() const
	{
		std::cout << Data << std::endl;
	}
private:
	int Data;
};

struct C
{
	void Load()
	{
		Data = 42.;
	}
	void Print() const
	{
		std::cout << Data << std::endl;
	}
private:
	double Data;
};

struct D
{
	void Load(std::string & str)
	{
		Data = 42;
		str = "done";
	}
	void Print() const
	{
		std::cout << Data << std::endl;
	}
private:
	int Data;
};

// статический полиморфизм
template<class T>
void loader(T & obj)
{
	obj.Load();
}

template<class T>
void printer(const T & obj)
{
	obj.Print();
}

int main()
{
	std::ofstream fl("text", std::ios::out);
	fl << 13;
	fl.close();

	A a;
	B b;
	C c;
	D d;

	loader(a);
	loader(c);
	loader(b);
	// loader(d); // compilation error

	printer(a);
	printer(b);
	printer(c);
	printer(d);
}