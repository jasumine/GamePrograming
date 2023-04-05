// 문자를 입려받아서 그게 펠린드롭이면 1, 아니면 0 리턴
// level 1 << 앞으로 읽으나, 뒤로 읽으나 똑같음 1로 출력
// abc 0  << 앞으로 읽으나, 뒤로 읽으나 다름 0으로 출력

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;


int main()
{
	/*
	while (1)
	{
		cout << "문자를 입력하세요." << '\n';
		char str[50];
		char str2[50];
		
		cin >> setw(cin.gcount()/2) >> str; // 딱 5글자만 입력받는다.
		cout << str << "\n";

		cin >> setw(cin.gcount()) >> str2; // 딱 5글자만 입력받는다.
		cout << str2 << "\n";

		if (str == str2)
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}*/

	string s;
	cin >> s;
	string temp = s;
	reverse(temp.begin(), temp.end()); //  temp를 처음부터 끝까지 뒤집는다.
	if (temp == s)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}