#include <iostream>

#define A1 0
#define A2 0
#define A3 0
#define A4 0
#define A5 0
#define A6 1

void change_val(int& number)
{
	int a = 10;

	number = a;
}

int& function(int& a)
{
	a = 5;
	return a;
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
#elif A5
	int arr[3] = { 1,2,3 };

	//int a,b int& arr[2] = {a,b};  ����� �Ұ��� �ϴ�. C++�������� �ȵȴٰ� �Ǿ� ����.
	//�ڼ��� ������ ������ڵ�. "������(modoocode.com/141)" �κ� ���� �� ��.
	int(&ref)[3] = arr;  

	ref[0] = 9;
	ref[1] = 8;
	ref[2] = 7;

	std::cout << arr[0] << "," << arr[1] << "," << arr[2] << std::endl;
#else A6
	/* tip. ���� �����ϴ� ���� ����� ���۷����� ��۸�(Dangling)���۷������ �Ѵ�. */

	int b = 2;
	int c = function(b);
	std::cout << c << std::endl;
#endif

	return 0;
}