// ���ڸ� �Է��޾Ƽ� �װ� �縰����̸� 1, �ƴϸ� 0 ����
// level 1 << ������ ������, �ڷ� ������ �Ȱ��� 1�� ���
// abc 0  << ������ ������, �ڷ� ������ �ٸ� 0���� ���

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
		cout << "���ڸ� �Է��ϼ���." << '\n';
		char str[50];
		char str2[50];
		
		cin >> setw(cin.gcount()/2) >> str; // �� 5���ڸ� �Է¹޴´�.
		cout << str << "\n";

		cin >> setw(cin.gcount()) >> str2; // �� 5���ڸ� �Է¹޴´�.
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
	reverse(temp.begin(), temp.end()); //  temp�� ó������ ������ �����´�.
	if (temp == s)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}