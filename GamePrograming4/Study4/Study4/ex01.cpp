// arr 1133011  이 들어오면 1301
// 44433 이 들어오면 43
// 연속된 숫자를 지우는것. 순서는 같아야함.

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
		// top의 값이랑 넣을려는 s의 값이 같지않으면 push
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

	//arr.erase(unique(arr.begin(), arr.end(), arr.end())); //중복된걸 지운다.. ㄷ.ㄷ;;
}