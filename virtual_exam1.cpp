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
// base class 의 관례적인 명칭 : base class, super class, parent class, 부모 클래스, 최상위 클래스 or 상위 클래스라 부른다.
// derived class의 관례적인 명칭 : sub class, child class, 자식 클래스, 하위 클래스, 최하위 클래스라 부른다.
// 접근 지정자 : public, private, protected 
class CTest1	// base calss 
{
public :
	int m_a;
	int m_b;

	//protected는 상속자에서는 private로 사용하는 형식. 
	//외부에서는 절대 접근이 안되며 오직 함수내에서만 사용이 가능하다.
	//만약에 부모클래스에서 private면 상속이 되어도 사용이 불가능.
private :
	int m_pri;

protected:
	void print();
};

class CTest2 : public CTest1 //, public CTest3 (여러가지로 하면 다중상속이 된다)          
							 //(부모 클래스를 상속 한다.)      
							 // 접근지정자 없는 경우 디폴트로 private로 지정된다.
							 // 만약 private로 상속하면 public는 private로 사용한다. 
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

//default 생성자. ( 인자를 하나도 가지지 않는 생성자 )
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