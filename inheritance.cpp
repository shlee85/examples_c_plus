//유뷰트 나우캠퍼스 강의 참고.

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

class B : protected A //private형식으로 상속.
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

//만약 protected로 상속 하면 public은 protected로 상속이 된다.
//만약 public로 상속하면 public은 public, protected는 protected로 상속이 된다.
// - 또한 외부에서 public 을 호출 할 수 있다. 
//만약 private로 삭송 하면 protected은 private로 public은 private로 상속이 된다.

int main(int argc, char* argv[])
{
	C Test;
	Test.Print();

	return 0;
}