// 버튼을 눌러서 숫자 0 만들기		10^n만 버튼이 존재.
//	-1, 1, 10, -10, 100, -100, 1000, -1000	// 숫자를 음수로 만들면서 할 순 없다.
// 
// 16 을 0으로 만들려면 
// 1) -1 6번, -10 1번 -> 7번
// 2) +1 4번, -10 2번 -> 6번
//
// 2554를 0으로 만들려면
// 1) -1 4번, -10 5번, -100 5번, -1000 2번 -> 16번
// 2) +1 6번, +10 4번, +100 3번, -1000 3번 -> 16번
//
// 숫자가 주어졌을때 10^n만 활용하여서, 최소의 횟수를 구하기

#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int main()
{/*
	int num = 2554;
	int count = 0;
	vector<int> vnum{ 2,5,5,4 };

	for (int i = vnum.size()-1; i >=0; i--)
	{
		if (vnum[i] >= 5)
		{
			// 5,6,7,8,9의 경우 더하는게 숫자가 작다.
			while (vnum[i] != 10)
			{
				vnum[i]++;
				count++;
			}
			int temp = vnum[i-1];
			vnum[i-1] = temp+1 ;
		}
		else
		{
			// 0 1,2,3,4
			count += vnum[i];
		}
	}
	
	cout << count;

	*/
	// 일의 자리가 5보다 크면 +
	// 일의 자리가 5보다 작으면 -
	// 일의자리가 5이고, 십의자리가 5보다 크면 일의자리의 5를 + , 십의자리가 5보다 작으면 일의자리의 5를 -

	int number = 160;
	int answer = 0;

	while (number > 0)
	{
		int temp = number % 10; // 10으로 나눈 나머지

		number = number / 10; // 10으로 나눈 몫

		if (temp > 5 || (temp == 5 && number % 10 >= 5)) // 나머지가 5보다크다(일의자리) || 나머지가 5와 같고, 몫(number, 십의자리)가 5보다 클 경우 -> 더하는게 횟수가 작음
		{
			answer += 10 - temp; // answer에 더해준다
			number++; // 더해줬기 때문에 number를 1 더해준다.
		}
		else // 위의 경우가 아니라면(일의 자리가 4이하라면) answer에 일의자리(temp)를 더해준다.
		{
			answer += temp; // 나머지를 계속 더해주기때문에 마지막자리수의 값만 더해지게 된다.
		}
	}

	cout << answer << endl;

}

