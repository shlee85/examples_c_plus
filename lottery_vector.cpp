//STL�н��� ���� vector�� Ȱ���Ͽ� �ζ� ���α׷��� ����� ����.
//�ζ� ��ȣ 1 ~ 45������ �Է� ����.
/*
	1�� ��÷��ȣ 6��, ���ʽ���ȣ 1���� ��÷
	�Է��� ��ȣ�� �����Ͽ� 1 ~ 5���� ����� �˷��ش�.
*/
//vector�� class�� �ִ��� Ȱ�� �غ���.

#include <iostream>
#include <vector>
#include <random>

#define LOTTO_MAX 7

using namespace std;

class Lottery {
private:
	int lotto_num;
	int lotto_idx;
	int* check_list;
	vector<int> user_vec;
	vector<int> machine_vec;

public:
	Lottery() {
		lotto_num = 0;
		lotto_idx = 0;

		check_list = new int[LOTTO_MAX];
		for (int i = 0; i < LOTTO_MAX; i++) {
			check_list[i] = 0;
		}

		user_vec.reserve(LOTTO_MAX - 1);
		machine_vec.reserve(LOTTO_MAX);
	}

	bool duplicate_check(int num, vector<int>& user_vec);
	void printLottoNumber(vector<int>& user_vec);
	void Lotto_Input(vector<int>& user_vec);
	void UserInterFace_Init();

	//�ζ� ��ȣ ����, ����ȣ + ���ʽ� ��ȣ
	void CreateLotteryNumber(/*vector<int>& machine*/);
	int BonusLotteryNumber(vector<int>& machine);

	//�Է��� ��ȣ�� ������ ��ȣ�� ���Ͽ� ������ �ű��.
	int ret_ranking(vector<int>& machine, vector<int>& user_vec);

	~Lottery() {
		if (check_list)
			delete[] check_list;
	}
};

int Lottery::ret_ranking(vector<int>& machine, vector<int>& user_vec) {
	int rank = 0;
	int match = 0;
	int bonus = 0;

	for (int i = 0; i < machine.size(); i++) {
		for (int j = 0; j < user_vec.size(); j++) {
			if (machine[i] == user_vec[j]) {
				if (i == (machine.size() - 1)) {
					bonus = 1;
				}
				match++;			
			}				
		}		
	}

	cout << "math = " << match << endl;
	cout << "bonus = " << bonus << endl;

	switch (match) {
	case 3: rank = 5; break;
	case 4: rank = 4; break;
	case 5: rank = 3; break;
	case 6: 
		if (bonus == 0)	rank = 1; 		
		else rank = 2; 
		
		break;
	default: rank = 0; break;
	}

	return rank;
}

int Lottery::BonusLotteryNumber(vector<int>& vec)
{
	int rand_number;
	int chk_flg = 0;

	random_device rand;		//�õ� ���� ��� ���� random_device ����.
	mt19937_64 gen(rand());	//random_device�� ���� ���� ���� ������ �ʱ�ȭ.	(�޸��� Ʈ������ �˰��� ���)

	uniform_int_distribution<int> dis(1, 45); //1 ~ 45���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ���� 

	rand_number = dis(gen);

	//���Ӱ� �߻��� ���ʽ���ȣ�� ������ 1�� ��ȣ�� ��ø�Ǵ��� üũ �Ѵ�.
	//1���ȣ�� ��ø�Ǹ� �ٽ� ���ʽ� ��ȣ�� ���� �Ѵ�.
	for (int i = 0; i < vec.size(); i++) {
		if (rand_number == vec[i])
			BonusLotteryNumber(vec);	
	}

	return rand_number; // ������ ���ʽ���ȣ ����.
}

void Lottery::CreateLotteryNumber(/*vector<int>& vec*/)
{
	//�������� 1 ~ 45�� �ߺ����� �ʴ� ���ڸ� ���� �Ѵ�.
	//���ʽ� ��ȣ�� ������ ����. 1 ~ 45���� �ߺ����� �ʴ� ������ ���� �Ѵ�. 

	int bonus_number = 0;
	int create_lottery_num = 0;
	random_device rand;		//�õ� ���� ��� ���� random_device ����.
	mt19937_64 gen(rand());	//random_device�� ���� ���� ���� ������ �ʱ�ȭ.	(�޸��� Ʈ������ �˰��� ���)
	
	uniform_int_distribution<int> dis(1, 45); //1 ~ 45���� �յ��ϰ� ��Ÿ���� �������� �����ϱ� ���� �յ� ���� ���� 
	
	for (int i = 0; i < LOTTO_MAX - 1; i++) {
		create_lottery_num = dis(gen);
		
		//�ߺ� �˻�.
		for (int j = 0; j < machine_vec.size(); j++) {
			if (create_lottery_num == machine_vec[j])
				CreateLotteryNumber();
		}
		machine_vec.push_back(create_lottery_num);
	}

	bonus_number = BonusLotteryNumber(machine_vec);

	machine_vec.push_back(bonus_number);

	cout << "������ 1���ȣ + ���ʽ���ȣ : ";
	for (int i = 0; i < machine_vec.size(); i++) {
		cout << "[" << machine_vec[i] << "] ";
	}

	cout << endl;

	int rank;
	rank = ret_ranking(machine_vec, user_vec);

	cout << "����� " << rank << "�Դϴ�." << endl;
}

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

	Lotto_Input(user_vec);

	printLottoNumber(user_vec);

	CreateLotteryNumber();
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