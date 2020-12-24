//템플릿 사용에 대한 예제. (모두의코드 modoocode.com/219)

#include <iostream>
#include <string>

using namespace std;

template <typename T>

class Vector {
	T* data;	//템플릿을 사용해서 typename T에서 int, class, char등을 지정하면 자동으로 타입이 지정되서 중복으로 선언하지 않아도 각각의 타입이 자동 들어간다. 
	int capacity;
	int length;

public:
	//생성자
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

	//맨 뒤에 새로운 원소를 추가한다.
	void push_back(T s) {
		if (capacity <= length) {
			T* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			delete[] data;
			data = temp;
			capacity *= 2;
		}
		data[length] = s;
		length++;
	}

	//임의의 위치의 원소에 접근한다.
	T operator[] (int i) { return data[i]; }

	//x번째 위치한 원소를 제거 한다.
	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	//현재 벡터의 크기를 구한다.
	int size() { return length; }

	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};

int main()
{
	//int를 보관하는 벡터를 만든다.
	Vector<int> int_vec;
	int_vec.push_back(1);
	int_vec.push_back(3);

	cout << "------- int vector --------" << endl;
	cout << "첫번째 원소 : " << int_vec[0] << endl;
	cout << "두번째 원소 : " << int_vec[1] << endl;

	Vector<string> str_vec;
	str_vec.push_back("hello");
	str_vec.push_back("world");

	cout << "------- string vector --------" << endl;
	cout << "첫번째 원소 : " << str_vec[0] << endl;
	cout << "두번째 원소 : " << str_vec[1] << endl;

	return 0;
}