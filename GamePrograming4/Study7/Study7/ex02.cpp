#include<iostream>
using namespace std;
#include<vector>
#include<queue>

int main()
{
	int n = 7;
	int k = 3;
	vector<int> enemy{ 4,2,4,5,3,3,3,1 };

	priority_queue<int, vector<int>, greater<int>> pq;

	int sum = 0;
	int round = 0;

	for (int i = 0; i < enemy.size(); i++)
	{
		int e = enemy[i]; 
		pq.push(e); // pq 에는 최소값이 top으로 가도록 설정
		if (pq.size() > k) // 패스권보다 커야 clear
		{
			sum += pq.top(); // 가장 작은값을 sum에 넣고
			pq.pop();	// 가장 작은 값은 pop -> pq에는 큰 값들만 남고. pass권으로 처리가능
		}
		if (sum > n) // 가장 작은값을 더했을때 n보다 크다면 
		{
			round = i; // 해당 라운드 이전까지만 클리어 한것.
			break; // +) sum이랑 n이 같다면 해당라운드는 clear한것으로 생각하기때문!
		}
		else // enemy가 패스권보다 작으면 round는 enemy의 크기 || enemy의 모든값을 합친것 보다 n이 크다면 마지막 라운드. round = enemy.size();
		{
			round = enemy.size();
		}
	}
	cout << round << endl;
}