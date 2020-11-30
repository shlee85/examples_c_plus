//����� �ڵ� : �Լ� �����ε� �н�.
#include <iostream>

#define O1 0
#define O2 1

//C �����Ϸ������� ������ ������ c++ �����Ͽ����� �Լ����� ���Ƶ� ���ڸ� �ٸ��� �ٸ��ٰ� �����Ѵ�.
void print(int x) { std::cout << "int : " << x << std::endl; }
void print(char x) { std::cout << "char : " << x << std::endl; }
void print(double x) { std::cout << "double : " << x << std::endl; }

class Date {
	int year_;
	int month_;
	int day_;

public:
	void SetDate(int year, int month, int date);
	void AddDay(int inc);
	void AddMonth(int inc);
	void AddYear(int inc);

	int GetCurrentMonthTotalDays(int year, int month);

	void ShowDate();

	//������.
	Date(int year, int month, int day) {
		year_ = year;
		month_ = month;
		day_ = day;
	}
};

void Date::SetDate(int year, int month, int day)
{
	year_ = year;
	month_ = month;
	day_ = day;
}

int Date::GetCurrentMonthTotalDays(int year, int month)
{
	static int month_day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (month != 2) {
		return month_day[month - 1];
	}
	else if (year % 4 == 0 && year % 100 != 0) {
		return 29; //����;
	}
	else {
		return 28;
	}
}

void Date::AddDay(int inc)
{
	while (true) {
		//���� ���� �� �� ��
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		//���� �� �ȿ� ������ ���.
		if (day_ + inc <= current_month_total_days) {
			day_ += inc;
			return;
		}
		else {
			inc -= (current_month_total_days - day_ + 1);
			day_ = 1;
			AddMonth(1);
		}
	}
}

void Date::AddMonth(int inc)
{
	AddYear((inc + month_ - 1) / 12);
	month_ = month_ + inc % 12;
	month_ = (month_ == 12 ? 12 : month_ % 12);
}

void Date::AddYear(int inc) {
	year_ += inc;
}

void Date::ShowDate() {
	std::cout << "������ " << year_ << " �� " << month_ << " �� " << day_ << " �� �Դϴ�. "
		<< std::endl;
}

int main() {

#if O1
	int a = 1;
	char b = 'c';
	double c = 3.2f;

	print(a);
	print(b);
	print(c);
#elif 02
	//�ƹ��� �ʱⰪ�� ���� ������ �����ڴ� ����Ʈ �������̴�. 
	/*  ����Ʈ ������ .
		class {
			Date() {
				year_ = 2012;
				month_ = 7;
				day_ = 12;
			}
		}

	    Date day = Date(); //����Ʈ ������.
	    Date day2; 

		c++11���ʹ� class Test {
			public:
				Test() = default; //����Ʈ �����ڸ� �����ض�. (�����Ϸ����� ��������� �˷��ִ� ����)
		}
	*/
	Date day = Date(2013, 1, 3); //(��������.) �����ڸ� �̿��Ͽ� �ʱ�ȭ �Ѵ�. �̷���� ���� SetDate �� ���� �ʿ� ����.
	Date day(2013, 1, 3); //(�Ͻ������.) �����ڸ� �̿��Ͽ� �ʱ�ȭ �Ѵ�. �̷���� ���� SetDate �� ���� �ʿ� ����.

	day.SetDate(2011, 3, 1);
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31);  //����
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();

#endif
	return 0;
}