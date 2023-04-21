#include<iostream>
#include <vector>
using namespace std;

int main()
{
	string s, ret;
	int cnt[200], flag = 0; // flag == 홀수의 갯수
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
				cnt[i]--; // 갯수가 3개면 1을 빼주고 중앙에 넣어 주게끔
			}

			if (flag == 2)
			{
				break;
			}

			for (int j = 0; j < cnt[i]; j += 2)
			{
				ret = char(i) + ret; // 좌우로 붙이는 함수
				ret += char(i);
			}
		}
	}

	// 중간값을 넣어준다.
	if (mid)
		ret.insert(ret.begin() + ret.size() / 2, mid);

	if (flag == 2)
		cout << -1 << "\n";
}
