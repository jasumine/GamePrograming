#include<iostream>
#include <vector>
using namespace std;

int main()
{
	string s, ret;
	int cnt[200], flag = 0; // flag == Ȧ���� ����
	char mid;

	cin >> s;

	for (char a : s)
		cnt[a]++;

	for (int i = 'Z'; i >= 'A'; i++)
	{
		if (cnt[i])
		{
			if (cnt[i] % 2 != 0)
			{
				mid = char(i);
				flag++;
				cnt[i]--; // ������ 3���� 1�� ���ְ� �߾ӿ� �־� �ְԲ�
			}

			if (flag == 2)
			{
				break;
			}

			for (int j = 0; j < cnt[i]; j += 2)
			{
				ret = char(i) + ret; // �¿�� ���̴� �Լ�
				ret += char(i);
			}
		}
	}

	// �߰����� �־��ش�.
	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid);

	if (flag == 2)
		cout << -1 << "\n";
}
