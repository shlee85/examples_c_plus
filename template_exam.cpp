//���ø� ��뿡 ���� ����. (������ڵ� modoocode.com/219)

#include <iostream>
#include <string>

using namespace std;

template <typename T>

class Vector {
	T* data;	//���ø��� ����ؼ� typename T���� int, class, char���� �����ϸ� �ڵ����� Ÿ���� �����Ǽ� �ߺ����� �������� �ʾƵ� ������ Ÿ���� �ڵ� ����. 
	int capacity;
	int length;

public:
	//������
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

	//�� �ڿ� ���ο� ���Ҹ� �߰��Ѵ�.
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

	//������ ��ġ�� ���ҿ� �����Ѵ�.
	T operator[] (int i) { return data[i]; }

	//x��° ��ġ�� ���Ҹ� ���� �Ѵ�.
	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}

	//���� ������ ũ�⸦ ���Ѵ�.
	int size() { return length; }

	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};

int main()
{
	//int�� �����ϴ� ���͸� �����.
	Vector<int> int_vec;
	int_vec.push_back(1);
	int_vec.push_back(3);

	cout << "------- int vector --------" << endl;
	cout << "ù��° ���� : " << int_vec[0] << endl;
	cout << "�ι�° ���� : " << int_vec[1] << endl;

	Vector<string> str_vec;
	str_vec.push_back("hello");
	str_vec.push_back("world");

	cout << "------- string vector --------" << endl;
	cout << "ù��° ���� : " << str_vec[0] << endl;
	cout << "�ι�° ���� : " << str_vec[1] << endl;

	return 0;
}