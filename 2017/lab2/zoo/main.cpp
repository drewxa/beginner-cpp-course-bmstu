#include <thread>
#include <iostream>
#include "TZoo.h"

class TCat
	: public TAnimal
{
public:
	TCat(const std::string & name)
		: TAnimal(name)
	{ }

	virtual void Live(float time) override
	{
		// с 6 до 7 кот ест
		if (time >= 6.f && time <= 7.f)
			std::cout << GetName() << " is eating" << std::endl;

		// остальное время спит
		else
			std::cout << GetName() << " is sleeping" << std::endl;
	}
};

class TPussInBoots
	: public TCat
{
public:
	TPussInBoots()
		: TCat("Puss in Boots")
	{ }

	virtual void Live(float time) override
	{
		// с 6 до 7 кот в сапогах ест
		if (time >= 6.f && time <= 7.f)
			std::cout << GetName() << " is eating" << std::endl;
		// с 8 до 15 кот в сапогах спит
		else if (time >= 8.f && time <= 15.f)
			std::cout << GetName() << " is sleeping" << std::endl;
		// остальное время бежит
		else
			std::cout << GetName() << " is running" << std::endl;
	}
};

int main()
{
	TZoo myZoo(10);

	TAnimal * myCat = new TCat("Snowball");
	TAnimal * catCalledGav = new TCat("Gav");
	TAnimal * pussBoots = new TPussInBoots();

	// если не удалось добавить, то очищаем память
	if (!myZoo.AddNewAnimal(&myCat))
		delete myCat;
	// если не удалось добавить, то очищаем память
	if (!myZoo.AddNewAnimal(&catCalledGav))
		delete catCalledGav;
	// если не удалось добавить, то очищаем память
	if (!myZoo.AddNewAnimal(&pussBoots))
		delete pussBoots;

	for (size_t i = 0; i < 100; ++i)
	{
		myZoo.Work();
		std::cout << std::endl;

		// поток ждет 1 секунду
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("pause");
}
