/*
// 진행률과		속도
// [93,30,55]	[1,30,5]
// 93%	하루에 1% -> 7일.
// 30% 하루에 30% ->3일. // 7일째에 2개의 기능
// 55%	하루에 5% -> 9일. // 9일째에 남은 1개의 기능
// return 2, 1 이 출력되도록.
//

// [95, 90, 99, 99, 80, 99]		[1, 1, 1, 1, 1, 1]
//	5,	10,	1,	1,	20,	1		
//	5일째에 1개
//	10일째 3개
//	20일째 2개
// return 1, 3, 2
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// 이런 문제는 queue를 활용하면 쉽게 풀 수 있다!
int main()
{/*
	queue<int> progress;
	queue<int> speeds;
	vector<int> answer;

	progress.push(95);
	progress.push(90);
	progress.push(99);

	progress.push(99);
	progress.push(80);
	progress.push(99);

	speeds.push(1);
	speeds.push(1);
	speeds.push(1);

	speeds.push(1);
	speeds.push(1);
	speeds.push(1);

	// for문을 돌려서
	// i번째 값이 i+1 보다 크다면, (7 ,3 일 경우) 7을 max에 넣어준다. 
	// i+2번째 값이 7보다 작을 경우, max는 계속7이고,--> max보다 작으면 answer+1
	// 이렇게 하다가 i번째 값이 7보다 큰경우에 그 값을 max에 넣어준다.

	// i번째 값이 i+1 보다 작을경우 (5,10 일 경우) max에 10을 넣고, answer +1 . 
	// 
	// progress 와 speeds로 나오는 값을 비교해서, 큰 값을 max에 넣고. max보다 작을경우 +1. 

	vector<int>dueDay;
	int size = progress.size();
	for (int i = 0; i < size; i++)
	{
		int _progress = 100-progress.front();
		int _speeds = speeds.front();
		int day;

		if (_progress % _speeds != 0 )
		{
			day = (_progress / _speeds) + 1;
			dueDay.push_back(day);
		}
		else
		{
			day = (_progress / _speeds) ;
			dueDay.push_back(day);
		}
		progress.pop();
		speeds.pop();
	}

	int maxDay = 0;
	int count = 0;
	for (int i = 0; i < dueDay.size(); i++)
	{
		if (maxDay == 0) // 0일경우 값을 설정.
		{
			maxDay = dueDay[i];
		}

		if(maxDay >= dueDay[i]) // max값이 5이고 뒤에값이 1 이라면
		{
			count++;
		}
		else if (maxDay < dueDay[i]) // max값이 5이고 뒤에값이 10이라면
		{
			answer.push_back(count);
			maxDay = dueDay[i];
			count = 1;
		}
		
		if (i == dueDay.size()-1)
		{
			answer.push_back(count);
		}
	}
	
	for (auto it = answer.begin(); it != answer.end(); it++)
	{
		cout << *it << endl;
	}
	*/
	//=============================================================
	vector<int>progress{ 95,90,99,99,80,99 };
	vector<int>speeds{ 1,1,1,1,1,1 };

	vector<int> answer;
	queue<int> q;

	int size = speeds.size();

	for (int i = 0; i < size; i++)
	{
		q.push(i);
	}

	while (!q.empty())
	{
		int cnt = 0;
		for(int j = 0; j < size; j++)
		{
			progress[j] += speeds[j];
		}
		
		while (!q.empty() && progress[q.front()] >= 100)
		{
			cnt++;
			q.pop();
		}

		if (cnt != 0)
			answer.push_back(cnt);
	}

	for (auto& c : answer)
		cout << c << endl;
}
