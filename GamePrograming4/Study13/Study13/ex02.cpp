// 백준 3474번
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>

//알고리즘 대회에서만 사용하기
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int line;
	cin >> line;

	while (line--)
	{
		int number;
		cin >> number;
		cin.ignore();
		int total = 1;
		for (int i = 2; i <= number; i++)
			total *= i;

		int cnt = 0;
		int top = total / 10;
		while (number>3)
		{
			if (top % 10 == 0)
				cnt++;
			else
				break;

			top = top * 0.1;
		}
		cout << cnt << "\n";
	}

}
