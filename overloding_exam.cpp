//모두의 코드 : 함수 오버로딩 학습.
#include <iostream>

#define O1 0
#define O2 1

//C 컴파일러에서는 에러가 나지만 c++ 컴파일에서는 함수명이 같아도 인자만 다르면 다르다고 인지한다.
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

	//생성자.
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
		return 29; //윤년;
	}
	else {
		return 28;
	}
}

void Date::AddDay(int inc)
{
	while (true) {
		//현재 달의 총 일 수
		int current_month_total_days = GetCurrentMonthTotalDays(year_, month_);

		//같은 달 안에 들어오는 경우.
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
	std::cout << "오늘은 " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 입니다. "
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
	//아무런 초기값을 주지 않으면 생성자는 디폴트 생성자이다. 
	/*  디폴트 생성자 .
		class {
			Date() {
				year_ = 2012;
				month_ = 7;
				day_ = 12;
			}
		}

	    Date day = Date(); //디폴트 생성자.
	    Date day2; 

		c++11부터는 class Test {
			public:
				Test() = default; //디폴트 생성자를 정의해라. (컴파일러에게 명시적으로 알려주는 역할)
		}
	*/
	Date day = Date(2013, 1, 3); //(명시적방법.) 생성자를 이용하요 초기화 한다. 이럴경우 굳이 SetDate 를 해줄 필요 없음.
	Date day(2013, 1, 3); //(암시적방법.) 생성자를 이용하요 초기화 한다. 이럴경우 굳이 SetDate 를 해줄 필요 없음.

	day.SetDate(2011, 3, 1);
	day.ShowDate();

	day.AddDay(30);
	day.ShowDate();

	day.AddDay(2000);
	day.ShowDate();

	day.SetDate(2012, 1, 31);  //윤년
	day.AddDay(29);
	day.ShowDate();

	day.SetDate(2012, 8, 4);
	day.AddDay(2500);
	day.ShowDate();

#endif
	return 0;
}