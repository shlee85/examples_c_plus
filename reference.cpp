#include <iostream>

#define A1 0
#define A2 0
#define A3 0
#define A4 1

void change_val(int& number)
{
	int a = 10;

	number = a;
}

int main()
{
#if A1    //������ (call by reference�� ���)
	int a = 3;

	std::cout << "a1 : " << a << std::endl;

	int& another_a = a;
	another_a = 5;

	std::cout << "a1 : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
#elif A2
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);  //������ �Լ��� �ѱ��.
	std::cout << number << std::endl;
#elif A3
	int		x;
	int& y = x;
	int& z = y; //y�� ������ ��� x�� �����ڰ� �ȴ�. c++�� �������� ������ �Ұ���. int&& y�� �ȵȴٴ� ����.

	x = 1;
	std::cout << "x : " << x << " y: " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y: " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y: " << y << " z : " << z << std::endl;
#elif A4
	const int& ref = 4; //��� ������ �����ϴ� const�� �ϸ�. �Ϲ������δ� ��� �� ��ü�� ���ͷ��̱� ������ �Ұ��� ��.
	std::cout << ref << std::endl;
	int a = ref;
	std::cout << a << std::endl;

#endif

	return 0;
}