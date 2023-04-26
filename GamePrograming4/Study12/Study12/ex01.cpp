#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s;
int vcnt, ccnt; // 모음카운트, 자음카운트

bool isVowel(char idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main()
{
	while (true)
	{
		cin >> s;

		if (s == "end")
			break;

		vcnt = ccnt = 0;

		bool flag = 0; // 조건에 맞는지 판단
		bool check_v = 0; // 모음 체크

		for (int i = 0; i < s.size(); i++)
		{
			if (isVowel(s[i]))
			{
				check_v = true; // 모음이 1개있다는 뜻
				vcnt++; // 모음은 늘려주고
				ccnt = 0; // 자음은 0으로 초기화
			}
			else  // 자음일 경우
			{
				ccnt++; // 자음은 늘려주고
				vcnt = 0; // 모음은 0으로 초기화
			}

			if (vcnt == 3 || ccnt == 3)
				flag = 1; // 조건을 만족하면 flag = 1

			if (i > 0 && s[i - 1] == s[i] && !(s[i] == 'e' || s[i] == 'o'))
				flag = 1; // i가 1보다크고, s[i-1]과 s[i]가 같고, s[i]가  e나 o가 아니라면 조건만족
		}

		if (check_v == 0)
			flag = 1;

		if (flag) // flag가 1이라면
			cout << "<" << s << "> is not acceptable. \n";
		else
			cout << "<" << s << "> is acceptable. \n";

	}

}