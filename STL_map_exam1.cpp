//STL 맵에 관한 예제
//Set과 거의 똑같은 자료 구조 이다.
//다만 set의 경우 키만 보관하지만 맵은 키에 대응하는 값도 보관한다.
//자세한 이론은 모두의코드를 참고한다. (https://modoocode.com/224)

#include <iostream>
#include <map>
#include <string>

using namespace std;

template <typename K, typename V>
void print_map(map<K, V>& m) {
	for (auto itr = m.begin(); itr != m.end(); ++itr) {
		cout << itr->first << " " << itr->second << endl;
	}
}

template <typename K, typename V>
void search_and_print(map<K, V>& m, K key) {
	auto itr = m.find(key);	//키가 존재 하지 않는다면 m.end()를 리턴 한다.
	if (itr != m.end()) {
		cout << key << " --> " << itr->second << endl;
	}
	else {
		cout << key << "은(는) 목록에 없습니다." << endl;
	}
}

int main()
{
	map<string, double> pitchar_list;	//map의 타입은 템플릿 인자로 2개 가지고 있음, 첫번째는 키의 타입, 두번째는 값의 타입.

	//맵의 insert함수는 pair 객체를 인자로 받는다.	
	//투수 이름이 키, 방어율리 대응되는 값이다.
	//만약에 같은 키가 들어가면 나중에 들어간 키는 무시한다. 키는 중복될 수 없음.
	pitchar_list.insert(pair<string, int>("박세웅", 2.23));  //만약에 int타입으로 하면? 당연히 소수점은 없어 지고 정수 값만 나올 것이다. ( 해당 부분에 대해서 일부러 warning 발생. )
	pitchar_list.insert(pair<string, double>("해커", 2.96));
	pitchar_list.insert(pair<string, double>("김광현", 2.12));

	//타입을 지정하지 않아도 간단히 make_pair함수로 pair객체를 만들 수도 있다.
	pitchar_list.insert(make_pair("차우천", 3.05));
	pitchar_list.insert(make_pair("장원준", 2.87));
	pitchar_list.insert(make_pair("헥터", 3.25));

	//혹은 insert를 안쓰더라도 []로 바로 원소를 추가 할 수 있음.
	pitchar_list["니퍼트"] = 3.78;
	pitchar_list["박종훈"] = 2.96;
	pitchar_list["켈리"] = 3.99;

	print_map(pitchar_list);

	cout << "-------------------------------" << endl;
	cout << "해커 방어률 : " << pitchar_list["해커"] << endl;
	cout << "류현진 방어률 : " << pitchar_list["류현진"] << endl;

	//find함수를 사용하여 찾는다. 만약 위에 예제처럼 바로 찾는경우 없는 key에 대한 처리를 할 수 없음.
	search_and_print(pitchar_list, string("차우천"));
	search_and_print(pitchar_list, string("차우층"));

	return 0;
}