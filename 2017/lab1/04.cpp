#include <iostream>
#include <string>

#include "THuman.h"


int main()
{
	{
		THuman stranger;
		stranger.Print();
	}

	{
		THuman anna("Anna", "Selezneva", 21);
		anna.Print();
		anna.HappyBirthDay();
		anna.Print();
	}

	{
		THuman lev("Lev", "Tolstoy");
		lev.Print();
		lev.HappyBirthDay();
		std::cout << lev << std::endl;
	}

	{
		THuman anna("Anna", "Selezneva", 21);
		anna.Print();

		THuman lev("Lev", "Tolstoy");
		lev.Print();

		// copy ctor
		THuman girl(anna);
		girl.Print();

		// copy ctor
		THuman woman {anna};
		woman.Print();

		// copy ctor
		THuman man = lev;
		man.Print();

		// copy operator
		anna = lev;
		anna.Print();
	}

	system("pause");
}