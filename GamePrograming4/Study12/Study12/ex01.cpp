#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

string s;
int vcnt, ccnt; // ����ī��Ʈ, ����ī��Ʈ

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

		bool flag = 0; // ���ǿ� �´��� �Ǵ�
		bool check_v = 0; // ���� üũ

		for (int i = 0; i < s.size(); i++)
		{
			if (isVowel(s[i]))
			{
				check_v = true; // ������ 1���ִٴ� ��
				vcnt++; // ������ �÷��ְ�
				ccnt = 0; // ������ 0���� �ʱ�ȭ
			}
			else  // ������ ���
			{
				ccnt++; // ������ �÷��ְ�
				vcnt = 0; // ������ 0���� �ʱ�ȭ
			}

			if (vcnt == 3 || ccnt == 3)
				flag = 1; // ������ �����ϸ� flag = 1

			if (i > 0 && s[i - 1] == s[i] && !(s[i] == 'e' || s[i] == 'o'))
				flag = 1; // i�� 1����ũ��, s[i-1]�� s[i]�� ����, s[i]��  e�� o�� �ƴ϶�� ���Ǹ���
		}

		if (check_v == 0)
			flag = 1;

		if (flag) // flag�� 1�̶��
			cout << "<" << s << "> is not acceptable. \n";
		else
			cout << "<" << s << "> is acceptable. \n";

	}

}