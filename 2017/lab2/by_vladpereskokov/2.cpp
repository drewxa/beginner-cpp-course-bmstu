#include <iostream>
#include <string>

class Unit {
public:
  using unit_name = std::string;
  using health = int;
  
	Unit(const unit_name &name)
  :_name(name), _health(100) {
    std::cout << "Unit: " << _name << std::endl;
  }
  virtual ~Unit() {
    std::cout << "~Unit" << std::endl;
  }
	void run() {
    std::cout << "Run" << std::endl;
  }
	virtual void talk() {
    std::cout << "Fight" << std::endl;
  }
protected:
	unit_name _name;
	health _health;
};

class Human : public Unit {
public:
	Human(const unit_name &name)
	:Unit(name) {
    std::cout << "Human" << std::endl;
  }
	void talk() {
    std::cout << _name << ": talk" << std::endl;
  }
  ~Human() {
    std::cout << "~Human" << std::endl;
  }
};

class Orc : public Human {
public:
  Orc(const unit_name &name)
  :Human(name) {
    std::cout << "Orc" << std::endl;
  }
  void talk() {
    std::cout << _name << ": Humming" << std::endl;
  }
  ~Orc() {
    std::cout << "~Orc" << std::endl;
  }
};

int main() {
  Unit *unit = new Orc("Mike");
  unit->talk();
  std::cout << "-------------------" << std::endl;
  delete unit;
  return 0;
}
