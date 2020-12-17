//STL학습을 위해 vector을 활용하여 로또 프로그램을 만들어 본다.
//로또 번호 1 ~ 45번까지 입력 가능.
/*
	1등 당첨번호 6개, 보너스번호 1개를 추첨
	입력한 번호를 추출하여 1 ~ 5등의 결과로 알려준다.
*/
//vector와 class를 최대한 활용 해본다.

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