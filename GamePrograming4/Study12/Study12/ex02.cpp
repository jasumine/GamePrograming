#include<iostream>
using namespace std;

string s;
int vcnt, ccnt; // 모음카운트, 자음카운트

bool isVowel(char idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

// 모음이 1개 이상 있어야하고
// 모음이나 자음이 3개 연속 오면안된다.
// 같은글자가 2개이상 오면 안되지만 ee나 oo는 가능

int main()
{
	while (true)
	{
		cin >> s; // s를 입력받고

		if (s == "end") // end일 경우 break;
			break;

		vcnt = ccnt = 0; // 모음과 자음의 개수를 0으로 초기화

		bool flag = 0; // 조건을 만족 할 경우 bool = 1;
		bool check_v = 0; // 모음체크하기

		for (int i = 0; i < s.size(); i++)
		{
			if (isVowel(s[i])) // 모음일 경우
			{
				check_v = true; // 모음이 있는걸 확인
				vcnt++;  // 모음이 연속으로 있는지 확인하기 위해서
				ccnt = 0; // 자음을 0으로 초기화한다
			}
			else // 자음일 경우 
			{
				ccnt++; // 연속 확인
				vcnt = 0; // 모음 0으로 초기화
			}

			if (vcnt == 3 || ccnt == 3) // 자음이나 모음이 3개 연속일경우
				flag = 1; // flag를 1로 만든다.

			if (i > 0 && s[i - 1] == s[i] && !(s[i] == 'e' || s[i] == 'oo'))
				flag = 1; // i가 1보다 크고, 이전 값과 같고, e나i가 아닐경우 조건 충족
		}

		if (check_v == 0)
			flag = 1; // 모음이 없다면 flag = 1

		// flag가 1이라면 불가능
		if (flag)
			cout << "<" << s << "> is not acceptable. \n";
		else
			cout << "<" << s << "> is acceptable. \n";

		
	}
}