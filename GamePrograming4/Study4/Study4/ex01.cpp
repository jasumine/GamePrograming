// arr 1133011  �� ������ 1301
// 44433 �� ������ 43
// ���ӵ� ���ڸ� ����°�. ������ ���ƾ���.

#include<stack>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void numberPrint(string s)
{
	stack<char>stk;
	for (int i = 0; i < s.length(); i++)
	{
		// top�� ���̶� �������� s�� ���� ���������� push
		if (stk.empty())
		{
			stk.push(s[i]);
			cout << s[i];
		}
		else
		{
			if (stk.top() != s[i])
			{
				stk.push(s[i]);
				cout << s[i];
			}
		}
	}
}

int main()
{
	string s;
	cin >> s;
	numberPrint(s);

	vector<int>arr{ 1,1,3,3,0,1,1 };
	vector<int>v;

	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i] == arr[i + 1])
			continue;
		else
			v.push_back(arr[i]);
	}

	//arr.erase(unique(arr.begin(), arr.end(), arr.end())); //�ߺ��Ȱ� �����.. ��.��;;
}