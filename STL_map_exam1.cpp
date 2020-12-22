//STL �ʿ� ���� ����
//Set�� ���� �Ȱ��� �ڷ� ���� �̴�.
//�ٸ� set�� ��� Ű�� ���������� ���� Ű�� �����ϴ� ���� �����Ѵ�.
//�ڼ��� �̷��� ������ڵ带 �����Ѵ�. (https://modoocode.com/224)

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
	auto itr = m.find(key);	//Ű�� ���� ���� �ʴ´ٸ� m.end()�� ���� �Ѵ�.
	if (itr != m.end()) {
		cout << key << " --> " << itr->second << endl;
	}
	else {
		cout << key << "��(��) ��Ͽ� �����ϴ�." << endl;
	}
}

int main()
{
	map<string, double> pitchar_list;	//map�� Ÿ���� ���ø� ���ڷ� 2�� ������ ����, ù��°�� Ű�� Ÿ��, �ι�°�� ���� Ÿ��.

	//���� insert�Լ��� pair ��ü�� ���ڷ� �޴´�.	
	//���� �̸��� Ű, ������� �����Ǵ� ���̴�.
	//���࿡ ���� Ű�� ���� ���߿� �� Ű�� �����Ѵ�. Ű�� �ߺ��� �� ����.
	pitchar_list.insert(pair<string, int>("�ڼ���", 2.23));  //���࿡ intŸ������ �ϸ�? �翬�� �Ҽ����� ���� ���� ���� ���� ���� ���̴�. ( �ش� �κп� ���ؼ� �Ϻη� warning �߻�. )
	pitchar_list.insert(pair<string, double>("��Ŀ", 2.96));
	pitchar_list.insert(pair<string, double>("�豤��", 2.12));

	//Ÿ���� �������� �ʾƵ� ������ make_pair�Լ��� pair��ü�� ���� ���� �ִ�.
	pitchar_list.insert(make_pair("����õ", 3.05));
	pitchar_list.insert(make_pair("�����", 2.87));
	pitchar_list.insert(make_pair("����", 3.25));

	//Ȥ�� insert�� �Ⱦ����� []�� �ٷ� ���Ҹ� �߰� �� �� ����.
	pitchar_list["����Ʈ"] = 3.78;
	pitchar_list["������"] = 2.96;
	pitchar_list["�̸�"] = 3.99;

	print_map(pitchar_list);

	cout << "-------------------------------" << endl;
	cout << "��Ŀ ���� : " << pitchar_list["��Ŀ"] << endl;
	cout << "������ ���� : " << pitchar_list["������"] << endl;

	//find�Լ��� ����Ͽ� ã�´�. ���� ���� ����ó�� �ٷ� ã�°�� ���� key�� ���� ó���� �� �� ����.
	search_and_print(pitchar_list, string("����õ"));
	search_and_print(pitchar_list, string("������"));

	return 0;
}