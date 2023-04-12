#include <iostream>
using namespace std;
#include <vector>

int main()
{
	vector<int> v6(10, 5);// 10칸의 크기에 5라는 값을 다 넣음.
	v6.push_back(10);
	v6.push_back(20);
	v6.push_back(15);
	v6.push_back(40);

	for (auto it = v6.begin(); it != v6.end(); it++)
	{
		cout << *it << endl;
	}

	//제일 큰 값 출력.

	auto temp = v6.begin();
	for (auto it = v6.begin(); it != v6.end(); it++)
	{
		if (temp < it)
		{
			temp = it;
		}
	}
	cout << "제일 큰 값은 " << *temp << " 입니다." << endl;
	
}