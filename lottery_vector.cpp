//STL학습을 위해 vector을 활용하여 로또 프로그램을 만들어 본다.
//로또 번호 1 ~ 45번까지 입력 가능.
/*
	1등 당첨번호 6개, 보너스번호 1개를 추첨
	입력한 번호를 추출하여 1 ~ 5등의 결과로 알려준다.
*/
//vector와 class를 최대한 활용 해본다.

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

	//로또 번호 생성, 본번호 + 보너스 번호
	void CreateLotteryNumber(/*vector<int>& machine*/);
	int BonusLotteryNumber(vector<int>& machine);

	//입력한 번호와 생성된 번호를 비교하여 순위를 매긴다.
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

	random_device rand;		//시드 값을 얻기 위한 random_device 생성.
	mt19937_64 gen(rand());	//random_device를 통해 난수 생성 엔진을 초기화.	(메르센 트위스터 알고리즘 사용)

	uniform_int_distribution<int> dis(1, 45); //1 ~ 45까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의 

	rand_number = dis(gen);

	//새롭게 발생된 보너스번호를 생성된 1등 번호와 충첩되는지 체크 한다.
	//1등번호와 충첩되면 다시 보너스 번호를 생성 한다.
	for (int i = 0; i < vec.size(); i++) {
		if (rand_number == vec[i])
			BonusLotteryNumber(vec);	
	}

	return rand_number; // 생성된 보너스번호 리턴.
}

void Lottery::CreateLotteryNumber(/*vector<int>& vec*/)
{
	//랜덤으로 1 ~ 45의 중복되지 않는 숫자를 생성 한다.
	//보너스 번호는 별도로 생성. 1 ~ 45에서 중복되지 않는 값으로 생성 한다. 

	int bonus_number = 0;
	int create_lottery_num = 0;
	random_device rand;		//시드 값을 얻기 위한 random_device 생성.
	mt19937_64 gen(rand());	//random_device를 통해 난수 생성 엔진을 초기화.	(메르센 트위스터 알고리즘 사용)
	
	uniform_int_distribution<int> dis(1, 45); //1 ~ 45까지 균등하게 나타나는 난수열을 생성하기 위해 균등 분포 정의 
	
	for (int i = 0; i < LOTTO_MAX - 1; i++) {
		create_lottery_num = dis(gen);
		
		//중복 검사.
		for (int j = 0; j < machine_vec.size(); j++) {
			if (create_lottery_num == machine_vec[j])
				CreateLotteryNumber();
		}
		machine_vec.push_back(create_lottery_num);
	}

	bonus_number = BonusLotteryNumber(machine_vec);

	machine_vec.push_back(bonus_number);

	cout << "생성된 1등번호 + 보너스번호 : ";
	for (int i = 0; i < machine_vec.size(); i++) {
		cout << "[" << machine_vec[i] << "] ";
	}

	cout << endl;

	int rank;
	rank = ret_ranking(machine_vec, user_vec);

	cout << "당신은 " << rank << "입니다." << endl;
}

bool check_number(int num)
{
	if (num > 45 || num < 1) {
		cout << "잘못된 숫자를 입력 하셨습니다. 다시 입력 하세요." << endl;

		return false;
	}
	else
		return true;
}

//중복 체크. 처음에 체크되는 부분은 true 이후 중복이 발견되면 fail
bool Lottery::duplicate_check(int input, vector<int>& vec)
{
	int check_cnt = 0;

	cout << "input : " << input << endl;
	cout << "vector size : " << vec.size() << endl;

	for (int i = 0; i < vec.size(); i++){
		cout << "vec : " << vec[i] << endl;
		if (input == vec[i]) {			
			cout << "데이터 중복." << endl;
			return false;			
		}
	}

	return true;
}

void Lottery::Lotto_Input(vector<int>& vec)
{
	cout << "번호를 입력하세요." << endl;	

	while (1) {		
		cout << lotto_idx +1 << "번째 번호 입력 : ";
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
	cout << "안녕하세요. 로또 테스트 프로그램에 오신 것을 환영 합니다." << endl;
	cout << "총 6개의 번호를 입력하세요 1 ~ 45 입니다." << endl;
	cout << "총 6개를 맞추면 1등입니다." << endl;
	cout << "총 5개를 맞추고 보너스번호 1개를 맞추면 2등입니다. ( 억울 하겠네요... ㅎㅎ ) " << endl;
	cout << "총 5개를 맞추면 3등 입니다. " << endl;
	cout << "총 4개를 맞추면 4등 입니다. " << endl;
	cout << "총 3개를 맞추면 3등 입니다. " << endl;
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