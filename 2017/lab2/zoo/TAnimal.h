#pragma once
#include <string>

class TAnimal
{
	std::string Name;
	size_t Age;

public:
	TAnimal();
	TAnimal(const std::string & name);

	/// Используем деструктор по умолчанию.
	/// т.к. специальных действия для очистки объектов не требуется
	virtual ~TAnimal() = default;

	/// Абстрактный метод
	/// <param name="time"> Время суток </param>
	virtual void Live(float time) = 0;

	std::string GetName() const;
	size_t GetAge() const;
};

