#include<iostream>
using namespace std;

string s;
int vcnt, ccnt; // ����ī��Ʈ, ����ī��Ʈ

bool isVowel(char idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

// ������ 1�� �̻� �־���ϰ�
// �����̳� ������ 3�� ���� ����ȵȴ�.
// �������ڰ� 2���̻� ���� �ȵ����� ee�� oo�� ����

int main()
{
	while (true)
	{
		cin >> s; // s�� �Է¹ް�

		if (s == "end") // end�� ��� break;
			break;

		vcnt = ccnt = 0; // ������ ������ ������ 0���� �ʱ�ȭ

		bool flag = 0; // ������ ���� �� ��� bool = 1;
		bool check_v = 0; // ����üũ�ϱ�

		for (int i = 0; i < s.size(); i++)
		{
			if (isVowel(s[i])) // ������ ���
			{
				check_v = true; // ������ �ִ°� Ȯ��
				vcnt++;  // ������ �������� �ִ��� Ȯ���ϱ� ���ؼ�
				ccnt = 0; // ������ 0���� �ʱ�ȭ�Ѵ�
			}
			else // ������ ��� 
			{
				ccnt++; // ���� Ȯ��
				vcnt = 0; // ���� 0���� �ʱ�ȭ
			}

			if (vcnt == 3 || ccnt == 3) // �����̳� ������ 3�� �����ϰ��
				flag = 1; // flag�� 1�� �����.

			if (i > 0 && s[i - 1] == s[i] && !(s[i] == 'e' || s[i] == 'oo'))
				flag = 1; // i�� 1���� ũ��, ���� ���� ����, e��i�� �ƴҰ�� ���� ����
		}

		if (check_v == 0)
			flag = 1; // ������ ���ٸ� flag = 1

		// flag�� 1�̶�� �Ұ���
		if (flag)
			cout << "<" << s << "> is not acceptable. \n";
		else
			cout << "<" << s << "> is acceptable. \n";

		
	}
}