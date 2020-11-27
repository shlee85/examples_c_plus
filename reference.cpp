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
#elif A5
	int arr[3] = { 1,2,3 };

	//int a,b int& arr[2] = {a,b};  방식은 불가능 하다. C++규정으로 안된다고 되어 있음.
	//자세한 내용은 모두의코드. "참조자(modoocode.com/141)" 부분 참고 할 것.
	int(&ref)[3] = arr;  

	ref[0] = 9;
	ref[1] = 8;
	ref[2] = 7;

	std::cout << arr[0] << "," << arr[1] << "," << arr[2] << std::endl;
#else A6
	/* tip. 원래 참조하던 것이 사라진 레퍼런스는 댕글링(Dangling)레퍼런스라고 한다. */

	int b = 2;
	int c = function(b);
	std::cout << c << std::endl;
#endif

	return 0;
}