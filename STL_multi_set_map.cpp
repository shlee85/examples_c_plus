//멀티셋 & 멀티맵
//기존에는 insert하면 중복된 것은 무시하였음. 그러나 멀티 셋&맵은 중복된 것도 처리 가능.

#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;

template <typename K>

void print_set(const multiset<K>& s) {
	//set의 모든 원소를 출력.
	for (const auto& elem : s) {
		cout << elem << endl;
	}
}

template <typename K, typename V>
void print_map(const multimap<K, V>& m) {
	for (const auto& kv : m) {
		cout << kv.first << " " << kv.second << endl;
	}
}

int main(int argc, char** argv)
{
	multiset<string> s;
	
	s.insert("a");
	s.insert("b");
	s.insert("c");
	s.insert("a");
	s.insert("c");

	print_set(s);

	cout << endl << endl;

	multimap<int, string> m;

	m.insert(make_pair(1, "Hello"));
	m.insert(make_pair(1, "DSB"));
	m.insert(make_pair(2, "Decoder"));
	m.insert(make_pair(1, "Encoder"));
	m.insert(make_pair(3, "converter"));

	print_map(m);

	cout << "------------------" << endl;
	cout << m.find(1)->second << endl;
	cout << endl;
	cout << "------------------" << endl;

	auto range = m.equal_range(1);
	//cout << "range.second : " << range.second << endl;

	for (auto itr = range.first; itr != range.second; ++itr) {
		cout << itr->first << " : " << itr->second << " " << endl;
	}

	return 0;
}
