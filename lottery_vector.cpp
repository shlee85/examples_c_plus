//STL�н��� ���� vector�� Ȱ���Ͽ� �ζ� ���α׷��� ����� ����.
//�ζ� ��ȣ 1 ~ 45������ �Է� ����.
/*
	1�� ��÷��ȣ 6��, ���ʽ���ȣ 1���� ��÷
	�Է��� ��ȣ�� �����Ͽ� 1 ~ 5���� ����� �˷��ش�.
*/
//vector�� class�� �ִ��� Ȱ�� �غ���.

#include <iostream>
#include <vector>

#define LOTTO_MAX 7

using namespace std;

class Lottery {
private:
	int lotto_num;
	int lotto_idx;
	int* check_list;
	vector<int> vec;

public:
	Lottery() {
		lotto_num = 0;
		lotto_idx = 0;

		check_list = new int[LOTTO_MAX];
		for (int i = 0; i < LOTTO_MAX; i++) {
			check_list[i] = 0;
		}

		vec.reserve(LOTTO_MAX);
	}

	bool duplicate_check(int num, vector<int>&);
	void printLottoNumber(vector<int>& vec);
	void Lotto_Input(vector<int>&);
	void UserInterFace_Init();	

	~Lottery() {
		if (check_list)
			delete[] check_list;
	}
};

bool check_number(int num)
{
	if (num > 45 || num < 1) {
		cout << "�߸��� ���ڸ� �Է� �ϼ̽��ϴ�. �ٽ� �Է� �ϼ���." << endl;

		return false;
	}
	else
		return true;
}

//�ߺ� üũ. ó���� üũ�Ǵ� �κ��� true ���� �ߺ��� �߰ߵǸ� fail
bool Lottery::duplicate_check(int input, vector<int>& vec)
{
	int check_cnt = 0;

	cout << "input : " << input << endl;
	cout << "vector size : " << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++){
		cout << "vec : " << vec[i] << endl;
		if (input == vec[i]) {			
			cout << "������ �ߺ�." << endl;
			return false;			
		}
	}

	return true;
}

void Lottery::Lotto_Input(vector<int>& vec)
{
	cout << "��ȣ�� �Է��ϼ���." << endl;	

	while (1) {		
		cout << lotto_idx +1 << "��° ��ȣ �Է� : ";
		cin >> lotto_num;

		if (check_number(lotto_num)){
			if (duplicate_check(lotto_num, vec)) {
				check_list[lotto_idx] = 1;
				vec.push_back(lotto_num);
				lotto_idx++;
			}
		}
		else Lotto_Input(vec);		
		
		if (lotto_idx > 5) break;
	}
}

void Lottery::UserInterFace_Init()
{
	cout << "�ȳ��ϼ���. �ζ� �׽�Ʈ ���α׷��� ���� ���� ȯ�� �մϴ�." << endl;
	cout << "�� 6���� ��ȣ�� �Է��ϼ��� 1 ~ 45 �Դϴ�." << endl;
	cout << "�� 6���� ���߸� 1���Դϴ�." << endl;
	cout << "�� 5���� ���߰� ���ʽ���ȣ 1���� ���߸� 2���Դϴ�. ( ��� �ϰڳ׿�... ���� ) " << endl;
	cout << "�� 5���� ���߸� 3�� �Դϴ�. " << endl;
	cout << "�� 4���� ���߸� 4�� �Դϴ�. " << endl;
	cout << "�� 3���� ���߸� 3�� �Դϴ�. " << endl;
	cout << endl;

	Lotto_Input(vec);

	printLottoNumber(vec);
}

void Lottery::printLottoNumber(vector<int>& vec)
{
	cout << "Lotto Number :";

	for (int i = 0; i < vec.size(); i++) {
		cout <<  "[" << vec[i] << "] ";
	}	
	
	cout << endl;
}

int main(int agrc, char** argv)
{
	Lottery lot;

	lot.UserInterFace_Init();
	
	return 0;
}