#include <iostream>
#include <vector>

#define V1 0
#define V2 1
using namespace std;

int main(int argc, char* argv[])
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(392);
	vec.push_back(30);
	vec.push_back(40);

	vec.pop_back();

#if V1
	for (int i=0; i < vec.size(); i++)
		cout << "vec[" << i << "] = " << vec[i] << endl;
#elif V2
	for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
		cout << "*itr : " << *itr << endl;

	vector<int>::iterator itr = vec.begin() + 2;
	cout << "3번째 원소 : " << *itr << endl;
#endif
	return 0;
}