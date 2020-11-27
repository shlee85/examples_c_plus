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
#if A1    //참조자 (call by reference와 비슷)
	int a = 3;

	std::cout << "a1 : " << a << std::endl;

	int& another_a = a;
	another_a = 5;

	std::cout << "a1 : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;
#elif A2
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);  //참조자 함수로 넘기기.
	std::cout << number << std::endl;
#elif A3
	int		x;
	int& y = x;
	int& z = y; //y의 참조자 고로 x의 참조자가 된다. c++은 참조자의 참조는 불가능. int&& y는 안된다는 것임.

	x = 1;
	std::cout << "x : " << x << " y: " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y: " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y: " << y << " z : " << z << std::endl;
#elif A4
	const int& ref = 4; //상수 참조는 가능하다 const로 하면. 일반적으로는 상수 값 자체는 리터럴이기 때문에 불가능 함.
	std::cout << ref << std::endl;
	int a = ref;
	std::cout << a << std::endl;

#endif

	return 0;
}