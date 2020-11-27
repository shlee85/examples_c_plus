#include <iostream>

class Animal {
private:
	int food;
	int weight;

public:
	void set_animal(int _food, int _weight) {
		food = _food;
		weight = _weight;
	}

	void increase_food(int inc) {
		food += inc;
		weight += (inc / 3);
	}

	void view_stat() {
		std::cout << "�� ������ food : " << food << std::endl;
		std::cout << "�� ������ weight : " << weight << std::endl;
	}
};

int main()
{
	Animal c_animal;

	c_animal.set_animal(10, 213);
	c_animal.increase_food(30);

	c_animal.view_stat();
}