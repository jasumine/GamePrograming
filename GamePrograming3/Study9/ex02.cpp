#include <iostream>
using namespace std;
#include <vector>

int main()
{
	vector<int> v6(10, 5);// 10ĭ�� ũ�⿡ 5��� ���� �� ����.
	v6.push_back(10);
	v6.push_back(20);
	v6.push_back(15);
	v6.push_back(40);

	for (auto it = v6.begin(); it != v6.end(); it++)
	{
		cout << *it << endl;
	}

	//���� ū �� ���.

	auto temp = v6.begin();
	for (auto it = v6.begin(); it != v6.end(); it++)
	{
		if (temp < it)
		{
			temp = it;
		}
	}
	cout << "���� ū ���� " << *temp << " �Դϴ�." << endl;
	
}