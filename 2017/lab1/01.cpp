#include <iostream>
#include <string>

int main()
{
	std::cout << "let's print message" << std::endl;

	std::cout << "let's print some number, for example " << 42 << std::endl;

	std::cout << "let's print some string, for example " << "'Hello, world!'" << std::endl;

	std::cout << "let's scan data" << std::endl;

	int num = 0;
	std::cout << "enter a number" << std::endl;
	std::cin >> num;
	std::cout << "num = " << num << std::endl;

	std::string word;
	std::cout << "enter a word" << std::endl;
	std::cin >> word;
	std::cout << "the word is " << word << std::endl;

	system("pause");
}