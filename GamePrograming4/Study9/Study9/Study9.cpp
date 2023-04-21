#include <iostream>
using namespace std;
#include <vector>
// 스택, 큐, 벡터, 리스트, 힙 bst 
// 정렬, dfs, bfs, 동적계획법(다양쓰)
#include <algorithm>

// #1
int main()
{
	// 저울에 담는다.
	//
	// 70	50	80	50			// 바구니 1개에 100kg
	//	50 + 50은 가능한데 80+50은 100을 초과해버려서 못함
	// 50+50	80		70		<- 총 3번 담아야함
	// 
	// 70	80	50 <- 총 3번 담아야함.

	vector<int> weight{ 70,50,80,50 };
	int basket = 100;

	// 최소로 바구니를 몇 번 사용할까?
	
	int count = 0;
	int total = 0;

	for (int i = 0; i < weight.size(); i++)
	{
		if (total <= basket) // 총 무게가 100보다 작으면
		{
			total += weight[i]; // 총 무게에 무게를 더해준다.
			if (total > basket) // 만약 더해준 값이 바구니의 무게보다 크다면
			{
				// 바구니를 새로운 바구니로 바꾸어주어야해서
				total = weight[i]; // 새로운 바구니에 초과되어버린 i번째 무게를 넣어주면서 초기화 시켜준다.
				count++; // 새로운 바구니라서 +1
			}
		}
	}

	cout << count << endl;

	
	// 바구니에 최대 2개를 담아야 한다면.
	sort(weight.begin(), weight.end());

	int answer = 0;
	int idx = 0;
	while (weight.size() > idx)
	{
		int back = weight.back();
		weight.pop_back(); // 제일 큰 값

		if (weight[idx] + back <= basket) // 제일 작은 값이랑 큰값이 바구니 무게보다 작거나 같다면
		{
			answer++;
			idx++;
		}
		else // 아니라면 weight[idx] 값 혼자 바구니에 들어가야됨
			answer++;
	}
	cout << answer << endl;
}

