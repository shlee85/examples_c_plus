#include <iostream>
#define A0 0
#define A1 1
using namespace std;
#if A0
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
#elif A1
// base class �� �������� ��Ī : base class, super class, parent class, �θ� Ŭ����, �ֻ��� Ŭ���� or ���� Ŭ������ �θ���.
// derived class�� �������� ��Ī : sub class, child class, �ڽ� Ŭ����, ���� Ŭ����, ������ Ŭ������ �θ���.
// ���� ������ : public, private, protected 
class CTest1	// base calss 
{
public :
	int m_a;
	int m_b;

	//protected�� ����ڿ����� private�� ����ϴ� ����. 
	//�ܺο����� ���� ������ �ȵǸ� ���� �Լ��������� ����� �����ϴ�.
	//���࿡ �θ�Ŭ�������� private�� ����� �Ǿ ����� �Ұ���.
private :
	int m_pri;

protected:
	void print();
};

class CTest2 : public CTest1 //, public CTest3 (���������� �ϸ� ���߻���� �ȴ�)          
							 //(�θ� Ŭ������ ��� �Ѵ�.)      
							 // ���������� ���� ��� ����Ʈ�� private�� �����ȴ�.
							 // ���� private�� ����ϸ� public�� private�� ����Ѵ�. 
{
public:
	void print2();
};

void CTest1::print()
{
	cout << m_a << "   " << m_b << endl;
}

void CTest2::print2() {
	CTest2::print();
}
#endif

//default ������. ( ���ڸ� �ϳ��� ������ �ʴ� ������ )
int main()
{
#if A0
	cout << "START" << endl;
	classB* B = new classB; 
	classA* A = B;

	delete A;
#elif A1
	CTest2 c_t;

	c_t.m_a = 10;
	c_t.m_b = 20;
	c_t.print2();
#endif
	
	return 0;
}