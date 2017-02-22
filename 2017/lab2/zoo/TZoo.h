#pragma once
#include "TAnimal.h"

const float STEP = 0.5;

class TZoo
{
	typedef TAnimal * TPtrAnimal;

	/// Звери
	TPtrAnimal * Animals;
	
	/// Максимальная вместимость зоопарка
	size_t Capacity;

	/// Количество зверей в зоопарке
	size_t NumAnimals;

	/// Время суток
	float Time;
public:
	TZoo(size_t capacity);
	bool AddNewAnimal(TAnimal ** newAnimal);
	void Work();
	~TZoo();
};

