// �縰��� �����.
// string s;
// AABB -> ABBA �� �ٲ۴�.
// AAABB -> ABABA	BAAAB -> ���������� �ؼ� ABABA�� ��µǾ���
// ABC -> -1(�Ұ���)
// ABACABA ->	AABCBAA -> ������
//
// �Ұ����ϸ� -1 ����, �����ϸ� ���������� ����������


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
		if (vstr.size() % 2 == 1) // Ȧ���� ���
		{
			if (count[a] % 2 == 1) // �ش簪�� Ȧ����
			{
				pass++;
			}
		}
		else // ¦���� ���
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