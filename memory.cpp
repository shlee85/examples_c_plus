#include <iostream>

#define M1 0
#define M2 0
#define M3 1

struct Animal {
	char name[30];
	int age;
	int health;
	int food;
	int clean;
};

void createAnimal(struct Animal* animal)
{
	std::cout << "������ �̸� : ";
	std::cin >> animal->name;

	std::cout << "������ ���� : ";
	std::cin >> animal->age;

	animal->clean = 100;
	animal->food = 100;
	animal->health = 100;
}

//���� ����.
void play(struct Animal* animal)
{
	animal->health += 10;
	animal->food -= 20;
	animal->clean -= 30;
}

void one_day_pass(struct Animal* animal)
{
	//�Ϸ簡 ���� ���.

	animal->health -= 10;
	animal->food -= 30;
	animal->clean -= 20;
}

//���� ���.
void show_stat(struct Animal* animal)
{
	std::cout << "Clean : " << animal->clean << std::endl;
	std::cout << "Food : " << animal->food << std::endl;
	std::cout << "Health : " << animal->health << std::endl;
}

int main()
{
#if M1
	int* p = new int;
	*p = 10;

	std::cout << "*p : " << *p << std::endl; 
	std::cout << "p : " << p << std::endl;

	delete p;
#elif M2 //�迭.
	int* list = new int[5];
	for (int i = 0; i < 5; i++) {
		list[i] = i + i;
	}

	for (int i = 0; i < 5; i++) {
		std::cout << i << "th element of list : " << list[i] << std::endl;
	}

	delete[] list;
#elif M3  //1���� ���������� ���� ����.

	struct Animal* list[10];
	int animal_num = 0;
	
	while (1)
	{
		std::cout << "1. ���� �߰��ϱ�" << std::endl;
		std::cout << "2. ���" << std::endl;
		std::cout << "3. ���� ����" << std::endl;

		int input;
		std::cin >> input;

		switch (input)
		{
			int play_with;
			case 1:
				list[animal_num] = new Animal;
				createAnimal(list[animal_num]);

				animal_num++;
				break;
			case 2:
				std::cout << "������ ���? : ";
				std::cin >> play_with;
				
				if (play_with < animal_num)
					play(list[play_with]);
				break;
			case 3:
				std::cout << "������ ����? : ";
				std::cin >> play_with;

				if (play_with < animal_num)
					show_stat(list[play_with]);
				break;
		}

		for (int i = 0; i != animal_num; i++) {
			one_day_pass(list[i]);
		}
	}

	for (int i = 0; i = animal_num; i++) {
		delete list[i];
	}

#endif
	return 1;
}

