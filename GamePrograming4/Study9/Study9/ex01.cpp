// 펠린드롬 만들기.
// string s;
// AABB -> ABBA 로 바꾼다.
// AAABB -> ABABA	BAAAB -> 사전순으로 해서 ABABA가 출력되야함
// ABC -> -1(불가능)
// ABACABA ->	AABCBAA -> 사전순
//
// 불가능하면 -1 리턴, 가능하면 사전순으로 먼저나오게


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string str;
	cin >> str;

	sort(str.begin(), str.end());

	vector<string> vstr;

	char ch;
	int chCount = 0;
	vector<int> count;
	for (int i = 0; i < str.size(); ++i)
	{
		if (ch == NULL || ch != str[i])
		{
			ch = str[i];
			count.push_back(chCount);
			chCount = 0;
		}

		if (ch == str[i])
		{
			chCount++;
		}
	}

	int pass = 0;
	for (auto a : count)
	{
		if (vstr.size() % 2 == 1) // 홀수일 경우
		{
			if (count[a] % 2 == 1) // 해당값이 홀수의
			{
				pass++;
			}
		}
		else // 짝수인 경우
		{
			if (count[a] == 1)
			{
				pass++;
			}
		}
	}

	if (pass)

		for (int i = 0; i < str.size(); ++i)
		{


		}


	for (int i = 0; i < str.size() / 2; i++)
	{
		vstr[i] = str[i];
		vstr[str.size() - i] = str[i + 1];
	}

	for (auto it : vstr)
		cout << it;
}