// 1,2,3,9,10,12를 입력 받아서
// 가장 작은 숫자 + (두번째로 작은 숫자 * 2)
// 1+4 = 5		<- 1번
// 
// 5,3,9,10,12
// 3,5,9,10,12
// 3+10			<- 2번
// 
// 9,10,12,13 // 모든 숫자가 7이상이면 종료, 답은 2 <- 출력

#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
	vector<int> scov{ 1,2,3,9,10,12 };
	int k = 7;
	int answer = 0;

	priority_queue<int, vector<int>, greater<int>>pq;
	
	for (auto& a : scov)
		pq.push(a);

	while (pq.size() >= 2 && pq.top() < k)
	{
		int min1 = pq.top();
		pq.pop();
		
		int min2 = pq.top() * 2;
		pq.pop();

		pq.push(min1 + min2);
		answer++;
	}

	if (pq.top() < k)
		answer = -1;
	
	cout << answer << endl;

	priority_queue<int, vector<int>, greater<int>> pscov;
	pscov.push(1);
	pscov.push(2); 
	pscov.push(3);
	pscov.push(9);
	pscov.push(10);
	pscov.push(12);

	int count = 0;
	while (pscov.top() <k)
	{
		int min = pscov.top();
		pscov.pop();

		// 사이즈가 1인데 7보다 작을경우 break;
		if (pscov.size() == 1 && pscov.top() < k) 
			break;

		int min2 = pscov.top() *2;
		pscov.pop();

		pscov.push(min + min2);
		count++;
	}

	cout << count << endl;

}

