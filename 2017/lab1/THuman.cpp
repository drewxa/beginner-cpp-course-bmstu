#include "THuman.h"

THuman::~THuman()
{
	std::cout << "DEBUG: " << "~THuman()" << std::endl;
	Print();
}

// default ctor
THuman::THuman()
{
	std::cout << "DEBUG: " << "THuman()" << std::endl;
}

// user ctor
THuman::THuman(const std::string & firstName, const std::string & secondName, std::size_t age)
{
	std::cout << "DEBUG: " << "user THuman(f, s, a)" << std::endl;
	FirstName = firstName;
	SecondName = secondName;
	Age = age;
}

// user ctor
THuman::THuman(const std::string & firstName, const std::string & secondName)
	: FirstName(firstName)
	, SecondName(secondName)
	, Age(1)
{
	std::cout << "DEBUG: " << "user THuman(f, s)" << std::endl;
}

// copy ctor
THuman::THuman(const THuman & rhs)
	: FirstName(rhs.FirstName)
	, SecondName(rhs.SecondName)
	, Age(rhs.Age)
{
	std::cout << "DEBUG: " << "copy ctor" << std::endl;
}

// copy operator
THuman::THuman& operator=(const THuman& rhs)
{
	FirstName = rhs.FirstName;
	SecondName = rhs.SecondName;
	Age = rhs.Age;
}

void THuman::Print()
{
	std::cout
		<< FirstName
		<< " "
		<< this->SecondName
		<< " is "
		<< Age
		<< std::endl;
}

void THuman::HappyBirthDay()
{
	++Age;
}


std::ostream& operator << (std::ostream& out, const THuman & h)
{
	std::cout << "DEBUG: using operator<<";
	out
		<< h.FirstName
		<< " "
		<< h.SecondName
		<< " is "
		<< h.Age;

	return out;
}