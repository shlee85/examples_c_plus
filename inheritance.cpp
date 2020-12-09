//����Ʈ ����ķ�۽� ���� ����.

#include <iostream>
#include <string>

using namespace std;

class A
{
private:
	void PrintPrivateA() { 	cout << "A Private " << endl;	}

protected:
	void PrintProtectedA() { cout << "A Procected " << endl; }

public:
	void PrintPublicA() { cout << "A Public " << endl; }
};

class B : protected A //private�������� ���.
{
public:
	void Print() {
		//PrintPrivateA();
		PrintProtectedA();
		PrintPublicA();
	}
};

class C : public B
{
public :
	void test() {
		PrintProtectedA();
		PrintPublicA();
	}
};

//���� protected�� ��� �ϸ� public�� protected�� ����� �ȴ�.
//���� public�� ����ϸ� public�� public, protected�� protected�� ����� �ȴ�.
// - ���� �ܺο��� public �� ȣ�� �� �� �ִ�. 
//���� private�� ��� �ϸ� protected�� private�� public�� private�� ����� �ȴ�.

int main(int argc, char* argv[])
{
	C Test;
	Test.Print();

	return 0;
}