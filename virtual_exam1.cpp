#include <iostream>
using namespace std;
class classA
{
public:
	classA();	
	virtual ~classA();
//	 ~classA();
};
class classB : public classA
{
public:
	classB();

	void D1();
	void D2();

	~classB();
};
classA::classA()
{
	cout << "A" << endl;
}
classA::~classA()
{
	cout << "~A" << endl;
}
classB::classB()
{
	cout << "B" << endl;
}
classB::~classB()
{
	cout << "~B" << endl;
}

void classB::D1()
{
	cout << "D1" << endl;
}

void classB::D2()
{
	cout << "D2" << endl;
}

//default ������. ( ���ڸ� �ϳ��� ������ �ʴ� ������ )

int main()
{
	cout << "START" << endl;
	classB* B = new classB; 
	classA* A = B;

	delete A;
	
	return 0;
}