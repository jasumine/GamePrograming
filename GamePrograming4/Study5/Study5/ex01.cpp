/*
// �������		�ӵ�
// [93,30,55]	[1,30,5]
// 93%	�Ϸ翡 1% -> 7��.
// 30% �Ϸ翡 30% ->3��. // 7��°�� 2���� ���
// 55%	�Ϸ翡 5% -> 9��. // 9��°�� ���� 1���� ���
// return 2, 1 �� ��µǵ���.
//

// [95, 90, 99, 99, 80, 99]		[1, 1, 1, 1, 1, 1]
//	5,	10,	1,	1,	20,	1		
//	5��°�� 1��
//	10��° 3��
//	20��° 2��
// return 1, 3, 2
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// �̷� ������ queue�� Ȱ���ϸ� ���� Ǯ �� �ִ�!
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

	// for���� ������
	// i��° ���� i+1 ���� ũ�ٸ�, (7 ,3 �� ���) 7�� max�� �־��ش�. 
	// i+2��° ���� 7���� ���� ���, max�� ���7�̰�,--> max���� ������ answer+1
	// �̷��� �ϴٰ� i��° ���� 7���� ū��쿡 �� ���� max�� �־��ش�.

	// i��° ���� i+1 ���� ������� (5,10 �� ���) max�� 10�� �ְ�, answer +1 . 
	// 
	// progress �� speeds�� ������ ���� ���ؼ�, ū ���� max�� �ְ�. max���� ������� +1. 

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
		if (maxDay == 0) // 0�ϰ�� ���� ����.
		{
			maxDay = dueDay[i];
		}

		if(maxDay >= dueDay[i]) // max���� 5�̰� �ڿ����� 1 �̶��
		{
			count++;
		}
		else if (maxDay < dueDay[i]) // max���� 5�̰� �ڿ����� 10�̶��
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
