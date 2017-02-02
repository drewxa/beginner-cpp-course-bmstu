#ifndef __THUMAN_INCLUDE__
#define __THUMAN_INCLUDE__


#include <iostream>
#include <string>

class THuman
{
private:
	std::string FirstName;
	std::string SecondName;
	std::size_t Age;

	friend std::ostream& operator << (std::ostream&, const THuman & h);
public:
	// dtor
	~THuman();
	// default ctor
	THuman();
	// user ctor
	THuman(const std::string & firstName, const std::string & secondName, std::size_t age);
	// user ctor
	THuman(const std::string & firstName, const std::string & secondName);
	// copy ctor
	THuman(const THuman & rhs);
	// copy operator
	THuman& operator=(const THuman& rhs);
	void Print();
	void HappyBirthDay();
};

std::ostream& operator << (std::ostream& out, const THuman & h);

#endif // __THUMAN_INCLUDE__