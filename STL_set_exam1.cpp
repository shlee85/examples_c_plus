//STL examples (https://modoocode.com/224)
//set, map, jmultiset, multimap

#include <iostream>
#include <set>

#define STL_SET 1

using namespace std;

template <typename T>

void print_set(set<T>& s) 
{
	//set의 모든 원소들을 출력하기.
	cout << "[";
	
	for (typename set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
		cout << *itr << " ";
	}
	cout << " ] " << endl;
}

int main(int argc, char** argv)
{
	set<int> s; //SET은 원소가 존재 하느냐 안하느냐 체크 한다. (내부적으로 트리구조로 되어 있다.)

	s.insert(10);
	s.insert(20);
	s.insert(30);
	s.insert(20);
	s.insert(50);

	cout << "순서대로 정렬되서 나온다." << endl;
	print_set(s); //set은 중복된 원소가 없다. ( 중복이 되면 하나만 출력이 된다. )

	cout << "20이 s의 원소인가요? :: ";

	auto itr = s.find(20);  // SET에 원소가 존재하는지 여부를 체크. (만약 존재 한다면 이를 가리키는 반복자를 리턴, 존재하지 않으면 s.end()를 리턴. 
	if (itr != s.end()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	cout << "25가 a의 원소인가요? :: ";
	itr = s.find(25);
	if (itr != s.end()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}