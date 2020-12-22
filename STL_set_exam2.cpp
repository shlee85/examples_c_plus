//STL_set_exam1�� �ι�° ����. 
//���� ���� Ŭ���� ��ü�� SET�� insert�ϰ� ���� ���.

#include <iostream>
#include <set>
#include <string>

using namespace std;

template <typename T>

void print_set(set<T>& s) {
	//SET�� ��� ���ҵ��� ����ϱ�.
//	cout << "[ ";

	for (const auto& elem : s) {
		cout << elem << " " << endl;
	}
//	cout << " ]" << endl;
}

class Todo {
	int priority; // �߿䵵, ���� ���� ���� ��.
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
	o << "[ �߿䵵: " << td.priority << "] " << td.job_desc;
	return o;
}

int main(int argc, char** argv) 
{
	set<Todo> todos;

	todos.insert(Todo(1, "�� �ϱ�"));
	todos.insert(Todo(2, "�౸ �ϱ�"));
	todos.insert(Todo(1, "���α׷��� ������Ʈ"));
	todos.insert(Todo(3, "ģ�� ������"));
	todos.insert(Todo(2, "Ź�� �ϱ�"));

	print_set(todos);

	cout << "---------------" << endl;
	cout << "������ ���´ٸ�!" << endl;

	todos.erase(todos.find(Todo(2, "�౸ �ϱ�")));

	print_set(todos);

	return 0;
}