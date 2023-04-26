// 백준 4659
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

// 출력초과 ㅠㅠ
int main()
{
	while (1)
	{
		string str;
		cin >> str;

		vector<char> vowel{ 'a','e','i','o','u' };
		int vowelCount = 0;
		int check = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == str[i + 1]) // 두글자 연속 일 경우
			{
				if (str[i] != 'e' && str[i] != 'o')
				{
					cout << "<" << str << "> is not aceptable. \n";
					check++;
					break;
				}
			}

			int one, two, three;
			if (i % 3 == 0 && find(vowel.begin(), vowel.end(), str[i]) == vowel.end()) { one = 1; }
			else { one = 2; vowelCount++; }

			if (i % 3 == 1 && find(vowel.begin(), vowel.end(), str[i]) == vowel.end()) { two = 1; }
			else { two = 2; vowelCount++; }

			if (i % 3 == 2 && find(vowel.begin(), vowel.end(), str[i]) == vowel.end()) { three = 1; }
			else { three = 2; vowelCount++; }

			if (one == two && two == three)
			{
				cout << "<" << str << "> is not aceptable. \n";
				check++;
				break;
			}
		}

		if (check == 0)
		{
			if (vowelCount == 0)
				cout << "<" << str << "> is not aceptable. \n";
			else
				cout << "<" << str << "> is aceptable. \n";
		}
	}
}

