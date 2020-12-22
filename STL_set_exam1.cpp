//STL examples (https://modoocode.com/224)
//set, map, jmultiset, multimap

#include <iostream>
#include <set>

#define STL_SET 1

using namespace std;

template <typename T>

void print_set(set<T>& s) 
{
	//set�� ��� ���ҵ��� ����ϱ�.
	cout << "[";
	
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << " ] " << endl;
}

int main(int argc, char** argv)
{
	set<int> s; //SET�� ���Ұ� ���� �ϴ��� ���ϴ��� üũ �Ѵ�. (���������� Ʈ�������� �Ǿ� �ִ�.)

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(20);
	s.insert(50);

	cout << "������� ���ĵǼ� ���´�." << endl;
	print_set(s); //set�� �ߺ��� ���Ұ� ����. ( �ߺ��� �Ǹ� �ϳ��� ����� �ȴ�. )

	cout << "20�� s�� �����ΰ���? :: ";

	auto itr = s.find(20);  // SET�� ���Ұ� �����ϴ��� ���θ� üũ. (���� ���� �Ѵٸ� �̸� ����Ű�� �ݺ��ڸ� ����, �������� ������ s.end()�� ����. 
	if (itr != s.end()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	cout << "25�� a�� �����ΰ���? :: ";
	itr = s.find(25);
	if (itr != s.end()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}