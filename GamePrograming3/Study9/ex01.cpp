// vector stringŸ���� ���͸� ���� 4���� �̸��� �Է¹ް�, 
// �������� ���� �ڿ� ������ �̸��� ����ϼ���.
#include <iostream>
using namespace std;
#include <vector>

int main()
{
	cout << "�̸��� 4�� �Է��ϼ���." << endl;

	vector<string> v;
	for (int i = 0; i < 4; i++)
	{
		string name;
		cin >> name;
		// getline(cin,name);
		v.push_back(name);
	}

	/*auto temp = v[0];
	for (int i = 0; i < 4; i++)
	{
		if (temp < v[i])
		{
			temp = v[i];
		}
	}
	cout << temp;*/

	// for���� ���鼭 ���ϰ� ū���� ����Ѵ�.
	// ū���� ����� temp

	/*auto it1 = v.begin();
	auto temp2 = &it1;
	for (it1; it1 != v.end(); it1++)
	{
		if (temp2 < *it1)
		{
			temp2 = *it1;
		}
	}
	cout << temp;*/

	vector<string>::iterator begin = v.begin();
	vector<string>::iterator end = v.end();
	vector<string>::iterator temp3 = v.begin();
	for (vector<string>::iterator it2 = begin; it2 != end; it2++)
	{
		if (temp3 < it2)
		{
			temp3 = it2;
		}
	}
	cout << *temp3;


}