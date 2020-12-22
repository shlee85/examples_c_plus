//STL_set_exam1의 두번째 예제. 
//내가 만든 클래스 객체를 SET에 insert하고 싶은 경우.

#include <iostream>
#include <set>
#include <string>

using namespace std;

template <typename T>

void print_set(set<T>& s) {
	//SET의 모든 원소들을 출력하기.
//	cout << "[ ";

	for (const auto& elem : s) {
		cout << elem << " " << endl;
	}
//	cout << " ]" << endl;
}

class Todo {
	int priority; // 중요도, 높을 수록 급한 것.
	string job_desc;

public:
	Todo(int priority, string job_desc)
		: priority(priority), job_desc(job_desc) {}

	bool operator < (const Todo& t) const {
		if (priority == t.priority) {
			return job_desc < t.job_desc;
		}
		return priority > t.priority;
	}

	friend ostream& operator << (ostream& o, const Todo& td);
};

ostream& operator << (ostream& o, const Todo& td) {
	o << "[ 중요도: " << td.priority << "] " << td.job_desc;
	return o;
}

int main(int argc, char** argv) 
{
	set<Todo> todos;

	todos.insert(Todo(1, "농구 하기"));
	todos.insert(Todo(2, "축구 하기"));
	todos.insert(Todo(1, "프로그래밍 프로젝트"));
	todos.insert(Todo(3, "친구 만나기"));
	todos.insert(Todo(2, "탁구 하기"));

	print_set(todos);

	cout << "---------------" << endl;
	cout << "숙제를 끝냈다면!" << endl;

	todos.erase(todos.find(Todo(2, "축구 하기")));

	print_set(todos);

	return 0;
}